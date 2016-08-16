/****************************************************************************************************************************************************
 *  File Name                   : maxsumincreasingsubsequence.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/maxsumincreasingsubsequence.h
 *  Created on                  : Aug 7, 2016 :: 7:35:44 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=494
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXSUMINCREASINGSUBSEQUENCE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXSUMINCREASINGSUBSEQUENCE_H_

//Tested
void solveProblem() {
    unsigned int testCases, size;
    long long int input, maxCurrentSum, maxSum;
    vector<long long int> userInput;
    vector<long long int> auxSpace;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        userInput.clear();
        auxSpace.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        auxSpace.push_back(userInput[0]);
        maxSum = userInput[0];
        for (unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
            maxCurrentSum = userInput[outerCrawler];
            for (unsigned int innerCrawler = 0; innerCrawler < outerCrawler; innerCrawler++) {
                if (userInput[innerCrawler] < userInput[outerCrawler]) {
                    maxCurrentSum = max(maxCurrentSum, auxSpace[innerCrawler] + userInput[outerCrawler]);
                }
            }
            auxSpace.push_back(maxCurrentSum);
            maxSum = max(maxSum, maxCurrentSum);
        }
        printf("%lld\n", maxSum);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXSUMINCREASINGSUBSEQUENCE_H_ */
