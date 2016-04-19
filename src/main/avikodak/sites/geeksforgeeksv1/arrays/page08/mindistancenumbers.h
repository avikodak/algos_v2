/****************************************************************************************************************************************************
 *  File Name                   : mindistancenumbers.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\mindistancenumbers.h
 *  Created on                  : Dec 28, 2014 :: 11:39:10 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/
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

#ifndef MINDISTANCENUMBERS_H_
#define MINDISTANCENUMBERS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int minDistanceBetweenNumbersON(vector<int> userInput,int firstNumber,int secondNumber) {
    if(userInput.size() < 2) {
        return INT_MAX;
    }
    int prevIndex = INT_MIN;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == firstNumber || userInput[counter] == secondNumber) {
            prevIndex = counter;
            break;
        }
    }
    if(prevIndex == INT_MIN) {
        return INT_MAX;
    }
    int minDistance = INT_MAX;
    for(unsigned int counter = prevIndex+1; counter < userInput.size(); counter++) {
        if(userInput[counter] == firstNumber || userInput[counter] == secondNumber) {
            if(userInput[prevIndex] != userInput[counter]) {
                minDistance = min(minDistance,(int)counter-prevIndex);
            }
            prevIndex = counter;
        }
    }
    return minDistance;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int minDistanceBetweenNumbersON2(vector<int> userInput,int firstNumber,int secondNumber) {
    if(userInput.size() < 2) {
        return 0;
    }
    int minDistance = INT_MAX;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-1; outerCounter++) {
        if(userInput[outerCounter] == firstNumber || userInput[outerCounter] == secondNumber) {
            for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
                if(userInput[innerCounter] == (userInput[outerCounter] ^ firstNumber ^ secondNumber)) {
                    minDistance = min(minDistance,(int)(innerCounter - outerCounter));
                }
            }
        }
    }
    return minDistance;
}


#endif /* MINDISTANCENUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
