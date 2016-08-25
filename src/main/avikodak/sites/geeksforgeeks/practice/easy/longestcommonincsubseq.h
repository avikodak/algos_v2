/****************************************************************************************************************************************************
 *  File Name                   : longestcommonincsubseq.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/longestcommonincsubseq.h
 *  Created on                  : Aug 8, 2016 :: 1:04:46 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=913
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
#include <limits.h>
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LONGESTCOMMONINCSUBSEQ_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LONGESTCOMMONINCSUBSEQ_H_

int longestCommonIncreasingSubSequece(vector<int> firstUserInput, vector<int> secondUserInput) {
    int auxSpace[firstUserInput.size() + 1][secondUserInput.size() + 1];
    int maxIncCommonLength = 0;
    for (unsigned int outerCrawler = 0; outerCrawler < firstUserInput.size(); outerCrawler++) {
        for (unsigned int innerCrawler = 0; innerCrawler < secondUserInput.size(); innerCrawler++) {
            if (outerCrawler == 0 || innerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = 0;
            } else {
                if (firstUserInput[outerCrawler] == secondUserInput[innerCrawler] && firstUserInput[outerCrawler - 1] < firstUserInput[outerCrawler]) {
                    auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler - 1][innerCrawler - 1];
                } else {
                    auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler - 1][innerCrawler], auxSpace[outerCrawler][innerCrawler]);
                }
            }
            maxIncCommonLength = max(maxIncCommonLength, auxSpace[outerCrawler][innerCrawler]);
        }
    }
    return maxIncCommonLength;
}

void solveProblem() {
    unsigned int testCases, size;
    int input;
    vector<int> firstUserInput, secondUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        firstUserInput.clear();
        secondUserInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%d", &input);
            firstUserInput.push_back(input);
        }
        scanf("%u", &size);
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%d", &input);
            firstUserInput.push_back(input);
        }
        printf("%d\n", longestCommonIncreasingSubSequece(firstUserInput, secondUserInput));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LONGESTCOMMONINCSUBSEQ_H_ */
