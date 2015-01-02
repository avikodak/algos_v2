/****************************************************************************************************************************************************
 *  File Name   		: maxlengthbitonicsubarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maxlengthbitonicsubarray.h
 *  Created on			: Nov 28, 2014 :: 1:48:16 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-length-bitonic-subarray/
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

#ifndef MAXLENGTHBITONICSUBARRAY_H_
#define MAXLENGTHBITONICSUBARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getIncreasingLengthSubArrays(vector<int> userInput){
	vector<int> increasingSubArraysLength;
	increasingSubArraysLength.push_back(1);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] > userInput[counter-1]){
			increasingSubArraysLength.push_back(increasingSubArraysLength[counter-1]+1);
		}else{
			increasingSubArraysLength.push_back(1);
		}
	}
	return increasingSubArraysLength;
}

//Tested
vector<int> getDecreasingLengthSubArrays(vector<int> userInput){
	vector<int> decreasingSubArraysLength;
	if(userInput.size() == 0){
		return decreasingSubArraysLength;
	}
	decreasingSubArraysLength.assign(userInput.size(),0);
	decreasingSubArraysLength[userInput.size() - 1] = 1;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		if(userInput[counter] > userInput[counter+1]){
			decreasingSubArraysLength[counter] = decreasingSubArraysLength[counter+1] + 1;
		}else{
			decreasingSubArraysLength[counter] = 1;
		}
	}
	return decreasingSubArraysLength;
}

//Tested
int maxLengthBitonicSubArrays(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> incSubArrayLen = getIncreasingLengthSubArrays(userInput);
	vector<int> decSubArrayLen = getDecreasingLengthSubArrays(userInput);
	int maxLen = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxLen = max(maxLen,incSubArrayLen[counter] + decSubArrayLen[counter] - 1);
	}
	return maxLen;
}

#endif /* MAXLENGTHBITONICSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
