/****************************************************************************************************************************************************
 *  File Name   		: coinchange.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\coinchange.h
 *  Created on			: Oct 28, 2014 :: 7:27:02 PM
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

#ifndef COINCHANGE_H_
#define COINCHANGE_H_

//Tested
unsigned int coinChange(vector<unsigned int> &availableDenominations,unsigned int amount){
	if(amount == 0){
		return 0;
	}
	unsigned int minNoOfNotes = UINT_MAX;
	unsigned int result;
	for(unsigned int counter = 0;counter < availableDenominations.size();counter++){
		if(availableDenominations[counter] <= amount){
			result = coinChange(availableDenominations,amount-availableDenominations[counter]);
			if(result != UINT_MAX){
				minNoOfNotes = 1 + min(minNoOfNotes,result);
			}
		}
	}
	return minNoOfNotes;
}

//Tested
unsigned int coinChangeMemoization(vector<unsigned int> availableDenominations,unsigned int amount){
	if(amount == 0){
		return 0;
	}
	static hash_map<unsigned int,unsigned int> amountMinCoinMap;
	hash_map<unsigned int,unsigned int>::iterator itToAmountMinCoinMap;
	unsigned int minCoins = UINT_MAX;
	unsigned int result;
	for(unsigned int counter = 0;counter < availableDenominations.size();counter++){
		if(amount >= availableDenominations[counter]){
			if((itToAmountMinCoinMap = amountMinCoinMap.find(amount)) == amountMinCoinMap.end()){
				result = coinChangeMemoization(availableDenominations,amount - availableDenominations[counter]);
				if(result != UINT_MAX){
					minCoins = 1 + min(minCoins,result);
				}
			}else{
				minCoins = min(minCoins,itToAmountMinCoinMap->second);
			}
		}
	}
	amountMinCoinMap.insert(pair<unsigned int,unsigned int>(amount,minCoins));
	return minCoins;
}

#endif /* COINCHANGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
