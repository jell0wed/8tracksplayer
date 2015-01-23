#include "BaseResponse.h"

using namespace tracksAPI;

BaseResponse::BaseResponse(string xmlContent, API_ACTIONS action) : XMLDecomposable(xmlContent)
{
	this->responseAction = action;
	this->logged_in = string(this->docRootNode->child("logged-in").text().as_string()) == string("true") ? true : false;
	this->status = this->extractStatus();
	this->errors = this->extractListOf("errors", "error");
	this->notices = this->extractListOf("notices", "notice");
}

BaseResponse::~BaseResponse()
{
	if(this->errors != NULL) { delete this->errors; }
	if(this->notices != NULL) { delete this->notices; }
}

API_STATUS_CODE BaseResponse::extractStatus()
{
	string httpCode = this->docRootNode->child("status").text().as_string();
	httpCode = httpCode.substr(0, 3);
	int iHttpCode = atoi(httpCode.c_str());

	return (API_STATUS_CODE)iHttpCode;
}

// extract a list of content from a xml structure 
// of commons error and notices from 8tracks api
vector<string>* BaseResponse::extractListOf(string collectionName, string entryName)
{
	vector<string>* result = NULL;
	xml_node collectionNode = this->docRootNode->child(collectionName.c_str());

	// if there's any entry in collection
	if(string(collectionNode.attribute("nil").as_string()) != "true")
	{
		result = new vector<string>();
		int i = 0;
		for(xml_node entry = collectionNode.child(entryName.c_str()); entry; entry = entry.next_sibling())
		{
			result->push_back(entry.text().as_string());
			i++;
		}

		if(i == 0) {
			if(collectionNode.text().as_string() != "") {
				result->push_back(collectionNode.text().as_string());
			}
		}
	} else {
		result = new vector<string>();
	}

	return result;
}

bool BaseResponse::hasError()
{
	return !this->errors->empty();
}

bool BaseResponse::hasNotices()
{
	return !this->notices->empty();
}

API_ACTIONS BaseResponse::getAction() const
{
	return this->responseAction;
}