/****************************************************************************************************************************************************
 *  File Name   		: longestbitonicsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\longestbitonicsubsequence.h
 *  Created on			: Nov 28, 2014 :: 12:00:50 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
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

#ifndef LONGESTBITONICSUBSEQUENCE_H_
#define LONGESTBITONICSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getIncreasingLengthsubsequence(vector<int> userInput){
	vector<int> incSubsequenceLen;
	incSubsequenceLen.push_back(1);
	int maxCurrentLength;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		maxCurrentLength = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				maxCurrentLength = max(maxCurrentLength,1+incSubsequenceLen[innerCounter]);
			}
		}
		incSubsequenceLen.push_back(maxCurrentLength);
	}
	return incSubsequenceLen;
}

//Tested
vector<int> getDecreasignLengthSubsequence(vector<int> userInput){
	vector<int> decSubsequenceLen;
	decSubsequenceLen.assign(userInput.size(),0);
	decSubsequenceLen[decSubsequenceLen.size()-1] = 1;
	int maxCurrentLength;
	for(int outerCounter = userInput.size()-2;outerCounter >=0;outerCounter--){
		maxCurrentLength = 1;
		for(int innerCounter = outerCounter+1;innerCounter < (int)userInput.size();innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				maxCurrentLength = max(maxCurrentLength,1+decSubsequenceLen[innerCounter]);
			}
		}
		decSubsequenceLen[outerCounter] = maxCurrentLength;
	}
	return decSubsequenceLen;
}

//Tested
int longestBitonicSubsequence(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int maxLength = 0;
	vector<int> incSubSequenceLen = getIncreasingLengthsubsequence(userInput);
	vector<int> decSubSequenceLen = getDecreasignLengthSubsequence(userInput);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxLength = max(maxLength,incSubSequenceLen[counter]+decSubSequenceLen[counter]-1);
	}
	return maxLength;
}

#endif /* LONGESTBITONICSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
