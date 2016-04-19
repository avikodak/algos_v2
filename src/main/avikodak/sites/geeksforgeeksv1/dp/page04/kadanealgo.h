/****************************************************************************************************************************************************
 *  File Name   		: kadanealgo.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\kadanealgo.h
 *  Created on			: Dec 5, 2014 :: 12:33:35 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KADANEALGO_H_
#define KADANEALGO_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxContinousSubArraySumON(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int currentSum = 0,maxSum = INT_MIN;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        currentSum = max(userInput[counter]+currentSum,userInput[counter]);
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxContinousSubArraySumON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int currentSum = 0,maxSum = INT_MIN;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        currentSum = 0;
        for(unsigned int innerCounter = outerCounter; innerCounter < userInput.size(); innerCounter++) {
            currentSum += userInput[innerCounter];
            maxSum = max(maxSum,currentSum);
        }
    }
    return maxSum;
}

//Tested
int maxCrossOverSum(vector<int> userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    int leftSum = 0,rightSum = 0,sum = 0;
    for(int counter = middleIndex; counter >= startIndex; counter--) {
        sum += userInput[counter];
        leftSum = max(leftSum,sum);
    }
    sum = 0;
    for(int counter = middleIndex+1; counter <= endIndex; counter++) {
        sum += userInput[counter];
        rightSum = max(rightSum,sum);
    }
    return leftSum + rightSum;
}

//Tested
int maxContigousSubArrayDAC(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    int middleIndex = (startIndex + endIndex)/2;
    return max(maxContigousSubArrayDAC(userInput,startIndex,middleIndex),max(maxContigousSubArrayDAC(userInput,middleIndex+1,endIndex),maxCrossOverSum(userInput,startIndex,middleIndex,endIndex)));
}

#endif /* KADANEALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
