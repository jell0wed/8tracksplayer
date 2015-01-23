#include "RequestFactory.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

BaseRequest* RequestFactory::createRequest(API_ACTIONS action, map<API_REQUESTS_PARAMS, string> params)
{
	BaseRequest* resultRequest = NULL;
	switch(action)
	{
	case API_ACTIONS::LOGIN:
		assert(params.find(API_REQUESTS_PARAMS::USERNAME) != params.end());
		assert(params.find(API_REQUESTS_PARAMS::PASSWORD) != params.end());
		// build a new request with the username / password param//////
		resultRequest = new LoginRequest(params.find(API_REQUESTS_PARAMS::USERNAME)->second,
										 params.find(API_REQUESTS_PARAMS::PASSWORD)->second);

		break;
	case API_ACTIONS::MIX_SEARCH:
		resultRequest = new MixSearchRequest();
		
		break;
	case API_ACTIONS::PLAY_TOKEN:
		resultRequest = new PlayTokenRequest();
		break;
	case API_ACTIONS::GET_SET:
		assert(params.find(API_REQUESTS_PARAMS::SET_ACTION) != params.end());
		assert(params.find(API_REQUESTS_PARAMS::PLAYTOKEN) != params.end());

		// build a new get set request
		resultRequest = new GetSetRequest(params.find(API_REQUESTS_PARAMS::PLAYTOKEN)->second,
										  params.find(API_REQUESTS_PARAMS::SET_ACTION)->second);
		break;
	case API_ACTIONS::PLAY_REPORT:
		assert(params.find(API_REQUESTS_PARAMS::PLAYTOKEN) != params.end());
		
		// build a new play report request
		resultRequest = new PlayReportRequest(params.find(API_REQUESTS_PARAMS::PLAYTOKEN)->second);
		break;
	case API_ACTIONS::GET_TAGS:
		{
			GetTagsRequest* tagReq = new GetTagsRequest();
			if(params.find(API_REQUESTS_PARAMS::QUERY_STRING) != params.end())
			{
				tagReq->setQuery(params.find(API_REQUESTS_PARAMS::QUERY_STRING)->second);
			}

			if(params.find(API_REQUESTS_PARAMS::PAGENUM) != params.end())
			{
				tagReq->setQuery(params.find(API_REQUESTS_PARAMS::PAGENUM)->second);
			}

			resultRequest = tagReq;
			break;
		}
	case API_ACTIONS::GET_MIX:
		assert(params.find(API_REQUESTS_PARAMS::MIX_ID) != params.end());

		resultRequest = new GetMixRequest(boost::lexical_cast<int>(params.find(API_REQUESTS_PARAMS::MIX_ID)->second));
		break;
	}

	return resultRequest;
}