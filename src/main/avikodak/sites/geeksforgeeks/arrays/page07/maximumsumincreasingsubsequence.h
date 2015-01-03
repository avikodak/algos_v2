/****************************************************************************************************************************************************
 *  File Name   		: maximumsumincreasingsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maximumsumincreasingsubsequence.h
 *  Created on			: Nov 27, 2014 :: 7:56:46 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
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

#ifndef MAXIMUMSUMINCREASINGSUBSEQUENCE_H_
#define MAXIMUMSUMINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maximumSumIncreasingSubsequence(vector<int> userInput){
	vector<int> maxSumSubsequence;
	if(userInput.size() == 0){
		return INT_MIN;
	}
	maxSumSubsequence.push_back(userInput[0]);
	int maxSum;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		maxSum = INT_MIN;
		for(unsigned int innercounter = 0;innercounter < outerCounter;innercounter++){
			if(userInput[outerCounter] > userInput[innercounter]){
				maxSum = max(maxSum,maxSumSubsequence[innercounter] + userInput[outerCounter]);
			}
		}
		maxSumSubsequence.push_back(maxSum);
	}
	return *max_element(maxSumSubsequence.begin(),maxSumSubsequence.end());
}

#endif /* MAXIMUMSUMINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
