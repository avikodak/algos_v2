/****************************************************************************************************************************************************
 *  File Name                   : pamcakesort.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\sorting\pamcakesort.h
 *  Created on                  : Dec 25, 2014 :: 2:57:59 AM
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

#ifndef PANCAKESORT_H_
#define PANCAKESORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void flip(vector<int> &userInput,int endIndex) {
    if(userInput.size() == 0 || endIndex < 2) {
        return;
    }
    int startIndex = 0;
    while(startIndex < endIndex) {
        swap(userInput[startIndex++],userInput[endIndex++]);
    }
}

int getMaxIndex(vector<int> userInput,int endIndex) {
    if(endIndex < 0) {
        return INT_MIN;
    }
    if(endIndex == 0) {
        return 0;
    }
    int maxIndex = 0;
    for(unsigned int counter = 1; counter <= endIndex; counter++) {
        if(userInput[maxIndex] < userInput[counter]) {
            maxIndex = counter;
        }
    }
    return maxIndex;
}

void pancakeSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int maxIndex;
    for(int counter = userInput.size()-1; counter >= 0; counter--) {
        maxIndex = getMaxIndex(userInput,counter);
        flip(userInput,maxIndex);
        flip(userInput,counter);
    }
}

#endif /* PANCAKESORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
