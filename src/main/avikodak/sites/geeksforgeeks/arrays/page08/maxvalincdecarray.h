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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
