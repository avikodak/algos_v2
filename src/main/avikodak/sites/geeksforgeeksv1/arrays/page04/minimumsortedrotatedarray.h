/****************************************************************************************************************************************************
 *  File Name                   : minimumsortedrotatedarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\minimumsortedrotatedarray.h
 *  Created on                  : Dec 22, 2014 :: 6:05:18 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
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

#ifndef MINIMUMSORTEDROTATEDARRAY_H_
#define MINIMUMSORTEDROTATEDARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int minInSortedRotateArray(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    if(endIndex - startIndex == 1) {
        return min(userInput[startIndex],userInput[endIndex]);
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] < userInput[middleIndex-1] && userInput[middleIndex] < userInput[middleIndex+1]) {
        return userInput[middleIndex];
    }
    if(userInput[middleIndex] < userInput[endIndex]) {
        return minInSortedRotateArray(userInput,startIndex,middleIndex-1);
    } else {
        return minInSortedRotateArray(userInput,middleIndex+1,endIndex);
    }
}

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int minInSortedRotateArray(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MAX;
    }
    int minVal = INT_MAX;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        minVal = min(minVal,userInput[counter]);
    }
    return minVal;
}

#endif /* MINIMUMSORTEDROTATEDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
