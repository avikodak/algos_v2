/****************************************************************************************************************************************************
 *  File Name                   : maxsumsubarray.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/dp/page05/maxsumsubarray.h
 *  Created on                  : Feb 7, 2016 :: 12:56:35 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE05_MAXSUMSUBARRAY_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE05_MAXSUMSUBARRAY_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getMaxSumSubarray(int userInput[],int size) {
    if(size == 0) {
        return 0;
    }
    int maxSum = userInput[0],currentSum = userInput[0];
    for(unsigned int counter = 1; counter < size; counter++) {
        currentSum = max(userInput[counter],userInput[counter]+currentSum);
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getMaxSumSubarrayON2(int userInput[],int size) {
    if(size == 0) {
        return 0;
    }
    int maxSum = INT_MIN,currentSum;
    for(unsigned int outerCrawler = 0; outerCrawler < size; outerCrawler++) {
        currentSum = 0;
        for(unsigned int innerCrawler = outerCrawler; innerCrawler < size; innerCrawler++) {
            currentSum += userInput[innerCrawler];
            maxSum = max(maxSum,currentSum);
        }
    }
    return maxSum;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE05_MAXSUMSUBARRAY_H_ */
