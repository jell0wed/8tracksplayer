#include "Mix.h"

using namespace tracksAPI::Entities;

/**
 Parse every details from xml
*/
Mix::Mix(xml_node* node) : XMLDecomposable(node)
{
	// parse mix details from xml
	this->id = this->docRootNode->child("id").text().as_int();
	this->name = this->docRootNode->child("name").text().as_string();
	this->published = string(this->docRootNode->child("published").text().as_string()) == string("true") ? true : false;
	this->description = this->docRootNode->child("description").text().as_string();
	this->playCount = this->docRootNode->child("plays-count").text().as_int();
	this->likesCount = this->docRootNode->child("likes-count").text().as_int();
	this->slug = this->docRootNode->child("slug").text().as_string();
	this->path = this->docRootNode->child("path").text().as_string();
	this->covers = XMLDecomposable::parseImageCollection(&this->docRootNode->child("cover-urls"));
	this->restUrl = this->docRootNode->child("restful-url").text().as_string();
	this->tags = Entities::Tag::collectionFromString(this->docRootNode->child("tag-list-cache").text().as_string());
	this->nsfw = this->docRootNode->child("nsfw").text().as_string() == "true" ? true : false;
	this->duration = this->docRootNode->child("duration").text().as_int();
	// get the user
	this->postedBy = new User(&this->docRootNode->child("user"));
}

Mix::~Mix()
{
	delete this->postedBy;
	// delete every covers
	delete this->covers;
	// delete every tags
	delete this->tags;
}

int Mix::getId() const
{
	return this->id;
}

string Mix::getName() const 
{
	return this->name;
}

bool Mix::isPublished() const
{
	return this->published;
}

string Mix::getDescription() const
{
	return this->description;
}

int Mix::getPlayCount() const
{
	return this->playCount;
}

int Mix::getLikesCount() const
{
	return this->likesCount;
}

string Mix::getSlug() const
{
	return this->slug;
}

string Mix::getPath() const
{
	return this->path;
}

vector<Tag>* Mix::getTags() const
{
	return this->tags;
}

User* Mix::getUser() const
{
	return this->postedBy;
}

bool Mix::isNsfw() const
{
	return this->nsfw;
}

int Mix::getDuration() const
{
	return this->duration;
}

/*
 Getters for covers
*/
map<AVATAR_TYPES, string>* Mix::getCovers() const
{
	return this->covers;
}