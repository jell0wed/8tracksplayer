#include "GetTagsResponse.h"

using namespace tracksAPI;

GetTagsResponse::GetTagsResponse(string xmlContent) : BaseResponse(xmlContent, API_ACTIONS::GET_TAGS)
{
	this->tags = new vector<Entities::Tag*>();
	
	xml_node tagsList = this->docRootNode->child("tags");
	for(xml_node tag = tagsList.child("tag"); tag; tag = tag.next_sibling("tag"))
	{
		this->tags->push_back(new Entities::Tag(&tag));
	}
}

GetTagsResponse::~GetTagsResponse()
{
	// tags entities arent managed within this classes, 
	// it must be deleted after using it in the api class
}

vector<Entities::Tag*>* GetTagsResponse::getTags() const
{
	return this->tags;
}

Pagination GetTagsResponse::getPagination() const
{
	Pagination page;
	// parse xml content
	page.setNextPage(this->docRootNode->child("next-page").text().as_int());
	page.setPreviousPage(this->docRootNode->child("previous-page").text().as_int());

	return page;
}