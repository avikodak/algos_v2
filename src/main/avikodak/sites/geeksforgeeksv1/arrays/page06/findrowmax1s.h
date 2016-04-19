/****************************************************************************************************************************************************
 *  File Name                   : findrowmax1s.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\findrowmax1s.h
 *  Created on                  : Dec 1, 2014 :: 3:45:10 PM
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

#ifndef FINDROWMAX1S_H_
#define FINDROWMAX1S_H_

int getLowIndex(vector<bool> userInput,bool key,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex == endIndex) {
        return key == userInput[startIndex];
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == key) {
        if(middleIndex-1 >= startIndex && userInput[middleIndex-1]) {
            return getLowIndex(userInput,key,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    } else {
        return getLowIndex(userInput,key,middleIndex+1,endIndex);
    }
}


unsigned int findRowWithMaxOnes(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return UINT_MAX;
    }
    int lowIndex = INT_MAX;
    int startColumnCounter = 0,endColumnCounter = userInput[0].size();
    unsigned rowCounter = 0;
    while(rowCounter < userInput.size()) {
        if(lowIndex == INT_MAX || userInput[rowCounter][lowIndex]) {
            endColumnCounter = lowIndex;
            lowIndex = getLowIndex(userInput[rowCounter],true,startColumnCounter,endColumnCounter);
        } else {
            rowCounter++;
        }
    }
    return lowIndex == INT_MAX?0:userInput.size()-lowIndex;
}

unsigned int findRowWithMax1s(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return UINT_MAX;
    }
    int maxOnes = 0,frequency;
    int maxOnesRowIndex = INT_MIN;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        frequency = 0;
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter]) {
                frequency += 1;
            }
        }
        if(frequency > maxOnes) {
            frequency = maxOnes;
            maxOnesRowIndex = rowCounter;
        }
    }
    return maxOnesRowIndex;
}

#endif /* FINDROWMAX1S_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
