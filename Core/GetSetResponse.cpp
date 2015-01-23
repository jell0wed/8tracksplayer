#include "GetSetResponse.h"

using namespace tracksAPI;

GetSetResponse::GetSetResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::GET_SET)
{
	this->currentSet = new Entities::Set(&this->docRootNode->child("set"));
}

Entities::Set* GetSetResponse::getCurrentSet() const
{
	return this->currentSet;
}