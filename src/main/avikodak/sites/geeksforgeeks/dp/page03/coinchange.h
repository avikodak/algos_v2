/****************************************************************************************************************************************************
 *  File Name   		: coinchange.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\coinchange.h
 *  Created on			: Jan 14, 2015 :: 8:53:41 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
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

#ifndef COINCHANGE_H_
#define COINCHANGE_H_

//Tested
int coinChange(vector<int> denominations,unsigned int currentIndex,int amount){
	if(amount < 0){
		return 0;
	}
	if(amount == 0){
		return 1;
	}
	if(currentIndex == denominations.size()){
		return amount == 0;
	}
	return coinChange(denominations,currentIndex+1,amount) + coinChange(denominations,currentIndex,amount - denominations[currentIndex]);
}

//Tested
int coinChangeMemoization(vector<int> denominations,int amount){
	if(amount == 0){
		return 0;
	}
	vector<int> auxSpace(amount+1,0);
	auxSpace[0] = 1;
	for(unsigned int coinCounter = 0;coinCounter < denominations.size();coinCounter++){
		for(int amountCounter = denominations[coinCounter];amountCounter <= amount;amountCounter++){
			auxSpace[amountCounter] += auxSpace[amountCounter - denominations[coinCounter]];
		}
	}
	return auxSpace[auxSpace.size()-1];
}

#endif /* COINCHANGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
