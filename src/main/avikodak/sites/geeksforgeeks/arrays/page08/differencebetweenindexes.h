/****************************************************************************************************************************************************
 *  File Name   		: differencebetweenindexes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\differencebetweenindexes.h
 *  Created on			: Dec 1, 2014 :: 11:14:19 AM
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

#ifndef DIFFERENCEBETWEENINDEXES_H_
#define DIFFERENCEBETWEENINDEXES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxIJIndexAuxspace(vector<int> userInput){
	if(userInput.size() < 1){
		return 0;
	}
	vector<int> lMin,rMax;
	lMin.push_back(userInput[0]);
	rMax.reserve(userInput.size());
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		lMin.push_back(userInput[counter],lMin[counter-1]);
	}
	rMax[userInput.size()-1] = userInput[userInput.size()-1];
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rMax[counter] = max(userInput[counter],rMax[counter+1]);
	}
	int maxDistance = 0;
	int firstCrawler = 0,secondCrawler = 0;
	while(firstCrawler < secondCrawler){
		if(lMin[firstCrawler] < rMax[secondCrawler]){
			maxDistance = max(maxDistance,secondCrawler-firstCrawler);
			secondCrawler++;
		}else{
			firstCrawler++;
		}
	}
	return maxDistance;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxIJIndexesON2(vector<int> userInput){
	if(userInput.size() < 1){
		return 0;
	}
	unsigned int maxDiffIndex = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] > userInput[outerCrawler]){
				maxDiffIndex = max(maxDiffIndex,innerCrawler - outerCrawler);
			}
		}
	}
	return maxDiffIndex;
}

#endif /* DIFFERENCEBETWEENINDEXES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
