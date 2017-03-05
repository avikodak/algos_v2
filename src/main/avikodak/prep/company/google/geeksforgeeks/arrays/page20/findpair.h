/****************************************************************************************************************************************************
 *  File Name                   : findpair.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/arrays/page20/findpair.h
 *  Created on                  : Mar 3, 2017 :: 1:31:55 AM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE20_FINDPAIR_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE20_FINDPAIR_H_

void findPair(vector<int> userInput, int sum) {
    sort(userInput.begin(), userInput.end());
    int frontCrawler = 0, rearCrawler = userInput.size() - 1;
    int currentSum;
    while (frontCrawler < rearCrawler) {
        currentSum = userInput[frontCrawler] + userInput[rearCrawler];
        if (currentSum == sum) {
            printf("%d %d\t", frontCrawler[userInput], rearCrawler[userInput]);
            return;
        } else if (currentSum < sum) {
            frontCrawler++;
        } else {
            rearCrawler--;
        }
    }
}

void findPairON(vector<int> userInput, int sum) {
    hash_map<int, bool> seenMap;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        if (seenMap.find(sum - userInput[counter]) != seenMap.end()) {
            return;
        }
        seenMap.insert(pair<int, bool>(userInput[counter], true));
    }
}

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE20_FINDPAIR_H_ */
