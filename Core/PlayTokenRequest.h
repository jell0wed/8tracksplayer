#ifndef PLAYTOKENREQUEST_H
#define PLAYTOKENREQUEST_H

/**
 Request that allows us to create a new PlayToken from the
 8tracks API
*/

#include "URI.h"
#include "BaseRequest.h"

namespace tracksAPI
{
	class PlayTokenRequest : public BaseRequest
	{
	public:
		PlayTokenRequest();
		~PlayTokenRequest() { };
		URI* getUri();
	};
}

#endif