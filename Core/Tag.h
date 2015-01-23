#ifndef TAG_H
#define TAG_H

/**
 Class that represents a Tag throughout the program
*/

#include <vector>
#include <string>
#include "XMLDecomposable.h"
using std::string;
using std::vector;

namespace tracksAPI { namespace Entities {

	class Tag : public XMLDecomposable
	{
	public:
		static vector<Tag>* collectionFromString(string str);
		Tag(xml_node* node);
		Tag(string name);
		~Tag() {  }
		string getName() const;
		int getCount() const;
	private:
		string name;
		int count;
	};
	
} }

#endif