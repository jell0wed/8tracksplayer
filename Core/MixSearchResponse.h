#ifndef MIXSEARCHRESPONSE_H
#define MIXSEARCHRESPONSE_H

/**
 Response to MixSearchRequest
*/

#include <string>
#include <vector>
#include "Mix.h"
#include "BaseResponse.h"
#include "Pagination.h"

using std::vector;
using std::string;

namespace tracksAPI
{
	class MixSearchResponse : public BaseResponse {
	public:
		// construct from xml string
		MixSearchResponse(string);
		~MixSearchResponse(); // memory is managed outside the response class
		vector<Entities::Mix*>* getMixes() const;
		Pagination getPaginationDetails() const; // get the pagination details form the request that has been made
	private:
		vector<Entities::Mix*>* mixes;
	};
}

#endif