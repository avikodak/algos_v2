/****************************************************************************************************************************************************
 *  File Name                   : editdistance.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/editdistance.h
 *  Created on                  : Mar 12, 2017 :: 7:55:11 PM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_EDITDISTANCE_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_EDITDISTANCE_H_

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
int getEditDistanceMemoization(string firstInput, string secondInput) {
    if (firstInput == 0) {
        return secondInput.size();
    }
    if (secondInput == 0) {
        return firstInput.size();
    }
    int auxSpace[firstInput.size() + 1][secondInput.size() + 1];
    memset(auxSpace, 0, sizeof(int) * (firstInput.size() + 1) * (secondInput.size() + 1));
    for (unsigned int outerCrawler = 0; outerCrawler < firstInput.size() + 1; outerCrawler++) {
        for (unsigned int innerCrawler = 0; innerCrawler < secondInput.size() + 1; innerCrawler++) {
            if (outerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = innerCrawler;
            } else if (innerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = outerCrawler;
            } else if (firstInput[outerCrawler - 1] == secondInput[innerCrawler - 1]) {
                auxSpace[outerCrawler][innerCrawler] = auxSpace[outerCrawler - 1][innerCrawler - 1];
            } else {
                auxSpace[outerCrawler][innerCrawler] = min(auxSpace[outerCrawler][innerCrawler - 1],
                                                           min(auxSpace[outerCrawler - 1][innerCrawler], auxSpace[outerCrawler - 1][innerCrawler - 1]));
            }
        }
    }
    return auxSpace[firstInput.size()][secondInput.size()];
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getEditDistance(string firstInput, string secondInput, int firstIndex, int secondIndex) {
    if (firstIndex >= firstInput.size()) {
        return secondInput.size() - secondIndex;
    }
    if (secondIndex >= secondInput.size()) {
        return firstInput.size() - firstIndex;
    }
    if (firstInput[firstIndex] == secondInput[secondIndex]) {
        return getEditDistance(firstInput, secondInput, firstIndex + 1, secondIndex + 1);
    } else {
        return min(getEditDistance(firstInput, secondInput, firstIndex + 1, secondIndex),
                   min(getEditDistance(firstInput, secondInput, firstIndex + 1, secondIndex + 1), getEditDistance(firstInput, secondInput, firstIndex, secondIndex + 1)));
    }
}
#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_EDITDISTANCE_H_ */
