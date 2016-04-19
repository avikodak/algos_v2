/****************************************************************************************************************************************************
 *  File Name   		: radixexchangesort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\radixexchangesort.h
 *  Created on			: Dec 11, 2014 :: 1:00:56 PM
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

#ifndef RADIXEXCHANGESORTV2_H_
#define RADIXEXCHANGESORTV2_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
int divideStepRadixExchangeSort(vector<int> &userInput,int startIndex,int endIndex,int bitPosition) {
    if(userInput.size() == 0 || bitPosition < 0) {
        return INT_MIN;
    }
    while(startIndex <= endIndex) {
        while(startIndex <= endIndex && !(userInput[startIndex] & 1 << bitPosition)) {
            startIndex++;
        }
        while(startIndex <= endIndex && userInput[endIndex] & 1 << bitPosition) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    return endIndex;
}

//Tested
void radixExchangeSortMainV2(vector<int> &userInput,int startIndex,int endIndex,int bitPosition) {
    if(startIndex >= endIndex || bitPosition < 0) {
        return;
    }
    int dividingIndex = divideStepRadixExchangeSort(userInput,startIndex,endIndex,bitPosition);
    radixExchangeSortMainV2(userInput,startIndex,dividingIndex,bitPosition-1);
    radixExchangeSortMainV2(userInput,dividingIndex+1,endIndex,bitPosition-1);
}

//Tested
void radixExchangeSortV2(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    int maxVal = *max_element(userInput.begin(),userInput.end());
    radixExchangeSortMainV2(userInput,0,userInput.size(),log2(maxVal));
}

#endif /* RADIXEXCHANGESORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
