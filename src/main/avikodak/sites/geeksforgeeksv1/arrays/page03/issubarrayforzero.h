/****************************************************************************************************************************************************
 *  File Name                   : issubarrayforzero.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\issubarrayforzero.h
 *  Created on                  : Dec 22, 2014 :: 8:39:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ISSUBARRAYFORZERO_H_
#define ISSUBARRAYFORZERO_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Should do more research
//Tested
bool isThereSubarrayForZeroON(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    hash_map<int,bool> visitedFlags;
    hash_map<int,bool>::iterator itToVisitedFlags;
    int currentSum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        currentSum += userInput[counter];
        if(currentSum == 0 || visitedFlags.find(currentSum) != visitedFlags.end()) {
            return true;
        }
        visitedFlags[currentSum] = true;
    }
    return false;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isThereSubarrayForZeroON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    int currentSum = 0;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        currentSum = 0;
        for(unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            currentSum += userInput[innerCrawler];
            if(currentSum == 0) {
                return true;
            }
        }
    }
    return false;
}
#endif /* ISSUBARRAYFORZERO_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
