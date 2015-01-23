#include "PlayTokenRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

PlayTokenRequest::PlayTokenRequest() : BaseRequest(API_ACTIONS::PLAY_TOKEN)
{
	this->httpOp = HTTP_OPERATION::GET;
}

URI* PlayTokenRequest::getUri()
{
	this->requestUri.path = PLAY_TOKEN_REQUEST_PATH;
	return BaseRequest::getUri();
}