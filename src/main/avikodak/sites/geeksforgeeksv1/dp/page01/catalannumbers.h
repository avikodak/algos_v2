/****************************************************************************************************************************************************
 *  File Name   		: catalannumbers.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\catalannumbers.h
 *  Created on			: Jan 13, 2015 :: 12:40:12 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/program-nth-catalan-number/
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

#ifndef CATALANNUMBERS_H_
#define CATALANNUMBERS_H_

//Tested
int catalanNumber(int number) {
    if(number < 2) {
        return 1;
    }
    int total = 0;
    for(int counter = 0; counter < number; counter++) {
        total += catalanNumber(counter)*catalanNumber(number-counter-1);
    }
    return total;
}

//Tested
int catalanNumberMemoization(int number) {
    if(number < 2) {
        return 1;
    }
    vector<int> userInput;
    userInput.push_back(1);
    userInput.push_back(1);
    int total;
    for(int outerCounter = 2; outerCounter <= number; outerCounter++) {
        total = 0;
        for(int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            total += userInput[innerCounter] * userInput[outerCounter-innerCounter-1];
        }
        userInput.push_back(total);
    }
    return userInput[userInput.size()-1];
}

#endif /* CATALANNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
