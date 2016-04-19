/****************************************************************************************************************************************************
 *  File Name   		: duplicateskdistance.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\duplicateskdistance.h
 *  Created on			: Jan 5, 2015 :: 10:23:53 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
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

#ifndef DUPLICATESKDISTANCE_H_
#define DUPLICATESKDISTANCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool duplicatesAtKDistance(vector<int> userInput,unsigned int kDistance) {
    if(userInput.size() == 0) {
        return false;
    }
    hash_map<int,unsigned int> valIndexMap;
    hash_map<int,unsigned int>::iterator itToValIndexMap;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if((itToValIndexMap = valIndexMap.find(userInput[counter])) == valIndexMap.end()) {
            valIndexMap.insert(pair<int,unsigned int>(userInput[counter],counter));
        } else {
            if(counter - itToValIndexMap->second  <= kDistance) {
                return true;
            }
            valIndexMap[userInput[counter]] = counter;
        }
    }
    return false;
}

//Tested
bool duplicatesAtKDistanceSet(vector<int> userInput,int kDistance) {
    if(userInput.size() == 0) {
        return false;
    }
    set<int> visitedValues;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(visitedValues.find(userInput[counter]) != visitedValues.end()) {
            return true;
        }
        visitedValues.insert(userInput[counter]);
        if(kDistance - counter >= 0) {
            visitedValues.erase(userInput[counter - kDistance]);
        }
    }
    return false;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool duplicatesAtKDistanceON2(vector<int> userInput,int kDistance) {
    if(userInput.size() == 0 || kDistance < 0) {
        return false;
    }
    int innerCounter;
    for(int outerCounter = 1; outerCounter < (int)userInput.size(); outerCounter++) {
        for(innerCounter = outerCounter-1; innerCounter >= 0 && innerCounter >= outerCounter - kDistance; innerCounter--) {
            if(userInput[outerCounter] == userInput[innerCounter]) {
                return true;
            }
        }
    }
    return false;
}

#endif /* DUPLICATESKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
