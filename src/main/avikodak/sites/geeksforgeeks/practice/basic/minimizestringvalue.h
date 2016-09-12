/****************************************************************************************************************************************************
 *  File Name                   : minimizestringvalue.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/minimizestringvalue.h
 *  Created on                  : Aug 14, 2016 :: 11:05:56 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=1304
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MINIMIZESTRINGVALUE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MINIMIZESTRINGVALUE_H_

void solveProblem() {
    unsigned int testCases, kValue;
    string input;
    long long int topValue, sum;
    scanf("%u", &testCases);
    priority_queue<long long int> auxSpace;
    while (testCases--) {
        cin >> input;
        scanf("%u", &kValue);
        long long int frequency[26] = { 0 };
        for (unsigned int counter = 0; counter < 26; counter++) {
            frequency[input[counter] - 26]++;
        }
        for (unsigned int counter = 0; counter < 26; counter++) {
            auxSpace.push(frequency[counter]);
        }
        while (kValue--) {
            topValue = auxSpace.top();
            auxSpace.pop();
            if (topValue > 0) {
                topValue--;
                auxSpace.push(topValue);
            }
        }
        while (!auxSpace.empty()) {
            sum = auxSpace.top() * auxSpace.top();
            auxSpace.pop();
        }
        printf("%lld\n", sum);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MINIMIZESTRINGVALUE_H_ */