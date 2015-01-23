#ifndef URI_H
#define URI_H

#include <string>
#include <map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using std::map;
using std::vector;
using std::pair;
using std::string;

namespace tracksAPI
{
	class URI
	{
	public:
		URI();
		URI(string);
		~URI() {  }
		string toUrlStr();

		string scheme;
		string host;
		int port;
		string path;
		map<string, string> queries;
	private:
		static inline string TailSlice(string&, string, bool);
		static inline string HeadSlice(string&, string);
	};
}

#endif