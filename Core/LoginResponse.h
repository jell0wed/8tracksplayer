#ifndef LOGINRESPONSE_H
#define LOGINRESPONSE_H

/*
 Response to LoginRequest from the 8tracks API
*/
/**
 Careful! The response doesnt delete the Entities::User*, make sure you clean
 up the entities manually by the API
*/

#include <string>
#include "User.h"
#include "BaseResponse.h"

using std::string;

namespace tracksAPI
{
	class LoginResponse : public BaseResponse
	{
	public:
		// construct from xml content
		LoginResponse(string);
		~LoginResponse(); // memory is managed outside the response class
		bool isSuccessful();
		string getUserToken();
		Entities::User* getUser();
	private:
		bool successful;
		string user_token;
		Entities::User* loggedInUser;
	};
}

#endif
