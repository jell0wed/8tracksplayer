#ifndef BASEREQUEST_H
#define BASEREQUEST_H

/**
 Class that represents an unknown Request
 Used to describe every request in the program
*/

#include <map>
#include <string>
#include "API_Defines.h"
#include "URI.h"
#include "Http_Enums.h"

using std::string;
using std::pair;
using std::map;

namespace tracksAPI
{
	class BaseRequest
	{
	public:
		BaseRequest(API_ACTIONS action); // init from API_ATCIONS
		virtual URI* getUri(); //getUri of the request
		HTTP_OPERATION getHttpMethod() const;
		map<string, string> getBodyParameters() const;
		void addBodyParam(string, string); // add parameters to the body of the request (mostly when HTTP POST)
		API_ACTIONS getAction() const;
	protected:
		API_ACTIONS requestAction;
		URI requestUri;
		HTTP_OPERATION httpOp;
		map<string, string> bodyParameters;
	};
}

#endif