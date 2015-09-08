/****************************************************************************************************************************************************
 *  File Name   		: smallestsubarraygreatersum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\smallestsubarraygreatersum.h
 *  Created on			: Jan 5, 2015 :: 8:05:45 AM
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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

#ifndef SMALLESTSUBARRAYGREATERSUM_H_
#define SMALLESTSUBARRAYGREATERSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int smallestSubarrayGreaterSumON(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int start = 0,end = 0;
	int currentSum = 0,minSize = INT_MAX;
	while(end < userInput.size()){
		while(end < userInput.size() && currentSum + userInput[end] < sum){
			currentSum += userInput[end++];
		}
		while(start <= end && currentSum > sum){
			minSize = min(minSize,end - start + 1);
			currentSum -= userInput[start++];
		}
	}
	return minSize;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int smallestSubarrayGreaterSumON2(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return 0;
	}
	int minSize = INT_MAX,innerCrawler,currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		currentSum = 0;
		for(innerCrawler = outerCrawler;innerCrawler < userInput.size();innerCrawler++){
			currentSum += userInput[innerCrawler];
			if(currentSum > sum){
				minSize = min(minSize,innerCrawler - outerCrawler + 1);
			}
		}
	}
	return minSize;
}

#endif /* SMALLESTSUBARRAYGREATERSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
