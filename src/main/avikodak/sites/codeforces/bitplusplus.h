/****************************************************************************************************************************************************
 *  File Name                   : bitplusplus.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\bitplusplus.h
 *  Created on                  : Feb 28, 2015 :: 7:28:16 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/282/A
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/
#define MAX_INPUT_SIZE 4
/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef BITPLUSPLUS_H_
#define BITPLUSPLUS_H_

void printPostBitPlusPlusOperation() {
    unsigned int testCases;
    scanf("%u",&testCases);
    char userInput[MAX_INPUT_SIZE];
    int counter = 0;
    while(testCases--) {
        scanf("%s",userInput);
        if(userInput[1] == '+') {
            counter++;
        } else {
            counter--;
        }
    }
}

#endif /* BITPLUSPLUS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
