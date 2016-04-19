/****************************************************************************************************************************************************
 *  File Name                   : selectionsort.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture22\selectionsort.h
 *  Created on                  : Dec 1, 2014 :: 9:48:02 PM
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

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void selectionsortON2(vector<int> &userInput) {
    if(userInput.size() < 1) {
        return;
    }
    int minValIndex;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-1; outerCounter++) {
        minValIndex = outerCounter;
        for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[minValIndex] > userInput[innerCounter]) {
                minValIndex = innerCounter;
            }
        }
        swap(userInput[outerCounter],userInput[minValIndex]);
    }
}

#endif /* SELECTIONSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
