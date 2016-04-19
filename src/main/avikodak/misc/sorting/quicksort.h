/****************************************************************************************************************************************************
 *  File Name                   : quicksort.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\sorting\quicksort.h
 *  Created on                  : Dec 11, 2014 :: 1:00:07 PM
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

#ifndef QUICKSORTV2_H_
#define QUICKSORTV2_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int qsDivideStep(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return startIndex;
    }
    int pivotIndex = endIndex;
    int key = userInput[endIndex];
    while(startIndex < endIndex) {
        while(userInput[startIndex] < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[endIndex],userInput[pivotIndex]);
    return endIndex;
}

//Tested
void qsQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return;
    }
    int dividingIndex = qsDivideStep(userInput,startIndex,endIndex);
    qsQuickSort(userInput,startIndex,dividingIndex-1);
    qsQuickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* QUICKSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
