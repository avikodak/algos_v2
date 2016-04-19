/****************************************************************************************************************************************************
 *  File Name   		: mergeoverlappinginterval.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\mergeoverlappinginterval.h
 *  Created on			: Dec 22, 2014 :: 8:22:37 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/merging-intervals/
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

#ifndef MERGEOVERLAPPINGINTERVAL_H_
#define MERGEOVERLAPPINGINTERVAL_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int divideStepQuickSortIntervals(vector<iInterval *> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    int key = userInput[pivotIndex]->start;
    while(startIndex < endIndex) {
        while(userInput[startIndex]->start < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex]->start >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[pivotIndex],userInput[endIndex]);
    return endIndex;
}

//Tested
void quickSortIntervals(vector<iInterval *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = divideStepQuickSortIntervals(userInput,startIndex,endIndex);
    quickSortIntervals(userInput,startIndex,dividingIndex-1);
    quickSortIntervals(userInput,dividingIndex+1,endIndex);
}

//Tested
void mergeStepInterval(vector<iInterval *> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    vector<iInterval *> auxSpace;
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler]->start < userInput[secondCrawler]->start) {
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

//Tested
void mergeSortInterval(vector<iInterval *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    mergeSortInterval(userInput,startIndex,middleIndex);
    mergeSortInterval(userInput,middleIndex+1,endIndex);
    mergeStepInterval(userInput,startIndex,middleIndex,endIndex);
}

//Tested
vector<iInterval *> mergeOverLappingInterval(vector<iInterval *> userInput) {
    vector<iInterval *> mergedIntervals;
    if(userInput.size() == 0) {
        return mergedIntervals;
    }
    mergeSortInterval(userInput,0,userInput.size()-1);
    unsigned int firstCrawler = 0,secondCrawler;
    while(firstCrawler < userInput.size()) {
        secondCrawler = firstCrawler;
        while(secondCrawler+1 < userInput.size() && userInput[secondCrawler]->end > userInput[secondCrawler+1]->start) {
            secondCrawler++;
        }
        mergedIntervals.push_back(new iInterval(userInput[firstCrawler]->start,userInput[secondCrawler]->end));
        firstCrawler = secondCrawler+1;
    }
    return mergedIntervals;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* MERGEOVERLAPPINGINTERVAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
