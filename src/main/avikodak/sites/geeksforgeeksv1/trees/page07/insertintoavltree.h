/****************************************************************************************************************************************************
 *  File Name                   : insertintoavltree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\insertintoavltree.h
 *  Created on                  : Nov 19, 2014 :: 1:52:21 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
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

#ifndef INSERTINTOAVLTREE_H_
#define INSERTINTOAVLTREE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void rotateNodes(ipAvlNode *parent,ipAvlNode *child) {
    ipAvlNode *grandParent = parent->parent;
    child->parent  = grandParent;
    parent->parent = child;
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

//Tested
ipAvlNode *insertNodeAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ipAvlNode(value);
        return null;
    } else {
        if(currentNode->value == value) {
            return null;
        } else if(currentNode->value > value) {
            if(currentNode->left == null) {
                currentNode->left = new ipAvlNode(value);
                currentNode->left->parent = currentNode;
                return currentNode;
            } else {
                return insertNodeAtRightPlace(root,currentNode->left,value);
            }
        } else {
            if(currentNode->right == null) {
                currentNode->right = new ipAvlNode(value);
                currentNode->right->parent = currentNode;
                return currentNode;
            } else {
                return insertNodeAtRightPlace(root,currentNode->right,value);
            }
        }
    }
}

//Tested
void insertIntoAvlTree(ipAvlNode **root,int value) {
    ipAvlNode *currentNode = insertNodeAtRightPlace(root,*root,value);
    if(currentNode == null) {
        return;
    }
    ipAvlNode *z = currentNode,*y,*x;
    int leftHeight,rightHeight;
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

#endif /* INSERTINTOAVLTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
