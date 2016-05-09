/****************************************************************************************************************************************************
 *  File Name                   : chblls.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/maychallenge2016/chblls.h
 *  Created on                  : May 9, 2016 :: 11:51:27 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/MAY16/problems/CHBLLS/
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_MAYCHALLENGE2016_CHBLLS_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_MAYCHALLENGE2016_CHBLLS_H_

//Tested
void solveProblem() {
    printf("1\n");
    printf("3 1 1 2\n");
    printf("3 3 3 4\n");
    int result;
    cin >> result;
    printf("2\n");
    if(result == 0) {
        printf("5\n");
    } else if(result == -2) {
        printf("3\n");
    } else if(result == 2) {
        printf("1\n");
    } else if(result == 1) {
        printf("2\n");
    } else if(result == -1) {
        printf("4\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_MAYCHALLENGE2016_CHBLLS_H_ */
