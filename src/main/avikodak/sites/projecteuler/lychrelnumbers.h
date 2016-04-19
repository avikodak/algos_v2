/****************************************************************************************************************************************************
 *  File Name                   : lychrelnumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\lychrelnumbers.h
 *  Created on                  : Aug 20, 2015 :: 12:22:48 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=55
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

#ifndef LYCHRELNUMBERS_H_
#define LYCHRELNUMBERS_H_

//Tested
unsigned long long int reverseNumber(unsigned long long int userInput) {
    unsigned long long int reverseValue = 0;
    while(userInput) {
        reverseValue *= 10;
        reverseValue += (userInput%10);
        userInput /= 10;
    }
    return reverseValue;
}

//Tested
bool isPalindrome(unsigned long long int userInput) {
    return reverseNumber(userInput) == userInput;
}

//Tested
unsigned long long int getIntermediateValue(unsigned long long int userInput) {
    return userInput + reverseNumber(userInput);
}

//Tested
bool isLychrelNumber(unsigned long long int userInput) {
    for(unsigned int counter = 0; counter < 50; counter++) {
        userInput = userInput+reverseNumber(userInput);
        if(isPalindrome(userInput)) {
            return false;
        }
    }
    return true;
}

//Tested
//Ans : 249
void getTotalLychrelNumber() {
    unsigned int total = 0;
    for(unsigned long long int counter = 10; counter < 10000; counter++) {
        if(isLychrelNumber(counter)) {
            total++;
        }
    }
    cout << total << endl;
}

#endif /* LYCHRELNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
