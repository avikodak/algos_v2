/****************************************************************************************************************************************************
 *  File Name                   : binarysearch.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture04\binarysearch.h
 *  Created on                  : Oct 22, 2014 :: 12:40:53 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int binarySearchMain(vector<int> userInput,int key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    unsigned int middleIndex = (startIndex  + endIndex)/2;
    if(userInput[middleIndex] == key) {
        return middleIndex;
    }
    if(userInput[middleIndex] > key) {
        return binarySearchMain(userInput,key,startIndex,middleIndex-1);
    } else {
        return binarySearchMain(userInput,key,middleIndex+1,endIndex);
    }
}

//Tested
int binarySearch(vector<int> userInput,int key) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    return binarySearchMain(userInput,key,0,userInput.size()-1);
}

#endif /* BINARYSEARCH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
