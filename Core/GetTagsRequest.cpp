#include "GetTagsRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

// get the brand new fresh tags
GetTagsRequest::GetTagsRequest() : BaseRequest(API_ACTIONS::GET_TAGS)
{
	this->query = "";
	this->page = 1;
}

// search for a specific tag
GetTagsRequest::GetTagsRequest(string q) : BaseRequest(API_ACTIONS::GET_TAGS)
{
	this->setQuery(q);
	this->page = 1;
}

GetTagsRequest::~GetTagsRequest()
{
	// memory is managed outside the request
}

void GetTagsRequest::setQuery(string q)
{
	this->query = q;
}

void GetTagsRequest::setPage(int p)
{
	this->page = p;
}

//overload from BaseRequest method
URI* GetTagsRequest::getUri()
{
	this->httpOp = HTTP_OPERATION::GET;
	this->requestUri.path = GET_TAGS_REQUEST_PATH;
	
	if(this->query != "")
	{
		this->requestUri.queries.emplace(std::pair<string, string>("q", this->query));
	}

	this->requestUri.queries.emplace(std::pair<string, string>("page", boost::lexical_cast<string>(this->page)));

	return BaseRequest::getUri();
}
