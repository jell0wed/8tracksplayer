#include "PlayReportRequest.h"
#include <boost/lexical_cast.hpp>

using namespace tracksAPI;

// construct from play token
PlayReportRequest::PlayReportRequest(string playToken) : BaseRequest(API_ACTIONS::PLAY_REPORT)
{
	this->playingMix = NULL;
	this->playingTrack = NULL;
	this->playToken = playToken;
}

PlayReportRequest::PlayReportRequest() : BaseRequest(API_ACTIONS::PLAY_REPORT)
{

}

PlayReportRequest::~PlayReportRequest()
{

}

void PlayReportRequest::setPlayingMix(Entities::Mix* currentMix)
{
	this->playingMix = currentMix;
}

void PlayReportRequest::setPlayingTrack(Entities::Track* currentTrack)
{
	this->playingTrack = currentTrack;
}

void PlayReportRequest::setPlayToken(string token)
{
	this->playToken = token;
}

URI* PlayReportRequest::getUri()
{
	assert(this->playingMix != NULL);
	assert(this->playingTrack != NULL);

	this->requestUri.path = GET_SET_REQUEST_PATH;
	this->requestUri.path += this->playToken; // sets the play token
	this->requestUri.path += GET_SET_ACTION_REPORT; 
	// sets the mix id and track id
	this->requestUri.queries.emplace(std::pair<string, string>("mix_id", boost::lexical_cast<string>(this->playingMix->getId())));
	this->requestUri.queries.emplace(std::pair<string, string>("track_id", boost::lexical_cast<string>(this->playingTrack->getId())));

	return BaseRequest::getUri();
}