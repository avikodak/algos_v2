/****************************************************************************************************************************************************
 *  File Name                   : nextgreaternumbersetdigits.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\nextgreaternumbersetdigits.h
 *  Created on                  : Jan 18, 2015 :: 9:53:02 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-next-greater-number-set-digits/
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

#ifndef NEXTGREATERNUMBERSETDIGITS_H_
#define NEXTGREATERNUMBERSETDIGITS_H_

//Tested
vector<char> nextGreaterNumberSetDigits(vector<char> userInput) {
    if(userInput.size() < 2) {
        return userInput;
    }
    int outerCounter,innerCounter;
    for(outerCounter = userInput.size() - 2; outerCounter >= 0; outerCounter--) {
        if(userInput[outerCounter] < userInput[outerCounter+1]) {
            break;
        }
    }
    if(outerCounter < 0) {
        return userInput;
    }
    int minDigit = INT_MIN;
    for(innerCounter = userInput.size()-1; innerCounter > outerCounter; innerCounter--) {
        if(userInput[innerCounter] > userInput[outerCounter]) {
            if(minDigit == INT_MIN) {
                minDigit = innerCounter;
            } else {
                if(userInput[minDigit] > userInput[innerCounter]) {
                    minDigit = innerCounter;
                }
            }
        }
    }
    swap(userInput[outerCounter],userInput[minDigit]);
    sort(userInput.begin()+outerCounter+1,userInput.end());
    return userInput;
}

#endif /* NEXTGREATERNUMBERSETDIGITS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
