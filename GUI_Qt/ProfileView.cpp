#include "ProfileView.h"

ProfileView::ProfileView(tracksAPI::I8tracksAPI* api, QWidget* parent) : APIWindow<QDialog>(api, parent)
{
	this->currentUser = NULL;
	this->ui.setupUi((QWidget*)this);
}

ProfileView::~ProfileView()
{
	
}

// reset user
void ProfileView::setUser(Entities::User* usr)
{
	this->currentUser = usr;
}

void ProfileView::show()
{
	// refresh informations on form
	this->refreshWindow();

	return QDialog::show();
}

void ProfileView::refreshWindow()
{
	// set text
	this->ui.lblSlug->setText(QString(this->currentUser->getSlug().c_str()));

	// download profile image
	ImageDownloader avatarImg(this->currentUser->getAvatars()->find(AVATAR_TYPES::MAX_200)->second, NULL);
	this->ui.lblAvatar200->setPixmap(avatarImg.getPixmap());

	this->ui.lblBio->setText(QString(this->currentUser->getBio().c_str()));
	this->ui.lblLocation->setText(QString(this->currentUser->getLocation().c_str()));
}