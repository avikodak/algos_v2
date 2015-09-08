/****************************************************************************************************************************************************
 *  File Name   		: maxofallsubarrayssizek.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\maxofallsubarrayssizek.h
 *  Created on			: Dec 1, 2014 :: 11:50:01 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MAXOFALLSUBARRAYSSIZEK_H_
#define MAXOFALLSUBARRAYSSIZEK_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> maxOfAllSubArraysOfSizeKON(vector<int> userInput,int kValue){
	vector<int> maxValues;
	if(userInput.size() < kValue){
		return maxValues;
	}
	deque<int> auxSpace;
	unsigned int counter;
	for(counter = 0;counter < kValue;counter++){
		while(!auxSpace.empty() && userInput[counter] >= auxSpace[auxSpace.back()]){
			auxSpace.pop_back();
		}
		auxSpace.push_back(counter);
	}
	while(counter < userInput.size()){
		maxValues.push_back(auxSpace.front());
		while(!auxSpace.empty() && auxSpace.front() > counter - kValue){
			auxSpace.pop_front();
		}
		while(!auxSpace.empty() && userInput[counter] >= auxSpace[auxSpace.back()]){
			auxSpace.pop_back();
		}
		auxSpace.push_back(userInput[counter]);
		counter++;
	}
}


/****************************************************************************************************************************************************/
/* 																O(N^k) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> maxOfAllSubArraysOfSizeKONK(vector<int> userInput,int kValue){
	vector<int> maxValues;
	if(userInput.size() < kValue){
		return maxValues;
	}
	unsigned int innerCrawler;
	int maxSubArray;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-kValue;outerCrawler++){
		innerCrawler = outerCrawler;
		maxSubArray = INT_MIN;
		while(innerCrawler < userInput.size() && innerCrawler < innerCrawler + kValue){
			maxSubArray = max(maxSubArray,userInput[innerCrawler]);
		}
		maxValues.push_back(maxSubArray);
	}
	return maxValues;
}

#endif /* MAXOFALLSUBARRAYSSIZEK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
