/****************************************************************************************************************************************************
 *  File Name                   : fibonnacinumbers.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\fibonnacinumbers.h
 *  Created on                  : Dec 9, 2014 :: 7:38:50 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
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

#ifndef FIBONNACINUMBERS_H_
#define FIBONNACINUMBERS_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int getNthFibonnaciNumber(unsigned int number) {
    if(number == 0) {
        return 0;
    }
    if(number == 1) {
        return 1;
    }
    return getNthFibonnaciNumber(number-1) + getNthFibonnaciNumber(number-2);
}

//Tested
unsigned int getNthFibonnaciNumberMemoization(unsigned int number) {
    if(number == 0) {
        return 0;
    }
    static vector<unsigned int> auxSpace(number+1);
    static bool isInit = false;
    if(!isInit) {
        for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
            auxSpace[counter] = 0;
        }
        isInit = true;
        auxSpace[0] = 0;
        auxSpace[1] = 1;
    }
    if(number == 1) {
        return 1;
    }
    if(auxSpace[number] != 0) {
        return auxSpace[number];
    } else {
        if(number - 1 != 0) {
            if(auxSpace[number-1] != 0) {
                auxSpace[number] += auxSpace[number-1];
            } else {
                auxSpace[number] += getNthFibonnaciNumberMemoization(number-1);
            }
        }
        if(number - 2 != 0) {
            if(auxSpace[number-2] != 0) {
                auxSpace[number] += auxSpace[number-2];
            } else {
                auxSpace[number] += getNthFibonnaciNumberMemoization(number-2);
            }
        }
    }
    return auxSpace[number];
}

//Tested
unsigned int getNthFibonnaciNumberBottomUp(unsigned int number) {
    if(number == 0) {
        return 0;
    }
    if(number == 1) {
        return 1;
    }
    vector<unsigned int> auxSpace(number+1);
    auxSpace[0] = 0;
    auxSpace[1] = 1;
    for(unsigned int counter = 2; counter <= number; counter++) {
        auxSpace[counter] = auxSpace[counter-1] + auxSpace[counter-2];
    }
    return auxSpace[number];
}

//Tested
unsigned int getNthFibonnaciNumberBottomUpSpace(unsigned int number) {
    if(number == 0) {
        return 0;
    }
    if(number == 1) {
        return 1;
    }
    int firstValue = 1,secondValue = 0,result;
    for(unsigned int counter = 2; counter <= number; counter++) {
        result = firstValue + secondValue;
        secondValue = firstValue;
        firstValue = result;
    }
    return result;
}

#endif /* FIBONNACINUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
