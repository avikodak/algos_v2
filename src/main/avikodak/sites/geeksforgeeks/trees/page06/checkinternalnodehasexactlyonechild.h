/****************************************************************************************************************************************************
 *  File Name   		: checkinternalnodehasexactlyonechild.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\checkinternalnodehasexactlyonechild.h
 *  Created on			: Nov 1, 2014 :: 6:58:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/
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

#ifndef CHECKINTERNALNODEHASEXACTLYONECHILD_H_
#define CHECKINTERNALNODEHASEXACTLYONECHILD_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkWhetherEachNodeHasExactlyOneChildON(vector<int> userInput){
	if(userInput.size() <= 2){
		return true;
	}
	int maxValue = max(userInput[userInput.size()-1],userInput[userInput.size()-2]);
	int minValue = min(userInput[userInput.size()-1],userInput[userInput.size()-2]);
	for(int counter = userInput.size()-3;counter >= 0;counter--){
		if(userInput[counter] > maxValue){
			maxValue = userInput[counter];
		}else if(userInput[counter] < minValue){
			minValue = userInput[counter];
		}else{
			return false;
		}
	}
	return true;
}

//Investigate
//Tested
bool checkWhetherEachNodeHasExactlySuccessor(vector<int> userInput){
	if(userInput.size() <= 2){
		return true;
	}
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if((userInput[counter] - userInput[counter+1]) * (userInput[counter] - userInput[userInput.size()-1]) < 0){
			return false;
		}
	}
	return true;
}
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkWhetherEachNodeHasExactlyOneChild(vector<int> userInput){
	if(userInput.size() <= 2){
		return true;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-2;outerCrawler++){
		bool isMax = userInput[outerCrawler] > userInput[outerCrawler+1];
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(isMax){
				if(userInput[innerCrawler] > userInput[outerCrawler]){
					return false;
				}
			}else{
				if(userInput[innerCrawler] < userInput[outerCrawler]){
					return false;
				}
			}
		}
	}
	return true;
}

#endif /* CHECKINTERNALNODEHASEXACTLYONECHILD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
