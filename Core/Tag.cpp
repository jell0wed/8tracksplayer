#include "Tag.h"
#include <boost/algorithm/string.hpp>

using namespace tracksAPI::Entities;

/*
 Parse tags details from a specific xml node
*/
Tag::Tag(xml_node* node) : XMLDecomposable(node)
{
	this->name = this->docRootNode->child("name").text().as_string();
	this->count = this->docRootNode->child("cool-taggings-count").text().as_int();
}

/*
Optional constructor that allows us to create a specific
tag without a xml node
*/
Tag::Tag(string name) : XMLDecomposable()
{
	this->name = name;
	this->count = 0;
}

string Tag::getName() const
{
	return this->name;
}

int Tag::getCount() const
{
	return this->count;
}

/**
 Parse every tags from a given string by a specific delimiter
 tag1, tag2, tag3
*/
vector<Tag>* Tag::collectionFromString(string str)
{
	vector<string> strResp;
	boost::split(strResp, str, boost::is_any_of(","));

	vector<Tag>* result = new vector<Tag>();
	vector<string>::iterator itt = strResp.begin();

	for(itt; itt < strResp.end(); itt ++)
	{
		if(*itt != "") {
			result->push_back(Tag(*itt));
		}
	}

	return result;
}