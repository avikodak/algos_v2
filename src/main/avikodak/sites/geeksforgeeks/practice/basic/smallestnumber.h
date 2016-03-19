/****************************************************************************************************************************************************
 *  File Name                   : smallestnumber.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/smallestnumber.h
 *  Created on                  : Aug 7, 2016 :: 12:23:21 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=826
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SMALLESTNUMBER_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SMALLESTNUMBER_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int sum, noOfDigits, topDigit;
    scanf("%u", &testCases);
    stack<int> digits;
    while (testCases--) {
        scanf("%lld %lld", &sum, &noOfDigits);
        if (noOfDigits * 9 < sum) {
            printf("-1\n");
        } else {
            sum -= 1;
            for (unsigned int counter = 0; counter < noOfDigits; counter++) {
                if (sum > 9) {
                    digits.push(9);
                    sum -= 9;
                } else {
                    digits.push(sum);
                    sum = 0;
                }
            }
            topDigit = digits.top();
            digits.pop();
            digits.push(topDigit + 1);
            while (!digits.empty()) {
                printf("%d", digits.top());
                digits.pop();
            }
            printf("\n");
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SMALLESTNUMBER_H_ */
