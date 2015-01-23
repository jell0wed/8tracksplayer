#ifndef RESPONSEFACTORY_H
#define RESPONSEFACTORY_H

#include <string>
#include "API_Defines.h"
#include "BaseResponse.h"
#include "LoginResponse.h"
#include "MixSearchResponse.h"
#include "PlayTokenResponse.h"
#include "GetSetResponse.h"
#include "PlayReportResponse.h"
#include "GetTagsResponse.h"
#include "GetMixResponse.h"

using std::string;

namespace tracksAPI
{
	class ResponseFactory {
	public:
		static BaseResponse* createResponse(API_ACTIONS _action, string respContent);
	};
}

#endif