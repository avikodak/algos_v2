/****************************************************************************************************************************************************
 *  File Name                   : findfirstrepeatingbinarysearch.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\findfirstrepeatingbinarysearch.h
 *  Created on                  : Jan 5, 2015 :: 11:24:23 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-first-repeating-element-array-integers/
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

#ifndef FINDFIRSTREPEATINGBINARYSEARCH_H_
#define FINDFIRSTREPEATINGBINARYSEARCH_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int frvLowerBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex] == key?startIndex:INT_MIN;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == key) {
            return frvLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    } else if(userInput[middleIndex] > key) {
        return frvLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
    } else {
    }    return frvLowerBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
}

//Tested
int frvHigherBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex] == key?startIndex:INT_MAX;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        if(middleIndex + 1 <= endIndex && userInput[middleIndex+1] == key) {
            return frvHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
        } else {
            return middleIndex;
        }
    } else if(userInput[middleIndex] > key) {
        return frvHigherBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
    } else {
    }    return frvHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
}

//Tested
int findFirstRepeatingValueBinarySearch(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    vector<int> auxSpace(userInput.size());
    copy(userInput.begin(),userInput.end(),auxSpace.begin());
    sort(auxSpace.begin(),auxSpace.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(frvHigherBoundBinarySearch(auxSpace,userInput[counter],0,auxSpace.size()-1) - frvLowerBoundBinarySearch(auxSpace,userInput[counter],0,auxSpace.size()-1) + 1 > 1) {
            return userInput[counter];
        }
    }
    return INT_MIN;
}

#endif /* FINDFIRSTREPEATINGBINARYSEARCH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
