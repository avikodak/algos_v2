/****************************************************************************************************************************************************
 *  File Name                   : gettreefromspecialinorder.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\gettreefromspecialinorder.h
 *  Created on                  : Oct 23, 2014 :: 6:42:52 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
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

#ifndef GETTREEFROMSPECIALINORDER_H_
#define GETTREEFROMSPECIALINORDER_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int getMaxIndexValue(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return UINT_MAX;
    }
    unsigned int maxIndex = startIndex;
    for(int counter = startIndex; counter <= endIndex; counter++) {
        if(userInput[maxIndex] < userInput[counter]) {
            maxIndex = counter;
        }
    }
    return maxIndex;
}

//Tested
itNode *getTreeFromSpecialInOrderMain(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return null;
    }
    unsigned int maxIndex = getMaxIndexValue(userInput,startIndex,endIndex);
    itNode *node = new itNode(userInput[maxIndex]);
    node->left = getTreeFromSpecialInOrderMain(userInput,startIndex,maxIndex-1);
    node->right = getTreeFromSpecialInOrderMain(userInput,maxIndex+1,endIndex);
    return node;
}

//Tested
itNode *getTreeFromSpecialInorder(vector<int> userInput) {
    if(userInput.size() == 0) {
        return null;
    }
    return getTreeFromSpecialInOrderMain(userInput,0,userInput.size()-1);
}

#endif /* GETTREEFROMSPECIALINORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
