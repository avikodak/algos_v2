/****************************************************************************************************************************************************
 *  File Name                   : unionintersectionsortedarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\unionintersectionsortedarray.h
 *  Created on                  : Nov 26, 2014 :: 1:30:42 AM
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

#ifndef UNIONINTERSECTIONSORTEDARRAY_H_
#define UNIONINTERSECTIONSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
iPairVector *getUnionIntersectionSortedArray(vector<int> firstSortedUserinput,vector<int> secondSortedUserinput) {
    if(firstSortedUserinput.size() == 0 && secondSortedUserinput.size() == 0) {
        return null;
    }
    vector<int> unionOfArrays,intersectionOfArrays;
    int firstCrawler = 0,secondCrawler = 0;
    while(firstCrawler < firstSortedUserinput.size() || secondCrawler < secondSortedUserinput.size()) {
        if(firstCrawler >= firstSortedUserinput.size() || secondCrawler >= secondSortedUserinput.size()) {
            if(firstCrawler < firstSortedUserinput.size()) {
                if(unionOfArrays.size() != 0 && unionOfArrays[unionOfArrays.size()-1] != firstSortedUserinput[firstCrawler]) {
                    unionOfArrays.push_back(firstSortedUserinput[firstCrawler]);
                }
                firstCrawler++;
            } else {
                if(unionOfArrays.size() != 0 && unionOfArrays[unionOfArrays.size()-1] != secondSortedUserinput[secondCrawler]) {
                    unionOfArrays.push_back(secondSortedUserinput[firstCrawler]);
                }
                secondCrawler++;
            }
        } else {
            if(firstSortedUserinput[firstCrawler] == secondSortedUserinput[secondCrawler]) {
                intersectionOfArrays.push_back(firstSortedUserinput[firstCrawler]);
                if(unionOfArrays.size() != 0 && unionOfArrays[unionOfArrays.size()-1] != firstSortedUserinput[firstCrawler]) {
                    unionOfArrays.push_back(firstSortedUserinput[firstCrawler]);
                }
                firstCrawler++;
                secondCrawler++;
            } else if(firstSortedUserinput[firstCrawler] < secondSortedUserinput[secondCrawler]) {
                if(unionOfArrays.size() != 0 && unionOfArrays[unionOfArrays.size()-1] != firstSortedUserinput[firstCrawler]) {
                    unionOfArrays.push_back(firstSortedUserinput[firstCrawler]);
                }
                firstCrawler++;
            } else {
                if(unionOfArrays.size() != 0 && unionOfArrays[unionOfArrays.size()-1] != secondSortedUserinput[secondCrawler]) {
                    unionOfArrays.push_back(secondSortedUserinput[firstCrawler]);
                }
                secondCrawler++;
            }
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void uisaRotateNodes(ifpAvlNode *parent,ifpAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ifpAvlNode *grandParent = parent->parent;
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

ifpAvlNode *uisaInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ifpAvlNode(value);
        return null;
    }
    if(currentNode->value == value) {
        currentNode->frequency += 1;
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ifpAvlNode(value);
            currentNode->left->parent = currentNode;
            return currentNode;
        } else {
            return uisaInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ifpAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return uisaInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

void uisaInsertIntoAvlTree(ifpAvlNode **root,int value) {
    ifpAvlNode *z = uisaInsertAtRightPlace(root,*root,value);
    if(z == null) {
        return;
    }
    ifpAvlNode *y,*x;
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
                uisaRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                uisaRotateNodes(y,x);
                uisaRotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                y->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z->height = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}



/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* UNIONINTERSECTIONSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
