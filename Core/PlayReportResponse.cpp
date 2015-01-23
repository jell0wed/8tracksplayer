#include "PlayReportResponse.h"

using namespace tracksAPI;

PlayReportResponse::PlayReportResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::PLAY_REPORT)
{
	
}

PlayReportResponse::~PlayReportResponse()
{

}

bool PlayReportResponse::isSuccessful()
{
	return this->status == API_STATUS_CODE::OK_200;
}