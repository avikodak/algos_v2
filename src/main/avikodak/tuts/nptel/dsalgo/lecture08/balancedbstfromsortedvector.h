/****************************************************************************************************************************************************
 *  File Name                   : balancedbstfromsortedvector.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\balancedbstfromsortedvector.h
 *  Created on                  : Nov 18, 2014 :: 7:39:54 PM
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
#ifndef BALANCEDBSTFROMSORTEDVECTOR_H_
#define BALANCEDBSTFROMSORTEDVECTOR_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *getBalancedBstSortedArrayMain(vector<int> userInput,int startIndex,int endIndex) {
    if(userInput.size() == 0 || startIndex > endIndex) {
        return null;
    }
    int middleIndex = (startIndex + endIndex) / 2;
    itNode *node = new itNode(userInput[middleIndex]);
    node->left = getBalancedBstSortedArrayMain(userInput,startIndex,middleIndex-1);
    node->right = getBalancedBstSortedArrayMain(userInput,middleIndex+1,endIndex);
    return node;
}

//Tested
itNode *getBalancedBstSortedArray(vector<int> userInput) {
    return getBalancedBstSortedArrayMain(userInput,0,userInput.size()-1);
}

#endif /* BALANCEDBSTFROMSORTEDVECTOR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
