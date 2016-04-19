/****************************************************************************************************************************************************
 *  File Name   		: nearlyluckynumber.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\nearlyluckynumber.h
 *  Created on			: Mar 1, 2015 :: 10:39:07 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/110/A
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef NEARLYLUCKYNUMBER_H_
#define NEARLYLUCKYNUMBER_H_

//Tested
bool isNumberLucky(long long int userInput) {
    if(userInput == 0) {
        return false;
    }
    long long int lastDigit;
    while(userInput > 0) {
        lastDigit = userInput%10;
        if(lastDigit != 4 && lastDigit != 7) {
            return false;
        }
        userInput /= 10;
    }
    return true;
}

//Tested
void isNumberNearlyLuckyNumber() {
    long long int userInput,lastDigit,luckyDigitCounter = 0;
    cin >> userInput;
    while(userInput > 0) {
        lastDigit = userInput%10;
        if(lastDigit == 4 || lastDigit == 7) {
            luckyDigitCounter++;
        }
        userInput /= 10;
    }
    if(isNumberLucky(luckyDigitCounter)) {
        printf("YES");
    } else {
        printf("NO");
    }
}

#endif /* NEARLYLUCKYNUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
