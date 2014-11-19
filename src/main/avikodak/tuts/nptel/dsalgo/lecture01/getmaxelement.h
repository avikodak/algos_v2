/****************************************************************************************************************************************************
 *  File Name   		: getmaxelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture01\getmaxelement.h
 *  Created on			: Oct 17, 2014 :: 2:59:35 PM
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
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GETMAXELEMENT_H_
#define GETMAXELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxElement(vector<int> userInput,unsigned int currentIndex = 0){
	if(currentIndex == userInput.size()-1){
		return userInput[currentIndex];
	}
	int temp;
	return userInput[currentIndex] > (temp = getMaxElement(userInput,currentIndex+1))?userInput[currentIndex]:temp;
}

//Tested
int getMaxElementIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int max = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(max < userInput[counter]){
			max = userInput[counter];
		}
	}
	return max;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	return userInput[userInput.size()-1];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	unsigned int outerCrawler = 0,innerCrawler;
	bool isMaxElement;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		isMaxElement = true;
		for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] > userInput[outerCrawler]){
				isMaxElement = false;
			}
		}
		if(isMaxElement){
			return userInput[outerCrawler];
		}
	}
	return INT_MAX;
}

#endif /* GETMAXELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
