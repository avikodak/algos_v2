/****************************************************************************************************************************************************
 *  File Name                   : lcs.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/lcs.h
 *  Created on                  : Aug 7, 2016 :: 7:21:04 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=152
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_LCS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_LCS_H_

//Tested
int longestCommonSubSequence(string firstInput, string secondInput) {
    int auxSpace[firstInput.size() + 1][secondInput.size() + 1];
    for (unsigned int outerCrawler = 0; outerCrawler <= firstInput.size(); outerCrawler++) {
        for (unsigned int innerCrawler = 0; innerCrawler <= secondInput.size(); innerCrawler++) {
            if (outerCrawler == 0 || innerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = 0;
            } else {
                if (firstInput[outerCrawler - 1] == secondInput[innerCrawler - 1]) {
                    auxSpace[outerCrawler][innerCrawler] = auxSpace[outerCrawler - 1][innerCrawler - 1] + 1;
                } else {
                    auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler - 1][innerCrawler], auxSpace[outerCrawler][innerCrawler - 1]);
                }
            }
        }
    }
    return auxSpace[firstInput.size()][secondInput.size()];
}

//Tested
void solveProblem() {
    unsigned int testCases, firstSize, secondSize;
    string firstInput, secondInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &firstSize, &secondSize);
        cin >> firstInput >> secondInput;
        printf("%d\n", longestCommonSubSequence(firstInput, secondInput));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_LCS_H_ */
