/****************************************************************************************************************************************************
 *  File Name   		: checkinternalnodehasexactlyonechild.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\checkinternalnodehasexactlyonechild.h
 *  Created on			: Nov 1, 2014 :: 6:58:16 PM
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
