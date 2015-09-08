/****************************************************************************************************************************************************
 *  File Name   		: radixexchangesort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\radixexchangesort.h
 *  Created on			: Dec 2, 2014 :: 12:21:42 PM
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

#ifndef RADIXEXCHANGESORT_H_
#define RADIXEXCHANGESORT_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
int divideStepRadixSort(vector<int> &userInput,int startIndex,int endIndex,int bitposition){
	int startCrawler = startIndex,endCrawler = endIndex;
	while(startCrawler <= endCrawler){
		while(startCrawler <= endCrawler && !(userInput[startCrawler]&1 << bitposition)){
			startCrawler++;
		}
		while(startCrawler <= endCrawler && (userInput[endCrawler] & 1 << bitposition)){
			endCrawler--;
		}
		if(startCrawler < endCrawler){
			swap(userInput[startCrawler],userInput[endCrawler]);
		}
	}
	return endCrawler;
}

//Tested
void radixExchangeSortMain(vector<int> &userInput,int startIndex,int endIndex,int bitPosition){
	if(startIndex >= endIndex || bitPosition < 0){
		return;
	}
	int dividingIndex = divideStepRadixSort(userInput,startIndex,endIndex,bitPosition);
	radixExchangeSortMain(userInput,startIndex,dividingIndex,bitPosition-1);
	radixExchangeSortMain(userInput,dividingIndex+1,endIndex,bitPosition-1);
}

//Tested
void radixExchangeSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxElement = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
	}
	int binaryDigits = log2(maxElement) + 1;
	radixExchangeSortMain(userInput,0,userInput.size()-1,binaryDigits-1);
}

#endif /* RADIXEXCHANGESORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
