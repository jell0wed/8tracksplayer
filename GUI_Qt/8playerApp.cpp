#include "8playerApp.h"
#include <vld.h>

eightPlayerApp::eightPlayerApp(int& argc, char** argv) : QApplication(argc, argv)
{
	this->loginDialog = NULL;

	this->currentApi = new eightTracksAPI(); // init api
	MusicPlayer::getInstance(this->currentApi); // init music player
}

int eightPlayerApp::exec()
{
	this->showLoginDialog();
	return QApplication::exec();
}

eightPlayerApp::~eightPlayerApp()
{
	delete this->currentApi;
	// make sure to delete the main window
	MainWindow::shutdown();
	// make sure to cleanup the currently listen
	CurrentlyListen::shutdown();
	// make sure to delete singleton music player
	MusicPlayer::shutdown();
}

void eightPlayerApp::showLoginDialog()
{
	this->loginDialog = new LoginDialog(this->currentApi, NULL);
	connect(this->loginDialog, SIGNAL(loginSucceded()), this, SLOT(LoginDialog_Sucess())); // bind login success signal
	connect(this->loginDialog, SIGNAL(closeEvent()), this, SLOT(ExitApplication())); // bind close event to ApplicationClose
	this->loginDialog->exec();

	delete this->loginDialog;
}

void eightPlayerApp::showMainWindow()
{
	MainWindow::getInstance(this->currentApi, NULL)->show();
	// exit app when MainWindow is closed
	connect(MainWindow::getInstance(), SIGNAL(closeEvent()), this, SLOT(ExitApplication()));
}

//
// Application Signals
//

//
// Signal from LoginDialog when login succeeded
//
void eightPlayerApp::LoginDialog_Sucess()
{
	// the user has been successfully logged in
	// show the main window
	this->showMainWindow();
}

//
// Slot to close the Application completely
//
void eightPlayerApp::ExitApplication(int ret = 0)
{
	QApplication::exit(ret);
}