#ifndef GETSETREQUEST_H
#define GETSETREQUEST_H

/**
 Request that allows us to get a specific set from a speicified Mix
*/

#include <string>

#include "BaseRequest.h"
#include "Mix.h"
#include "URI.h"

using std::string;

namespace tracksAPI
{
	class GetSetRequest : public BaseRequest
	{
	public:
		GetSetRequest(string playToken, string action);
		~GetSetRequest() {};  // memory is managed outside the request
		URI* getUri();
		void setToPlayMix(Entities::Mix* currentMix);
		Entities::Mix* getToPlayMix() const;
	private:
		Entities::Mix* currentMix;
		string playToken;
		string actionPath; // play, next, skip
	};
}

#endif