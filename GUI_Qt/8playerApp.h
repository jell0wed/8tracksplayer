#include <QtWidgets/QApplication>
#include "../Core/8TracksAPI.h"
#include "LoginDialog.h"
#include "MainWindow.h"
#include "MusicPlayer.h"

using namespace tracksAPI;

class eightPlayerApp : public QApplication
{
	Q_OBJECT
public:
	eightPlayerApp(int& argc, char** argv);
	~eightPlayerApp();
	int exec();
private slots:
	void LoginDialog_Sucess();

	void ExitApplication(int ret);
private:
	I8tracksAPI* currentApi;
	LoginDialog* loginDialog;

	void showLoginDialog();
	void showMainWindow();
};