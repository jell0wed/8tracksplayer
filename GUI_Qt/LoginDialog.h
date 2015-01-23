#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

/**
 Class that represents the login dialog
*/

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include "../Core/I8tracksAPI.h"
#include "APIWindow.h"
#include "ui_LoginDialog.h"

using namespace tracksAPI;

class LoginDialog : public APIWindow<QDialog>
{
	Q_OBJECT
public:
	LoginDialog(tracksAPI::I8tracksAPI* api, QWidget* parent);
	~LoginDialog();
signals:
	void loginSucceded();
public slots:
	void loginButtonReleased();
	void tryToLogin();
	void endLogin();
private:
	Ui::LoginDialog ui;
};

#endif