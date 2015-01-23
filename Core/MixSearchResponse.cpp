#include "MixSearchResponse.h"

using namespace tracksAPI;

MixSearchResponse::MixSearchResponse(string respContent) : BaseResponse(respContent, API_ACTIONS::MIX_SEARCH)
{
	this->mixes = new vector<Entities::Mix*>();
	
	// loop for every mixes
	xml_node mixes = this->docRootNode->child("mixes");
	for(xml_node mix = mixes.child("mix"); mix; mix = mix.next_sibling("mix"))
	{
		this->mixes->push_back(new Entities::Mix(&mix));
	}
}

MixSearchResponse::~MixSearchResponse()
{
	// response arent managed by themselves!
}

vector<Entities::Mix*>* MixSearchResponse::getMixes() const
{
	return this->mixes;
}

// get the pagination details from the request that has been made
Pagination MixSearchResponse::getPaginationDetails() const
{
	Pagination page;

	// get pagination details
	page.setCurrentPage(this->docRootNode->child("page").text().as_int());
	page.setPreviousPage(this->docRootNode->child("previous-page").text().as_int());
	page.setNextPage(this->docRootNode->child("next-page").text().as_int());
	page.setPerPage(this->docRootNode->child("per-page").text().as_int());
	page.setTotalPages(this->docRootNode->child("total-pages").text().as_int());
	page.setTotalEntries(this->docRootNode->child("total-entries").text().as_int());

	return page;
}