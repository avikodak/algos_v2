/****************************************************************************************************************************************************
 *  File Name                   : preordertraversal.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\preordertraversal.h
 *  Created on                  : Nov 17, 2014 :: 11:06:58 PM
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

#ifndef PREORDERTRAVERSAL_H_
#define PREORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void preOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    printf("%d\t",ptr->value);
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

//Tested
void preOrderTraversalIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        printf("%d\t",currentNode->value);
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

//Tested
void morrisPreorderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                temp->right = currentNode;
                printf("%d\t",currentNode->value);
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

#endif /* PREORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
