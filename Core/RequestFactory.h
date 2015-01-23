#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

/**
 factory used to create request from specified actions and parameters
*/

#include <map>
#include <string>
#include <assert.h>

#include "API_Defines.h"
#include "BaseRequest.h"
#include "LoginRequest.h"
#include "MixSearchRequest.h"
#include "PlayTokenRequest.h"
#include "GetSetRequest.h"
#include "PlayReportRequest.h"
#include "GetTagsRequest.h"
#include "GetMixRequest.h"

using std::map;
using std::string;
using std::pair;

namespace tracksAPI
{
	class RequestFactory
	{
	public:
		static BaseRequest* createRequest(API_ACTIONS action, map<API_REQUESTS_PARAMS, string> params);
	};
}

#endif