/****************************************************************************************************************************************************
 *  File Name                   : maximumsizesubmatrix.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\maximumsizesubmatrix.h
 *  Created on                  : Dec 30, 2014 :: 6:07:02 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
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

#ifndef MAXIMUMSIZESUBMATRIX_H_
#define MAXIMUMSIZESUBMATRIX_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maximumSizeSubMatrixAllOnes(vector<vector<int> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return 0;
    }
    vector<vector<int> > auxSpace(userInput.size());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter].assign(userInput[0].size(),0);
    }
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        auxSpace[rowCounter][0] = userInput[rowCounter][0];
    }
    for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = userInput[0][columnCounter];
    }
    int maxSize = INT_MIN;
    for(unsigned int rowCounter = 1; rowCounter < userInput.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter] == 1) {
                auxSpace[rowCounter][columnCounter] = 1 + min(auxSpace[rowCounter][columnCounter-1],min(auxSpace[rowCounter-1][columnCounter-1],auxSpace[rowCounter-1][columnCounter]));
                maxSize = max(maxSize,auxSpace[rowCounter][columnCounter]);
            }
        }
    }
    return maxSize;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* MAXIMUMSIZESUBMATRIX_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
