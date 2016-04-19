/****************************************************************************************************************************************************
 *  File Name                   : searchinbst.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\searchinbst.h
 *  Created on                  : Nov 18, 2014 :: 7:40:22 PM
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

#ifndef SEARCHINBST_H_
#define SEARCHINBST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *searchInBst(itNode *ptr,int userInput) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value == userInput) {
        return ptr;
    } else if(ptr->value > userInput) {
        return searchInBst(ptr->left,userInput);
    } else {
        return searchInBst(ptr->right,userInput);
    }
}

//Tested
itNode *searchInBstIterative(itNode *ptr,int userInput) {
    if(ptr == null) {
        return null;
    }
    itNode *currentNode = ptr;
    while(currentNode != null) {
        if(currentNode->value == userInput) {
            break;
        } else if(currentNode->value > userInput) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return currentNode;
}

#endif /* SEARCHINBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
