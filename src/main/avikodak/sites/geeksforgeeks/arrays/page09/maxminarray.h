/****************************************************************************************************************************************************
 *  File Name   		: maxminarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\maxminarray.h
 *  Created on			: Nov 26, 2014 :: 10:53:30 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
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

#ifndef MAXMINARRAY_H_
#define MAXMINARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
iMaxMin *getMaxMinArray3NBy2(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	if(startIndex == endIndex){
		return new iMaxMin(userInput[startIndex],userInput[startIndex]);
	}
	if(endIndex - startIndex == 1){
		return new iMaxMin(min(userInput[startIndex],userInput[endIndex]),max(userInput[startIndex],userInput[endIndex]));
	}
	int middleIndex = (startIndex + endIndex)/2;
	iMaxMin *leftResult = getMaxMinArray3NBy2(userInput,startIndex,middleIndex);
	iMaxMin *rightResult = getMaxMinArray3NBy2(userInput,middleIndex+1,endIndex);
	if(leftResult == null || rightResult == null){
		return leftResult == null?rightResult:leftResult;
	}
	return new iMaxMin(min(leftResult->minValue,rightResult->minValue),max(leftResult->maxValue,rightResult->maxValue));
}

iMaxMin *getMaxMinArrayPairs3By2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iMaxMin *result = new iMaxMin();
	unsigned int counter = 0;
	if(userInput.size() % 2 == 0){
		result->minValue = min(userInput[0],userInput[1]);
		result->maxValue = max(userInput[0],userInput[1]);
		counter = 2;
	}else{
		result->maxValue = userInput[0];
		result->minValue = userInput[0];
		counter = 1;
	}
	for(;counter < userInput.size()-1;counter++){
		if(userInput[counter] > userInput[counter+1]){
			result->maxValue = max(result->maxValue,userInput[counter]);
			result->minValue = min(result->minValue,userInput[counter+1]);
		}else{
			result->maxValue = max(result->maxValue,userInput[counter+1]);
			result->minValue = min(result->minValue,userInput[counter]);
		}
	}
	return result;
}

iMaxMin *getMaxMinArrayO2N(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iMaxMin *result = new iMaxMin();
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(result->maxValue < userInput[counter]){
			result->maxValue = userInput[counter];
		}
		if(result->minValue > userInput[counter]){
			result->minValue = userInput[counter];
		}
	}
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iMaxMin *getMaxMinArrayONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	return new iMaxMin(userInput[0],userInput[userInput.size()-1]);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
iMaxMin *getMaxMinArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		return new iMaxMin(userInput[0],userInput[0]);
	}
	iMaxMin *result = new iMaxMin();
	bool flag;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		flag = true;
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(outerCounter != innerCounter){
				if(userInput[innerCounter] < userInput[outerCounter]){
					flag = false;
				}
			}
		}
		if(flag){
			result->minValue = userInput[outerCounter];
		}
	}
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		flag = true;
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(outerCounter != innerCounter){
				if(userInput[innerCounter] > userInput[outerCounter]){
					flag = false;
				}
			}
		}
		if(flag){
			result->maxValue = userInput[outerCounter];
		}
	}
	return result;
}

#endif /* MAXMINARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
