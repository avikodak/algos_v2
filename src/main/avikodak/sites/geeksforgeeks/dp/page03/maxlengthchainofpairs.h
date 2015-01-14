/****************************************************************************************************************************************************
 *  File Name   		: maxlengthchainofpairs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\maxlengthchainofpairs.h
 *  Created on			: Dec 15, 2014 :: 11:43:32 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-20-maximum-length-chain-of-pairs/
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

#ifndef MAXLENGTHCHAINOFPAIRS_H_
#define MAXLENGTHCHAINOFPAIRS_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int mlcDivideStepQuickSort(vector<iPair *> &userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int key = userInput[pivotIndex]->firstValue;
	while(startIndex < endIndex){
		while(userInput[startIndex]->firstValue < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex]->firstValue >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[endIndex],userInput[startIndex]);
		}
	}
	swap(userInput[endIndex],userInput[pivotIndex]);
	return endIndex;
}

//Tested
void mlcQuickSort(vector<iPair *> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = mlcDivideStepQuickSort(userInput,startIndex,endIndex);
	mlcQuickSort(userInput,startIndex,dividingIndex-1);
	mlcQuickSort(userInput,dividingIndex+1,endIndex);
}

//Tested
int maxLengthChainOfPairs(vector<iPair *> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	mlcQuickSort(userInput,0,userInput.size()-1);
	vector<int> lengths;
	lengths.push_back(1);
	int maxLength = 1;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		maxLength = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[outerCounter]->firstValue > userInput[innerCounter]->secondValue){
				maxLength = max(maxLength,1 + lengths[innerCounter]);
			}
		}
		lengths.push_back(maxLength);
	}
	return lengths[lengths.size()-1];
}

#endif /* MAXLENGTHCHAINOFPAIRS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
