/****************************************************************************************************************************************************
 *  File Name                   : coinchange.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\coinchange.h
 *  Created on                  : Jan 14, 2015 :: 8:53:41 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef COINCHANGE_H_
#define COINCHANGE_H_

//Tested
int coinChange(vector<int> denominations,unsigned int currentIndex,int amount) {
    if(amount < 0) {
        return 0;
    }
    if(amount == 0) {
        return 1;
    }
    if(currentIndex == denominations.size()) {
        return amount == 0;
    }
    return coinChange(denominations,currentIndex+1,amount) + coinChange(denominations,currentIndex,amount - denominations[currentIndex]);
}

//Tested
int coinChangeMemoization(vector<int> denominations,int amount) {
    if(amount == 0) {
        return 0;
    }
    vector<int> auxSpace(amount+1,0);
    auxSpace[0] = 1;
    for(unsigned int coinCounter = 0; coinCounter < denominations.size(); coinCounter++) {
        for(int amountCounter = denominations[coinCounter]; amountCounter <= amount; amountCounter++) {
            auxSpace[amountCounter] += auxSpace[amountCounter - denominations[coinCounter]];
        }
    }
    return auxSpace[auxSpace.size()-1];
}

#endif /* COINCHANGE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
