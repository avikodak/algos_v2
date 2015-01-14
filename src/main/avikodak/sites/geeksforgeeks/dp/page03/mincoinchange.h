/****************************************************************************************************************************************************
 *  File Name   		: coinchange.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\coinchange.h
 *  Created on			: Dec 9, 2014 :: 8:01:55 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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

#ifndef MINCOINCHANGE_H_
#define MINCOINCHANGE_H_

//Tested
int minCoinChangeMemoization(vector<int> denominations,int amount){
	if(amount < 0){
		return INT_MAX;
	}
	if(amount == 0){
		return 0;
	}
	vector<int> minDenominations(amount+1,0);
	int minChange;
	for(unsigned int outerCralwer = 1;outerCralwer < minDenominations.size();outerCralwer++){
		minChange = INT_MAX;
		for(unsigned int innerCrawler = 0;innerCrawler < denominations.size();innerCrawler++){
			if(amount >= denominations[innerCrawler]){
				minChange = min(minChange,1+minDenominations[amount-denominations[innerCrawler]]);
			}
		}
		minDenominations[outerCralwer] = minChange;
	}
	return minDenominations[minDenominations.size()-1];
}

//Tested
int minCoinChange(vector<int> denominations,int amount){
	if(amount < 0){
		return INT_MAX;
	}
	if(amount == 0){
		return 0;
	}
	int minCoins = INT_MAX,result;;
	for(unsigned int counter = 0;counter < denominations.size();counter++){
		if(denominations[counter] <= amount){
			result = minCoinChange(denominations,amount-denominations[counter]);
			if(result != INT_MAX){
				minCoins = min(minCoins,1+result);
			}
		}
	}
	return minCoins;
}

#endif /* MINCOINCHANGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
