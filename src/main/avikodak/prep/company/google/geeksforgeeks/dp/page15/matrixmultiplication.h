/****************************************************************************************************************************************************
 *  File Name                   : matrixmultiplication.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/matrixmultiplication.h
 *  Created on                  : Mar 18, 2017 :: 10:25:28 AM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_MATRIXMULTIPLICATION_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_MATRIXMULTIPLICATION_H_

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
int minMatrixMultiplicationOperationAuxSpace(vector<int> dimensions) {
    vector<vector<int> > auxSpace(dimensions.size());
    for (unsigned int counter = 0; counter < dimensions.size(); counter++) {
        auxSpace[counter].assign(dimensions.size(), 0);
    }
    for (unsigned int length = 2; length < dimensions.size(); length++) {
        for (unsigned int startIndex = 0; startIndex < dimensions.size() - length + 1; startIndex++) {
            unsigned int endIndex = startIndex + length - 1;
            int minOperations = INT_MAX;
            for (unsigned int kIndex = startIndex; kIndex < endIndex; kIndex) {
                minOperations = min(minOperations,
                                    auxSpace[startIndex][kIndex] + auxSpace[kIndex + 1][endIndex] + dimensions[startIndex] * dimensions[kIndex] * dimensions[endIndex]);
            }
        }
    }
    return auxSpace[dimensions.size() - 1][dimensions.size() - 1];
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int minMatrixMultiplicationOperations(vector<int> dimensions, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        return 0;
    }
    if (startIndex > endIndex) {
        return INT_MAX;
    }
    int minOperations = INT_MAX;
    for (unsigned int counter = startIndex; counter <= endIndex; counter++) {
        minOperations = min(
                minOperations,
                minMatrixMultiplicationOperations(dimensions, startIndex, counter) + minMatrixMultiplicationOperations(dimensions, counter + 1, endIndex)
                        + dimensions[startIndex] * dimensions[counter] * dimensions[endIndex]);
    }
    return minOperations;
}

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_MATRIXMULTIPLICATION_H_ */
