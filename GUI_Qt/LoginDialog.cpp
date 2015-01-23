#include "LoginDialog.h"

LoginDialog::LoginDialog(tracksAPI::I8tracksAPI* api, QWidget* parent = 0) : APIWindow<QDialog>(api, parent)
{
	this->ui.setupUi(this);
	this->moveToThread(this->currentThread);
	// connect the button with the login function
	this->connect(this->ui.btnLogin, SIGNAL(released()), this, SLOT(loginButtonReleased()));
	this->show();
}

LoginDialog::~LoginDialog()
{
	
}

void LoginDialog::loginButtonReleased()
{
	// make form validation
	QString username = this->ui.txtUsername->text();
	QString password = this->ui.txtPassword->text();

	if(username == "") {
		QMessageBox::warning(this, "Error !", "Enter your username !", QMessageBox::StandardButton::Retry, QMessageBox::StandardButton::NoButton);
	} else if(password == "") {
		QMessageBox::warning(this, "Erreur !", "Enter your password !", QMessageBox::StandardButton::Retry, QMessageBox::StandardButton::NoButton);
	} else {
		// now try to log in
		this->setupThread(SLOT(tryToLogin()), SLOT(endLogin()));
		this->emitStart();
	}
}

void LoginDialog::tryToLogin()
{
	this->apiAccess->logInUser(this->ui.txtUsername->text().toUtf8().constData(), this->ui.txtPassword->text().toUtf8().constData());
	this->emitFinished();
}

void LoginDialog::endLogin()
{
	if(this->apiAccess->isLoggedIn())
	{
		emit loginSucceded(); //emit login success signal
		this->close();
	}
	else
	{
		QMessageBox::warning(this, "Error !", "Wrong username / password combination !", QMessageBox::StandardButton::Retry, QMessageBox::StandardButton::NoButton);
	}
}