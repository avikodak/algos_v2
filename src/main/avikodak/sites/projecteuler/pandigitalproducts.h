/****************************************************************************************************************************************************
 *  File Name                   : pandigitalproducts.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pandigitalproducts.h
 *  Created on                  : Aug 23, 2015 :: 6:32:14 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=32
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

#ifndef PANDIGITALPRODUCTS_H_
#define PANDIGITALPRODUCTS_H_

//Tested
unsigned int getLength(unsigned long long int userInput) {
    unsigned int length = 0;
    while(userInput) {
        length++;
        userInput /= 10;
    }
    return length;
}

//Tested
unsigned long long int concate(unsigned int first,unsigned int second) {
    while(second) {
        first *= 10;
        first += second%10;
        second /= 10;
    }
    return first;
}

//Tested
bool isPandigital(unsigned long long int multiplicand,unsigned long long int multiplier,unsigned long long int result) {
    unsigned int userInput = concate(multiplicand,multiplier);
    userInput = concate(userInput,result);
    bool flags[10] = {false};
    while(userInput) {
        if(userInput%10 == 0|| flags[userInput%10]) {
            return false;
        }
        flags[userInput%10] = true;
        userInput /= 10;
    }
    for(unsigned int counter = 1; counter < 10; counter++) {
        if(!flags[counter]) {
            return false;
        }
    }
    return true;
}

//Tested
//Ans : 45228
void getSumPanDigitalProducts() {
    map<unsigned long long int,bool> visitedProducts;
    unsigned long long int result,sum =0;
    unsigned int length;
    for(unsigned long long int outerCounter = 1; outerCounter <= 9876; outerCounter++) {
        for(unsigned long long int innerCounter = 1; innerCounter <= 9876; innerCounter++) {
            result = outerCounter * innerCounter;
            length = getLength(result) + getLength(outerCounter) + getLength(innerCounter);
            if(length < 10) {
                if(length == 9) {
                    if(visitedProducts.find(result) == visitedProducts.end()) {
                        if(isPandigital(outerCounter,innerCounter,result)) {
                            visitedProducts.insert(pair<unsigned long long int,bool>(result,true));
                            sum +=result;
                        }
                    }
                }
            } else {
                break;
            }
        }
    }
    cout << sum << endl;
}

#endif /* PANDIGITALPRODUCTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
