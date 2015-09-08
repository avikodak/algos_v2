/****************************************************************************************************************************************************
 *  File Name   		: sortedsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\sortedsubsequence.h
 *  Created on			: Nov 27, 2014 :: 7:59:40 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/
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

#ifndef SORTEDSUBSEQUENCE_H_
#define SORTEDSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iTriplet *getSortedTripletON(vector<int> userInput){
	if(userInput.size() < 3){
		return null;
	}
	vector<int> leftMin;
	vector<int> rightMax;
	leftMin.push_back(INT_MAX);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftMin.push_back(min(leftMin[counter-1],userInput[counter-1]));
	}
	rightMax.reserve(userInput.size());
	rightMax[userInput.size()-1] = INT_MIN;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rightMax[counter] = max(userInput[counter+1],rightMax[counter+1]);
	}
	for(unsigned int counter = 1;counter < userInput.size()-1;counter++){
		if(userInput[counter] > leftMin[counter] && userInput[counter] < rightMax[counter]){
			return new iTriplet(leftMin[counter],userInput[counter],rightMax[counter]);
		}
	}
	return null;
}


/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iTriplet *getSortedTripletON3(vector<int> userInput){
	if(userInput.size() < 3){
		return null;
	}
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-2;outerCounter++){
		for(unsigned int middleCounter = outerCounter+1;middleCounter < userInput.size()-1;middleCounter++){
			for(unsigned int innerCounter = middleCounter+1;innerCounter < userInput.size();innerCounter++){
				if(userInput[middleCounter] > userInput[outerCounter] && userInput[middleCounter] < userInput[innerCounter]){
					return new iTriplet(userInput[outerCounter],userInput[middleCounter],userInput[innerCounter]);
				}
			}
		}
	}
	return null;
}

#endif /* SORTEDSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
