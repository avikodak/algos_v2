/****************************************************************************************************************************************************
 *  File Name   		: radixexchangesort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\radixexchangesort.h
 *  Created on			: Dec 11, 2014 :: 1:00:56 PM
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

#ifndef RADIXEXCHANGESORTV2_H_
#define RADIXEXCHANGESORTV2_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
int divideStepRadixExchangeSort(vector<int> &userInput,int startIndex,int endIndex,int bitPosition){
	if(userInput.size() == 0 || bitPosition < 0){
		return INT_MIN;
	}
	while(startIndex <= endIndex){
		while(startIndex <= endIndex && !(userInput[startIndex] & 1 << bitPosition)){
			startIndex++;
		}
		while(startIndex <= endIndex && userInput[endIndex] & 1 << bitPosition){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}

//Tested
void radixExchangeSortMainV2(vector<int> &userInput,int startIndex,int endIndex,int bitPosition){
	if(startIndex >= endIndex || bitPosition < 0){
		return;
	}
	int dividingIndex = divideStepRadixExchangeSort(userInput,startIndex,endIndex,bitPosition);
	radixExchangeSortMainV2(userInput,startIndex,dividingIndex,bitPosition-1);
	radixExchangeSortMainV2(userInput,dividingIndex+1,endIndex,bitPosition-1);
}

//Tested
void radixExchangeSortV2(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	radixExchangeSortMainV2(userInput,0,userInput.size(),log2(maxVal));
}

#endif /* RADIXEXCHANGESORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
