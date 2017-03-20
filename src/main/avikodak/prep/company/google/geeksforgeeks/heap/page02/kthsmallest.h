/****************************************************************************************************************************************************
 *  File Name                   : kthsmallest.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/heap/page02/kthsmallest.h
 *  Created on                  : Mar 8, 2017 :: 10:30:07 PM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_KTHSMALLEST_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_KTHSMALLEST_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int partitionArray(vector<int> userInput, int startIndex, int endIndex) {
    int fillCounter = startIndex;
    for (unsigned int counter = startIndex; counter < endIndex; counter++) {
        if (userInput[counter] < userInput[endIndex]) {
            userInput[fillCounter++];
        }
    }
    swap(userInput[fillCounter], userInput[endIndex]);
    return fillCounter;
}

int kthOrderStatistics(vector<int> userInput, int startIndex, int endIndex, int kValue) {
    if (kValue <= 0 || kValue >= endIndex - startIndex - 1) {
        return INT_MIN;
    }
    int partitionedIndex = partitionArray(userInput, startIndex, endIndex);
    if (partitionedIndex - startIndex == kValue - 1) {
        return userInput[partitionedIndex];
    } else if (partitionedIndex - startIndex > kValue - 1) {
        return kthOrderStatistics(userInput, startIndex, partitionedIndex - 1, kValue);
    } else {
        return kthOrderStatistics(userInput, partitionedIndex + 1, endIndex, kValue - partitionedIndex + startIndex - 1);
    }
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_KTHSMALLEST_H_ */
