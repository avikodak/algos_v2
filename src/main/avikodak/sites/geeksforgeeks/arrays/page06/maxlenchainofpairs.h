/****************************************************************************************************************************************************
 *  File Name   		: maxlenchainofpairs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\maxlenchainofpairs.h
 *  Created on			: Dec 1, 2014 :: 3:30:35 PM
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

#ifndef MAXLENCHAINOFPAIRS_H_
#define MAXLENCHAINOFPAIRS_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

int getMaxLengthChainOfPairsONLOGN(vector<iPair *> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	if(userInput.size() == 1){
		return 1;
	}
	vector<int> activeLists;

	return activeLists.size();
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool sortFuncChain(iPair *firstPair,iPair *secondPair){
	return firstPair->firstValue > secondPair->firstValue?firstPair:secondPair;
}

int getMaxLengthChainOfPairs(vector<iPair *> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	if(userInput.size() == 1){
		return 1;
	}
	vector<int> lengths;
	lengths.push_back(1);
	int maxLength;
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		maxLength = 1;
		for(unsigned int innerCrawler = 0;innerCrawler < outerCrawler;innerCrawler++){
			if(userInput[outerCrawler]->firstValue > userInput[innerCrawler]->secondValue){
				maxLength  = max(maxLength,lengths[innerCrawler]);
			}
		}
		lengths.push_back(maxLength);
	}
	return userInput[userInput.size()-1];
}

int maxLengthChainOfPairs(vector<iPair *> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	sort(userInput.begin(),userInput.end(),sortFuncChain);

}

#endif /* MAXLENCHAINOFPAIRS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
