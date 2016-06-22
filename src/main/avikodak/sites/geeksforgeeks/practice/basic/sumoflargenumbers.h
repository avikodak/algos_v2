/****************************************************************************************************************************************************
 *  File Name                   : sumoflargenumbers.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/sumoflargenumbers.h
 *  Created on                  : Jun 12, 2016 :: 2:07:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=852
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SUMOFLARGENUMBERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SUMOFLARGENUMBERS_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    int carry, fInputCrawler, sInputCrawler, sum;
    string fUserInput, sUserInput;
    stack<int> result;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> fUserInput >> sUserInput;
        fInputCrawler = fUserInput.size() - 1;
        sInputCrawler = sUserInput.size() - 1;
        carry = 0;
        while (fInputCrawler >= 0 && sInputCrawler >= 0) {
            sum = carry + fUserInput[fInputCrawler--] - '0' + sUserInput[sInputCrawler--] - '0';
            result.push(sum % 10);
            carry = sum / 10;
        }
        while (fInputCrawler >= 0) {
            sum = carry + fUserInput[fInputCrawler--] - '0';
            result.push(sum % 10);
            carry = sum / 10;
        }
        while (sInputCrawler >= 0) {
            sum = carry + sUserInput[sInputCrawler--] - '0';
            result.push(sum % 10);
            carry = sum / 10;
        }
        while (carry > 0) {
            result.push(carry % 10);
            carry /= 10;
        }
        while (!result.empty()) {
            printf("%d", result.top());
            result.pop();
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SUMOFLARGENUMBERS_H_ */
