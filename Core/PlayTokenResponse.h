#ifndef PLAYTOKENRESPONSE_H
#define PLAYTOKENRESPONSE_H

/**
 Response to playtokenRequest
*/

#include <string>
#include "BaseResponse.h"

using std::string;

namespace tracksAPI
{
	class PlayTokenResponse : public BaseResponse
	{
	public:
		// build from xmlcontent
		PlayTokenResponse(string);
		~PlayTokenResponse() { };
		string getPlayToken(); // get the play token
	private:
		string playToken;
	};
}

#endif