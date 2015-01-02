/****************************************************************************************************************************************************
 *  File Name   		: findsubarraywithsum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\findsubarraywithsum.h
 *  Created on			: Nov 27, 2014 :: 7:52:05 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-subarray-with-given-sum/
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

#ifndef FINDSUBARRAYWITHSUM_H_
#define FINDSUBARRAYWITHSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getSubArrayForSumON(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	int runningSum = userInput[0],startIndex = 0;
	for(int counter = 1;counter < (int)userInput.size();counter++){
		while(runningSum > sum && startIndex < counter-1){
			runningSum -= userInput[startIndex++];
		}
		if(runningSum+userInput[counter] == sum){
			return new iPair(startIndex,counter);
		}else{
			runningSum += userInput[counter];
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getSubarrayForSumON2(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	int runningSum;
	for(unsigned int outerCrawler = 0;outerCrawler <userInput.size();outerCrawler++){
		runningSum = 0;
		for(unsigned int innerCrawler = outerCrawler;innerCrawler < userInput.size();innerCrawler++){
			runningSum += userInput[innerCrawler];
			if(runningSum == sum){
				return new iPair(outerCrawler,innerCrawler);
			}
		}
	}
	return null;
}

#endif /* FINDSUBARRAYWITHSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
