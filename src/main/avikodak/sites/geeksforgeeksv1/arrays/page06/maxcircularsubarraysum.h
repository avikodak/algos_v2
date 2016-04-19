/****************************************************************************************************************************************************
 *  File Name                   : maxcircularsubarraysum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\maxcircularsubarraysum.h
 *  Created on                  : Jan 3, 2015 :: 10:59:43 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
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

#ifndef MAXCIRCULARSUBARRAYSUM_H_
#define MAXCIRCULARSUBARRAYSUM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int kadanesAlgo(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int currentSum = 0,maxSum = INT_MIN;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        currentSum = max(userInput[counter],currentSum+userInput[counter]);
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

//Tested
int maxCircularSubArraySum(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int maxContigousSum = kadanesAlgo(userInput);
    int sumOfArray = 0;
    for(unsigned int counter  = 0; counter < userInput.size(); counter++) {
        sumOfArray += userInput[counter];
        userInput[counter] *= -1;
    }
    int maxCircularSum = sumOfArray + kadanesAlgo(userInput);
    return max(maxCircularSum,maxContigousSum);
}

#endif /* MAXCIRCULARSUBARRAYSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
