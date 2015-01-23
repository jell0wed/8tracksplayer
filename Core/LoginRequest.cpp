#include "LoginRequest.h"

using namespace tracksAPI;

// constructor from username/password
LoginRequest::LoginRequest(string _username, string _password) : BaseRequest(API_ACTIONS::LOGIN)
{
	this->username = _username;
	this->password = _password;
	this->httpOp = HTTP_OPERATION::POST;
}

void LoginRequest::setUsername(string username)
{
	this->username = username;
}

void LoginRequest::setPassword(string password)
{
	this->password = password;
}

//overload from getUri() baseRequest method
URI* LoginRequest::getUri()
{
	this->requestUri.path = LOGIN_REQUEST_PATH;

	this->addBodyParam(LOGIN_REQUEST_USERNAME, this->username);
	this->addBodyParam(LOGIN_REQUEST_PASSWORD, this->password);

	return BaseRequest::getUri();
}