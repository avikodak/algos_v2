/****************************************************************************************************************************************************
 *  File Name                   : chainmatrixmultiplication.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\chainmatrixmultiplication.h
 *  Created on                  : Dec 11, 2014 :: 12:51:01 AM
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

#ifndef CHAINMATRIXMULTIPLICATION_H_
#define CHAINMATRIXMULTIPLICATION_H_

int minChainMatrixMultiplicationMemoization(vector<matrixsize *> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<vector<int> > auxSpace(userInput.size());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter].resize(userInput.size());
        auxSpace[counter][counter] = 0;
    }
    for(unsigned int counter = 1; counter < userInput.size()-1; counter++) {
        auxSpace[counter][counter+1] = userInput[counter]->rows * userInput[counter]->columns * userInput[counter+1]->columns;
    }
    return auxSpace[0][userInput.size()-1];
}

int minChainMatrixMultiplication(vector<matrixsize *> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex == endIndex) {
        return 0;
    }
    int minOperations = INT_MAX;
    for(int counter = startIndex; counter < endIndex; counter++) {
        minOperations = min(minOperations,minChainMatrixMultiplication(userInput,startIndex,counter) + minChainMatrixMultiplication(userInput,counter+1,endIndex) + userInput[startIndex]->rows * userInput[counter]->columns * userInput[endIndex]->columns);
    }
    return minOperations;
}


#endif /* CHAINMATRIXMULTIPLICATION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
