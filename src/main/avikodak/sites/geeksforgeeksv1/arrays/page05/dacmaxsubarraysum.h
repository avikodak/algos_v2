/****************************************************************************************************************************************************
 *  File Name                   : dacmaxsubarraysum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\dacmaxsubarraysum.h
 *  Created on                  : Dec 25, 2014 :: 12:20:17 PM
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

#ifndef DACMAXSUBARRAYSUM_H_
#define DACMAXSUBARRAYSUM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int maxCrossOverSum(vector<int> userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int leftSum = INT_MIN,sum = 0,rightSum = INT_MIN;
    for(int counter = middleIndex; counter >= startIndex; counter--) {
        sum += userInput[counter];
        leftSum = max(leftSum,sum);
    }
    for(int counter = middleIndex+1; counter <= endIndex; counter++) {
        sum += userInput[counter];
        rightSum = max(rightSum,sum);
    }
    return leftSum + rightSum;
}

int dacMaxSubArraySum(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    int middleIndex = (startIndex + endIndex)/2;
    return max(dacMaxSubArraySum(userInput,startIndex,middleIndex),max(dacMaxSubArraySum(userInput,middleIndex+1,endIndex),maxCrossOverSum(userInput,startIndex,middleIndex,endIndex)));
}

#endif /* DACMAXSUBARRAYSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
