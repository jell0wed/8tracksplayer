#include "URI.h"

using namespace tracksAPI;

string URI::TailSlice(std::string &subject, std::string delimiter, bool keep_delim=false) {
    // Chops off the delimiter and everything that follows (destructively)
    // returns everything after the delimiter
    auto delimiter_location = subject.find(delimiter);
    auto delimiter_length = delimiter.length();
    std::string output = "";

    if (delimiter_location < std::string::npos) {
        auto start = keep_delim ? delimiter_location : delimiter_location + delimiter_length;
        auto end = subject.length() - start;
        output = subject.substr(start, end);
        subject = subject.substr(0, delimiter_location);
    }
    return output;
}

string URI::HeadSlice(std::string &subject, std::string delimiter) {
    // Chops off the delimiter and everything that precedes (destructively)
    // returns everthing before the delimeter
    auto delimiter_location = subject.find(delimiter);
    auto delimiter_length = delimiter.length();
    std::string output = "";
    if (delimiter_location < std::string::npos) {
        output = subject.substr(0, delimiter_location);
        subject = subject.substr(delimiter_location + delimiter_length, subject.length() - (delimiter_location + delimiter_length));
    }
    return output;
}

URI::URI()
{
	this->port = 80;
	this->scheme = "http";
}

URI::URI(string _url)
{
	URI::URI();
	// capture the scheme
	this->scheme = URI::HeadSlice(_url, "://");
	// capture the host
	this->host = URI::HeadSlice(_url, ":");
	// port number found
	if(this->host != "") {
		this->port = atoi(URI::HeadSlice(_url, "/").c_str());
	}

	// if no :, try with /
	this->host = this->host == "" ? URI::HeadSlice(_url, "/") : this->host;
	// if / found, get the path
	if(this->host != "") {
		this->path = URI::HeadSlice(_url, "?");
		// ? token found, must have query strings
		if(this->path != "") {
			// parse queries if any
			if(_url != "") {
				vector<string> queries;
				boost::split(queries, _url, boost::is_any_of("&"));

				// for each queries
				vector<string>::iterator itt = queries.begin();
				while(itt != queries.end())
				{
					this->queries.emplace(std::pair<string, string>(URI::HeadSlice(*itt, "="), *itt));
					itt++;
				}

			}
		}
		// no ? token found, path is the rest of the string
		this->path = this->path == "" ? _url : this->path;
	}

	// if no /, host is the rest of the string
	this->host = this->host == "" ? _url : this->host;

}

string URI::toUrlStr()
{
	string output;
	output = this->scheme + "://";
	output += this->host;
	output += ":";
	output += boost::lexical_cast<string>(this->port);
	output += "/";
	output += this->path;
	
	if(this->queries.size() > 0)
	{
		output += "?";
		map<string, string>::iterator itt = this->queries.begin();
		for(itt; itt != this->queries.end(); itt++)
		{
			if(itt->first == "") {
				output += itt->second;
			} else {
				output += itt->first + "=" + itt->second;
			}
			output += "&";
		}

		output = output.substr(0, output.length() - 1);
	}

	return output;
}
