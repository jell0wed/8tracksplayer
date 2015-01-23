#include "MusicPlayer.h"

MusicPlayer* MusicPlayer::instance = 0;

// singleton get instance
MusicPlayer* MusicPlayer::getInstance(I8tracksAPI* apiAccess)
{
	if(apiAccess != NULL) {
		if(MusicPlayer::instance == 0)
		{
			MusicPlayer::instance = new MusicPlayer(apiAccess);
		}
	}

	return MusicPlayer::instance;
}

// shutdown music player
void MusicPlayer::shutdown()
{
	if(MusicPlayer::instance != NULL)
	{
		delete MusicPlayer::instance;
	}
}

// music player init
MusicPlayer::MusicPlayer(I8tracksAPI* apiAccess) : APIWindow<QObject>(apiAccess, NULL)
{
	// create a new play token
	this->playToken = this->apiAccess->getNewPlayToken();

	this->player = NULL;
	this->playingMix = NULL;
	this->playingSet = NULL;

	this->initPlayer();
}

void MusicPlayer::initPlayer()
{
	// make sure we delete the player
	if(this->player != NULL) { this->stop(); delete this->player; }

	this->player = new QMediaPlayer;
	this->reported = false;
}

// stop player
void MusicPlayer::stop()
{
	if(this->isPlaying())
	{
		this->player->stop();
		this->player->disconnect();

		// only delete the set
		if(this->playingSet != NULL)
		{
			delete this->playingSet;
			this->playingSet = NULL;
		}
	}
}

// play a given mix
void MusicPlayer::playMix(Entities::Mix* toPlay)
{
	this->stop(); // make sure the player is stopped
	
	this->playingMix = toPlay;
	this->playingSet = this->apiAccess->getMixSet(toPlay, this->playToken, GET_SET_ACTION_PLAY);
	this->playerPlaySet();
}

// play the next set
void MusicPlayer::playNextSet()
{
	this->stop();
	
	this->playingSet = this->apiAccess->getMixSet(this->playingMix, this->playToken, GET_SET_ACTION_NEXT);
	this->playerPlaySet();
}

void MusicPlayer::skip()
{
	if(this->isPlaying() && this->canSkip())
	{
		// get next set
		this->stop();
		// set the next set to play
		this->playingSet = this->apiAccess->getMixSet(this->playingMix, this->playToken, GET_SET_ACTION_SKIP);
		this->playerPlaySet(); // play the next set
	}
}


// play a given set
void MusicPlayer::playerPlaySet()
{
	this->reported = false;
	if(this->playingSet->isAtEnd()) {
		// if the end is at end
		QMessageBox::information(0, "Fin du mix!", "La fin du mix à été atteint!", QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
	}

	string streamUrl = string(this->playingSet->getCurrentTrack()->getStreamUrl());

	this->player->setMedia(QUrl(QString(streamUrl.c_str())));
	this->player->setVolume(100);
	this->player->play();

	// connect player signals
	connect(this->player, SIGNAL(error(QMediaError::Error)), this, SLOT(player_error(QMediaPlayer::Error)));
	connect(this->player, SIGNAL(positionChanged(qint64)), this, SLOT(player_positionChanged(qint64)));
	connect(this->player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(player_mediaStatusChanged(QMediaPlayer::MediaStatus)));
	
	emit trackChanged();
}

// make sure to delete everything correctly
MusicPlayer::~MusicPlayer()
{
	this->stop();
	delete this->player;
}


bool MusicPlayer::isPlaying() const
{
	return this->playingSet != NULL && this->playingMix != NULL && this->player->state() == QMediaPlayer::State::PlayingState;
}

bool MusicPlayer::canSkip() const
{
	return this->isPlaying() && this->playingSet->isSkipAllowed();
}

void MusicPlayer::pause()
{
	if(this->isPlaying())
	{
		this->player->pause();
	}
}

void MusicPlayer::resume()
{
	if(this->player->isAudioAvailable())
	{
		this->player->play();
	}
}

Entities::Track* MusicPlayer::getPlayingTrack() const
{
	if(this->isPlaying())
	{
		return this->playingSet->getCurrentTrack();
	}

	return NULL;
}

Entities::Mix* MusicPlayer::getPlayingMix() const
{
	if(this->isPlaying())
	{
		return this->playingMix;
	}

	return NULL;
}

Entities::Set* MusicPlayer::getPlayingSet() const
{
	if(this->isPlaying())
	{
		return this->playingSet;
	}

	return NULL;
}

void MusicPlayer::player_error(QMediaPlayer::Error err)
{
	// TODO : handle error
}

int MusicPlayer::getDurationInSec() const
{
	if(this->isPlaying())
	{
		return this->player->duration() / 1000; // in sec
	}

	return 0;
}

void MusicPlayer::player_positionChanged(qint64 pos)
{
	// we must report the song at 30 secs
	int sec = pos / 1000;
	if(!this->reported && sec >= 30)
	{
		qDebug() << "Reporting current track";
		// report current playing set
		if(!this->apiAccess->reportSong(this->playingMix, this->playingSet->getCurrentTrack(), this->playToken))
		{
			qDebug() << "Error while reporting current track";
		}

		this->reported = true;
	}

	emit positionChanged(sec, this->getDurationInSec());
}

void MusicPlayer::player_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
	if(status == QMediaPlayer::MediaStatus::EndOfMedia)
	{
		this->playNextSet();
	}
}

void MusicPlayer::changeVolume(int vol)
{
	if(this->isPlaying())
	{
		this->player->setVolume(vol);
	}
}