/****************************************************************************************************************************************************
 *  File Name   		: largestsumcontigousarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\largestsumcontigousarray.h
 *  Created on			: Oct 17, 2014 :: 6:26:07 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
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
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LARGESTSUMCONTIGOUSARRAY_H_
#define LARGESTSUMCONTIGOUSARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestSumContinousSubArray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int maxSum = userInput[0],continousSum = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		continousSum = max(continousSum+userInput[counter],userInput[counter]);
		maxSum = max(maxSum,continousSum);
	}
	return maxSum;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestSumContigousSubArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int currentSum,maxSum = INT_MIN;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		currentSum = 0;
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			currentSum += userInput[innerCounter];
			maxSum = max(maxSum,currentSum);
		}
	}
	return maxSum;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestSumContigousSubArrayON3(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int sum,maxSum = INT_MIN;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int middleCrawler = outerCrawler;middleCrawler < userInput.size();middleCrawler++){
			sum = 0;
			for(unsigned int innerCrawler = outerCrawler;innerCrawler <= middleCrawler;innerCrawler++){
				sum += userInput[innerCrawler];
			}
			maxSum = max(sum,maxSum);
		}
	}
	return maxSum;
}


#endif /* LARGESTSUMCONTIGOUSARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
