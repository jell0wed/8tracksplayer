#include "Set.h"

using namespace tracksAPI::Entities;

//
// Parse details from a specific XML Node
// 
Set::Set(xml_node* node) : XMLDecomposable(node)
{
	this->currentTrack = NULL;
	this->currentTrack = new Entities::Track(&this->docRootNode->child("track"));

	this->at_beginning = string(this->docRootNode->child("at-beginning").text().as_string()) == "true" ? true : false;
	this->at_end = string(this->docRootNode->child("at-end").text().as_string()) == "true" ? true : false;
	this->skip_allowed = string(this->docRootNode->child("skip-allowed").text().as_string()) == "true" ? true : false;
	this->at_last_track = string(this->docRootNode->child("at-last-track").text().as_string()) == "true" ? true : false;
}

// delete the attached current track
Set::~Set()
{
	// delete the current track
	if(this->currentTrack != NULL)
	{
		delete this->currentTrack;
	}
}

bool Set::isAtBeginning() const
{
	return this->at_beginning;
}

bool Set::isAtEnd() const
{
	return this->at_end;
}

bool Set::isSkipAllowed() const
{
	return this->skip_allowed;
}

bool Set::isAtLastTrack() const
{
	return this->at_last_track;
}

Track* Set::getCurrentTrack() const
{
	return this->currentTrack;
}