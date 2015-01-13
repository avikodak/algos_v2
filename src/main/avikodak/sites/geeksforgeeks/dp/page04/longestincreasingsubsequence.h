/****************************************************************************************************************************************************
 *  File Name   		: longestincreasingsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\longestincreasingsubsequence.h
 *  Created on			: Dec 5, 2014 :: 6:18:35 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
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

#ifndef LONGESTINCREASINGSUBSEQUENCE_H_
#define LONGESTINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int longestIncreasingSequenceONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	vector<int> activeLists;
	activeLists.push_back(userInput[0]);
	unsigned int innerCounter;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(activeLists[0] > userInput[counter]){
			activeLists[0] = userInput[counter];
		}else if(activeLists[activeLists.size()-1] < userInput[counter]){
			activeLists.push_back(userInput[counter]);
		}else{
			innerCounter = 1;
			while(innerCounter < activeLists.size()-1 && userInput[counter] > activeLists[innerCounter]){
				innerCounter++;
			}
			activeLists[innerCounter] = userInput[counter];
		}
	}
	return activeLists.size();
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int longestIncreasingSequenceON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	vector<int> lengths;
	lengths.push_back(1);
	int maxLength;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		maxLength = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				maxLength = max(maxLength,1+lengths[innerCounter]);
			}
		}
		lengths.push_back(maxLength);
	}
	return maxLength;
}

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool lIsVectorSorted(vector<int> userInput){
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] < userInput[counter-1]){
			return false;
		}
	}
	return true;
}

//Tested
int longestIncreasingSubSequence2NMain(vector<int> userInput,vector<int> auxSpace,unsigned int index){
	if(index > userInput.size()){
		return INT_MIN;
	}
	if(index == userInput.size()){
		return lIsVectorSorted(auxSpace)?auxSpace.size():INT_MIN;
	}
	int result = longestIncreasingSubSequence2NMain(userInput,auxSpace,index+1);
	auxSpace.push_back(userInput[index]);
	return max(result,longestIncreasingSubSequence2NMain(userInput,auxSpace,index+1));
}

//Tested
int longestIncreasingSubSequence2N(vector<int> userInput){
	vector<int> auxSpace;
	return longestIncreasingSubSequence2NMain(userInput,auxSpace,0);
}

//Tested
int longestIncreasingSubSequence2NIterative(vector<int> userInput){
	if(userInput.size() < 2){
		return userInput.size();
	}
	int limit = pow(2,userInput.size());
	vector<int> auxSpace;
	int maxSize = INT_MIN;
	for(int counter = 0;counter < limit;counter++){
		auxSpace.clear();
		for(unsigned int objCounter = 0;objCounter < userInput.size();objCounter++){
			if(counter & 1 << objCounter){
				auxSpace.push_back(userInput[objCounter]);
			}
		}
		if(isVectorSorted(auxSpace)){
			maxSize = max(maxSize,(int)auxSpace.size());
		}
	}
	return maxSize;
}

#endif /* LONGESTINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
