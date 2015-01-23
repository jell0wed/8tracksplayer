#include "User.h"

using namespace tracksAPI::Entities;

/**
 Must be the current user node (must have to xml parent)
*/
User::User(xml_node* rootNode) : XMLDecomposable(rootNode)
{
	// parse user attributes from xml
	this->id = this->docRootNode->child("id").text().as_int();
	this->slug = this->docRootNode->child("slug").text().as_string();
	this->login = this->docRootNode->child("login").text().as_string();
	this->location = this->docRootNode->child("location").text().as_string();
	this->bio_html = this->docRootNode->child("bio-html").text().as_string();
	
	// parse every avatars
	this->avatars = XMLDecomposable::parseImageCollection(&this->docRootNode->child("avatar-urls"));
}

User::~User()
{
	delete this->avatars;
}

int User::getId() const
{
	return this->id;
}

string User::getSlug() const
{
	return this->slug;
}

string User::getLogin() const
{
	return this->login;
}

string User::getLocation() const
{
	return this->location;
}

string User::getBio() const
{
	return this->bio_html;
}

map<AVATAR_TYPES, string>* User::getAvatars() const
{
	return this->avatars;
}