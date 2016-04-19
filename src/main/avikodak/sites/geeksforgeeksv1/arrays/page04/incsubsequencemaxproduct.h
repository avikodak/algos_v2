/****************************************************************************************************************************************************
 *  File Name                   : incsubsequencemaxproduct.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\incsubsequencemaxproduct.h
 *  Created on                  : Jan 19, 2015 :: 10:58:42 AM
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

#ifndef INCSUBSEQUENCEMAXPRODUCT_H_
#define INCSUBSEQUENCEMAXPRODUCT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void incSubRotateNodes(ipAvlNode *parent,ipAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ipAvlNode *grandParent = parent->parent;
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

void incSubInsertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ipAvlNode(value);
        return null;
    }
    if(currentNode->value == value) {
        return null;
    }
    if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ipAvlNode(value);
            currentNode->left->parent = currentNode;
            return currentNode;
        } else {
            return incSubInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right== null) {
            currentNode->right = new ipAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return incSubInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

void incSubInsertIntoAvlTree(ipAvlNode **root,int value) {
    ipAvlNode *z = incSubInsertAtRightPlace(root,*root,value);
    if(z == null) {
        return;
    }
    ipAvlNode *y,*x;
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
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z->left = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}

ipAvlNode *incSubGetFloorForValueAvlTree(ipAvlNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        return ptr;
    }
    if(ptr->value > value) {
        return incSubGetFloorForValueAvlTree(ptr->left,value);
    } else {
        ipAvlNode *floor = incSubGetFloorForValueAvlTree(ptr->right,value);
        return floor == null?ptr:floor;
    }
}

int incSubsequenceLengthThreeMaxProduct(vector<int> userInput) {
    if(userInput.size() < 3) {
        return INT_MIN;
    }
    vector<int> auxSpace;
    ipAvlNode *root = null,*floor;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        floor = incSubGetFloorForValueAvlTree(root,userInput[counter]);
        auxSpace.push_back(floor == null?INT_MIN:floor->value);
        incSubInsertIntoAvlTree(root,userInput[counter]);
    }
    int maxTillNow = userInput[userInput.size()-1];
    int maxProduct = INT_MIN;
    for(unsigned int counter = userInput.size()-2; counter > 0; counter--) {
        if(maxTillNow > userInput[counter] && auxSpace[counter] != INT_MIN) {
            maxProduct = max(maxProduct,userInput[counter] * auxSpace[counter] * maxTillNow);
        }
        maxTillNow = max(maxTillNow,userInput[counter]);
    }
    return maxProduct;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int incSubsequenceMaxProduct(vector<int> userInput) {
    if(userInput.size() < 3) {
        return INT_MIN;
    }
    int maxProduct = INT_MIN;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-2; outerCrawler++) {
        for(unsigned int middleCrawler = outerCrawler+1; middleCrawler < userInput.size()-1; middleCrawler++) {
            for(unsigned int innerCrawler = middleCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
                if(userInput[innerCrawler] > userInput[middleCrawler] && userInput[middleCrawler] > userInput[outerCrawler]) {
                    maxProduct = max(maxProduct,userInput[outerCrawler] * userInput[middleCrawler] * userInput[innerCrawler]);
                }
            }
        }
    }
    return maxProduct;
}

#endif /* INCSUBSEQUENCEMAXPRODUCT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
