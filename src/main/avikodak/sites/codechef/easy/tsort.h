/****************************************************************************************************************************************************
 *  File Name   		: tsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\tsort.h
 *  Created on			: Feb 3, 2015 :: 12:48:45 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.codechef.com/problems/TSORT
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

#ifndef TSORT_H_
#define TSORT_H_

/****************************************************************************************************************************************************/
/* 																O(B*N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int divideStepRadixSort(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	while(startIndex < endIndex){
		while(startIndex <= endIndex && !(userInput[startIndex] & (1 << bitPosition))){
			startIndex++;
		}
		while(startIndex <= endIndex && (userInput[endIndex] & (1 << bitPosition ))){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}

//Tested
void radixSortMain(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex >= endIndex || bitPosition < 0){
		return;
	}
	int dividingIndex = divideStepRadixSort(userInput,bitPosition,startIndex,endIndex);
	radixSortMain(userInput,bitPosition-1,startIndex,dividingIndex);
	radixSortMain(userInput,bitPosition-1,dividingIndex+1,endIndex);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%d\n",userInput[counter]);
	}
}

//Tested
void radixSort(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	int bits = log2(maxVal);
	radixSortMain(userInput,bits,0,userInput.size()-1);
}

#endif /* TSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
