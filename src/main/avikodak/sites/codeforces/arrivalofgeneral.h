/****************************************************************************************************************************************************
 *  File Name   		: arrivalofgeneral.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\arrivalofgeneral.h
 *  Created on			: Mar 22, 2015 :: 8:22:54 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/144/A
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

#ifndef ARRIVALOFGENERAL_H_
#define ARRIVALOFGENERAL_H_

//Tested
void noOfSwapsForLines() {
    vector<unsigned int> userInput;
    unsigned int testCases,heights;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%d",&heights);
        userInput.push_back(heights);
    }
    unsigned int maxVal = 0,minVal = UINT_MAX;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        maxVal = max(maxVal,userInput[counter]);
        minVal = min(minVal,userInput[counter]);
    }
    unsigned int maxValIndex,minValueIndex;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == maxVal) {
            maxValIndex = counter;
            break;
        }
    }
    for(int counter = userInput.size()-1; counter >= 0; counter--) {
        if(userInput[counter] == minVal) {
            minValueIndex = counter;
            break;
        }
    }
    if(minValueIndex > maxValIndex) {
        printf("%d",userInput.size() - minValueIndex + maxValIndex - 1);
    } else {
        printf("%d",userInput.size() - minValueIndex + maxValIndex - 2);
    }
}

#endif /* ARRIVALOFGENERAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
