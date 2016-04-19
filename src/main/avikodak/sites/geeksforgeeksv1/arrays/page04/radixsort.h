/****************************************************************************************************************************************************
 *  File Name                   : radixsort.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\radixsort.h
 *  Created on                  : Dec 22, 2014 :: 3:39:04 PM
 *  Author                      : AVINASH
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

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

//Tested
int getDividingIndexRadixSort(vector<int> &userInput,int start,int end,int index) {
    if(start > end || index < 0) {
        return INT_MIN;
    }
    while(start <= end) {
        while(start <= end && !(userInput[start] & 1 << index)) {
            start++;
        }
        while(start <= end && userInput[end] & 1 << index) {
            end--;
        }
        if(start < end) {
            swap(userInput[start],userInput[end]);
        }
    }
    return end;
}

//Tested
void radixSortMain(vector<int> &userInput,int start,int end,int index) {
    if(start >= end || index < 0) {
        return;
    }
    int dividingIndex = getDividingIndexRadixSort(userInput,start,end,index);
    radixSortMain(userInput,start,dividingIndex,index-1);
    radixSortMain(userInput,dividingIndex+1,end,index-1);
}

//Tested
void radixSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int noOfBits = log2(*max_element(userInput.begin(),userInput.end()));
    radixSortMain(userInput,0,userInput.size()-1,noOfBits+1);
}

#endif /* RADIXSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
