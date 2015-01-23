#include "PlayTokenResponse.h"

using namespace tracksAPI;

PlayTokenResponse::PlayTokenResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::PLAY_TOKEN)
{
	this->playToken = this->docRootNode->child("play-token").text().as_string();
}

string PlayTokenResponse::getPlayToken()
{
	return this->playToken;
}
