#include "8TracksAPI.h"

/**
 Main API implementation class that uses request and response
 to communicate with the API
*/

using namespace tracksAPI;

eightTracksAPI::eightTracksAPI()
{
	this->loggedInUser = NULL;
	APIManager::getInstance(); // make sure we initialized the APIManager
}

eightTracksAPI::~eightTracksAPI()
{
	// make sure we delete the user if its logged in
	if(this->loggedInUser != NULL) { delete this->loggedInUser; }
	// make sure we shutdown the api manager
	APIManager::shutdown();
}

bool eightTracksAPI::logInUser(string username, string password)
{
	map<API_REQUESTS_PARAMS, string> loginParams;
	loginParams.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::USERNAME, username));
	loginParams.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::PASSWORD, password));

	// create a login request
	LoginRequest* loginReq = (LoginRequest*)RequestFactory::createRequest(API_ACTIONS::LOGIN, loginParams);
	LoginResponse* loginResp = (LoginResponse*)APIManager::getInstance()->sendRequest(loginReq);

	// analyze the response
	if(!loginResp->isSuccessful())
	{
		delete loginReq; // delete both the request and the response
		delete loginResp;
		return false; // unable to login user
	}

	// set the logged in user
	this->loggedInUser = loginResp->getUser();

	// now delete the resquest and the response
	delete loginReq;
	delete loginResp;

	return true;
}

bool eightTracksAPI::isLoggedIn()
{
	return this->loggedInUser != NULL;
}

vector<Entities::Mix*>* eightTracksAPI::searchMixes(vector<string> tags, Pagination* page, string sort, int pagenum, int perpage)
{
	vector<Entities::Mix*>* resultMixes;

	MixSearchRequest* searchReq = (MixSearchRequest*)RequestFactory::createRequest(API_ACTIONS::MIX_SEARCH, map<API_REQUESTS_PARAMS, string>());
	vector<string>::iterator itt;
	for(itt = tags.begin(); itt != tags.end(); itt++)
	{
		searchReq->addTag(*itt);
	}

	// add optional stuff
	if(sort != "") { searchReq->setSort(sort); }
	if(pagenum != 0) { searchReq->setPage(pagenum); }
	if(perpage != 0) { searchReq->setPerPage(perpage); }

	MixSearchResponse* searchResp = (MixSearchResponse*)APIManager::getInstance()->sendRequest(searchReq);
	
	assert(!searchResp->hasError());

	resultMixes = searchResp->getMixes();

	// handle pagination
	if(page != NULL) {
		*page = Pagination(searchResp->getPaginationDetails());
	}

	// delete request and response
	delete searchReq;
	delete searchResp;

	return resultMixes;
}

vector<Entities::Mix*>* eightTracksAPI::searchMixes(string terms, Pagination* page, string sort, int pagenum, int perpage)
{
	vector<Entities::Mix*>* resultMixes;

	map<API_REQUESTS_PARAMS, string> searchParams;
	searchParams.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::QUERY_STRING, terms));

	MixSearchRequest* searchReq = (MixSearchRequest*)RequestFactory::createRequest(API_ACTIONS::MIX_SEARCH, searchParams);

	// add optional stuff
	if(terms != "") { searchReq->setQuery(terms); }
	if(sort != "") { searchReq->setSort(sort); }
	if(pagenum != 0) { searchReq->setPage(pagenum); }
	if(perpage != 0) { searchReq->setPerPage(perpage); }

	MixSearchResponse* searchResp = (MixSearchResponse*)APIManager::getInstance()->sendRequest(searchReq);
	
	assert(!searchResp->hasError());

	resultMixes = searchResp->getMixes();

	// handle pagination
	if(page != NULL) {
		*page = Pagination(searchResp->getPaginationDetails());
	}

	// delete request and response
	delete searchReq;
	delete searchResp;

	return resultMixes;
}

vector<Entities::Mix*>* eightTracksAPI::searchMixes(Pagination* page, string sort, int pagenum, int perpage)
{
	vector<Entities::Mix*>* resultMixes;

	map<API_REQUESTS_PARAMS, string> searchParams;

	MixSearchRequest* searchReq = (MixSearchRequest*)RequestFactory::createRequest(API_ACTIONS::MIX_SEARCH, searchParams);

	// add optional stuff
	if(sort != "") { searchReq->setSort(sort); }
	if(pagenum != 0) { searchReq->setPage(pagenum); }
	if(perpage != 0) { searchReq->setPerPage(perpage); }

	MixSearchResponse* searchResp = (MixSearchResponse*)APIManager::getInstance()->sendRequest(searchReq);
	
	assert(!searchResp->hasError());

	resultMixes = searchResp->getMixes();

	// handle pagination
	if(page != NULL) {
		*page = Pagination(searchResp->getPaginationDetails());
	}

	// delete req and resp
	delete searchReq;
	delete searchResp;

	return resultMixes;
}

string eightTracksAPI::getNewPlayToken()
{
	string playToken = "";
	// create request
	PlayTokenRequest* playTokenReq = (PlayTokenRequest*)RequestFactory::createRequest(API_ACTIONS::PLAY_TOKEN, map<API_REQUESTS_PARAMS, string>());
	PlayTokenResponse* playTokenResp = (PlayTokenResponse*)APIManager::getInstance()->sendRequest(playTokenReq);

	assert(!playTokenResp->hasError());
	playToken = playTokenResp->getPlayToken();

	// delete request and response
	delete playTokenReq;
	delete playTokenResp;

	return playToken;
}

Entities::Set* eightTracksAPI::getMixSet(Entities::Mix* mixPlay, string playToken, string action)
{
	Entities::Set* resultSet = NULL;
	// create request
	map<API_REQUESTS_PARAMS, string> params;
	params.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::PLAYTOKEN, playToken));
	params.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::SET_ACTION, action));

	GetSetRequest* setReq = (GetSetRequest*)RequestFactory::createRequest(API_ACTIONS::GET_SET, params);
	setReq->setToPlayMix(mixPlay); // set the mix to get set for

	GetSetResponse* setResp = (GetSetResponse*)APIManager::getInstance()->sendRequest(setReq);

	assert(!setResp->hasError());
	resultSet = setResp->getCurrentSet();

	// delete request and response
	delete setReq;
	delete setResp;

	return resultSet;
}

bool eightTracksAPI::reportSong(Entities::Mix* mixPlay, Entities::Track* trackPlay, string playToken)
{
	bool result = false;
	// create request
	map<API_REQUESTS_PARAMS, string> params;
	params.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::PLAYTOKEN, playToken));

	PlayReportRequest* playReq = (PlayReportRequest*)RequestFactory::createRequest(API_ACTIONS::PLAY_REPORT, params);
	playReq->setPlayingMix(mixPlay); // set currently playing mix
	playReq->setPlayingTrack(trackPlay); // set currentply playing track

	PlayReportResponse* playResp = (PlayReportResponse*)APIManager::getInstance()->sendRequest(playReq);

	assert(!playResp->hasError());

	result = playResp->isSuccessful();

	// delete request and response
	delete playReq;
	delete playResp;

	return result;
}

vector<Entities::Tag*>* eightTracksAPI::getTags()
{
	vector<Entities::Tag*>* resultTags;
	// create request
	GetTagsRequest* tagsReq = (GetTagsRequest*)RequestFactory::createRequest(API_ACTIONS::GET_TAGS, map<API_REQUESTS_PARAMS, string>());
	GetTagsResponse* tagsResp = (GetTagsResponse*)APIManager::getInstance()->sendRequest(tagsReq);

	assert(!tagsResp->hasError());

	resultTags = tagsResp->getTags();

	// delete request and response
	delete tagsReq;
	delete tagsResp;

	return resultTags;
}

Entities::Mix* eightTracksAPI::getMix(int mixId)
{
	Entities::Mix* resultMix;

	// create parameter
	map<API_REQUESTS_PARAMS, string> params;
	params.emplace(pair<API_REQUESTS_PARAMS, string>(API_REQUESTS_PARAMS::MIX_ID, boost::lexical_cast<string>(mixId)));

	// create request
	GetMixRequest* mixReq = (GetMixRequest*)RequestFactory::createRequest(API_ACTIONS::GET_MIX, params);
	GetMixResponse* mixResp = (GetMixResponse*)APIManager::getInstance()->sendRequest(mixReq);

	assert(!mixResp->hasError());

	resultMix = mixResp->getMix();

	// delete request and response
	delete mixReq;
	delete mixResp;

	return resultMix;
}

Entities::User* eightTracksAPI::getLoggedInUser()
{
	if(this->isLoggedIn())
	{
		return this->loggedInUser;
	}
	
	return NULL;
}