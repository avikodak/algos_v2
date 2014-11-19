/****************************************************************************************************************************************************
 *  File Name   		: randomizedquicksort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture10\randomizedquicksort.h
 *  Created on			: Nov 18, 2014 :: 2:48:58 PM
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

#ifndef RANDOMIZEDQUICKSORT_H_
#define RANDOMIZEDQUICKSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int dividingStepRandomizedQuickSort(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return -1;
	}
	srand(time(NULL));
	int key = userInput[rand() % endIndex + startIndex];
	while(startIndex < endIndex){
		while(userInput[startIndex] <= key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] > key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}


void randomizedQuickSort(vecor<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return;
	}
	int dividingIndex = dividingStepRandomizedQuickSort(userInput,startIndex,endIndex);
	randomizedQuickSort(userInput,startIndex,dividingIndex-1);
	randomizedQuickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* RANDOMIZEDQUICKSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
