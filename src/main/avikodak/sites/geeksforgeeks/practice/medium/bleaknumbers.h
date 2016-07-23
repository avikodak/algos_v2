/****************************************************************************************************************************************************
 *  File Name                   : bleaknumbers.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/bleaknumbers.h
 *  Created on                  : Jul 23, 2016 :: 9:32:16 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=796
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_BLEAKNUMBERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_BLEAKNUMBERS_H_

//Tested
unsigned int getSetBitCount(long long int userInput) {
    if (userInput == 0) {
        return 0;
    }
    unsigned int totalSetBitCount = 0;
    while (userInput) {
        userInput &= userInput - 1;
        totalSetBitCount++;
    }
    return totalSetBitCount;
}

//Tested
long long int ceilLog2(long long int userInput) {
    long long int count = 0;
    userInput--;
    while (userInput > 0) {
        userInput = userInput >> 1;
        count++;
    }
    return count;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int input;
    bool isNumberBleak;
    map<long long int, unsigned int> setBitCountMap;
    for (long long int counter = 0; counter < 10001; counter++) {
        setBitCountMap.insert(pair<long long int, unsigned int>(counter, getSetBitCount(counter)));
    }
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &input);
        isNumberBleak = true;
        for (unsigned int counter = input - ceilLog2(input); counter < input; counter++) {
            if (counter + setBitCountMap.find(counter)->second == input) {
                isNumberBleak = false;
            }
        }
        printf("%d\n", isNumberBleak ? 1 : 0);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_BLEAKNUMBERS_H_ */
