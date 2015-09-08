/****************************************************************************************************************************************************
 *  File Name   		: minmax.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture05\minmax.h
 *  Created on			: Dec 12, 2014 :: 12:18:49 PM
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

#ifndef MINMAX_H_
#define MINMAX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iMaxMin *getMinMaxON(vector<int> userInput){
	iMaxMin *result = new iMaxMin();
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		result->maxValue = userInput[0];
		result->minValue = userInput[0];
		return result;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(result->minValue > userInput[counter]){
			result->minValue = userInput[counter];
		}
		if(result->maxValue < userInput[counter]){
			result->maxValue = userInput[counter];
		}
	}
	return result;
}

//Tested
iMaxMin *getMinMaxDAD(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	iMaxMin *result = new iMaxMin();
	if(startIndex == endIndex){
		result->minValue = userInput[startIndex];
		result->maxValue = userInput[startIndex];
		return result;
	}
	int middleIndex = (startIndex + endIndex)/2;
	iMaxMin *leftResult = getMinMaxDAD(userInput,startIndex,middleIndex);
	iMaxMin *rightResult = getMinMaxDAD(userInput,middleIndex+1,endIndex);
	result->minValue = min(leftResult->minValue,rightResult->minValue);
	result->maxValue = max(leftResult->maxValue,rightResult->maxValue);
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iMaxMin *getMinMaxONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iMaxMin *result = new iMaxMin();
	if(userInput.size() == 1){
		result->minValue = result->maxValue = userInput[0];
		return result;
	}
	sort(userInput.begin(),userInput.end());
	result->maxValue = userInput[userInput.size()-1];
	result->minValue = userInput[0];
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* MINMAX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
