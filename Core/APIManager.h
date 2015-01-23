#define	NULL	0

#ifndef APIMANAGER_H
#define APIMANAGER_H

/**
 Class used to communicate directly with the api throughout 
 HTTP using Libcurl

 This class is a singleton
*/

#include <iostream>
#include <assert.h>
#include <curl/curl.h>
#include <string>
#include <map>
#include <exception>

#include "API_Defines.h"
#include "RequestFactory.h"
#include "ResponseFactory.h"
#include "BaseRequest.h"
#include "BaseResponse.h"

using std::map;
using std::pair;
using std::string;
using std::exception;

namespace tracksAPI
{
	class APIManager
	{
	public:
		static APIManager* getInstance(); // singleton
		static void shutdown(); //singleton
		APIManager();
		~APIManager();
		// send a request and retrieve the response
		BaseResponse* sendRequest(BaseRequest*); 
	private:
		static const string apiKey;
		static APIManager* instance;
		CURL* apiHttp;
		string curlBuffer;

		void initCurl();
		void curlCleanup();
		void cleanBuffer();
		static size_t curlWriteData(char*, size_t, size_t, void*); // callback function for curl to write data
	};
}

#endif