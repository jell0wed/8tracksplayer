#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

/**
 Class used to play music (stream) over the internet
 This class is a singleton
*/

#include <QMessageBox>
#include <string>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include "APIWindow.h"
#include "../Core/I8tracksAPI.h"

using std::string;
using namespace tracksAPI;

class MusicPlayer : public APIWindow<QObject>
{
	Q_OBJECT
public:
	static MusicPlayer* getInstance(I8tracksAPI* apiAccess = NULL);
	static void shutdown();
	~MusicPlayer();
	void playMix(Entities::Mix* toPlay);
	void pause();
	void resume();
	void stop();
	void skip();
	bool isPlaying() const;
	bool canSkip() const;
	int getDurationInSec() const;
	Entities::Track* getPlayingTrack() const;
	Entities::Mix* getPlayingMix() const;
	Entities::Set* getPlayingSet() const;
public slots:
	void changeVolume(int vol);
private slots:
	void player_error(QMediaPlayer::Error err);
	void player_positionChanged(qint64 pos);
	void player_mediaStatusChanged(QMediaPlayer::MediaStatus status);
signals:
	void positionChanged(int pos, int length);
	void trackChanged();
private:
	MusicPlayer(I8tracksAPI* apiAccess);
	void playerPlaySet();
	void initPlayer();
	void playNextSet();

	static MusicPlayer* instance;

	QMediaPlayer* player;
	string playToken;
	Entities::Mix* playingMix;
	Entities::Set* playingSet;
	bool reported;
};

#endif