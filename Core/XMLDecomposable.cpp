#include "XMLDecomposable.h"

using namespace tracksAPI;

XMLDecomposable::XMLDecomposable(string xmlContent)
{
	this->fromPart = false;
	this->xmlDoc = new xml_document();
	// +1 to the length because of the null ended string char (\0)
	xml_parse_result result = this->xmlDoc->load_buffer(xmlContent.c_str(), xmlContent.length() + 1);
	if(!result)
	{
		delete this->xmlDoc;
		throw API_ERROR_XML_PARSE;
	}

	// deep copy xml_node object so its not a temporary given by pugi xml on xmlDoc->first_child()
	this->docRootNode = new xml_node(this->xmlDoc->first_child());
}

XMLDecomposable::XMLDecomposable(xml_node* node)
{
	this->fromPart = true;
	this->xmlDoc = NULL;
	this->docRootNode = node;
	// no need to delete the node, it will be deleted by the referenced 
	// xml decomposable
}

XMLDecomposable::~XMLDecomposable()
{
	if(!this->fromPart) { delete this->docRootNode; }
	if(this->xmlDoc != NULL) { delete this->xmlDoc; }
}

map<AVATAR_TYPES, string>* XMLDecomposable::parseImageCollection(xml_node* imagesNode)
{
	map<AVATAR_TYPES, string>* result = new map<AVATAR_TYPES, string>();
	map<string, AVATAR_TYPES> strToType;
	strToType.emplace(pair<string, AVATAR_TYPES>("sq56", AVATAR_TYPES::SQUARE_56));
	strToType.emplace(pair<string, AVATAR_TYPES>("sq72", AVATAR_TYPES::SQUARE_72));
	strToType.emplace(pair<string, AVATAR_TYPES>("sq100", AVATAR_TYPES::SQUARE_100));
	strToType.emplace(pair<string, AVATAR_TYPES>("sq133", AVATAR_TYPES::SQUARE_133));
	strToType.emplace(pair<string, AVATAR_TYPES>("max200", AVATAR_TYPES::MAX_200));
	strToType.emplace(pair<string, AVATAR_TYPES>("max133w", AVATAR_TYPES::MAX_133W));
	strToType.emplace(pair<string, AVATAR_TYPES>("original", AVATAR_TYPES::ORIGINAL));

	for(pugi::xml_node_iterator it = imagesNode->begin(); it != imagesNode->end(); it++)
	{
		// find the avatar type corresponding to the node tag value
		string tagName = it->name();
		// if the type was found
		if(strToType.find(tagName) != strToType.end())
		{
			AVATAR_TYPES type = strToType.find(tagName)->second;
			result->emplace(pair<AVATAR_TYPES, string>(type, it->text().as_string()));
		}
	}

	return result;
}