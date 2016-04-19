/****************************************************************************************************************************************************
 *  File Name                   : sortbyfrequencyavltree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\sortbyfrequencyavltree.h
 *  Created on                  : Dec 22, 2014 :: 9:06:38 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/sort-elements-by-frequency-set-2/
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

#ifndef SORTBYFREQUENCYAVLTREE_H_
#define SORTBYFREQUENCYAVLTREE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void sbfRotateNodes(ifpAvlNode *parent,ifpAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ifpAvlNode *grandParent = parent->parent;
    parent->parent = grandParent;
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

//Tested
ifpAvlNode *sbfInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value) {
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
            return sbfInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ifpAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return sbfInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void sbfInsertIntoAvlTree(ifpAvlNode **root,int value) {
    ifpAvlNode *z = sbfInsertAtRightPlace(root,*root,value);
    if(z == null) {
        return;
    }
    ifpAvlNode *x,*y;
    int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight - rightHeight) > 1) {
            y = z->value > value?z->left:z->right;
            x = y->value > value?y->left:y->right;
            if((z->left == y && y->left == x) || (z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                sbfRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = y;
                }
                sbfRotateNodes(y,x);
                sbfRotateNodes(z,x);
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

//Tested
void getVectorForValFreqAvlTree(ifpAvlNode *ptr,vector<iFrequency *> &auxSpace) {
    if(ptr == null) {
        return;
    }
    getVectorForValFreqAvlTree(ptr->left,auxSpace);
    auxSpace.push_back(new iFrequency(ptr->value,ptr->frequency));
    getVectorForValFreqAvlTree(ptr->right,auxSpace);
}

//Tested
void mergeStepFrequency(vector<iFrequency *> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    vector<iFrequency *> auxSpace;
    int firstCrawler = startIndex, secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler]->frequency >= userInput[secondCrawler]->frequency) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        }
    }
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        userInput[startIndex + counter] = auxSpace[counter];
    }
}

//Tested
void mergeSortByFrequency(vector<iFrequency *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    mergeSortByFrequency(userInput,startIndex,middleIndex);
    mergeSortByFrequency(userInput,middleIndex+1,endIndex);
    mergeStepFrequency(userInput,startIndex,middleIndex,endIndex);
}

//Tested
void sortByFrequency(vector<int> &userInput) {
    if(userInput.size() < 3) {
        return;
    }
    ifpAvlNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sbfInsertIntoAvlTree(&root,userInput[counter]);
    }
    vector<iFrequency *> auxSpace;
    getVectorForValFreqAvlTree(root,auxSpace);
    mergeSortByFrequency(auxSpace,0,auxSpace.size()-1);
    int fillCounter = -1;
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        while(auxSpace[counter]->frequency--) {
            userInput[++fillCounter] = auxSpace[counter]->value;
        }
    }
}

#endif /* SORTBYFREQUENCYAVLTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
