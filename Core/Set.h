#ifndef SET_H
#define SET_H

/**
 Class that represents a given set that can be player
 throughout the program.
*/


#include "API_Defines.h"
#include "XMLDecomposable.h"
#include "Track.h"

namespace tracksAPI { namespace Entities {
	class Set : public XMLDecomposable
	{
	public:
		Set(xml_node* node);
		~Set();
		bool isAtBeginning() const;
		bool isAtEnd() const;
		bool isSkipAllowed() const;
		bool isAtLastTrack() const;
		Entities::Track* getCurrentTrack() const;
	private:
		Entities::Track* currentTrack;
		bool at_beginning;
		bool at_end;
		bool skip_allowed;
		bool at_last_track;
	};
} }

#endif