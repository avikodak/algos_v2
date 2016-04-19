/****************************************************************************************************************************************************
 *  File Name                   : bouncynumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\bouncynumbers.h
 *  Created on                  : Aug 25, 2015 :: 4:44:50 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=112
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

#ifndef BOUNCYNUMBERS_H_
#define BOUNCYNUMBERS_H_

//Tested
bool isBouncyNumber(unsigned long long int userInput) {
    vector<unsigned int> digits;
    while(userInput) {
        digits.push_back(userInput%10);
        userInput /= 10;
    }
    bool isIncreasing = true;
    for(unsigned int counter = 1; counter < digits.size(); counter++) {
        if(digits[counter] < digits[counter-1]) {
            isIncreasing = false;
            break;
        }
    }
    if(isIncreasing) {
        return false;
    }
    bool isDecreasing = true;
    for(unsigned int counter = 1; counter < digits.size(); counter++) {
        if(digits[counter] > digits[counter-1]) {
            isDecreasing = false;
            break;
        }
    }
    if(isDecreasing) {
        return false;
    }
    return true;
}

//Tested
//Ans : 1587000
void getLeastNumber() {
    unsigned long long int counter = 99;
    unsigned long long int bouncyNumbersCount = 0;
    while(true) {
        if(isBouncyNumber(counter)) {
            bouncyNumbersCount++;
        }
        if(bouncyNumbersCount*100 >= 99*counter) {
            cout << counter << endl;
            return;
        }
        counter++;
    }
}

#endif /* BOUNCYNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
