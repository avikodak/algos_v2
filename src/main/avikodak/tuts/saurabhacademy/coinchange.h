/****************************************************************************************************************************************************
 *  File Name                   : coinchange.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\coinchange.h
 *  Created on                  : Oct 28, 2014 :: 7:27:02 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
unsigned int coinChange(vector<unsigned int> &availableDenominations,unsigned int amount) {
    if(amount == 0) {
        return 0;
    }
    unsigned int minNoOfNotes = UINT_MAX;
    unsigned int result;
    for(unsigned int counter = 0; counter < availableDenominations.size(); counter++) {
        if(availableDenominations[counter] <= amount) {
            result = coinChange(availableDenominations,amount-availableDenominations[counter]);
            if(result != UINT_MAX) {
                minNoOfNotes = 1 + min(minNoOfNotes,result);
            }
        }
    }
    return minNoOfNotes;
}

//Tested
unsigned int coinChangeMemoization(vector<unsigned int> availableDenominations,unsigned int amount) {
    if(amount == 0) {
        return 0;
    }
    static hash_map<unsigned int,unsigned int> amountMinCoinMap;
    hash_map<unsigned int,unsigned int>::iterator itToAmountMinCoinMap;
    unsigned int minCoins = UINT_MAX;
    unsigned int result;
    for(unsigned int counter = 0; counter < availableDenominations.size(); counter++) {
        if(amount >= availableDenominations[counter]) {
            if((itToAmountMinCoinMap = amountMinCoinMap.find(amount)) == amountMinCoinMap.end()) {
                result = coinChangeMemoization(availableDenominations,amount - availableDenominations[counter]);
                if(result != UINT_MAX) {
                    minCoins = 1 + min(minCoins,result);
                }
            } else {
                minCoins = min(minCoins,itToAmountMinCoinMap->second);
            }
        }
    }
    amountMinCoinMap.insert(pair<unsigned int,unsigned int>(amount,minCoins));
    return minCoins;
}

#endif /* COINCHANGE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
