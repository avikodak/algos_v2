/****************************************************************************************************************************************************
 *  File Name                   : selectionsort.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\recursion\page01\selectionsort.h
 *  Created on                  : Oct 13, 2014 :: 11:59:22 AM
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

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void recursiveSelectionSort(vector<int> &userInput,unsigned int minIndex,unsigned int maxIndex) {
    if(minIndex > maxIndex) {
        return;
    }
    int minValue = userInput[minIndex];
    for(unsigned int counter = minIndex; counter <= maxIndex; counter++) {
        minValue = min(minValue,userInput[counter]);
    }
    userInput[minIndex] = minValue;
    recursiveSelectionSort(userInput,minIndex+1,maxIndex);
}

#endif /* SELECTIONSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
