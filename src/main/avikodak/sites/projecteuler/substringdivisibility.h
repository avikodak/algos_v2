/****************************************************************************************************************************************************
 *  File Name                   : substringdivisibility.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\substringdivisibility.h
 *  Created on                  : Aug 16, 2015 :: 8:17:14 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=43
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

#ifndef SUBSTRINGDIVISIBILITY_H_
#define SUBSTRINGDIVISIBILITY_H_

//Tested
bool isSubStringDivisible(string userInput) {
    unsigned long long int divisibility[] = {2,3,5,7,11,13,17};
    unsigned long long int value,divisibleCounter = 0;
    for(unsigned long long int counter = 1; counter < userInput.size()-2; counter+=1) {
        value = 0;
        for(unsigned long long int innerCounter = counter; innerCounter < counter+3; innerCounter++) {
            value *= 10;
            value += (userInput[innerCounter]-'0');
        }
        if(value%divisibility[divisibleCounter++] != 0) {
            return false;
        }
    }
    return true;
}

//Tested
unsigned long long int getUnsignedIntValue(string userInput) {
    unsigned long long int value = 0;
    for(unsigned long long int counter = 0; counter < userInput.size(); counter++) {
        value *= 10;
        value += userInput[counter];
    }
    return value;
}

//Tested
//Sum generating is wrong though sequence are right
//Ans : 16695334890
void getSumSubStringPandigital() {
    string userInput = "0123456789";
    unsigned long long int totalSum = 0;
    do {
        if(isSubStringDivisible(userInput)) {
            cout << userInput << endl;
            totalSum += getUnsignedIntValue(userInput);
        }
    } while (next_permutation(userInput.begin(), userInput.end()));
    cout << totalSum << endl;
}

#endif /* SUBSTRINGDIVISIBILITY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
