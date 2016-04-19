/****************************************************************************************************************************************************
 *  File Name                   : topfox.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\topfox.h
 *  Created on                  : Apr 29, 2015 :: 7:23:52 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=12643
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TOPFOX_H_
#define TOPFOX_H_

class TopFox {
public:
    int possibleHandles(string familyName,string givenName) {
        set<string> handles;
        vector<string> familyNameSubs,givenNameSubs;
        for(unsigned int counter = 0; counter < familyName.size(); counter++) {
            familyNameSubs.push_back(familyName.substr(0,counter+1));
        }
        for(unsigned int counter = 0; counter < givenName.size(); counter++) {
            givenNameSubs.push_back(givenName.substr(0,counter+1));
        }
        for(unsigned int outerCounter = 0; outerCounter < familyNameSubs.size(); outerCounter++) {
            for(unsigned int innerCounter = 0; innerCounter < givenNameSubs.size(); innerCounter++) {
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
