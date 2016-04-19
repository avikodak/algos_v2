/****************************************************************************************************************************************************
 *  File Name   		: pancakesortproblem.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\pancakesortproblem.h
 *  Created on			: Jan 4, 2015 :: 3:54:04 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef PANCAKESORTPROBLEM_H_
#define PANCAKESORTPROBLEM_H_

int ceilSearch(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(key < userInput[startIndex]) {
        return userInput[startIndex];
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        return userInput[middleIndex];
    }
    if(userInput[middleIndex] < key) {
        return ceilSearch(userInput,key,middleIndex+1,endIndex);
    } else {
        if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] > startIndex) {
            return ceilSearch(userInput,key,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    }
}



void pancakeSortingProblem(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {

    }
}

#endif /* PANCAKESORTPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
