/****************************************************************************************************************************************************
 *  File Name   		: largestsumcontigousarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page11\largestsumcontigousarray.h
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

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

//Tested
int maxSumMergeStep(vector<int> userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int leftSum = INT_MIN,rightSum = INT_MIN,sum = 0;
	int counter = middleIndex;
	while(counter >= startIndex){
		sum += userInput[counter];
		leftSum = max(leftSum,sum);
		counter--;
	}
	sum = 0;
	counter = middleIndex + 1;
	while(counter <= endIndex){
		sum += userInput[counter];
		rightSum = max(rightSum,sum);
		counter++;
	}
	return leftSum + rightSum;
}

//Tested
int largestSumContigousSubArrayON2DACMain(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	int middleIndex = (startIndex + endIndex)/2;
	return max(largestSumContigousSubArrayON2DACMain(userInput,startIndex,middleIndex),max(largestSumContigousSubArrayON2DACMain(userInput,middleIndex+1,endIndex),maxSumMergeStep(userInput,startIndex,middleIndex,endIndex)));
}

//Tested
int largestSumContinousSubArrayON2DAC(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput.size() == 1){
		return userInput[0];
	}
	return largestSumContigousSubArrayON2DACMain(userInput,0,userInput.size()-1);
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
