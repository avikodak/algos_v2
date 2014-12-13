/****************************************************************************************************************************************************
 *  File Name   		: minelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture05\minelement.h
 *  Created on			: Dec 12, 2014 :: 11:51:54 AM
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

#ifndef MINELEMENT_H_
#define MINELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int minElementON(vector<int> userInput,unsigned int currentIndex = 0){
	if(currentIndex >= userInput.size()){
		return INT_MAX;
	}
	return min(userInput[currentIndex],minElementON(userInput,currentIndex+1));
}

int minElementIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int minElement = INT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		minElement = min(minElement,userInput[counter]);
	}
	return minElement;
}

int minElementDAD(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(startIndex  == endIndex){
		return startIndex;
	}
	if(endIndex - startIndex == 1){
		return min(userInput[startIndex],userInput[endIndex]);
	}
	int middleIndex = (startIndex + endIndex)/2;
	return min(minElementDAD(userInput,startIndex,middleIndex),minElementDAD(userInput,middleIndex+1,endIndex));
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int minElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	return userInput[0];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int minElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int minElement;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		minElement = userInput[outerCrawler];
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			minElement = min(minElement,userInput[innerCrawler]);
		}
		if(minElement == userInput[outerCrawler]){
			return minElement;
		}
	}
	return INT_MIN;
}

#endif /* MINELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
