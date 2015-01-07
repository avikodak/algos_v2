/****************************************************************************************************************************************************
 *  File Name   		: maxsumpatharrays.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\maxsumpatharrays.h
 *  Created on			: Jan 5, 2015 :: 11:38:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
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

#ifndef MAXSUMPATHARRAYS_H_
#define MAXSUMPATHARRAYS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxSumPathArrays(vector<int> firstSortedInput,vector<int> secondSortedInput){
	if(firstSortedInput.size() == 0 && secondSortedInput.size()){
		return 0;
	}
	int maxSum = 0,maxFirstArraySum = 0,maxSecondArraySum = 0;
	unsigned int firstCrawler = 0,secondCrawler = 0;
	while(firstCrawler < firstSortedInput.size() && secondCrawler < secondSortedInput.size()){
		if(firstSortedInput[firstCrawler] == secondSortedInput[secondCrawler]){
			maxSum += max(maxFirstArraySum,maxSecondArraySum);
			maxFirstArraySum = 0;
			maxSecondArraySum = 0;
			while(firstCrawler < firstSortedInput.size() && secondCrawler < secondSortedInput.size() && firstSortedInput[firstCrawler] == secondSortedInput[secondCrawler]){
				maxSum += firstSortedInput[firstCrawler++];
				secondCrawler++;
			}
		}else if(firstSortedInput[firstCrawler] < secondSortedInput[secondCrawler]){
			maxFirstArraySum += firstSortedInput[firstCrawler++];
		}else{
			maxSecondArraySum += secondSortedInput[secondCrawler++];
		}
	}
	while(firstCrawler < firstSortedInput.size()){
		maxFirstArraySum += firstSortedInput[firstCrawler++];
	}
	while(secondCrawler < secondSortedInput.size()){
		maxSecondArraySum += secondSortedInput[secondCrawler++];
	}
	return maxSum + max(maxFirstArraySum,maxSecondArraySum);;
}

#endif /* MAXSUMPATHARRAYS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
