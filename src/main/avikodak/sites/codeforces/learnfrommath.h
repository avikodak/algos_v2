/****************************************************************************************************************************************************
 *  File Name                   : learnfrommath.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\learnfrommath.h
 *  Created on                  : Mar 1, 2015 :: 7:04:56 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/472/A
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

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef LEARNFROMMATH_H_
#define LEARNFROMMATH_H_

bool isNumberPrime(unsigned int userInput) {
    if(userInput < 2) {
        return false;
    }
    unsigned int root = sqrt(userInput);
    for(unsigned int counter = 2; counter <= root; counter++) {
        if(userInput%counter == 0) {
            return false;
        }
    }
    return true;
}

void printSumUsingComposites() {
    unsigned int userInput;
    scanf("%u",&userInput);
    for(unsigned int counter = userInput-2; counter >= 0; counter--) {
        if(isNumberPrime(counter) && isNumberPrime(userInput-counter)) {
            printf("%u %u",counter,userInput-counter);
            return;
        }
    }
}

#endif /* LEARNFROMMATH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
