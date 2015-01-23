#ifndef API_DEFINES_H
#define API_DEFINES_H

/**
 Majors API defines
*/

#define	API_CURL_VERBOSE	1L
#define API_VERSION_KEY		"api_version"
#define	API_VERSION			"2" // make sure we're using version 2 of api

#define API_KEY	"api_key"
#define API_KEY_VALUE "0bb92442246e512ac341b2f1aa7b018e8ae5a413"

#define API_URL_HOST	"8tracks.com"
#define API_URL_SCHEME	"http"
#define API_PAGE		"page"

#define LOGIN_REQUEST_PATH		"sessions.xml"
#define	LOGIN_REQUEST_USERNAME	"login"
#define LOGIN_REQUEST_PASSWORD	"password"

#define MIX_SEARCH_REQUEST_PATH	"mixes.xml"
#define MIX_SEARCH_REQUEST_Q	"q"
#define MIX_SEARCH_REQUEST_TAG	"tag"
#define MIX_SEARCH_REQUEST_TAGS "tags"
#define MIX_SEARCH_REQUEST_SORT	"sort"
#define MIX_SEARCH_PER_AGE		"per_page"

#define PLAY_TOKEN_REQUEST_PATH	"sets/new.xml"

#define GET_SET_REQUEST_PATH  "sets/"
#define GET_SET_ACTION_PLAY	"/play.xml"
#define GET_SET_ACTION_NEXT	"/next.xml"
#define GET_SET_ACTION_SKIP	"/skip.xml"

#define GET_SET_ACTION_REPORT "/report.xml"

#define MIX_SORT_RECENT		"recent"
#define MIX_SORT_POPULAR	"popular"
#define MIX_SORT_HOT		"hot"

#define GET_TAGS_REQUEST_PATH	"tags.xml"

#define GET_MIX_REQUEST_PATH "mixes/"

#define API_ERROR_XML_PARSE	1
#define API_UNKNOWN_RESPONSE 2

enum API_STATUS_CODE
{
	OK_200 = 200,
	MOVED_PARMANENTLY_301 = 301,
	MOVED_302 = 302,
	UNAUTHORIZED_401 = 401,
	FORBIDDEN_403 = 403,
	NOT_FOUND_404 = 404,
	INTERNAL_ERROR_500 = 500
};

enum API_ACTIONS
{
	LOGIN,
	MIX_SEARCH,
	PLAY_TOKEN,
	GET_SET,
	PLAY_REPORT,
	GET_TAGS,
	GET_MIX
};

enum API_REQUESTS_PARAMS
{
	USERNAME,
	PASSWORD,
	SORT,
	PAGENUM, 
	PER_PAGE,
	QUERY_STRING,
	TAGS,
	SET_ACTION,
	PLAYTOKEN,
	MIX_ID
};

#define MIX_SEARCH_PER_PAGE	20


// entities settings

enum USER_PREFERENCES
{
	POPUP_PREF,
	NEXT_MIX_PREF
};

enum AVATAR_TYPES
{
	SQUARE_56,
	SQUARE_72,
	SQUARE_100,
	SQUARE_133,
	MAX_200,
	MAX_133W,
	ORIGINAL
};

#endif