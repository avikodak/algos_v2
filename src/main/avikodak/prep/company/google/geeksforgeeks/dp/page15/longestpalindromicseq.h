/****************************************************************************************************************************************************
 *  File Name                   : longestpalindromicseq.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page15/longestpalindromicseq.h
 *  Created on                  : Mar 13, 2017 :: 12:21:27 AM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LONGESTPALINDROMICSEQ_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LONGESTPALINDROMICSEQ_H_

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
int getLongestPalindromicSequenceMemoization(string userInput) {
    int auxSpace[userInput.size()][userInput.size()] = { 0 };
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter][counter] = 1;
    }
    int maxLength = 0;
    for (unsigned int frontCrawler = 0; frontCrawler < userInput.size(); frontCrawler++) {
        for (unsigned int rearCrawler = frontCrawler + 1; rearCrawler < userInput.size(); rearCrawler++) {
            if (userInput[frontCrawler] == userInput[rearCrawler]) {
                auxSpace[frontCrawler][rearCrawler] = 2 + auxSpace[frontCrawler + 1][rearCrawler - 1];
            } else {
                auxSpace[frontCrawler][rearCrawler] = max(auxSpace[frontCrawler + 1][rearCrawler], auxSpace[frontCrawler][rearCrawler - 1]);
            }
            maxLength = max(maxLength, auxSpace[frontCrawler][rearCrawler]);
        }
    }
    return maxLength;
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getLongestPalindromicSequence(string userInput, int frontCrawler, int rearCrawler) {
    if (frontCrawler >= rearCrawler) {
        return frontCrawler == rearCrawler;
    }
    if (userInput[frontCrawler] == userInput[rearCrawler]) {
        return 2 + getLongestPalindromicSequence(userInput, frontCrawler + 1, rearCrawler - 1);
    } else {
        return max(getLongestPalindromicSequence(userInput, frontCrawler + 1, rearCrawler), getLongestPalindromicSequence(userInput, frontCrawler, rearCrawler - 1));
    }
}
#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE15_LONGESTPALINDROMICSEQ_H_ */
