/****************************************************************************************************************************************************
 *  File Name   		: mindistancenumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\mindistancenumbers.h
 *  Created on			: Dec 28, 2014 :: 11:39:10 PM
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

#ifndef MINDISTANCENUMBERS_H_
#define MINDISTANCENUMBERS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int minDistanceBetweenNumbersON(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() < 2){
		return INT_MAX;
	}
	int prevIndex = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == firstNumber || userInput[counter] == secondNumber){
			prevIndex = counter;
			break;
		}
	}
	if(prevIndex == INT_MIN){
		return INT_MAX;
	}
	int minDistance = INT_MAX;
	for(unsigned int counter = prevIndex+1;counter < userInput.size();counter++){
		if(userInput[counter] == firstNumber || userInput[counter] == secondNumber){
			if(userInput[prevIndex] != userInput[counter]){
				minDistance = min(minDistance,counter-prevIndex);
			}
			prevIndex = counter;
		}
	}
	return minDistance;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int minDistanceBetweenNumbersON2(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() < 2){
		return INT_MAX;
	}
	unsigned int secondCrawler,thirdCrawler;
	int minDistance = INT_MAX;
	for(unsigned int firstCrawler = 0;firstCrawler < userInput.size();firstCrawler++){
		secondCrawler = firstCrawler;
		while(secondCrawler < userInput.size() && userInput[secondCrawler] != firstNumber & userInput[secondCrawler] != secondNumber){
			secondCrawler++;
		}
		if(secondCrawler >= userInput.size()){
			return minDistance;
		}
		thirdCrawler = secondCrawler+1;
		while(thirdCrawler < userInput.size() && userInput[thirdCrawler] != userInput[secondCrawler]){
			thirdCrawler++;
		}
		if(thirdCrawler < userInput.size()){
			minDistance = min(minDistance,thirdCrawler-secondCrawler);
		}
	}
	return minDistance;
}

#endif /* MINDISTANCENUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
