/****************************************************************************************************************************************************
 *  File Name                   : pandigitalprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pandigitalprimes.h
 *  Created on                  : Aug 15, 2015 :: 5:47:40 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=41
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

#ifndef PANDIGITALPRIMES_H_
#define PANDIGITALPRIMES_H_

//Tested
unsigned int isPanDigital(unsigned long long int userInput) {
    unsigned int digitCount[10] = {0};
    while(userInput) {
        digitCount[userInput%10]++;
        if(userInput%10 == 0 ||digitCount[userInput%10] > 1) {
            return 0;
        }
        userInput /= 10;
    }
    if(digitCount[1] == 0) {
        return 0;
    }
    unsigned int length = 1;
    unsigned int counter;
    for(counter = 2; counter < 10; counter++) {
        if(digitCount[counter] == 1) {
            length++;
        } else {
            break;
        }
    }
    for(; counter < 10; counter++) {
        if(digitCount[counter] == 1) {
            return 0;
        }
    }
    return length;
}

//Tested
//Ans : 7652413
void printLargestPanDigitalPrime() {
    unsigned long int limit = 987654322;
    vector<bool> flags;
    flags.assign(limit,true);
    unsigned long int maxPanDigital = 0;
    for(unsigned int counter = 2; counter < limit; counter++) {
        if(flags[counter]) {
            if(isPanDigital(counter)) {
                maxPanDigital = maxPanDigital > counter?maxPanDigital:counter;
                cout << maxPanDigital << endl;
            }
            unsigned int innerCounter = 2;
            while(counter*innerCounter <= limit) {
                flags[counter*innerCounter] = false;
                innerCounter+=1;
            }
        }
    }
    cout << maxPanDigital << endl;
}

#endif /* PANDIGITALPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
