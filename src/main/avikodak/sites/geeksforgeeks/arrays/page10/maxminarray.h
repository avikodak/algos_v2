/****************************************************************************************************************************************************
 *  File Name   		: maxminarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\maxminarray.h
 *  Created on			: Nov 26, 2014 :: 10:53:30 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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

#ifndef MAXMINARRAY_H_
#define MAXMINARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
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

//Tested
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

//Tested
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
//Tested
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
//Tested
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
