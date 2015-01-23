#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

/**
 Request that logs in a specific user with a username/password
 combination into the system
*/

#include <string>
#include "API_Defines.h"
#include "URI.h"
#include "BaseRequest.h"

using std::string;

namespace tracksAPI
{
	class LoginRequest : public BaseRequest
	{
	public:
		LoginRequest(string _username, string _password);
		void setUsername(string username);
		void setPassword(string password);
		URI* getUri(); //overload baseRequest getUri() method
	private:
		string username;
		string password;
	};
}

#endif