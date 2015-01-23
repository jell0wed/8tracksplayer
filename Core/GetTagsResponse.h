#ifndef GETTAGSRESPONSE_H
#define GETTAGSRESPONSE_H

/**
 Response to GetTagsRequest from the 8tracks API
*/

#include <string>
#include <vector>
#include "BaseResponse.h"
#include "Tag.h"
#include "Pagination.h"

using std::string;
using std::vector;

namespace tracksAPI
{
	class GetTagsResponse : public BaseResponse
	{
	public:
		// construct from xml
		GetTagsResponse(string xmlContent);
		~GetTagsResponse(); // memory is managed outside the response class
		vector<Entities::Tag*>* getTags() const;
		Pagination getPagination() const;
	private:
		vector<Entities::Tag*>* tags;
	};
}

#endif