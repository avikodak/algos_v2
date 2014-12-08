/****************************************************************************************************************************************************
 *  File Name   		: kadanealgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\kadanealgo.h
 *  Created on			: Dec 5, 2014 :: 12:33:35 AM
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

#ifndef KADANEALGO_H_
#define KADANEALGO_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxContinousSubArraySum(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int currentSum = 0,maxSum = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentSum = max(userInput[counter],currentSum);
		maxSum = max(maxSum,currentSum);
	}
	return maxSum;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxContinousSubArraySum(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int currentSum = 0,maxSum = INT_MIN;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		currentSum = 0;
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			currentSum += userInput[innerCounter];
			maxSum = max(maxSum,currentSum);
		}
	}
	return maxSum;
}

#endif /* KADANEALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
