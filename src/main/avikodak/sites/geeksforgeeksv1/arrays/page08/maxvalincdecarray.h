/****************************************************************************************************************************************************
 *  File Name   		: maxvalincdecarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maxvalincdecarray.h
 *  Created on			: Nov 28, 2014 :: 10:21:54 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
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

#ifndef MAXVALINCDECARRAY_H_
#define MAXVALINCDECARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxValBitonicArrayBinarySearchMain(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	if(endIndex - startIndex == 1){
		if(userInput[startIndex] > userInput[endIndex]){
			return userInput[startIndex];
		}else{
			return userInput[endIndex];
		}
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] > userInput[middleIndex+1]){
		return userInput[middleIndex];
	}else if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] < userInput[middleIndex+1]){
		return getMaxValBitonicArrayBinarySearchMain(userInput,middleIndex+1,endIndex);
	}else{
		return getMaxValBitonicArrayBinarySearchMain(userInput,startIndex,middleIndex-1);
	}
}

//Tested
int getMaxValBitonicArrayBinarySearch(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	return getMaxValBitonicArrayBinarySearchMain(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxValBitonicArray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int maxVal = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxVal = max(maxVal,userInput[counter]);
	}
	return maxVal;
}

#endif /* MAXVALINCDECARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
