/****************************************************************************************************************************************************
 *  File Name   		: searchinsortedpivotedarray.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\searchinsortedpivotedarray.h
 *  Created on			: Oct 17, 2014 :: 6:49:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SEARCHINSORTEDPIVOTEDARRAY_H_
#define SEARCHINSORTEDPIVOTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getPivotElementIndex(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex == endIndex) {
        return startIndex;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] > userInput[middleIndex+1]) {
        return middleIndex;
    } else if(userInput[middleIndex] > userInput[startIndex]) {
        return getPivotElementIndex(userInput,middleIndex+1,endIndex);
    } else {
        return getPivotElementIndex(userInput,startIndex,middleIndex-1);
    }
}

//Tested
bool binarySearchPivot(vector<int> userInput,int startIndex,int endIndex,int key) {
    if(startIndex > endIndex) {
        return false;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        return true;
    } else if(userInput[middleIndex] > key) {
        return binarySearchPivot(userInput,startIndex,middleIndex-1,key);
    } else {
        return binarySearchPivot(userInput,middleIndex+1,endIndex,key);
    }
}

//Tested
bool searchInSortedPivotedArray(vector<int> userInput,int key) {
    int pivotIndex = getPivotElementIndex(userInput,0,userInput.size()-1);
    if(pivotIndex == INT_MAX) {
        return false;
    }
    if(userInput[0] <= key && key <= userInput[pivotIndex]) {
        return binarySearchPivot(userInput,0,pivotIndex,key);
    } else {
        return binarySearchPivot(userInput,pivotIndex+1,userInput.size()-1,key);
    }
}

//Tested
bool searchInSortedPivotedArrayOLOGN(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return false;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        return true;
    } else if(userInput[startIndex] < userInput[middleIndex]) {
        if(key >= userInput[startIndex] && key <= userInput[middleIndex-1]) {
            return searchInSortedPivotedArrayOLOGN(userInput,key,startIndex,middleIndex-1);
        } else {
            return searchInSortedPivotedArrayOLOGN(userInput,key,middleIndex+1,endIndex);
        }
    } else {
        if(key >= userInput[middleIndex+1] && key <= userInput[endIndex]) {
            return searchInSortedPivotedArrayOLOGN(userInput,key,middleIndex+1,endIndex);
        } else {
            return searchInSortedPivotedArrayOLOGN(userInput,key,startIndex,middleIndex-1);
        }
    }
}

//Tested
bool searchInSortedPivotedArrayOLOGN(vector<int> &userInput,int key) {
    if(userInput.size() == 0) {
        return false;
    }
    return searchInSortedPivotedArrayOLOGN(userInput,key,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool searchInRotatedArray(vector<int> userInput,int key) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == key) {
            return true;
        }
    }
    return false;
}


#endif /* SEARCHINSORTEDPIVOTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
