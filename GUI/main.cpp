#include <iostream>
#include <stdio.h>
#include "../Core/APIManager.h"
#include "../Core/MixSearchRequest.h"
#include "../Core/MixSearchResponse.h"

#include "../Core/PlayTokenRequest.h"
#include "../Core/PlayTokenResponse.h"

#include "../Core/GetSetRequest.h"
#include "../Core/GetSetResponse.h"

using namespace std;
using namespace tracksAPI;

int main()
{
	/*LoginRequest req("s", "q7w8r9t0");
	LoginResponse* test = (LoginResponse*)APIManager::getInstance()->sendRequest(&req);
	*/

	MixSearchRequest req("metalica");
	req.setSort(MIX_SORT_RECENT);

	MixSearchResponse* test = (MixSearchResponse*)APIManager::getInstance()->sendRequest(&req);
	
	PlayTokenRequest req2(test->getMixes()->at(0)->getId());
	PlayTokenResponse* test2 = (PlayTokenResponse*)APIManager::getInstance()->sendRequest(&req2);

	GetSetRequest test3(*test->getMixes()->at(0), test2->getPlayToken());
	GetSetResponse* resp = (GetSetResponse*)APIManager::getInstance()->sendRequest(&test3);

	system("pause");
	return 0;
}