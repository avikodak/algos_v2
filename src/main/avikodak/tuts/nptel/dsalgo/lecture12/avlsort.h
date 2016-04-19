/****************************************************************************************************************************************************
 *  File Name                   : avlsort.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture12\avlsort.h
 *  Created on                  : Nov 19, 2014 :: 2:11:29 AM
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

#ifndef AVLSORT_H_
#define AVLSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void rotateNodes(ipAvlNode *parent,ipAvlNode *child) {
    ipAvlNode *grandParent = parent->parent;
    child->parent = grandParent;
    if(grandParent != null) {
        if(grandParent->left == parent) {
            grandParent->left = child;
        } else {
            grandParent->right = child;
        }
    }
    parent->parent = child;
    if(parent->left == child) {
        parent->left = child->right;
        child->right = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
}

ipAvlNode *insertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ipAvlNode(value);
        return null;
    }
    if(currentNode->value == value) {
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ipAvlNode(value);
            currentNode->left->parent = currentNode;
            return currentNode->left;
        } else {
            return insertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ipAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return insertAtRightPlace(root,currentNode->right,value);
        }
    }

}

void insertValueIntoAvlTree(ipAvlNode **root,int value) {
    ipAvlNode *ptrToKey = insertAtRightPlace(root,*root,value);
    if(ptrToKey == null) {
        return;
    }
    ipAvlNode *x,*y,*z = ptrToKey;
    unsigned int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight - rightHeight) > 1) {
            y = z->value > value?z->left:z->right;
            x = y->value > value?y->left:y->right;
            if((z->left == y && y->left == x)||(z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                rotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                rotateNodes(y,x);
                rotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z->height = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}

void setInorderValuesIntoVector(ipAvlNode *ptr,vector<int> &userInput) {
    static int counter = 0;
    if(ptr == null) {
        return;
    }
    setInorderValuesIntoVector(ptr->left,userInput);
    userInput[counter++] = ptr->value;
    setInorderValuesIntoVector(ptr->right,userInput);
}

void avlSort(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    ipAvlNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        insertValueIntoAvlTree(&root,userInput[counter]);
    }
    setInorderValuesIntoVector(root,userInput);
}

#endif /* AVLSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
