/****************************************************************************************************************************************************
 *  File Name                   : fibonnaciseries.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\fibonnaciseries.h
 *  Created on                  : Oct 18, 2014 :: 12:33:46 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FIBONNACISERIES_H_
#define FIBONNACISERIES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
unsigned int getNthTermInFibonacci(unsigned int nValue) {
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    unsigned int lastValue = 1,lastSecondValue = 1,currentValue,temp;
    for(unsigned int counter = 3; counter <= nValue; counter++) {
        temp = currentValue;
        currentValue = lastSecondValue + lastValue;
        lastSecondValue = lastValue;
        lastValue = temp;
    }
    return currentValue;
}

unsigned int getNthTermInFibonnaciDP(unsigned int nValue) {
    if(nValue == 0) {
        return 0;
    }
    static int fbValues[1024] = {0};
    fbValues[1] = 1;
    fbValues[2] = 1;
    if(fbValues[nValue] != 0) {
        return fbValues;
    }
    if(fbValues[nValue-1] == 0) {
        fbValues[nValue-1] = getNthTermInFibonnaciDP(nValue-1);
    }
    if(fbValues[nValue-2] == 0) {
        fbValues[nValue-2] = getNthTermInFibonnaciDP(nValue-2);
    }
    fbValues[nValue] = fbValues[nValue-1] + fbValues[nValue-2];
    return fbValues[nValue];
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
unsigned int getNthTermInFibonacciRecursion(unsigned int nValue) {
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    return getNthTermInFibonacciRecursion(nValue-1) + getNthTermInFibonacciRecursion(nValue-2);
}

#endif /* FIBONNACISERIES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
