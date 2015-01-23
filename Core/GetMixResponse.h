#ifndef GETMIXRESPONSE_H
#define GETMIXRESPONSE_H

/**
 Response from GetMixRequest
*/

#include <string>
#include "API_Defines.h"
#include "BaseResponse.h"
#include "Mix.h"

using std::string;

namespace tracksAPI
{
	class GetMixResponse : public BaseResponse
	{
	public:
		// construt from xml content
		GetMixResponse(string xmlContent);
		~GetMixResponse(); // memory is managed outside the Response class
		Entities::Mix* getMix() const;
	private:
		Entities::Mix* currentMix;
	};
}

#endif