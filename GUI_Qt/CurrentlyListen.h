#ifndef CURRENTLYLISTEN_H
#define CURRENTLYLISTEN_H

/**
 Window used to control the mix playback (singleton)
*/

#include <QMessageBox>
#include <assert.h>
#include "MusicPlayer.h"
#include "ProfileView.h"
#include "ui_CurrentlyPlaying.h"
#include "APIWindow.h"
#include "../Core/I8tracksAPI.h"
#include "ImageDownloader.h"

using namespace tracksAPI;

class CurrentlyListen : public APIWindow<QWidget>
{
	Q_OBJECT
public:
	static CurrentlyListen* getInstance(tracksAPI::I8tracksAPI* api = NULL, QWidget* parent = NULL);
	static void shutdown();
	void show();
public slots:
	void changePos(int pos, int duration);
	void refreshWindow();
	void showProfileWindow();
	void playPauseBtn();
	void skipTrack();
private:
	CurrentlyListen(tracksAPI::I8tracksAPI* api, QWidget* parent);
	~CurrentlyListen();

	static CurrentlyListen* instance;

	Ui::currentlyListen ui;
	ProfileView* profileWindow;
};

#endif