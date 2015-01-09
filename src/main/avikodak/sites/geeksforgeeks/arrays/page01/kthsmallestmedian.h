/****************************************************************************************************************************************************
 *  File Name   		: kthsmallestmedian.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\kthsmallestmedian.h
 *  Created on			: Jan 5, 2015 :: 10:40:57 AM
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

#ifndef KTHSMALLESTMEDIAN_H_
#define KTHSMALLESTMEDIAN_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int getMedianOfGroupsOfFive(vector<int> userInput,int startIndex,int endIndex){
	if(userInput.size() == 0){
		return 0;
	}
	if(userInput.size() > 5){
		throw "Size is greater than five";
	}
	sort(userInput.begin() + startIndex,userInput.begin() + endIndex);
	return userInput[(startIndex + endIndex)/2];
}

int partitionArray(vector<int> userInput,int startIndex,int endIndex,int median){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	while(startIndex < endIndex){
		while(startIndex < endIndex && userInput[startIndex] < median){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= median){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}

int getKthSmallestElement(vector<int> userInput,int kValue,int startIndex,int endIndex){
	if(userInput.size() < kValue){
		return INT_MIN;
	}
	vector<int> auxSpace;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter += 5){
		auxSpace.push_back(getMedianOfGroupsOfFive(userInput,outerCounter,outerCounter + 4));
	}
	int median = getKthSmallestElement(userInput,auxSpace.size()/2,0,auxSpace.size()-1);
	int pivotIndex = partitionArray(userInput,startIndex,endIndex,median);
	if(pivotIndex == kValue + startIndex - 1){
		return userInput[pivotIndex];
	}else if(kValue + startIndex - 1 < pivotIndex){
		return getKthSmallestElement(userInput,kValue,startIndex,pivotIndex-1);
	}else{
		return getKthSmallestElement(userInput,kValue - pivotIndex,pivotIndex+1,endIndex);
	}
}

#endif /* KTHSMALLESTMEDIAN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/