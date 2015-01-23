#include "ResponseFactory.h"

using namespace tracksAPI;

BaseResponse* ResponseFactory::createResponse(API_ACTIONS _action, string respContent)
{
	BaseResponse* resp = NULL;
	
	switch(_action) {
		case API_ACTIONS::LOGIN:
			resp = new LoginResponse(respContent);
			break;

		case API_ACTIONS::MIX_SEARCH:
			resp = new MixSearchResponse(respContent);
			break;

		case API_ACTIONS::PLAY_TOKEN:
			resp = new PlayTokenResponse(respContent);
			break;

		case API_ACTIONS::GET_SET:
			resp = new GetSetResponse(respContent);
			break;
		case API_ACTIONS::PLAY_REPORT:
			resp = new PlayReportResponse(respContent);
			break;
		case API_ACTIONS::GET_TAGS:
			resp = new GetTagsResponse(respContent);
			break;
		case API_ACTIONS::GET_MIX:
			resp = new GetMixResponse(respContent);
			break;
	}

	return resp;
}