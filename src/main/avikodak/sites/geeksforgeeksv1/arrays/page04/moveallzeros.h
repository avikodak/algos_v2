/****************************************************************************************************************************************************
 *  File Name                   : moveallzeros.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\moveallzeros.h
 *  Created on                  : Dec 22, 2014 :: 3:39:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/move-zeroes-end-array/
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

#ifndef MOVEALLZEROS_H_
#define MOVEALLZEROS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void moveAllZerosToEnd(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    unsigned int fillCounter = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] != 0) {
            userInput[fillCounter++] = userInput[counter];
        }
    }
    while(fillCounter < userInput.size()) {
        userInput[fillCounter++] = 0;
    }
}

//Tested
void moveAllZerosToEndBucketSort(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    queue<int> auxSpace;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] != 0) {
            auxSpace.push(userInput[counter]);
        }
    }
    unsigned int fillCounter = 0;
    while(!auxSpace.empty()) {
        userInput[fillCounter++] = auxSpace.front();
        auxSpace.pop();
    }
    while(fillCounter < userInput.size()) {
        userInput[fillCounter++] = 0;
    }
}

#endif /* MOVEALLZEROS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
