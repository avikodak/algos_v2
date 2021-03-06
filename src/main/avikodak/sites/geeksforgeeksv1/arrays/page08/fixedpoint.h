/****************************************************************************************************************************************************
 *  File Name                   : fixedpoint.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\fixedpoint.h
 *  Created on                  : Nov 27, 2014 :: 7:50:15 PM
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FIXEDPOINT_H_
#define FIXEDPOINT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int findFixedPointOLOGNMain(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return -1;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == middleIndex) {
        return middleIndex;
    } else if(userInput[middleIndex] > middleIndex) {
        return findFixedPointOLOGNMain(userInput,startIndex,middleIndex-1);
    } else {
        return findFixedPointOLOGNMain(userInput,middleIndex+1,endIndex);
    }
}

int findFixedPointOLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return -1;
    }
    return findFixedPointOLOGNMain(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int findFixedPointON(vector<int> userInput) {
    if(userInput.size() == 0) {
        return -1;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == (int)counter) {
            return counter;
        }
    }
    return -1;
}

#endif /* FIXEDPOINT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
