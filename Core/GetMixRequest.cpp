#include "GetMixRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

// construct request with mix id
GetMixRequest::GetMixRequest(int mixId) : BaseRequest(API_ACTIONS::GET_MIX)
{
	this->mixId = mixId;
}

GetMixRequest::~GetMixRequest()
{
	// memory is not managaged directly from
	// the request
}

// overload from BaseRequest
URI* GetMixRequest::getUri()
{
	this->requestUri.path = GET_MIX_REQUEST_PATH;
	this->requestUri.path+= boost::lexical_cast<string>(this->mixId);
	this->requestUri.path+= ".xml";

	return BaseRequest::getUri();
}

void GetMixRequest::setMixId(int id)
{
	this->mixId = id;
}