#include "GetSetRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

// create request from play token and action
// notice : we must specify the toPlayMix id with the setter
GetSetRequest::GetSetRequest(string playToken, string action = GET_SET_ACTION_PLAY) : BaseRequest(API_ACTIONS::GET_SET)
{
	this->currentMix = NULL;
	this->playToken = playToken;
	this->actionPath = action;
}

// overload base Request
URI* GetSetRequest::getUri()
{
	this->requestUri.path = GET_SET_REQUEST_PATH;
	this->requestUri.path += this->playToken; // sets the play token
	this->requestUri.path += this->actionPath; 
	// sets the mix id
	this->requestUri.queries.emplace(std::pair<string, string>("mix_id", boost::lexical_cast<string>(this->currentMix->getId())));

	return BaseRequest::getUri();
}

void GetSetRequest::setToPlayMix(Entities::Mix* currentMix)
{
	this->currentMix = currentMix;
}

Entities::Mix* GetSetRequest::getToPlayMix() const
{
	return this->currentMix;
}