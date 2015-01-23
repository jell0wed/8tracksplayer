#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <vector>
#include <assert.h>

#include "URI.h"
#include "API_Defines.h"
#include "XMLDecomposable.h"

using std::string;
using std::map;
using std::pair;
using namespace pugi;

namespace tracksAPI { namespace Entities {
	class User : XMLDecomposable
	{
	public:
		User(xml_node*);
		~User();
		int getId() const;
		string getSlug() const;
		string getLogin() const;
		string getLocation() const;
		string getBio() const;
		map<AVATAR_TYPES, string>* getAvatars() const;
	private:
		int id;
		string slug;
		string login;
		string location;
		string bio_html;
		map<AVATAR_TYPES, string>* avatars;
	};
} }

#endif