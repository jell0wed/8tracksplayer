#ifndef PLAYREPORTREQUEST_H
#define PLAYREPORTREQUEST_H

/**
 Class that allows us to report a specified track from a given
 mix to the 8tracks servers. (its mandatory to report after 30 sec of 
 listenning)
*/

#include <string>
#include <assert.h>

#include "API_Defines.h"
#include "BaseRequest.h"
#include "Mix.h"
#include "Track.h"

using std::string;

namespace tracksAPI
{
	class PlayReportRequest : public BaseRequest
	{
	public:
		PlayReportRequest();
		PlayReportRequest(string playToken);
		~PlayReportRequest();
		void setPlayingMix(Entities::Mix* currentMix);
		void setPlayingTrack(Entities::Track* currentTrack);
		void setPlayToken(string token);
		URI* getUri(); //poverload of getUri from baseReuqest
	private:
		Entities::Mix* playingMix;
		Entities::Track* playingTrack;
		string playToken;
	};
}

#endif