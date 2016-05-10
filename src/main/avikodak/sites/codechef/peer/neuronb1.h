/****************************************************************************************************************************************************
 *  File Name                   : neuronb1.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/neuronb1.h
 *  Created on                  : May 8, 2016 :: 3:19:33 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/NEURONB1
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_NEURONB1_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_NEURONB1_H_

//Tested
long long int reverseNumber(long long int userInput) {
    long long int reverseNumber = 0;
    while (userInput) {
        reverseNumber = reverseNumber * 10 + (userInput % 10);
        userInput /= 10;
    }
    return reverseNumber;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int fUserInput, sUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld %lld", &fUserInput, &sUserInput);
        printf("%lld\n", reverseNumber(reverseNumber(fUserInput) + reverseNumber(sUserInput)));
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_NEURONB1_H_ */
