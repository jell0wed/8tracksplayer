#include "Track.h"

using namespace tracksAPI::Entities;

// parse xml details
Track::Track(xml_node* node) : XMLDecomposable(node)
{
	// parse xml attributes
	this->releaseName = this->docRootNode->child("release-name").text().as_string();
	this->year = this->docRootNode->child("year").text().as_int();
	this->name = this->docRootNode->child("name").text().as_string();
	this->duration = this->docRootNode->child("play-duration").text().as_int();
	this->performer = this->docRootNode->child("performer").text().as_string();
	this->id = this->docRootNode->child("id").text().as_int();
	this->url = this->docRootNode->child("url").text().as_string(); //a stream url
}

string Track::getReleaseName() const
{
	return this->releaseName;
}

int Track::getYear() const
{
	return this->year;
}

string Track::getName() const
{
	return this->name;
}

int Track::getDuration() const
{
	return this->duration;
}

string Track::getPerformer() const
{
	return this->performer;
}

int Track::getId() const
{
	return this->id;
}

string Track::getStreamUrl() const
{
	return this->url;
}