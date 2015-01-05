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
