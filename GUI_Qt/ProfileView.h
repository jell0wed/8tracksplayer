#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

/**
 Used to visualize the profile of a user
*/

#include <QDialog>
#include "ImageDownloader.h"
#include "ui_ProfileView.h"
#include "../Core/I8tracksAPI.h"
#include "APIWindow.h"

using namespace tracksAPI;

class ProfileView : public APIWindow<QDialog>
{
	Q_OBJECT
public:
	ProfileView(tracksAPI::I8tracksAPI* api, QWidget* parent);
	~ProfileView();
	void setUser(Entities::User* usr);
	void show();
private:
	Entities::User* currentUser;
	Ui::ProfileView ui;

	void refreshWindow();
};

#endif