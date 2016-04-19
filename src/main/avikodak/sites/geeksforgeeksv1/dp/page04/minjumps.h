/****************************************************************************************************************************************************
 *  File Name                   : minjumps.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\minjumps.h
 *  Created on                  : Dec 9, 2014 :: 8:02:03 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
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

#ifndef MINJUMPS_H_
#define MINJUMPS_H_

//Tested
int minJumpsToEndMemoization(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MAX;
    }
    if(userInput[0] == INT_MAX) {
        return 0;
    }
    vector<int> auxSpace(userInput.size());
    userInput[userInput.size()-1] = 0;
    int minJumps;
    for(int outerCounter = userInput.size()-2; outerCounter >= 0; outerCounter--) {
        minJumps = INT_MAX;
        if(userInput[outerCounter] != 0) {
            for(int innerCounter = outerCounter+1; innerCounter <= outerCounter + userInput[outerCounter] && innerCounter < (int)userInput.size(); innerCounter++) {
                if(auxSpace[innerCounter] != INT_MAX) {
                    minJumps = min(minJumps,1+auxSpace[innerCounter]);
                }
            }
        }
        auxSpace[outerCounter] = minJumps;
    }
    return auxSpace[0];
}

//Tested
int minJumpsToEnd(vector<int> userInput,unsigned int index = 0) {
    if(index >= userInput.size()) {
        return INT_MAX;
    }
    if(index == userInput.size()-1) {
        return 0;
    }
    if(userInput[index] == 0) {
        return INT_MAX;
    }
    int minJumps = INT_MAX;
    for(int counter = 1; counter <= userInput[index]; counter++) {
        minJumps = min(minJumps,minJumpsToEnd(userInput,index + counter));
    }
    return minJumps == INT_MAX?INT_MAX:1+minJumps;
}

#endif /* MINJUMPS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
