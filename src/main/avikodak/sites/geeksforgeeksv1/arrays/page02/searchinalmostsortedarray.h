/****************************************************************************************************************************************************
 *  File Name                   : searchinalmostsortedarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\searchinalmostsortedarray.h
 *  Created on                  : Jan 6, 2015 :: 10:20:47 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/search-almost-sorted-array/
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

#ifndef SEARCHINALMOSTSORTEDARRAY_H_
#define SEARCHINALMOSTSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool searchInAlmostSortedArrayONLOGN(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return false;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex] == key;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        return true;
    }
    if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == key) {
        return true;
    }
    if(middleIndex+1 <= endIndex && userInput[middleIndex+1] == key) {
        return true;
    }
    if(userInput[middleIndex] > key) {
        return searchInAlmostSortedArrayONLOGN(userInput,key,startIndex,middleIndex-2);
    } else {
        return searchInAlmostSortedArrayONLOGN(userInput,key,middleIndex+2,endIndex);
    }
}

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool searchInAlmostSortedArray(vector<int> userInput,int key) {
    if(userInput.size() == 0) {
        return false;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == key) {
            return true;
        }
    }
    return false;
}

#endif /* SEARCHINALMOSTSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
