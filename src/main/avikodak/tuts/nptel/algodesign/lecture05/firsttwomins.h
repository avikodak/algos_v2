/****************************************************************************************************************************************************
 *  File Name                   : firsttwomins.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture05\firsttwomins.h
 *  Created on                  : Dec 12, 2014 :: 12:27:23 PM
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

#ifndef FIRSTTWOMINS_H_
#define FIRSTTWOMINS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
iPair *findFirstTwoMinsON(vector<int> userInput) {
    if(userInput.size() == 0) {
        return null;
    }
    iPair *result = new iPair(INT_MAX,INT_MAX);
    if(userInput.size() == 1) {
        result->firstValue = userInput[0];
        result->secondValue = INT_MAX;
        return result;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(result->firstValue > userInput[counter]) {
            result->secondValue = result->firstValue;
            result->firstValue = userInput[counter];
        } else if(result->secondValue > userInput[counter]) {
            result->secondValue = userInput[counter];
        }
    }
    return result;
}

//Tested
iPair *findFirstTwoMinDAD(vector<int> userInput,int startIndex,int endIndex) {
    if(userInput.size() == 0) {
        return null;
    }
    iPair *result = new iPair(INT_MAX,INT_MAX);
    if(endIndex == startIndex) {
        result->firstValue = userInput[startIndex];
        result->secondValue = INT_MAX;
        return result;
    }
    int middleIndex = (startIndex + endIndex)/2;
    iPair *leftResult = findFirstTwoMinDAD(userInput,startIndex,middleIndex);
    iPair *rightResult = findFirstTwoMinDAD(userInput,middleIndex+1,endIndex);
    if(leftResult->firstValue > rightResult->firstValue) {
        result->firstValue = rightResult->firstValue;
        if(leftResult->firstValue > rightResult->secondValue) {
            result->secondValue = rightResult->secondValue;
        } else {
            result->secondValue = leftResult->firstValue;
        }
    } else {
        result->firstValue = leftResult->firstValue;
        if(rightResult->firstValue > leftResult->secondValue) {
            result->secondValue = leftResult->secondValue;
        } else {
            result->secondValue = rightResult->firstValue;
        }
    }
    return result;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
iPair *findFirstTwoMinsONLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return null;
    }
    iPair *result = new iPair(INT_MAX,INT_MAX);
    if(userInput.size() == 1) {
        result->firstValue = userInput[0];
        return result;
    }
    sort(userInput.begin(),userInput.end());
    result->firstValue = userInput[0];
    result->secondValue = userInput[1];
    return result;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* FIRSTTWOMINS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
