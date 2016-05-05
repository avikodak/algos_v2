/****************************************************************************************************************************************************
 *  File Name                   : cb1.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/cb1.h
 *  Created on                  : May 6, 2016 :: 1:32:55 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CB1
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
#define MAX_SIZE 1000001

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_CB1_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_CB1_H_

//Tested
void solveProblem() {
    bool primeNumbers[MAX_SIZE];
    memset(primeNumbers, true, sizeof(primeNumbers));
    primeNumbers[0] = false;
    primeNumbers[1] = false;
    for (int outerCounter = 2; outerCounter * outerCounter < MAX_SIZE; outerCounter++) {
        if (primeNumbers[outerCounter]) {
            for (int innerCounter = outerCounter * 2; innerCounter < MAX_SIZE; innerCounter = innerCounter + outerCounter) {
                primeNumbers[innerCounter] = false;
            }
        }
    }
    int countOfPrimes[MAX_SIZE] = { 0 };
    for (int outerCounter = 2; outerCounter < MAX_SIZE; outerCounter++) {
        if (primeNumbers[outerCounter]) {
            countOfPrimes[outerCounter] = countOfPrimes[outerCounter - 1] + 1;
        } else {
            countOfPrimes[outerCounter] = countOfPrimes[outerCounter - 1];
        }
    }
    unsigned int testCases;
    int fUserInput, sUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%d %d", &fUserInput, &sUserInput);
        printf("%d\n", countOfPrimes[sUserInput] - countOfPrimes[fUserInput - 1]);
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_CB1_H_ */
