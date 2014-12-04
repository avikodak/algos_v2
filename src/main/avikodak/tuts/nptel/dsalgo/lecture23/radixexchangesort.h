/****************************************************************************************************************************************************
 *  File Name   		: radixexchangesort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\radixexchangesort.h
 *  Created on			: Dec 2, 2014 :: 12:21:42 PM
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

#ifndef RADIXEXCHANGESORT_H_
#define RADIXEXCHANGESORT_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
void divideStepRadixSort(vector<int> &userInput,int bitposition){
	int startCrawler = 0,endCrawler = userInput.size()-1,temp;
	while(startCrawler < endCrawler){
		while(!(userInput[startCrawler]&1 << bitposition)){
			startCrawler++;
		}
		while(userInput[endCrawler] & 1 << bitposition){
			endCrawler--;
		}
		if(startCrawler < endCrawler){
			temp = userInput[startCrawler];
			userInput[startCrawler] = userInput[endCrawler];
			userInput[endCrawler] = temp;
		}
	}
	return endCrawler;
}

void radixExchangeSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int binaryDigits = log2(max_element(userInput.begin(),userInput.end())) + 1;
	for(int counter = binaryDigits-1;counter >= 0;counter++){
		divideStepRadixSort(userInput,counter);
	}
}

#endif /* RADIXEXCHANGESORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/