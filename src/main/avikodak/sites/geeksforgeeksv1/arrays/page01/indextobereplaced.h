/****************************************************************************************************************************************************
 *  File Name   		: indextobereplaced.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\indextobereplaced.h
 *  Created on			: Jan 21, 2015 :: 5:28:40 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-index-0-replaced-1-get-longest-continuous-sequence-1s-binary-array/
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

#ifndef INDEXTOBEREPLACED_H_
#define INDEXTOBEREPLACED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getZeroIndexToBeReplaced(vector<int> userInput) {
    if(userInput.size() < 2) {
        return userInput.size() == 0?0:userInput[0] == 0?1:0;
    }
    int prevZeroIndex = -1,prevToPrevZeroIndex = -1,maxOneSubArray = INT_MIN,zeroIndex = -1;
    for(int counter = 0; counter < (int)userInput.size(); counter++) {
        if(userInput[counter] == 0) {
            if(prevToPrevZeroIndex != -1) {
                if(counter - prevToPrevZeroIndex > maxOneSubArray) {
                    maxOneSubArray = counter - prevToPrevZeroIndex;
                    zeroIndex = prevZeroIndex;
                }
            }
            prevToPrevZeroIndex = prevZeroIndex;
            prevZeroIndex = counter;
        }
    }
    if(prevToPrevZeroIndex == -1) {
        zeroIndex = userInput.size()-1;
    } else {
        if((int)userInput.size() - prevToPrevZeroIndex > maxOneSubArray) {
            maxOneSubArray = userInput.size() - prevToPrevZeroIndex;
            zeroIndex = prevZeroIndex;
        }
    }
    return zeroIndex;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getZeroIndexToBeReplacedON2(vector<int> userInput) {
    if(userInput.size() < 2) {
        return userInput.size() == 0?0:userInput[0] == 0?1:0;
    }
    unsigned int maxOneSubArray = 0;
    int zeroIndex = -1;
    unsigned int innerCounter,oneFrequency;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        if(userInput[outerCounter] == 0) {
            innerCounter = outerCounter-1;
            oneFrequency = 0;
            while(innerCounter >= 0 && userInput[innerCounter--] == 1) {
                oneFrequency += 1;
            }
            innerCounter = outerCounter + 1;
            while(innerCounter < userInput.size() && userInput[innerCounter++] == 1) {
                oneFrequency += 1;
            }
            if(maxOneSubArray < oneFrequency) {
                maxOneSubArray = oneFrequency;
                zeroIndex = outerCounter;
            }
        }
    }
    return zeroIndex;
}

#endif /* INDEXTOBEREPLACED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
