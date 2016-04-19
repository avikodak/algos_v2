/****************************************************************************************************************************************************
 *  File Name                   : straightradixsortz.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\straightradixsortz.h
 *  Created on                  : Dec 2, 2014 :: 11:56:51 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/
#ifndef STRAIGHTRADIXSORTZ_H_
#define STRAIGHTRADIXSORTZ_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/

void reorganizeNumbersForDigitPosition(vector<int> &userInput,int digitPosition) {
    map<int,queue<int> > buckets;
    map<int,queue<int> >::iterator itToBuckets;
    int digit;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        digit = (userInput[counter]/pow(10,digitPosition))%10;
        if((itToBuckets = buckets.find(digit)) != buckets.end()) {
            itToBuckets->second.push(userInput[counter]);
        } else {
            queue<int> digitBucket;
            digitBucket.push(userInput[counter]);
            buckets.insert(pair<int,queue<int> >(digit,digitBucket));
        }

    }
    int fillCounter = -1;
    for(itToBuckets = buckets.begin(); itToBuckets != buckets.end(); itToBuckets++) {
        while(!itToBuckets->second.empty()) {
            userInput[++fillCounter] = itToBuckets->second.front();
            itToBuckets->second.pop();
        }
    }
}

void straightRadixSortWholeNumbers(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int totalDigits = log(max_element(userInput.begin(),userInput.end())) + 1;
    for(unsigned int counter = 0; counter < totalDigits; counter++) {
        reorganizeNumbersForDigitPosition(userInput,counter);
    }
}

#endif /* STRAIGHTRADIXSORTZ_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/

