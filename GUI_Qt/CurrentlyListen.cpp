#include "CurrentlyListen.h"
#include <boost/lexical_cast.hpp>

CurrentlyListen* CurrentlyListen::instance = NULL;

CurrentlyListen* CurrentlyListen::getInstance(tracksAPI::I8tracksAPI* api, QWidget* parent)
{
	if(CurrentlyListen::instance == NULL)
	{
		assert(api != NULL);
		CurrentlyListen::instance = new CurrentlyListen(api, parent);
	}

	return CurrentlyListen::instance;
}

void CurrentlyListen::shutdown()
{
	if(CurrentlyListen::instance != NULL)
	{
		delete CurrentlyListen::instance;
	}
}

CurrentlyListen::CurrentlyListen(tracksAPI::I8tracksAPI* api, QWidget* parent) : APIWindow(api, parent)
{
	this->ui.setupUi(this);

	this->profileWindow = NULL;
	// connect every signal
	connect(MusicPlayer::getInstance(this->apiAccess), SIGNAL(positionChanged(int, int)), this, SLOT(changePos(int, int)));
	connect(MusicPlayer::getInstance(this->apiAccess), SIGNAL(trackChanged()), this, SLOT(refreshWindow()));
	connect(this->ui.btnProfile, SIGNAL(clicked()), this, SLOT(showProfileWindow()));
	connect(this->ui.volumeSlider, SIGNAL(sliderMoved(int)), MusicPlayer::getInstance(), SLOT(changeVolume(int)));
	connect(this->ui.btnPlayPause, SIGNAL(clicked()), this, SLOT(playPauseBtn()));
	connect(this->ui.btnSkip, SIGNAL(clicked()), this, SLOT(skipTrack()));
}

CurrentlyListen::~CurrentlyListen()
{
	if(this->profileWindow != NULL)
	{
		delete this->profileWindow;
	}
}

void CurrentlyListen::refreshWindow()
{
	// reset proress bar
	this->ui.prgListenStatus->setMaximum(MusicPlayer::getInstance()->getDurationInSec());
	this->ui.prgListenStatus->setValue(0);

	// set the currently playing infos
	this->ui.lblMixName->setText(QString(MusicPlayer::getInstance()->getPlayingMix()->getName().c_str()));
	this->ui.lblDescription->setText(QString(MusicPlayer::getInstance()->getPlayingMix()->getDescription().c_str()));

	// set the mix image
	ImageDownloader picDownload(MusicPlayer::getInstance()->getPlayingMix()->getCovers()->at(AVATAR_TYPES::MAX_200), NULL);
	this->ui.lblMixImg->setPixmap(picDownload.getPixmap());

	// set tracks infos
	this->ui.lblReleaseName->setText(QString(MusicPlayer::getInstance()->getPlayingTrack()->getReleaseName().c_str()));
	this->ui.lblName->setText(QString(MusicPlayer::getInstance()->getPlayingTrack()->getName().c_str()));
	this->ui.lblPerformer->setText(QString(MusicPlayer::getInstance()->getPlayingTrack()->getPerformer().c_str()));
	this->ui.lblYear->setText(QString(boost::lexical_cast<string>(MusicPlayer::getInstance()->getPlayingTrack()->getYear()).c_str()));

	// set btns
	this->ui.btnProfile->setText(QString(MusicPlayer::getInstance()->getPlayingMix()->getUser()->getSlug().c_str()));

	// set skip button
	this->ui.btnSkip->setEnabled(MusicPlayer::getInstance()->canSkip());
}

void CurrentlyListen::show()
{
	if(MusicPlayer::getInstance(this->apiAccess)->isPlaying())
	{
		this->refreshWindow();

		return QWidget::show();
	}

	return;
}

void CurrentlyListen::changePos(int pos, int duration)
{
	this->ui.prgListenStatus->setMaximum(duration);
	this->ui.prgListenStatus->setValue(pos);
}

void CurrentlyListen::showProfileWindow()
{
	// create new profile window if doenst exists
	if(this->profileWindow == NULL)
	{
		this->profileWindow = new ProfileView(this->apiAccess, this);
	}

	this->profileWindow->setUser(MusicPlayer::getInstance()->getPlayingMix()->getUser());
	this->profileWindow->show();
}

void CurrentlyListen::playPauseBtn()
{
	if(MusicPlayer::getInstance()->isPlaying())
	{
		QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/play.png"), QSize(), QIcon::Normal, QIcon::Off);

		MusicPlayer::getInstance()->pause();
		this->ui.btnPlayPause->setIcon(icon);
		this->ui.btnPlayPause->setChecked(true);
	} else
	{
		QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);

		MusicPlayer::getInstance()->resume();
		this->ui.btnPlayPause->setIcon(icon);
		this->ui.btnPlayPause->setChecked(false);
	}
}

void CurrentlyListen::skipTrack()
{
	if(MusicPlayer::getInstance()->canSkip())
	{
		MusicPlayer::getInstance()->skip();
	}
}