/****************************************************************************************************************************************************
 *  File Name   		: firsttwomins.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture05\firsttwomins.h
 *  Created on			: Dec 12, 2014 :: 12:27:23 PM
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

#ifndef FIRSTTWOMINS_H_
#define FIRSTTWOMINS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *findFirstTwoMinsON(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(INT_MAX,INT_MAX);
	if(userInput.size() == 1){
		result->firstValue = userInput[0];
		result->secondValue = INT_MAX;
		return result;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(result->firstValue > userInput[counter]){
			result->secondValue = result->firstValue;
			result->firstValue = userInput[counter];
		}else if(result->secondValue > userInput[counter]){
			result->secondValue = userInput[counter];
		}
	}
	return result;
}

iPair *findFirstTwoMinDAD(vector<int> userInput,int startIndex,int endIndex){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(INT_MAX,INT_MAX);
	if(endIndex - startIndex == 1){
		result->firstValue = userInput[startIndex];
		result->secondValue = INT_MAX;
		return result;
	}
	int middleIndex = (startIndex + endIndex)/2;
	iPair *leftResult = findFirstTwoMinDAD(userInput,startIndex,middleIndex);
	iPair *rightResult = findFirstTwoMinDAD(userInput,middleIndex+1,endIndex);
	if(leftResult->firstValue > rightResult->firstValue){
		result->firstValue = rightResult->firstValue;
		if(leftResult->firstValue > rightResult->secondValue){
			result->secondValue = rightResult->secondValue;
		}else{
			result->secondValue = leftResult->firstValue;
		}
	}else{
		result->firstValue = leftResult->firstValue;
		if(rightResult->firstValue > leftResult->secondValue){
			result->secondValue = leftResult->secondValue;
		}else{
			result->secondValue = rightResult->firstValue;
		}
	}
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *findFirstTwoMinsONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(INT_MAX,INT_MAX);
	if(userInput.size() == 1){
		result->firstValue = userInput[0];
		return result;
	}
	sort(userInput.begin(),userInput.end());
	result->firstValue = userInput[0];
	result->secondValue = userInput[1];
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* FIRSTTWOMINS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
