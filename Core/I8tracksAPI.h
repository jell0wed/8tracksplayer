#ifndef I8TRACKSAPI_H
#define I8TRACKSAPI_H

/**
 Interface that is used to communicate with GUI that represents every
 method that can be used to communicate with the api
*/

#include <string>
#include <map>
#include <vector>

#include "API_Defines.h"
#include "APIManager.h"
#include "RequestFactory.h"
#include "User.h"
#include "Mix.h"
#include "Set.h"
#include "Tag.h"
#include "Pagination.h"

using std::string;
using std::map;
using std::pair;
using std::vector;

namespace tracksAPI
{
	class I8tracksAPI {
	public:
		virtual bool logInUser(string, string) = 0;
		virtual bool isLoggedIn() = 0;
		
		//virtual I8tracksAPI(); // virtual constructor
		virtual ~I8tracksAPI() { }; // virutal destructor

		// search mixes from tags
		virtual vector<Entities::Mix*>* searchMixes(vector<string> tags, Pagination* page = NULL, string sort = "", int pagenum = 0, int perpage = 0) = 0;
		// search mixes from terms
		virtual vector<Entities::Mix*>* searchMixes(string terms, Pagination* page = NULL, string sort = "", int pagenum = 0, int perpage = 0) = 0;
		// search mixes (no criteria)
		virtual vector<Entities::Mix*>* searchMixes(Pagination* page = NULL, string sort = "", int pagenum = 0, int perpage = 0) = 0;
		// create a new play token
		virtual string getNewPlayToken() = 0;
		// get a specific set
		virtual Entities::Set* getMixSet(Entities::Mix* mixPlay, string playToken, string action) = 0;
		// report a track from a set after 30 sec
		virtual bool reportSong(Entities::Mix* mixPlay, Entities::Track* trackPlay, string playToken) = 0;
		// get tags
		virtual vector<Entities::Tag*>* getTags() = 0;
		// get user
		virtual Entities::User* getLoggedInUser() = 0;
		/**
		 static method used to clean pointer of vector of pointers 
		 that is mostly used with given set of API elements (such as vector<Entities::Mix*>*)
		*/
		template<class T>
		static void cleanupVector(vector<T*>* vect)
		{
			if(vect != NULL)
			{
				// delete every element
				while(!vect->empty())
				{
					delete vect->back();
					vect->pop_back();
				}

				delete vect;
			}
		};
	};
}

#endif