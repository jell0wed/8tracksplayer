#ifndef TRACK_H
#define TRACK_H

/**
 Class that represents a track tack can be play throughout a set
 in the program
*/

#include <string>
#include "XMLDecomposable.h"

using std::string;

namespace tracksAPI { namespace Entities {
	class Track : public XMLDecomposable
	{
	public:
		Track(xml_node* node);
		~Track() { };
		string getReleaseName() const;
		int getYear() const;
		string getName() const;
		int getDuration() const;
		string getPerformer() const;
		int getId() const;
		string getStreamUrl() const;
	private:
		string releaseName; //album
		int year;
		string name;
		int duration;
		string performer;
		int id;
		string url;
	};
} }

#endif