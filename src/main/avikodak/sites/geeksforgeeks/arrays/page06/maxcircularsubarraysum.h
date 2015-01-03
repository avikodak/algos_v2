/****************************************************************************************************************************************************
 *  File Name   		: maxcircularsubarraysum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\maxcircularsubarraysum.h
 *  Created on			: Jan 3, 2015 :: 10:59:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
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

#ifndef MAXCIRCULARSUBARRAYSUM_H_
#define MAXCIRCULARSUBARRAYSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int kadanesAlgo(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int currentSum = 0,maxSum = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentSum = max(userInput[counter],currentSum+userInput[counter]);
		maxSum = max(maxSum,currentSum);
	}
	return maxSum;
}

//Tested
int maxCircularSubArraySum(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int maxContigousSum = kadanesAlgo(userInput);
	int sumOfArray = 0;
	for(unsigned int counter  = 0;counter < userInput.size();counter++){
		sumOfArray += userInput[counter];
		userInput[counter] *= -1;
	}
	int maxCircularSum = sumOfArray + kadanesAlgo(userInput);
	return max(maxCircularSum,maxContigousSum);
}

#endif /* MAXCIRCULARSUBARRAYSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
