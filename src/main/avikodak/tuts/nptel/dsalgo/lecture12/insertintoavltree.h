/****************************************************************************************************************************************************
 *  File Name   		: insertintoavltree.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture12\insertintoavltree.h
 *  Created on			: Nov 18, 2014 :: 10:41:00 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef INSERTINTOAVLTREE_H_
#define INSERTINTOAVLTREE_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
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

iptNode *insertAtRightPlace(ipAvlNode *ptr,int value) {
    if(ptr->value == value) {
        return null;
    } else if(ptr->value > value) {
        if(ptr->left == null) {
            ptr->left = new ipAvlNode(value);
            ptr->left->parent = ptr;
            return ptr;
        } else {
            return insertAtRightPlace(ptr->left,value);
        }
    } else {
        if(ptr->right == null) {
            ptr->right = new ipAvlNode(value);
            ptr->right->parent = ptr;
            return ptr;
        } else {
            return insertAtRightPlace(ptr->right,value);
        }
    }
}

void insertIntoAvlTree(ipAvlNode **root,int value) {
    if(*root == null) {
        (*root) = new ipvlNode(value);
        return;
    } else {
        iptNode *currentNode = insertAtRightPlace(*root,value);
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
                    rotateNodes(x,z);
                    z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                    y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                    x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
                }
                return;
            }
            z->height = max(leftHeight,rightHeight) + 1;
            z = z->parent;
        }
    }
}

#endif /* INSERTINTOAVLTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
