/****************************************************************************************************************************************************
 *  File Name                   : knapsackproblem.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/knapsackproblem.h
 *  Created on                  : Mar 18, 2017 :: 12:36:13 PM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_KNAPSACKPROBLEM_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_KNAPSACKPROBLEM_H_

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
int getMaxKnapsackValueON2(vector<int> weights, vector<int> value, int maxWeight) {
    vector<vector<int> > auxSpace(weights.size());
    for (unsigned int counter = 0; counter < weights.size(); counter++) {
        auxSpace[counter].assign(0, maxWeight + 1);
    }
    for (unsigned int weightCounter = 0; weightCounter < weights.size(); weightCounter++) {
        for (unsigned int weight = 0; weight <= maxWeight; weight++) {
            int maxValue = 0;
            if (weight <= weights[weightCounter]) {
                maxValue = max(maxValue, value[weightCounter] + auxSpace[weightCounter - 1][weight - weights[weightCounter]]);
            }
            if (weightCounter > 0) {
                maxValue = max(maxValue, auxSpace[weightCounter - 1][weight]);
            }
            auxSpace[weightCounter][weight] = maxValue;
        }
    }
    return auxSpace[weights.size()][maxWeight];
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getMaxKnapsackValue(vector<int> weight, vector<int> value, int maxWeight, int index) {
    if (index > weight.size()) {
        return INT_MIN;
    }
    if (maxWeight == 0) {
        return 0;
    }
    int maxValue = INT_MIN;
    if (weight[index] <= maxWeight) {
        maxValue = max(maxValue, getMaxKnapsackValue(weight, value, maxWeight - weight[index], index + 1));
    }
    maxValue = max(maxValue, getMaxKnapsackValue(weight, value, maxWeight, index + 1));
    return maxValue;
}

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_KNAPSACKPROBLEM_H_ */
