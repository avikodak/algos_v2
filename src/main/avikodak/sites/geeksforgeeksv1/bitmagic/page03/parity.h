/****************************************************************************************************************************************************
 *  File Name                   : parity.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page03\parity.h
 *  Created on                  : Jan 8, 2015 :: 10:25:01 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-find-the-parity-of-an-unsigned-integer/
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

#ifndef PARITY_H_
#define PARITY_H_

//Tested
int parity(int userInput) {
    bool parity = true;
    while(userInput > 0) {
        parity = !parity;
        userInput = userInput & (userInput-1);
    }
    return parity;
}

//Tested
int parityRightMostBit(int userInput) {
    bool parity = false;
    while(userInput > 0) {
        parity = !parity;
        userInput = userInput & (userInput-1);
    }
    return parity;
}

//Tested
int parityBitCounter(int userInput) {
    if(userInput == 0) {
        return 0;
    }
    unsigned int setBitCounter = 0;
    while(userInput > 0) {
        setBitCounter += userInput & 1;
        userInput = userInput >> 1;
    }
    return setBitCounter % 2 != 0;
}

#endif /* PARITY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
