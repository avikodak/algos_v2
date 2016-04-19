/****************************************************************************************************************************************************
 *  File Name                   : freecash.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\freecash.h
 *  Created on                  : Apr 8, 2015 :: 12:39:40 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/237/A
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

#ifndef FREECASH_H_
#define FREECASH_H_

//Tested
void getFreeCashCountersRequired() {
    unsigned int testCases,hour,minute;
    scanf("%u",&testCases);
    map<unsigned int,map<unsigned int,unsigned int> > timeCountersMap;
    map<unsigned int,map<unsigned int,unsigned int> >::iterator itToTimeCountersMap;
    map<unsigned int,unsigned int> existingMinuteMap;
    map<unsigned int,unsigned int>::iterator itToExistingMinuteMap;
    unsigned int maxFreeCash = 0;
    while(testCases--) {
        scanf("%u %u",&hour,&minute);
        if((itToTimeCountersMap = timeCountersMap.find(hour)) != timeCountersMap.end()) {
            existingMinuteMap = itToTimeCountersMap->second;
            if((itToExistingMinuteMap = existingMinuteMap.find(minute)) != existingMinuteMap.end()) {
                timeCountersMap[hour][minute] = itToExistingMinuteMap->second+1;
                maxFreeCash = max(maxFreeCash,itToExistingMinuteMap->second+1);
            } else {
                timeCountersMap[hour][minute] = 1;
                maxFreeCash = max(maxFreeCash,1U);
            }
        } else {
            timeCountersMap[hour][minute] = 1;
            maxFreeCash = max(maxFreeCash,1U);
        }
    }
    printf("%u",maxFreeCash);
}
#endif /* FREECASH_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
