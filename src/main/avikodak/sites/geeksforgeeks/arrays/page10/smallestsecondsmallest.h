/****************************************************************************************************************************************************
 *  File Name   		: smallestsecondsmallest.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\smallestsecondsmallest.h
 *  Created on			: Nov 25, 2014 :: 11:12:26 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/
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

#ifndef SMALLESTSECONDSMALLEST_H_
#define SMALLESTSECONDSMALLEST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getSmallestAndSecondSmallest(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int smallestValue = userInput[0],secondSmallestValue = userInput[0];
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < smallestValue){
			secondSmallestValue = smallestValue;
			smallestValue = userInput[counter];
		}else if(userInput[counter] < secondSmallestValue && userInput[counter] != smallestValue){
			secondSmallestValue = userInput[counter];
		}
	}
	return new iPair(smallestValue,secondSmallestValue);
}

//Tested
iPair *getSmallestAndSecondSmallestO2N(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		return new iPair(userInput[0],INT_MAX);
	}
	int smallestValue = userInput[0],secondSmallestValue = INT_MAX;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(smallestValue > userInput[counter]){
			smallestValue = userInput[counter];
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(secondSmallestValue> userInput[counter]){
			if(smallestValue != userInput[counter]){
				secondSmallestValue = userInput[counter];
			}
		}
	}
	return new iPair(smallestValue,secondSmallestValue);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
//Distinct
iPair *getSmallestAndSecondSmallestONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		return new iPair(userInput[0],INT_MAX);
	}
	sort(userInput.begin(),userInput.end());
	return new iPair(userInput[0],userInput[1]);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getSmallestAndSecondSmallestON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		iPair *result = new iPair();
		result->firstValue = userInput[0];
		result->secondValue = INT_MAX;
		return result;
	}
	unsigned int smallestValueIndex,secondSmallestValueIndex;
	bool isMin;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		isMin = true;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(innerCrawler != outerCrawler){
				if(userInput[outerCrawler] > userInput[innerCrawler]){
					isMin = false;
					break;
				}
			}
		}
		if(isMin){
			smallestValueIndex = outerCrawler;
		}
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		if(outerCrawler != smallestValueIndex){
			isMin = true;
			for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
				if(innerCrawler != outerCrawler && innerCrawler != smallestValueIndex){
					if(userInput[outerCrawler] > userInput[innerCrawler]){
						isMin = false;
						break;
					}
				}
			}
			if(isMin){
				secondSmallestValueIndex = outerCrawler;
			}
		}
	}
	return new iPair(userInput[smallestValueIndex],userInput[secondSmallestValueIndex]);
}

#endif /* SMALLESTSECONDSMALLEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
