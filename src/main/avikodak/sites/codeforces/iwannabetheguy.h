/****************************************************************************************************************************************************
 *  File Name                   : iwannabetheguy.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iwannabetheguy.h
 *  Created on                  : Apr 7, 2015 :: 11:49:25 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/469/A
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef IWANNABETHEGUY_H_
#define IWANNABETHEGUY_H_

//Tested
void willTheyPassLevels() {
    unsigned int finalLevel;
    vector<bool> flags;
    scanf("%u",&finalLevel);
    flags.assign(finalLevel,false);
    unsigned int littleXTotalLevels,littleYTotalLevels;
    unsigned int inputLevel;
    scanf("%u",&littleXTotalLevels);
    while(littleXTotalLevels--) {
        scanf("%u",&inputLevel);
        flags[inputLevel-1] = true;
    }
    scanf("%u",&littleYTotalLevels);
    while(littleYTotalLevels--) {
        scanf("%u",&inputLevel);
        flags[inputLevel-1] = true;
    }
    for(unsigned int counter = 0; counter < finalLevel; counter++) {
        if(!flags[counter]) {
            printf("Oh, my keyboard!");
            return;
        }
    }
    printf("I become the guy.");
}

#endif /* IWANNABETHEGUY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
