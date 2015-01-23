#ifndef MIXSEARCHREQUEST_H
#define MIXSEARCHREQUEST_H

/**
 Request that allows us to search the Mix database from specifics
 parameters such as terms, directly via a sort ora
 tags
*/

#include <string>
#include <vector>
#include <map>
#include "API_Defines.h"
#include "URI.h"
#include "BaseRequest.h"

using std::map;
using std::pair;
using std::string;
using std::vector;

namespace tracksAPI
{
	class MixSearchRequest : public BaseRequest {
	public:
		MixSearchRequest();
		~MixSearchRequest() {};
		MixSearchRequest(string sort, int pageNum, int perPage);
		MixSearchRequest(string query);
		void addTag(string tag);
		URI* getUri();
		void setPage(int page);
		void setSort(string sort);
		void setPerPage(int perPage);
		void setQuery(string q);
	private:
		string sort;
		int requestPage;
		int perPage;
		string query;
		vector<string> searchTags;

		void init();
	};
}

#endif