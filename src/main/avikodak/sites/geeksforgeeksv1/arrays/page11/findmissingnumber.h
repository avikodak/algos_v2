/****************************************************************************************************************************************************
 *  File Name                   : findmissingnumber.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\findmissingnumber.h
 *  Created on                  : Oct 17, 2014 :: 6:26:42 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-the-missing-number/
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FINDMISSINGNUMBER_H_
#define FINDMISSINGNUMBER_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int findMissingNumberHashmap(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    hash_map<int,bool> visitedNumbers;
    hash_map<int,bool>::iterator itToVisitedNumbers;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        visitedNumbers.insert(pair<unsigned int,bool>(userInput[counter],true));
    }
    for(unsigned int counter = 1; counter <= userInput.size()+1; counter++) {
        itToVisitedNumbers = visitedNumbers.find(counter);
        if(itToVisitedNumbers == visitedNumbers.end()) {
            return counter;
        }
    }
    return INT_MAX;
}

//Tested
unsigned int findMissingNumberXOR(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    unsigned int xorArray = 0,xorNumbers = userInput.size()+1;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        xorArray ^= userInput[counter];
        xorNumbers ^= counter+1;
    }
    return xorArray ^ xorNumbers;
}

//Tested
unsigned int findMissingNumberSum(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    unsigned int sumOfArray = 0,requiredSum = userInput.size()+1;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        requiredSum += counter+1;
        sumOfArray += userInput[counter];
    }
    return requiredSum - sumOfArray;
}

//Tested
unsigned int findMissingNumberArrayFlags(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        userInput[abs(userInput[counter])-1] *= -1;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] > 0) {
            return counter+1;
        }
    }
    return userInput.size()+1;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int findMissingNumberONLOGN(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    sort(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] !=  counter+1) {
            return counter+1;
        }
    }
    return userInput.size()+1;
}

//Tested
void fmnRotateNodes(ipAvlNode *parent,ipAvlNode *child) {
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

//Tested
ipAvlNode *fmnInsertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value) {
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
            return currentNode;
        } else {
            return fmnInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ipAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return fmnInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void fmnInsertIntoAvlTree(ipAvlNode **root,int value) {
    ipAvlNode *z = fmnInsertAtRightPlace(root,*root,value);
    if(z == null) {
        return;
    }
    ipAvlNode *x,*y;
    int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight - rightHeight) > 0) {
            y = z->value > value?z->left:z->right;
            x = y->value > value?y->left:y->right;
            if((z->left == y && y->left == x)||(z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                fmnRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                fmnRotateNodes(y,x);
                fmnRotateNodes(z,x);
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
bool fmnSearchForValue(ipAvlNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    } else if(ptr->value > value) {
        return fmnSearchForValue(ptr->left,value);
    } else {
        return fmnSearchForValue(ptr->right,value);
    }
}

//Tested
int findMissingNumbersAvlTree(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    ipAvlNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        fmnInsertIntoAvlTree(&root,userInput[counter]);
    }
    for(unsigned int counter = 0; counter <= userInput.size()+2; counter++) {
        if(!fmnSearchForValue(root,counter+1)) {
            return counter+1;
        }
    }
    return 1;
}

//Tested
void fmnRotateNodes(iRbTreeNode *parent,iRbTreeNode *child) {
    if(parent == null || child == null) {
        return;
    }
    iRbTreeNode *grandParent = parent->parent;
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

//Tested
iRbTreeNode *fmnInsertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new iRbTreeNode(value);
        (*root)->isRedNode = false;
        return null;
    }
    if(currentNode->value == value) {
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new iRbTreeNode(value);
            currentNode->left->parent = currentNode;
            return currentNode->left;
        } else {
            return fmnInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new iRbTreeNode(value);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return fmnInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void fmnReorganiseTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode) {
    if(currentNode == null) {
        return;
    }
    iRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
    if(!parent->isRedNode) {
        return;
    }
    if(grandParent->left == parent) {
        if(grandParent->right == null || !grandParent->right->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            fmnRotateNodes(grandParent,parent);
            grandParent->isRedNode = true;
            parent->isRedNode = false;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            fmnReorganiseTreePostInsertion(root,grandParent);
        }
    } else {
        if(grandParent->left == null || !grandParent->left->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            fmnRotateNodes(grandParent,parent);
            grandParent->isRedNode = true;
            parent->isRedNode = false;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            fmnReorganiseTreePostInsertion(root,grandParent);
        }
    }
}

//Tested
void fmnInsertIntoRbTree(iRbTreeNode **root,int value) {
    iRbTreeNode *ptrToKey = fmnInsertAtRightPlace(root,*root,value);
    if(ptrToKey == null) {
        return;
    }
    if(!ptrToKey->parent->isRedNode) {
        return;
    }
    fmnReorganiseTreePostInsertion(root,ptrToKey);
}

//Tested
bool fmnSearchForValueInRbTree(iRbTreeNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    } else if(ptr->value > value) {
        return fmnSearchForValueInRbTree(ptr->left,value);
    } else {
        return fmnSearchForValueInRbTree(ptr->right,value);
    }
}

//Tested
unsigned int findMissingNumberRbTree(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    iRbTreeNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        fmnInsertIntoRbTree(&root,userInput[counter]);
    }
    for(unsigned int counter = 1; counter <= userInput.size()+2; counter++) {
        if(!fmnSearchForValueInRbTree(root,counter)) {
            return counter;
        }
    }
    return UINT_MAX;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int findMissingNumberON2(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    bool flag;
    for(unsigned int outerCounter = 1; outerCounter <= userInput.size()+1; outerCounter++) {
        flag = false;
        for(unsigned int innerCounter = 0; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[innerCounter] == outerCounter) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            return outerCounter;
        }
    }
    return UINT_MAX;
}

#endif /* FINDMISSINGNUMBER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
