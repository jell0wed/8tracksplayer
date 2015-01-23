#ifndef GETSETRESPONSE_H
#define GETSETRESPONSE_H

/**
 Response from GetSetRequest
*/

#include <string>
#include "Track.h"
#include "BaseResponse.h"
#include "Set.h"

using std::string;

namespace tracksAPI
{
	class GetSetResponse : public BaseResponse
	{
	public:
		// construct from xml content
		GetSetResponse(string xmlContent);
		~GetSetResponse() {  }; // memory leaks arent managed directly inside the responses classes
		Entities::Set* getCurrentSet() const;
	private:
		Entities::Set* currentSet;
	};
}

#endif