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
