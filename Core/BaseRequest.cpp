#include "BaseRequest.h"

using namespace tracksAPI;

// Init a request with an API_ACTIONS
BaseRequest::BaseRequest(API_ACTIONS action)
{
	this->requestAction = action;
	this->requestUri.scheme = API_URL_SCHEME;
	this->requestUri.host = API_URL_HOST;
}

// get url from Uri class
URI* BaseRequest::getUri()
{
	return &this->requestUri;
}

HTTP_OPERATION BaseRequest::getHttpMethod() const
{
	return this->httpOp;
}

map<string, string> BaseRequest::getBodyParameters() const
{
	return this->bodyParameters;
}

void BaseRequest::addBodyParam(string name, string value)
{
	this->bodyParameters.emplace(std::pair<string, string>(name, value));
}

API_ACTIONS BaseRequest::getAction() const
{
	return this->requestAction;
}