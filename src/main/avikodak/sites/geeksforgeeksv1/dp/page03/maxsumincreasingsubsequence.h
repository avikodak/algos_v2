/****************************************************************************************************************************************************
 *  File Name   		: maxsumincreasingsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\maxsumincreasingsubsequence.h
 *  Created on			: Dec 9, 2014 :: 8:02:58 PM
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

#ifndef MAXSUMINCREASINGSUBSEQUENCE_H_
#define MAXSUMINCREASINGSUBSEQUENCE_H_

//Tested
int maxSumIncreasingSubsequence(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	vector<int> maxSumsAuxspace;
	maxSumsAuxspace.push_back(userInput[0]);
	int maxSum;
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		maxSum = INT_MIN;
		for(unsigned int innerCrawler = 0;innerCrawler < outerCrawler;innerCrawler++){
			if(userInput[outerCrawler] > userInput[innerCrawler]){
				maxSum = max(maxSum,userInput[outerCrawler]+maxSumsAuxspace[innerCrawler]);
			}
		}
		maxSumsAuxspace.push_back(maxSum);
	}
	return *max_element(maxSumsAuxspace.begin(),maxSumsAuxspace.end());
}

#endif /* MAXSUMINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
