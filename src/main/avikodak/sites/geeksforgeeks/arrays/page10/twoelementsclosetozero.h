/****************************************************************************************************************************************************
 *  File Name   		: twoelementsclosetozero.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\twoelementsclosetozero.h
 *  Created on			: Nov 25, 2014 :: 6:38:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/
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

#ifndef TWOELEMENTSCLOSETOZERO_H_
#define TWOELEMENTSCLOSETOZERO_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoElementsClosestToZeroONLOGN(vector<int> userInput){
	sort(userInput.begin(),userInput.end());
	int startCrawler = 0,endCrawler = userInput.size()-1,sum,min = INT_MAX;
	iPair *result = new iPair(INT_MAX,INT_MAX);
	while(startCrawler < endCrawler){
		sum = userInput[startCrawler] + userInput[endCrawler];
		if(abs(min) > abs(sum)){
			min = sum;
			result->firstValue =  userInput[startCrawler];
			result->secondValue = userInput[endCrawler];
		}
		if(sum > 0){
			endCrawler--;
		}else{
			startCrawler++;
		}
	}
	return result;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoElementsClosestToZero(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int minSum = INT_MAX;
	iPair *result = new iPair(INT_MAX,INT_MAX);
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(abs(minSum) > abs(userInput[outerCrawler] + userInput[innerCrawler])){
				result->firstValue = userInput[outerCrawler];
				result->secondValue = userInput[innerCrawler];
			}
		}
	}
	return result;
}

#endif /* TWOELEMENTSCLOSETOZERO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
