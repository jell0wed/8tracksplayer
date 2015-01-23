#ifndef BASERESPONSE_H
#define BASERESPONSE_H

/**
 Class that represents a response used in every request
 in the program
*/

#include <vector>
#include <string>

#include "XMLDecomposable.h"
#include "API_Defines.h"

using std::vector;
using std::string;

namespace tracksAPI
{
	class BaseResponse : public XMLDecomposable
	{
	public:
		// always construct from xmlContent and AOPI_ACTIONS
		BaseResponse(string xmlContent, API_ACTIONS action);
		~BaseResponse();

		bool hasError();
		bool hasNotices();
		API_ACTIONS getAction() const;
	protected:
		// commons elements in every response in the program
		API_ACTIONS responseAction;
		API_STATUS_CODE status;
		vector<string>* errors;
		vector<string>* notices;
		bool logged_in;

		API_STATUS_CODE extractStatus();
		vector<string>* extractListOf(string, string);
	};
}

#endif