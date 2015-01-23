#ifndef XMLDECOMPOSABLE_H
#define XMLDECOMPOSABLE_H

#include <string>
#include <map>

#include "API_Defines.h"
#include "pugixml/pugixml.hpp"

using std::string;
using std::map;
using std::pair;
using namespace pugi;

namespace tracksAPI
{
	class XMLDecomposable
	{
	public:
		XMLDecomposable() { this->xmlDoc = NULL; }; // default constructor
		XMLDecomposable(string); // constructor from brand new xml
		XMLDecomposable(xml_node* node); // constructor from a specific node
		virtual ~XMLDecomposable();
	protected:
		xml_document* xmlDoc;
		xml_node* docRootNode;
		bool fromPart;

		static map<AVATAR_TYPES, string>* parseImageCollection(xml_node* imagesNode);
	};
}

#endif