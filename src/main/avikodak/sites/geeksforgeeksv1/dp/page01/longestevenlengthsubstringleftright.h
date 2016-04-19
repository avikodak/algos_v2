/****************************************************************************************************************************************************
 *  File Name   		: longestevenlengthsubstringleftright.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\longestevenlengthsubstringleftright.h
 *  Created on			: Jan 13, 2015 :: 9:06:42 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_
#define LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestEvenLengthSubStringLeftRightSum(vector<int> userInput) {
    if(userInput.size() == 0 || userInput.size()%2 != 0) {
        return 0;
    }
    int currentSubstringLength,leftSum,rightSum;
    int maxLength = INT_MIN;
    for(int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        for(int middleCounter = outerCounter+1; middleCounter < userInput.size(); middleCounter++) {
            currentSubstringLength = middleCounter - outerCounter + 1;
            leftSum = 0;
            rightSum = 0;
            for(int innerCounter = 0; innerCounter < currentSubstringLength/2; innerCounter++) {
                leftSum += userInput[outerCounter + innerCounter];
                rightSum += userInput[outerCounter + currentSubstringLength/2 + innerCounter];
            }
            if(leftSum == rightSum) {
                maxLength = max(maxLength,middleCounter - outerCounter + 1);
            }
        }
    }
    return maxLength;
}

#endif /* LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
