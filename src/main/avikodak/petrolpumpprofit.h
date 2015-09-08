/****************************************************************************************************************************************************
 *  File Name   		: petrolpumpprofit.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\petrolpumpprofit.h
 *  Created on			: Feb 4, 2015 :: 12:56:22 PM
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

#ifndef PETROLPUMPPROFIT_H_
#define PETROLPUMPPROFIT_H_

void calculateProfit(vector < int > prices) {
    int maxTillNow = prices.size() - 1,maxProfit = 0,buy,sell;
    for(int counter = prices.size()-2;counter >= 0;counter--){
        if(prices[counter] < prices[maxTillNow]){
            if(maxProfit < prices[maxTillNow] - prices[counter]){
                maxProfit = prices[maxTillNow] - prices[counter];
                buy = counter;
                sell = maxTillNow;
            }
        }else{
            maxTillNow = counter;
        }
    }
    printf("%d %d\n",buy+1,prices[buy]);
    printf("%d %d\n",sell+1,prices[sell]);
}

#endif /* PETROLPUMPPROFIT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
