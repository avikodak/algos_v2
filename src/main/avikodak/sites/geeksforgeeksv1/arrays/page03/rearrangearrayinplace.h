/****************************************************************************************************************************************************
 *  File Name                   : rearrangearrayinplace.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\rearrangearrayinplace.h
 *  Created on                  : Jan 4, 2015 :: 1:22:19 PM
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

#ifndef REARRANGEARRAYINPLACE_H_
#define REARRANGEARRAYINPLACE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void rearrangeArray(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        userInput[counter] += (userInput[userInput[counter]]%userInput.size())*(userInput.size());
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        userInput[counter] /= userInput.size();
    }
}

void rearrangeArrayAuxSpace(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    vector<int> auxSpace(userInput.size());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter] = userInput[userInput[counter]];
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        userInput[counter] = auxSpace[counter];
    }
}

#endif /* REARRANGEARRAYINPLACE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
