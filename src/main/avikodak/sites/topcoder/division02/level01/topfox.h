/****************************************************************************************************************************************************
 *  File Name                   : topfox.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\topfox.h
 *  Created on                  : Apr 29, 2015 :: 7:23:52 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TOPFOX_H_
#define TOPFOX_H_

class TopFox{
public:
	int possibleHandles(string familyName,string givenName){
		set<string> handles;
		vector<string> familyNameSubs,givenNameSubs;
		for(unsigned int counter = 0;counter < familyName.size();counter++){
			familyNameSubs.push_back(familyName.substr(0,counter+1));
		}
		for(unsigned int counter = 0;counter < givenName.size();counter++){
			givenNameSubs.push_back(givenName.substr(0,counter+1));
		}
		for(unsigned int outerCounter = 0;outerCounter < familyNameSubs.size();outerCounter++){
			for(unsigned int innerCounter = 0;innerCounter < givenNameSubs.size();innerCounter++){
				string result;
				result.append(familyNameSubs[outerCounter].begin(),familyNameSubs[outerCounter].end());
				result.append(givenNameSubs[innerCounter].begin(),givenNameSubs[innerCounter].end());
				handles.insert(result);
			}
		}
		return (int)handles.size();
	}
};

#endif /* TOPFOX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
