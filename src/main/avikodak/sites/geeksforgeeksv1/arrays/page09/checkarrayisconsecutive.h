/****************************************************************************************************************************************************
 *  File Name   		: checkarrayisconsecutive.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\checkarrayisconsecutive.h
 *  Created on			: Nov 26, 2014 :: 9:06:50 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef CHECKARRAYISCONSECUTIVE_H_
#define CHECKARRAYISCONSECUTIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isArrayConsecutiveHashmap(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    hash_map<unsigned int,unsigned int> frequencyMap;
    hash_map<unsigned int,unsigned int>::iterator itToFrequencyMap;
    int minValue = *min_element(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= minValue + userInput.size()) {
            return false;
        }
        if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()) {
            frequencyMap[userInput[counter]] = 1;
        } else {
            return false;
        }
    }
    return true;
}

//Tested
bool isArrayConsecutiveSum(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    unsigned int arraySum = 0;
    unsigned int minElement = *min_element(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= minElement + userInput.size()) {
            return false;
        }
        arraySum += userInput[counter];
    }
    unsigned int requiredSum = (userInput.size())*(minElement + minElement + userInput.size() - 1);
    return requiredSum == arraySum*2;
}

//Tested
//Works for positive elements..if array contains +/- separate using quicksort divide step
bool isArrayConsecutiveArrayAsFlags(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    int minValue = *min_element(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(abs(userInput[counter]) >= minValue + (int)userInput.size()) {
            return false;
        }
        if(userInput[abs(userInput[counter]) - minValue] < 0) {
            return false;
        }
        userInput[abs(userInput[counter]) - minValue] *= -1;
    }
    return true;
}

/**************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm																  */
/**************************************************************************************************************************************************/
//Tested
bool isArrayConsecutiveONLOGN(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    sort(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size()-1; counter++) {
        if(userInput[counter+1] - userInput[counter] > 1) {
            return false;
        }
    }
    return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isArrayConsecutiveON2(vector<unsigned int> userInput) {
    if(userInput.size() < 2) {
        return true;
    }
    unsigned int minVal = uMinValueVector(userInput);
    bool valFound;
    for(unsigned int counter = minVal; counter < minVal + userInput.size(); counter++) {
        valFound = false;
        for(unsigned int innerCounter = 0; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[innerCounter] == counter) {
                valFound = true;
                break;
            }
        }
        if(!valFound) {
            return false;
        }
    }
    return true;
}

#endif /* CHECKARRAYISCONSECUTIVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
