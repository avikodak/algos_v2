/****************************************************************************************************************************************************
 *  File Name   		: longestincsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\longestincsubsequence.h
 *  Created on			: Nov 28, 2014 :: 1:58:53 AM
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

#ifndef LONGESTINCSUBSEQUENCE_H_
#define LONGESTINCSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestIncreasingSubSequenceONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> activeLists;
	activeLists.reserve(userInput.size());
	activeLists[0] = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(activeLists[0] > userInput[counter]){
			activeLists[0] = userInput[counter];
		}else if(activeLists[activeLists.size()-1] < userInput[counter]){
			activeLists[activeLists.size()+1] = userInput[counter];
		}else{
			int innerCounter = 1;
			while(innerCounter < activeLists.size()-1 && userInput[counter] > activeLists[innerCounter]){
				innerCounter++;
			}
			activeLists[innerCounter-1] = userInput[counter];
		}
	}
	return activeLists.size();
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestIncreasingSubSequenceDP(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> maxLengths;
	int finalMaxVal = 1,currentMax;
	maxLengths.push_back(1);
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		currentMax = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				currentMax = max(currentMax,1 + maxLengths[innerCounter]);
			}
		}
		maxLengths.push_back(currentMax);
		finalMaxVal = max(finalMaxVal,currentMax);
	}
	return maxLength;
}

int longestIncreasingSubSequence(vector<int> userInput,int currentIndex){
	if(userInput.size() == 0){
		return 0;
	}
	if(currentIndex >= userInput.size()){
		return INT_MAX;
	}
	if(currentIndex == 0){
		return 1;
	}
	int maxLength = 1;
	for(int counter = currentIndex-1;counter >= 0;counter--){
		if(userInput[counter] > userInput[currentIndex]){
			maxLength = max(maxLength,longestIncreasingSubSequence(userInput,counter));
		}
	}
	return maxLength;
}

#endif /* LONGESTINCSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
