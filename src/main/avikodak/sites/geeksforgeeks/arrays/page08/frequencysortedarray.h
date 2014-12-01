/****************************************************************************************************************************************************
 *  File Name   		: frequencysortedarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\frequencysortedarray.h
 *  Created on			: Nov 26, 2014 :: 6:29:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/
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

#ifndef FREQUENCYSORTEDARRAY_H_
#define FREQUENCYSORTEDARRAY_H_


/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getLowerBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 >= startIndex && userInput[middleIndex-1] == key){
			return getLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return getLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return getLowerBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
int getHigherBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex+1 <= endIndex && userInput[middleIndex+1] == key ){
			return getHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return getHigherBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return getHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
int getFrequencySortedArray(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	int lowIndex = getLowerBoundBinarySearch(userInput,key,0,userInput.size()-1);
	if(lowIndex == INT_MAX){
		return 0;
	}
	int highIndex = getHigherBoundBinarySearch(userInput,key,0,userInput.size()-1);
	if(highIndex == INT_MIN){
		return 0;
	}
	return highIndex - lowIndex + 1;
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int frequencySortedArrayON(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			frequency++;
		}
	}
	return frequency;
}

#endif /* FREQUENCYSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
