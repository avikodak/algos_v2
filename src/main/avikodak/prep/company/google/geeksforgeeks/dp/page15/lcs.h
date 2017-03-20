/****************************************************************************************************************************************************
 *  File Name                   : lcs.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/lcs.h
 *  Created on                  : Mar 12, 2017 :: 7:33:58 PM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LCS_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LCS_H_

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
int longestCommonSubSequence(string firstUserInput, string secondUserInput) {
    vector<vector<int> > auxSpace(firstUserInput + 1);
    for (unsigned int counter = 0; counter < firstUserInput.size() + 1; counter++) {
        auxSpace[counter].resize(secondUserInput.size() + 1);
    }
    int maxLCSLength = 0;
    for (unsigned int outerCrawler = 0; outerCrawler <= firstUserInput.size(); outerCrawler++) {
        for (unsigned int innerCrawler = 0; innerCrawler <= secondUserInput.size(); innerCrawler++) {
            if (outerCrawler == 0 || innerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = 0;
            } else if (firstUserInput[outerCrawler - 1] == secondUserInput[innerCrawler - 1]) {
                auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler - 1][innerCrawler - 1];
            } else {
                auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler][innerCrawler - 1], auxSpace[outerCrawler - 1][innerCrawler]);
            }
        }
    }
    return maxLCSLength;
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int longestCommonSubSequence(string firstUserInput, string secondUserInput, int firstIndex, int secondIndex) {
    if (firstIndex >= firstUserInput.size() || secondIndex >= secondUserInput.size()) {
        return 0;
    }
    if (firstUserInput[firstIndex] == secondUserInput[secondIndex]) {
        return 1 + longestCommonSubSequence(firstUserInput, secondUserInput, firstIndex + 1, secondIndex + 1);
    } else {
        return max(longestCommonSubSequence(firstUserInput, secondUserInput, firstIndex + 1, secondIndex),
                   longestCommonSubSequence(firstUserInput, secondUserInput, firstIndex, secondIndex + 1));
    }
}
#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LCS_H_ */
