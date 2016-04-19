/****************************************************************************************************************************************************
 *  File Name   		: peakelement.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\peakelement.h
 *  Created on			: Jan 18, 2015 :: 6:00:53 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
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

#ifndef PEAKELEMENT_H_
#define PEAKELEMENT_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
//Tested
int findPeakElementBinarySearch(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    if(endIndex - startIndex == 1) {
        return max(userInput[startIndex],userInput[endIndex]);
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] > userInput[middleIndex+1]) {
        return userInput[middleIndex];
    }
    if(userInput[middleIndex-1] > userInput[middleIndex]) {
        return findPeakElementBinarySearch(userInput,startIndex,middleIndex-1);
    } else {
        return findPeakElementBinarySearch(userInput,middleIndex+1,endIndex);
    }
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int findPeakElementON(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    if(userInput.size() == 1) {
        return userInput[0];
    }
    if(userInput[0] > userInput[1]) {
        return userInput[0];
    }
    if(userInput[userInput.size()-1] > userInput[userInput.size()-2]) {
        return userInput[userInput.size()-1];
    }
    for(unsigned int counter = 1; counter < userInput.size()-1; counter++) {
        if(userInput[counter] > userInput[counter-1] && userInput[counter] > userInput[counter+1]) {
            return userInput[counter];
        }
    }
    return INT_MIN;
}

#endif /* PEAKELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
