/****************************************************************************************************************************************************
 *  File Name                   : findconflictingappointments.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\findconflictingappointments.h
 *  Created on                  : Jan 22, 2015 :: 9:05:31 PM
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

#ifndef FINDCONFLICTINGAPPOINTMENTS_H_
#define FINDCONFLICTINGAPPOINTMENTS_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void fcaRotateNodes(intervalpAvlNode *parent,intervalpAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    intervalpAvlNode *grandParent = parent->parent;
    parent->parent = child;
    child->parent = grandParent;
    if(grandParent != null) {
        if(grandParent->left == parent) {
            grandParent->left = child;
        } else {
            grandParent->right = child;
        }
    }
    if(parent->left == child) {
        parent->left = child->right;
        child->right = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
}

intervalpAvlNode *fcaInsertAtRightPlace(intervalpAvlNode **root,intervalpAvlNode *currentNode,iInterval *userInput) {
    if(*root == null) {
        (*root) = new intervalpAvlNode(userInput->start,userInput->end);
        return null;
    }
    if(currentNode->start == userInput->start) {
        if(currentNode->end != userInput->end) {
            currentNode->right = new intervalpAvlNode(userInput->start,userInput->end);
            currentNode->right->parent = currentNode;
            return currentNode;
        }
        return null;
    } else if(currentNode->start > userInput->start) {
        if(currentNode->left == null) {
            currentNode->left = new intervalpAvlNode(userInput->start,userInput->end);
            currentNode->left->parent = currentNode;
            return currentNode;
        } else {
            return fcaInsertAtRightPlace(root,currentNode->left,userInput);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new intervalpAvlNode(userInput->start,userInput->end);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return fcaInsertAtRightPlace(root,currentNode->right,userInput);
        }
    }
}

void fcaSetMaxValue(intervalpAvlNode *ptr) {
    int maxValue = ptr->end;
    if(ptr->left != null) {
        maxValue = max(maxValue,ptr->left->max);
    }
    if(ptr->right != null) {
        maxValue = max(maxValue,ptr->right->max);
    }
    ptr->max = maxValue;
}

void fcaInsertIntoAVLTree(intervalpAvlNode **root,iInterval *userInput) {
    intervalpAvlNode *z = fcaInsertAtRightPlace(root,*root,userInput);
    if(z == null) {
        return;
    }
    intervalpAvlNode *y,*x;
    int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight - rightHeight) > 0) {
            y = z->start > userInput->start?z->left:z->right;
            x = y->start > userInput->start?y->left:y->right;
            if((z->left == y && y->left == x) || (z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                fcaRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                fcaSetMaxValue(z);
                fcaSetMaxValue(y);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                fcaRotateNodes(y,x);
                fcaRotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                fcaSetMaxValue(z);
                fcaSetMaxValue(y);
                fcaSetMaxValue(x);
            }
            return;
        }
        z->height = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}

intervalpAvlNode *isIntervalConflicting(intervalpAvlNode *ptr,iInterval *userInput) {
    if(ptr == null) {
        return null;
    }
    if(ptr->start < userInput->end && userInput->start < ptr->start) {
        return ptr;
    }
    if(ptr->left != null && ptr->left->max >= userInput->start) {
        return isIntervalConflicting(ptr->left,userInput);
    } else {
        return isIntervalConflicting(ptr->right,userInput);
    }
}

void printConflictingIntervals(vector<iInterval *> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    intervalpAvlNode *root = null,*temp;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(isIntervalConflicting(root,userInput[counter])) {
            temp = isIntervalConflicting(root,userInput[counter]);
            if(temp != null) {
                printf("[%d,%d] - [%d,%d]",userInput[counter]->start,userInput[counter]->end,temp->start,temp->end);
            }
        }
        fcaInsertIntoAVLTree(&root,userInput[counter]);
    }
    return;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* FINDCONFLICTINGAPPOINTMENTS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
