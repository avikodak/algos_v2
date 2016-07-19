/****************************************************************************************************************************************************
 *  File Name                   : sumoftwonumbersarrays.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/sumoftwonumbersarrays.h
 *  Created on                  : Jul 5, 2016 :: 6:22:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=506
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SUMOFTWONUMBERSARRAYS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SUMOFTWONUMBERSARRAYS_H_

//Tested
void solveProblem() {
    unsigned int testCases, fSize, sSize;
    long long int input, carry, sum, fCrawler, sCrawler;
    vector<long long int> fUserInput, sUserInput;
    stack<long long int> auxSpace;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &fSize, &sSize);
        fUserInput.clear();
        sUserInput.clear();
        for (unsigned int counter = 0; counter < fSize; counter++) {
            scanf("%lld", &input);
            fUserInput.push_back(input);
        }
        for (unsigned int counter = 0; counter < sSize; counter++) {
            scanf("%lld", &input);
            sUserInput.push_back(input);
        }
        carry = 0;
        sum = 0;
        fCrawler = fSize - 1;
        sCrawler = sSize - 1;
        while (fCrawler >= 0 || sCrawler >= 0) {
            if (sCrawler < 0) {
                sum = fUserInput[fCrawler--] + carry;
            } else if (fCrawler < 0) {
                sum = sUserInput[sCrawler--] + carry;
            } else {
                sum = fUserInput[fCrawler--] + sUserInput[sCrawler--] + carry;
            }
            auxSpace.push(sum % 10);
            carry = sum / 10;
        }
        while (carry) {
            auxSpace.push(carry % 10);
            carry /= 10;
        }
        while (!auxSpace.empty()) {
            printf("%lld ", auxSpace.top());
            auxSpace.pop();
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SUMOFTWONUMBERSARRAYS_H_ */
