/****************************************************************************************************************************************************
 *  File Name                   : frequencysortedarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\frequencysortedarray.h
 *  Created on                  : Nov 26, 2014 :: 6:29:43 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FREQUENCYSORTEDARRAY_H_
#define FREQUENCYSORTEDARRAY_H_


/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int getLowerBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        if(middleIndex-1 >= startIndex && userInput[middleIndex-1] == key) {
            return getLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    } else if(userInput[middleIndex] > key) {
        return getLowerBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
    } else {
        return getLowerBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
    }
}

//Tested
int getHigherBoundBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        if(middleIndex+1 <= endIndex && userInput[middleIndex+1] == key ) {
            return getHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
        } else {
            return middleIndex;
        }
    } else if(userInput[middleIndex] > key) {
        return getHigherBoundBinarySearch(userInput,key,startIndex,middleIndex-1);
    } else {
        return getHigherBoundBinarySearch(userInput,key,middleIndex+1,endIndex);
    }
}

//Tested
int getFrequencySortedArray(vector<int> userInput,int key) {
    if(userInput.size() == 0) {
        return 0;
    }
    int lowIndex = getLowerBoundBinarySearch(userInput,key,0,userInput.size()-1);
    if(lowIndex == INT_MAX) {
        return 0;
    }
    int highIndex = getHigherBoundBinarySearch(userInput,key,0,userInput.size()-1);
    if(highIndex == INT_MIN) {
        return 0;
    }
    return highIndex - lowIndex + 1;
}

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int frequencySortedArrayON(vector<int> userInput,int key) {
    if(userInput.size() == 0) {
        return 0;
    }
    unsigned int frequency = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == key) {
            frequency++;
        }
    }
    return frequency;
}

#endif /* FREQUENCYSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
