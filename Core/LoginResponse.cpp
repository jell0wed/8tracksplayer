#include "LoginResponse.h"

using namespace tracksAPI;

LoginResponse::LoginResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::LOGIN)
{
	this->loggedInUser = NULL;

	// handle the logged in request response
	// first check if the login was sucessful
	this->successful = this->logged_in;
	if(this->logged_in)
	{
		// create the user entity
		this->loggedInUser = new Entities::User(&this->docRootNode->child("current-user"));
		// get the user token
		this->user_token = this->docRootNode->child("user-token").text().as_string();
	}
}

LoginResponse::~LoginResponse()
{
	// dont delete the user, it will be deleted manually by the API
}

bool LoginResponse::isSuccessful()
{
	return this->successful;
}

string LoginResponse::getUserToken()
{
	if(this->isSuccessful())
	{
		return this->user_token;
	}

	return "";
}

Entities::User* LoginResponse::getUser()
{
	if(this->isSuccessful())
	{
		return this->loggedInUser;
	}

	return NULL;
}