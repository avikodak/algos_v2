/****************************************************************************************************************************************************
 *  File Name   		: radixsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\radixsort.h
 *  Created on			: Dec 22, 2014 :: 3:39:04 PM
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

//Tested
int getDividingIndexRadixSort(vector<int> &userInput,int start,int end,int index){
	if(start > end || index < 0){
		return INT_MIN;
	}
	while(start <= end){
		while(start <= end && !(userInput[start] & 1 << index)){
			start++;
		}
		while(start <= end && userInput[end] & 1 << index){
			end--;
		}
		if(start < end){
			swap(userInput[start],userInput[end]);
		}
	}
	return end;
}

//Tested
void radixSortMain(vector<int> &userInput,int start,int end,int index){
	if(start >= end || index < 0){
		return;
	}
	int dividingIndex = getDividingIndexRadixSort(userInput,start,end,index);
	radixSortMain(userInput,start,dividingIndex,index-1);
	radixSortMain(userInput,dividingIndex+1,end,index-1);
}

//Tested
void radixSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int noOfBits = log2(*max_element(userInput.begin(),userInput.end()));
	radixSortMain(userInput,0,userInput.size()-1,noOfBits+1);
}

#endif /* RADIXSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
