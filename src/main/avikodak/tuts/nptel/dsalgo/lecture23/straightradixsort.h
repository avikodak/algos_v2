/****************************************************************************************************************************************************
 *  File Name   		: straightradixsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\straightradixsort.h
 *  Created on			: Dec 2, 2014 :: 12:24:49 PM
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

#ifndef STRAIGHTRADIXSORT_H_
#define STRAIGHTRADIXSORT_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
void reorganizeStraightRadixSort(vector<int> &userInput,int bitPosition){
	if(userInput.size() == 0){
		return;
	}
	queue<int> unsetBitBucket,setBitBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & 1 << bitPosition){
			setBitBucket.push(userInput[counter]);
		}else{
			unsetBitBucket.push(userInput[counter]);
		}
	}
	userInput.clear();
	while(!unsetBitBucket.empty()){
		userInput.push_back(unsetBitBucket.front());
		unsetBitBucket.pop();
	}
	while(!setBitBucket.empty()){
		userInput.push_back(setBitBucket.front());
		setBitBucket.pop();
	}
}

//Tested
void  straightRadixSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxElement = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
	}
	int totalBits = log2(maxElement) + 1;
	for(int counter = 0;counter < totalBits;counter++){
		reorganizeStraightRadixSort(userInput,counter);
	}
}

#endif /* STRAIGHTRADIXSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
