/****************************************************************************************************************************************************
 *  File Name                   : coinchange.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/coinchange.h
 *  Created on                  : Jul 23, 2016 :: 6:40:08 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=89
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_COINCHANGE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_COINCHANGE_H_

long long int totalWays(vector<long long int> userInput, long long int amount) {
    long long int memoization[amount + 1][userInput.size()];
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        memoization[counter][0] = 1;
    }
    long long int waysIncludingN, waysExcludingN;
    for (unsigned int rowCrawler = 0; rowCrawler < amount + 1; rowCrawler++) {
        for (unsigned int columnCrawler = 0; columnCrawler < userInput.size(); columnCrawler++) {
            waysIncludingN = (rowCrawler - userInput[columnCrawler]) > 0 ? memoization[rowCrawler - userInput[columnCrawler]][columnCrawler] : 0;
            waysExcludingN = columnCrawler > 0 ? userInput[rowCrawler][columnCrawler - 1] : 0;
            memoization[rowCrawler][columnCrawler] = waysExcludingN + waysIncludingN;
        }
    }
    return memoization[amount][userInput.size() - 1];
}

void solveProblem() {
    unsigned int testCases, size;
    long long int input, amount;
    vector<long long int> userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        userInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        scanf("%lld", &amount);
        printf("%lld\n", totalWays(userInput, amount));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_COINCHANGE_H_ */
