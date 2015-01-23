#ifndef MIX_H
#define MIX_H

/*
 Class that represents a given mix throughout the program
*/

#include <string>
#include <map>
#include <vector>
#include "API_Defines.h"
#include "XMLDecomposable.h"
#include "User.h"
#include "Tag.h"

using std::map;
using std::vector;
using std::pair;
using std::string;
using namespace pugi;

namespace tracksAPI { namespace Entities {
	class Mix : public XMLDecomposable
	{
	public:
		Mix(xml_node* node);
		~Mix();
		// getters
		int getId() const;
		string getName() const;
		bool isPublished() const;
		string getDescription() const;
		int getPlayCount() const;
		int getLikesCount() const;
		string getSlug() const;
		string getPath() const;
		vector<Tag>* getTags() const;
		User* getUser() const;
		bool isNsfw() const;
		int getDuration() const;
		map<AVATAR_TYPES, string>* getCovers() const;
	private:
		int id;
		string name;
		bool published;
		string description;
		int playCount;
		int likesCount;
		string slug;
		string path;
		map<AVATAR_TYPES, string>* covers;
		string restUrl;
		vector<Entities::Tag>* tags;
		User* postedBy;
		bool nsfw;
		int duration;
	};
} }

#endif