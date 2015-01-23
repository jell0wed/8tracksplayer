#ifndef GETMIXREQUEST_H
#define GETMIXREQUEST_H

/*
 Request that allows us to get details for a Single mix
 with a specific mix id
*/

#include <string>

#include "API_Defines.h"
#include "BaseRequest.h"
#include "URI.h"

using std::string;

namespace tracksAPI
{
	class GetMixRequest : public BaseRequest
	{
	public:
		GetMixRequest(int mixId = 0);
		~GetMixRequest();
		URI* getUri(); //overload from baserquest
		void setMixId(int id);
	private:
		int mixId;
	};
}

#endif