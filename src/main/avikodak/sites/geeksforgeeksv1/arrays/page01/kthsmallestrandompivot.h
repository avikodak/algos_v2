/****************************************************************************************************************************************************
 *  File Name   		: kthsmallestrandompivot.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\kthsmallestrandompivot.h
 *  Created on			: Jan 5, 2015 :: 10:40:47 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
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

#ifndef KTHSMALLESTRANDOMPIVOT_H_
#define KTHSMALLESTRANDOMPIVOT_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int randomizedDivideStep(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	srand(time(NULL));
	int randIndex = rand() % endIndex + startIndex;
	swap(userInput[randIndex],userInput[endIndex]);
	int pivotIndex = endIndex,key = userInput[pivotIndex];
	while(startIndex < endIndex){
		while(userInput[startIndex] < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[pivotIndex],userInput[endIndex]);
	return endIndex;
}

//Tested
int kthSmallestRandomizedQuickSort(vector<int> &userInput,int kValue,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = randomizedDivideStep(userInput,startIndex,endIndex);

	if(pivotIndex + 1 == kValue){
		return userInput[pivotIndex];
	}
	if(pivotIndex > kValue - 1){
		return kthSmallestRandomizedQuickSort(userInput,kValue,startIndex,pivotIndex-1);
	}else{
		return kthSmallestRandomizedQuickSort(userInput,kValue,pivotIndex+1,endIndex);
	}
}

#endif /* KTHSMALLESTRANDOMPIVOT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
