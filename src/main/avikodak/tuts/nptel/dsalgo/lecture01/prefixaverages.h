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
