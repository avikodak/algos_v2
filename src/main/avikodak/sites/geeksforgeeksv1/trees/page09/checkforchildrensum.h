/****************************************************************************************************************************************************
 *  File Name                   : checkforchildrensum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\checkforchildrensum.h
 *  Created on                  : Oct 16, 2014 :: 1:47:59 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
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

#ifndef CHECKFORCHILDRENSUM_H_
#define CHECKFORCHILDRENSUM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool checkForChildrenSumPreorder(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    int leftChildValue = ptr->left == null?0:ptr->left->value;
    int rightChildValue = ptr->right == null?0:ptr->right->value;
    if(ptr->value != leftChildValue+rightChildValue) {
        return false;
    }
    return checkForChildrenSumPreorder(ptr->left) && checkForChildrenSumPreorder(ptr->right);
}

//Tested
bool checkForChildrenSumPreOrderIterative(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if(currentNode->left != null || currentNode->right != null) {
            if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                return false;
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
        }
    }
    return true;
}

//Tested
bool checkForChildrenSumInorder(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    if(!checkForChildrenSumInorder(ptr->left)) {
        return false;
    }
    int leftChildValue = ptr->left == null?0:ptr->left->value;
    int rightChildValue = ptr->right == null?0:ptr->right->value;
    if(ptr->value != leftChildValue+rightChildValue) {
        return false;
    }
    return checkForChildrenSumInorder(ptr->right);
}

//Tested
bool checkForChildrenSumInorderIterative(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(currentNode->left != null || currentNode->right != null) {
                if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                    return false;
                }
            }
            currentNode = currentNode->right;
        }
    }
    return true;
}

//Tested
bool checkForChildrenSumPostorder(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    if(!checkForChildrenSumInorder(ptr->left) || !checkForChildrenSumPostorder(ptr->right)) {
        return false;
    }
    int leftChildValue = ptr->left == null?0:ptr->left->value;
    int rightChildValue = ptr->right == null?0:ptr->right->value;
    return ptr->value == leftChildValue+rightChildValue;
}

//Tested
bool checkForChildrenSumPostOrderTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    itNode *currentNode;
    primaryAuxspace.push(ptr);
    while(!primaryAuxspace.empty()) {
        currentNode = primaryAuxspace.top();
        primaryAuxspace.pop();
        secondaryAuxspace.push(currentNode);
        if(currentNode->left != null) {
            primaryAuxspace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            primaryAuxspace.push(currentNode->right);
        }
    }
    while(!secondaryAuxspace.empty()) {
        currentNode = secondaryAuxspace.top();
        secondaryAuxspace.pop();
        if(currentNode->left != null || currentNode->right != null) {
            if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                return false;
            }
        }
    }
    return true;
}

//Tested
bool checkForChildrenSumPostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                if(currentNode->left != null || currentNode->right != null) {
                    if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                        return false;
                    }
                }
                currentNode = null;
            }
        }
    }
    return true;
}

//Tested
bool checkForChildrenSumPostOrderIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(currentNode->left != null || currentNode->right != null) {
                if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                    return false;
                }
            }
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                if(currentNode->left != null || currentNode->right != null) {
                    if(currentNode->value != (currentNode->left == null?0:currentNode->left->value) + (currentNode->right == null?0:currentNode->right->value)) {
                        return false;
                    }
                }
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return true;
}

//Tested
bool checkForChildrenSumLevelOrder(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right== null)) {
        return true;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    int childNodesSum = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        if(currentNode->left != null || currentNode->right != null) {
            childNodesSum = 0;
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
                childNodesSum += currentNode->left->value;
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
                childNodesSum += currentNode->right->value;
            }
            if(currentNode->value != childNodesSum) {
                return false;
            }
        }
    }
    return true;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool checkForChildrenSumAtLevel(itNode *ptr,unsigned int level) {
    if(ptr == null || (ptr->left == null && ptr->right == null)) {
        return true;
    }
    if(level == 0) {
        return ptr->value == (ptr->left == null?0:ptr->left->value) + (ptr->right == null?0:ptr->right->value);
    }
    return checkForChildrenSumAtLevel(ptr->left,level-1) && checkForChildrenSumAtLevel(ptr->right,level-1);
}

//Tested
bool checkForChildrenSumON2(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(unsigned int counter = 0; counter < height; counter++) {
        if(!checkForChildrenSumAtLevel(ptr,counter)) {
            return false;
        }
    }
    return true;
}

#endif /* CHECKFORCHILDRENSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
