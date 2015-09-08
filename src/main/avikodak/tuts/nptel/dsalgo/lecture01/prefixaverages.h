/****************************************************************************************************************************************************
 *  File Name   		: prefixaverages.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture01\prefixaverages.h
 *  Created on			: Oct 18, 2014 :: 12:38:07 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PREFIXAVERAGES_H_
#define PREFIXAVERAGES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getPrefixAveragesON(vector<int> userInput){
	vector<int> prefixAverages;
	if(userInput.size() == 0){
		return prefixAverages;
	}
	prefixAverages.push_back(userInput[0]);
	int runningSum = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		runningSum += userInput[counter];
		prefixAverages.push_back(runningSum/(counter+1));
	}
	return prefixAverages;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getPrefixAveragesON2(vector<int> userInput){
	vector<int> prefixAverages;
	if(userInput.size() == 0){
		return prefixAverages;
	}
	int sum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		sum = 0;
		for(unsigned int innerCrawler = 0;innerCrawler <= outerCrawler;innerCrawler++){
			sum += userInput[innerCrawler];
		}
		prefixAverages.push_back(sum/(outerCrawler+1));
	}
	return prefixAverages;
}

#endif /* PREFIXAVERAGES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
