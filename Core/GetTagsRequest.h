#ifndef GETTAGSREQUEST_H
#define GETTAGSREQUEST_H

/**
 Request that queries tags from server
*/

#include <string>
#include "API_Defines.h"
#include "URI.h"
#include "BaseRequest.h"

using std::string;

namespace tracksAPI
{
	class GetTagsRequest : public BaseRequest
	{
	public:
		GetTagsRequest();
		GetTagsRequest(string q);
		void setQuery(string q);
		void setPage(int p);
		~GetTagsRequest();
		URI* getUri(); // overload baserequest getUri method
	private:
		string query;
		int page;
	};
}

#endif