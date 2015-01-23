#include "APIManager.h"

using std::cout;
using namespace tracksAPI;

const string APIManager::apiKey = "0bb92442246e512ac341b2f1aa7b018e8ae5a413";

APIManager* APIManager::instance = NULL;

/*
 Singleton Method
*/
APIManager* APIManager::getInstance()
{
	if(APIManager::instance == NULL) 
	{
		APIManager::instance = new APIManager();
	}

	return APIManager::instance;
}

void APIManager::shutdown()
{
	delete APIManager::instance;
}

APIManager::APIManager()
{
	this->initCurl();
}

void APIManager::initCurl()
{
	this->apiHttp = curl_easy_init();
	assert(this->apiHttp);

	curl_easy_setopt(this->apiHttp, CURLOPT_VERBOSE, API_CURL_VERBOSE);
	curl_easy_setopt(this->apiHttp, CURLOPT_FOLLOWLOCATION, 1L);
	// callback to a write function that will write into the APIManager buffer
	curl_easy_setopt(this->apiHttp, CURLOPT_WRITEFUNCTION, &curlWriteData);
}

size_t APIManager::curlWriteData(char *buf, size_t size, size_t nmemb, void *stream)
 {
	for(int i = 0; i < size * nmemb; i++)
	{
		APIManager::getInstance()->curlBuffer.push_back(buf[i]);
	}

	return size * nmemb;
}

void APIManager::curlCleanup()
{
	this->cleanBuffer();
	curl_easy_cleanup(this->apiHttp);
}

APIManager::~APIManager()
{
	// cleanup is done at the end of every session
}

void APIManager::cleanBuffer()
{
	this->curlBuffer.clear();
}

BaseResponse* APIManager::sendRequest(BaseRequest* _req)
{
	this->initCurl();

	// prepare curl form data if we need to post
	struct curl_httppost* formpost = NULL;
	struct curl_httppost* lastptr = NULL;

	_req->getUri()->queries.emplace(std::pair<string, string>(API_VERSION_KEY, API_VERSION));
	_req->getUri()->queries.emplace(std::pair<string, string>(API_KEY, API_KEY_VALUE));

	curl_easy_setopt(this->apiHttp, CURLOPT_URL, _req->getUri()->toUrlStr().c_str());
	std::cout << _req->getUri()->toUrlStr() << std::endl;
	if(_req->getHttpMethod() == HTTP_OPERATION::POST)
	{
		// add curl post data
		map<string, string> postBody = _req->getBodyParameters();
		map<string, string>::iterator itt = postBody.begin();
		for(itt; itt != postBody.end(); itt++)
		{
			curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, itt->first.c_str(), CURLFORM_COPYCONTENTS, itt->second.c_str(), CURLFORM_END);
		}

		curl_easy_setopt(this->apiHttp, CURLOPT_HTTPPOST, formpost);
	}

	// perform the request
	curl_easy_perform(this->apiHttp);

	// create response with api
	BaseResponse* resp = ResponseFactory::createResponse(_req->getAction(), this->curlBuffer);
	if(resp == NULL) {
		throw API_UNKNOWN_RESPONSE;
	}
	
	// clean formpost if posted data
	if(_req->getHttpMethod() == HTTP_OPERATION::POST)
	{
		curl_formfree(formpost); // clean up form post
	}

	// cleanup curl
	this->curlCleanup();

	return resp;
}