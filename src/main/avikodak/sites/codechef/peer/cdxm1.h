/****************************************************************************************************************************************************
 *  File Name                   : cdxm1.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/cdxm1.h
 *  Created on                  : Apr 26, 2016 :: 8:06:39 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CDXM1
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_CDXM1_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_CDXM1_H_

//Tested
void solveProblem() {
    unsigned int testCases, sizeOfString;
    string userInput;
    cin >> userInput;
    long long int firstIndex, secondIndex;
    scanf("%u", &testCases);
    sizeOfString = userInput.size();
    while (testCases--) {
        scanf("%lld %lld", &firstIndex, &secondIndex);
        if (userInput[(firstIndex - 1) % sizeOfString] == userInput[(secondIndex - 1) % sizeOfString]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_CDXM1_H_ */
