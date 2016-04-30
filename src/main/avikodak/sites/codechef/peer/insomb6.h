/****************************************************************************************************************************************************
 *  File Name                   : insomb6.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/insomb6.h
 *  Created on                  : Apr 28, 2016 :: 12:24:06 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/INSOMB6
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_INSOMB6_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_INSOMB6_H_

void solveProblem() {
    unsigned int noOfdignitaries, noOfPreference;
    string userInput;
    vector<string> dignataries;
    map<string, unsigned int> carCountMap;
    map<string, unsigned int>::iterator itToCarCountMap;
    vector<vector<string> > usersPreferences;
    scanf("%u", &noOfdignitaries);
    for (unsigned int counter = 0; counter < noOfdignitaries; counter++) {
        for (unsigned int dignitaryCounter = 0; dignitaryCounter < noOfdignitaries; dignitaryCounter++) {
            cin >> userInput;
            dignataries.push_back(userInput);
        }
        for (unsigned int carCounter = 0; carCounter < noOfdignitaries; carCounter++) {
            cin >> userInput;
            itToCarCountMap = carCountMap.find(userInput);
            if (itToCarCountMap == carCountMap.end()) {
                carCountMap.insert(pair<string, unsigned int>(userInput, 1));
            } else {
                carCountMap.insert(pair<string, unsigned int>(userInput, itToCarCountMap->second + 1));
            }
        }
        for (unsigned int userCounter = 0; userCounter < noOfdignitaries; userCounter++) {
            scanf("%u", &noOfPreference);
            vector<string> individualPreference;
            for (unsigned int preferenceCounter = 0; preferenceCounter < noOfPreference; preferenceCounter++) {
                cin >> userInput;
                individualPreference.push_back(userInput);
            }
            usersPreferences.push_back(individualPreference);
        }
    }
    //Perform Logic
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_INSOMB6_H_ */
