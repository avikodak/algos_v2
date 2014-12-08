/****************************************************************************************************************************************************
 *  File Name   		: span.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\span.h
 *  Created on			: Oct 18, 2014 :: 1:16:32 PM
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

#ifndef SPAN_H_
#define SPAN_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getSpansOfStockON(vector<int> userInput){
	vector<int> stockSpans;
	if(userInput.size() == 0){
		return stockSpans;
	}
	stockSpans.push_back(INT_MIN);
	stack<int> auxSpace;
	auxSpace.push(userInput[0]);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		while(!auxSpace.empty() && userInput[auxSpace.top()] < userInput[counter]){
			auxSpace.pop();
		}
		stockSpans.push_back(auxSpace.empty()?INT_MIN:counter - auxSpace.top());
		auxSpace.push(counter);
	}
	return stockSpans;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getSpansOfStockON2(vector<int> userInput){
	vector<int> stockSpans;
	if(userInput.size() == 0){
		return stockSpans;
	}
	stockSpans.push_back(INT_MIN);
	int innerCrawler;
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		for(innerCrawler = outerCrawler;innerCrawler >= 0;innerCrawler--){
			if(userInput[innerCrawler] > userInput[outerCrawler]){
				stockSpans.push_back(outerCrawler - innerCrawler);
				break;
			}
		}
		if(innerCrawler < 0){
			stockSpans.push_back(INT_MIN);
		}
	}
	return stockSpans;
}

#endif /* SPAN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
