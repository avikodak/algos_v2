/****************************************************************************************************************************************************
 *  File Name                   : predecessor.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\predecessor.h
 *  Created on                  : Nov 18, 2014 :: 8:40:33 PM
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

#ifndef PREDECESSOR_H_
#define PREDECESSOR_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *predecessor(itNode *ptr,int value) {
    static bool keyFound = false;
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        if(ptr->left != null) {
            ptr = ptr->left;
            while(ptr->right != null) {
                ptr = ptr->right;
            }
            return ptr;
        }
        keyFound = true;
        return null;
    } else if(ptr->value > value) {
        return predecessor(ptr->left,value);
    } else {
        itNode *result = predecessor(ptr->right,value);
        if(result == null) {
            return keyFound?ptr:null;
        }
        return result;
    }
}

//Tested
itNode *predecessorIterative(itNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    itNode *probablePredecessor = null,*currentNode = ptr;
    while(currentNode != null) {
        if(currentNode->value == value) {
            if(currentNode->left == null) {
                return probablePredecessor;
            }
            currentNode = currentNode->left;
            while(currentNode->right != null) {
                currentNode = currentNode->right;
            }
            return currentNode;
        } else if(currentNode->value > value) {
            currentNode = currentNode->left;
        } else {
            probablePredecessor = currentNode;
            currentNode = currentNode->right;
        }
    }
    return currentNode;
}

#endif /* PREDECESSOR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
