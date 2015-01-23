#include "MixSearchRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

// bae constructor
MixSearchRequest::MixSearchRequest() : BaseRequest(API_ACTIONS::MIX_SEARCH)
{
	this->init();
}

// Search from a specified search query term
MixSearchRequest::MixSearchRequest(string query) : BaseRequest(API_ACTIONS::MIX_SEARCH)
{
	this->init();

	this->query = query;
}

// base initialization
void MixSearchRequest::init()
{
	this->sort = MIX_SORT_HOT;
	this->requestPage = 1;
	this->perPage = MIX_SEARCH_PER_PAGE;

	this->httpOp = HTTP_OPERATION::GET;
}

// add tag to search
void MixSearchRequest::addTag(string tag)
{
	this->searchTags.push_back(tag);
}

void MixSearchRequest::setPage(int page)
{
	this->requestPage;
}

void MixSearchRequest::setSort(string sort)
{
	this->sort = sort;
}

void MixSearchRequest::setPerPage(int perPage)
{
	this->perPage = perPage;
}

void MixSearchRequest::setQuery(string q)
{
	this->query= q;
}

// getUri overload from baserequest
URI* MixSearchRequest::getUri()
{
	
	this->requestUri.path = MIX_SEARCH_REQUEST_PATH;
	// add tag(s) parameters
	if(!this->searchTags.empty())
	{
		if(this->searchTags.size() == 1)
		{
			this->requestUri.queries.emplace(pair<string, string>(MIX_SEARCH_REQUEST_TAG, this->searchTags[0]));
		}
		else
		{
			string completeSearch = "";
			vector<string>::iterator itt;
			for(itt = this->searchTags.begin(); itt != this->searchTags.end(); itt++)
			{
				completeSearch += *itt + "+";
			}
			completeSearch = completeSearch.substr(0, completeSearch.length() - 1);
			this->requestUri.queries.emplace(pair<string, string>(MIX_SEARCH_REQUEST_TAGS, completeSearch));
		}
	}

	// add search query parameters
	if(!this->query.empty())
	{
		//this->addBodyParam(MIX_SEARCH_REQUEST_Q, this->query);
		this->requestUri.queries.emplace(pair<string, string>(MIX_SEARCH_REQUEST_Q, this->query));
	}

	this->requestUri.queries.emplace(pair<string, string>(API_PAGE, boost::lexical_cast<string>(this->requestPage)));
	this->requestUri.queries.emplace(pair<string, string>(MIX_SEARCH_PER_AGE, boost::lexical_cast<string>(this->perPage)));
	this->requestUri.queries.emplace(pair<string, string>(MIX_SEARCH_REQUEST_SORT, this->sort));

	return BaseRequest::getUri();
}