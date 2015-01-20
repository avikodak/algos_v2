/****************************************************************************************************************************************************
 *  File Name   		: findfirstrepeatingbinarysearch.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\findfirstrepeatingbinarysearch.h
 *  Created on			: Jan 5, 2015 :: 11:24:23 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-first-repeating-element-array-integers/
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

#ifndef FINDFIRSTREPEATINGBINARYSEARCH_H_
#define FINDFIRSTREPEATINGBINARYSEARCH_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int frvLowerBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex] == key?startIndex:INT_MIN;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == key){
			return frvLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return frvLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
	}	return frvLowerBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
}

//Tested
int frvHigherBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(startIndex == endIndex){
		return userInput[startIndex] == key?startIndex:INT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex + 1 <= endIndex && userInput[middleIndex+1] == key){
			return frvHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return frvHigherBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
	}	return frvHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
}

//Tested
int findFirstRepeatingValueBinarySearch(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	vector<int> auxSpace(userInput.size());
	copy(userInput.begin(),userInput.end(),auxSpace.begin());
	sort(auxSpace.begin(),auxSpace.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frvHigherBoundBinarySearch(auxSpace,userInput[counter],0,auxSpace.size()-1) - frvLowerBoundBinarySearch(auxSpace,userInput[counter],0,auxSpace.size()-1) + 1 > 1){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

#endif /* FINDFIRSTREPEATINGBINARYSEARCH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
