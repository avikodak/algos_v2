/****************************************************************************************************************************************************
 *  File Name   		: quicksort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture06\quicksort.h
 *  Created on			: Dec 12, 2014 :: 2:24:15 PM
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

#ifndef QUICKSORTV3_H_
#define QUICKSORTV3_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int qsDivideStepQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    int key = userInput[pivotIndex];
    while(startIndex < endIndex) {
        while(userInput[startIndex] < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[endIndex],userInput[pivotIndex]);
    return endIndex;
}

//Tested
void qsQuicksort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = qsDivideStepQuickSort(userInput,startIndex,endIndex);
    qsQuicksort(userInput,startIndex,dividingIndex-1);
    qsQuicksort(userInput,dividingIndex+1,endIndex);
}

#endif /* QUICKSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
