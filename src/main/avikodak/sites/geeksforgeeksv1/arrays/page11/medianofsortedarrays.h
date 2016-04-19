/****************************************************************************************************************************************************
 *  File Name   		: medianofsortedarrays.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\medianofsortedarrays.h
 *  Created on			: Nov 25, 2014 :: 9:01:27 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
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

#ifndef MEDIANOFSORTEDARRAYS_H_
#define MEDIANOFSORTEDARRAYS_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int medianSortedArray(int userInput[], int size) {
    if (size%2 == 0)
        return (userInput[size/2] + userInput[size/2-1])/2;
    else
        return userInput[size/2];
}

//Tested
int medianByBinarySearchMain(int firstSortedArray[],int secondSortedArray[],int size) {
    if(size == 1) {
        return (firstSortedArray[0] + secondSortedArray[0])/2;
    }
    if(size == 2) {
        return (max(firstSortedArray[0],secondSortedArray[0])+min(firstSortedArray[1],secondSortedArray[1]))/2;
    }
    int medianFirstArray = medianSortedArray(firstSortedArray,size);
    int medianSecondArray = medianSortedArray(secondSortedArray,size);
    if(medianFirstArray < medianSecondArray) {
        if(size%2 == 0) {
            return medianByBinarySearchMain(firstSortedArray + size/2 -1 ,secondSortedArray,size - size/2 + 1);
        } else {
            return medianByBinarySearchMain(firstSortedArray + size/2,secondSortedArray,size - size/2);
        }
    } else {
        if(size%2 == 0) {
            return medianByBinarySearchMain(secondSortedArray + size/2 -1 ,firstSortedArray,size - size/2 + 1);
        } else {
            return medianByBinarySearchMain(secondSortedArray + size/2,firstSortedArray,size - size/2);
        }
    }
}

//Tested
int medianByBinarySearch(int firstSortedArray[],int secondSortedArray[],int size) {
    return medianByBinarySearchMain(firstSortedArray,secondSortedArray,size);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int medianByMerging(vector<int> firstSortedArray,vector<int> secondSortedArray) {
    if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0) {
        return INT_MIN;
    }
    int medianElement,prevMedianElement;
    unsigned int firstCrawler = 0,secondCrawler = 0;
    int requiredSize = (firstSortedArray.size() + secondSortedArray.size())/2 + 1;
    bool isEven = (firstSortedArray.size() + secondSortedArray.size())%2 == 0;
    while(requiredSize-- && firstCrawler < firstSortedArray.size() && secondCrawler < secondSortedArray.size()) {
        prevMedianElement = medianElement;
        if(firstSortedArray[firstCrawler] < secondSortedArray[secondCrawler]) {
            medianElement = firstSortedArray[firstCrawler++];
        } else {
            medianElement = secondSortedArray[secondCrawler++];
        }
    }
    if(requiredSize  > 0) {
        return INT_MIN;
    }
    return isEven?(medianElement + prevMedianElement)/2:medianElement;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int medianBySorting(vector<int> firstSortedArray,vector<int> secondSortedArray) {
    vector<int> mergedArray(firstSortedArray.size()+secondSortedArray.size());
    merge(firstSortedArray.begin(),firstSortedArray.end(),secondSortedArray.begin(),secondSortedArray.end(),mergedArray.begin());
    sort(mergedArray.begin(),mergedArray.end());
    if(mergedArray.size() % 2 == 1) {
        return mergedArray[mergedArray.size()/2];
    } else {
        return (mergedArray[mergedArray.size()/2] + mergedArray[mergedArray.size()/2 - 1])/2;
    }
}

#endif /* MEDIANOFSORTEDARRAYS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
