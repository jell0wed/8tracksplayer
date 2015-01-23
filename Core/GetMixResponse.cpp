#include "GetMixResponse.h"

using namespace tracksAPI;

// construct from xml content
GetMixResponse::GetMixResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::GET_MIX)
{
	// parse mix
	this->currentMix = new Entities::Mix(&this->docRootNode->child("mix"));
}

GetMixResponse::~GetMixResponse()
{
	// pointers are managed outside this class
}

Entities::Mix* GetMixResponse::getMix() const
{
	return this->currentMix;
}