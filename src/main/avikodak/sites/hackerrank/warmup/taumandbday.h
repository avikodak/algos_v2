/****************************************************************************************************************************************************
 *  File Name                   : taumandbday.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\taumandbday.h
 *  Created on                  : Mar 10, 2015 :: 9:39:03 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/taum-and-bday
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

#ifndef TAUMANDBDAY_H_
#define TAUMANDBDAY_H_

//Tested
void getMinAmountForGifts() {
    unsigned int testCases;
    long long int costOfBlackGift,costOfWhiteGift,transferCost,numberOfBlackGifts,numberOfWhiteGifts,totalCost;
    scanf("%u",&testCases);
    while(testCases--) {
        cin >> numberOfBlackGifts >> numberOfWhiteGifts >> costOfBlackGift >> costOfWhiteGift >> transferCost;
        totalCost = 0;
        if(costOfBlackGift < costOfWhiteGift) {
            totalCost += (numberOfBlackGifts * costOfBlackGift);
            if(costOfWhiteGift < costOfBlackGift + transferCost) {
                totalCost += (numberOfWhiteGifts * costOfWhiteGift);
            } else {
                totalCost += (numberOfWhiteGifts * (costOfBlackGift+transferCost));
            }
        } else {
            totalCost += numberOfWhiteGifts * costOfWhiteGift;
            if(costOfBlackGift < costOfWhiteGift + transferCost) {
                totalCost += (numberOfBlackGifts * costOfBlackGift);
            } else {
                totalCost += (numberOfBlackGifts * (costOfWhiteGift+transferCost));
            }
        }
        cout << totalCost << endl;
    }
}

#endif /* TAUMANDBDAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
