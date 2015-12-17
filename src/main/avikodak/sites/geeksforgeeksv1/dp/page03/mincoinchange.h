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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

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
