/****************************************************************************************************************************************************
 *  File Name                   : coinchange.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/coinchange.h
 *  Created on                  : Mar 15, 2017 :: 10:15:40 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_COINCHANGE_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_COINCHANGE_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int totalCoinChangeOn2Auxspace(vector<int> denominations, int amount) {
    vector<vector<int> > auxSpace(amount + 1);
    for (unsigned int counter = 0; counter <= amount; counter++) {
        auxSpace[counter].assign(denominations.size(), 0);
    }
    for (unsigned int counter = 0; counter < denominations.size(); counter++) {
        auxSpace[0][counter] = 1;
    }
    int coinsIncludingDenomination, coinsExcludingDenomination;
    for (unsigned int rowCounter = 0; rowCounter <= amount; rowCounter++) {
        for (unsigned int columnCounter = 0; columnCounter < denominations.size(); columnCounter++) {
            coinsIncludingDenomination = rowCounter - denominations[columnCounter] >= 0 ? auxSpace[rowCounter - denominations[columnCounter]][columnCounter] : 0;
            coinsExcludingDenomination = columnCounter > 0 ? auxSpace[rowCounter][columnCounter - 1] : 0;
            auxSpace[rowCounter][columnCounter] = coinsIncludingDenomination + coinsExcludingDenomination;
        }
    }
    return auxSpace[amount][denominations.size() - 1];
}

int totalCoinChange(vector<int> denominations, int amount) {
    vector<int> totalCoins;
    totalCoins.assign(amount + 1, 0);
    totalCoins[0] = 1;
    for (unsigned int outerCounter = 0; outerCounter < denominations.size(); outerCounter++) {
        for (unsigned int innerCounter = denominations[outerCounter]; innerCounter <= amount; innerCounter++) {
            totalCoins[innerCounter] += totalCoins[innerCounter - denominations[outerCounter]];
        }
    }
    return totalCoins[amount];
}
/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_COINCHANGE_H_ */
