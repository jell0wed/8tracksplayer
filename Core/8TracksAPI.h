#ifndef TRACKSAPI_H
#define TRACKSAPI_H

#include <string>
#include <map>
#include <vector>

#include "I8tracksAPI.h"

using std::vector;

namespace tracksAPI
{
	class eightTracksAPI : public I8tracksAPI {
	public:
		eightTracksAPI();
		~eightTracksAPI();

		bool logInUser(string username, string password);
		bool isLoggedIn();

		// search mixes from tags
		vector<Entities::Mix*>* searchMixes(vector<string> tags, Pagination* page = NULL,string sort = "", int pagenum = 0, int perpage = 0);
		// search mixes from terms
		vector<Entities::Mix*>* searchMixes(string terms, Pagination* page = NULL, string sort = "", int pagenum = 0, int perpage = 0);
		// search mixes (no criteria)
		vector<Entities::Mix*>* searchMixes(Pagination* page = NULL, string sort = "", int pagenum = 0, int perpage = 0);
		// get single mix
		Entities::Mix* getMix(int mixId);
		// create a new play token
		string getNewPlayToken();
		// get a set from a specified mix
		Entities::Set* getMixSet(Entities::Mix* mixPlay, string playToken, string action);
		// report song for playing
		bool reportSong(Entities::Mix* mixPlay, Entities::Track* trackPlay, string playToken);
		// get tags
		vector<Entities::Tag*>* getTags();
		// get logged in user
		Entities::User* getLoggedInUser();
	private:
		Entities::User* loggedInUser;
		string loggedInUserToken;
	};
}

#endif