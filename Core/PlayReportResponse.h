#ifndef PLAYREPORTRESPONSE_H
#define PLAYREPORTRESPONSE_H

/**
 Response to PlayReportRequest
*/

#include <string>
#include "API_Defines.h"
#include "BaseResponse.h"

using std::string;

namespace tracksAPI
{
	class PlayReportResponse : public BaseResponse
	{
	public:
		// build from xml content
		PlayReportResponse(string xmlContent);
		~PlayReportResponse();
		bool isSuccessful(); // is the request was successful
	};
}

#endif