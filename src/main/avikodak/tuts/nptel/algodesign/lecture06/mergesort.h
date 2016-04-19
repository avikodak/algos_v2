/****************************************************************************************************************************************************
 *  File Name   		: mergesort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture06\mergesort.h
 *  Created on			: Dec 12, 2014 :: 2:09:53 PM
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

#ifndef MERGESORTV2_H_
#define MERGESORTV2_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void msMerge(vector<int> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex > endIndex) {
        return;
    }
    vector<int> auxSpace;
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        }
    }
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        userInput[startIndex + counter] = auxSpace[counter];
    }
}

void msMergeSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    msMergeSort(userInput,startIndex,middleIndex);
    msMergeSort(userInput,middleIndex+1,endIndex);
    msMerge(userInput,startIndex,middleIndex,endIndex);
}

void msMergeSortV2(vector<int> &userInput,int startIndex,int endIndex);

void msMergeV2(vector<int> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex && secondCrawler <= endIndex) {
        if(userInput[firstCrawler] > userInput[secondCrawler]) {
            swap(userInput[firstCrawler],userInput[secondCrawler]);
        }
        firstCrawler++;
    }
    msMergeSortV2(userInput,middleIndex,endIndex);
}

void msMergeSortV2(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    msMergeSortV2(userInput,startIndex,middleIndex);
    msMergeSortV2(userInput,middleIndex+1,endIndex);
    msMergeV2(userInput,startIndex,middleIndex,endIndex);
}

#endif /* MERGESORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
