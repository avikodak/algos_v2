/****************************************************************************************************************************************************
 *  File Name   		: twooddoccurence.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\twooddoccurence.h
 *  Created on			: Nov 27, 2014 :: 7:59:19 PM
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

#ifndef TWOODDOCCURENCE_H_
#define TWOODDOCCURENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoOddOccurenceHashmap(vector<int> userInput) {
    if(userInput.size() == 0) {
        return null;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()) {
            frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
        } else {
            frequencyMap[userInput[counter]] += 1;
        }
    }
    iPair *result = new iPair();
    for(itToFrequencyMap = frequencyMap.begin(); itToFrequencyMap != frequencyMap.end(); itToFrequencyMap++) {
        if(itToFrequencyMap->second % 2 == 1) {
            if(result->firstValue == INT_MAX) {
                result->firstValue = itToFrequencyMap->first;
            } else {
                result->secondValue = itToFrequencyMap->first;
                return result;
            }
        }
    }
    return result;
}

//Tested
int divideArrayOddOccurence(vector<int> &userInput,int xorResult) {
    int startCrawler = 0,endCrawler = userInput.size()-1;
    int setBitPosition = log2(xorResult&-xorResult)+1,temp;
    while(startCrawler < endCrawler) {
        while(!(userInput[startCrawler] & (1 << setBitPosition))) {
            startCrawler++;
        }
        while((userInput[endCrawler] & (1 << setBitPosition))) {
            endCrawler--;
        }
        if(startCrawler < endCrawler) {
            temp = userInput[startCrawler];
            userInput[startCrawler] = userInput[endCrawler];
            userInput[endCrawler] = temp;
        }
    }
    return endCrawler;
}

//Tested
iPair *getTwoOddOccurenceXOR(vector<int> userInput) {
    if(userInput.size() < 2) {
        return null;
    }
    int xorResult = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        xorResult ^= userInput[counter];
    }
    int dividingIndex = divideArrayOddOccurence(userInput,xorResult);
    iPair *result = new iPair(0,0);
    for(int counter = 0; counter <= dividingIndex; counter++) {
        result->firstValue ^= userInput[counter];
    }
    for(unsigned int counter = dividingIndex+1; counter <userInput.size(); counter++) {
        result->secondValue ^= userInput[counter];
    }
    return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoOddOccurenceSorting(vector<int> userInput) {
    if(userInput.size() < 2) {
        return null;
    }
    sort(userInput.begin(),userInput.end());
    unsigned int counter = 0,frequency;
    iPair *result = new iPair();
    while(counter < userInput.size()) {
        frequency = 1;
        while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]) {
            counter++;
            frequency++;
        }
        if(frequency%2 == 1) {
            if(result->firstValue == INT_MAX) {
                result->firstValue = userInput[counter];
            } else {
                result->secondValue = userInput[counter];
                return result;
            }
        }
        counter++;
    }
    return result;
}

//Tested
void toddoRotateNodes(ifpAvlNode *parent,ifpAvlNode *child) {
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

//Tested
ifpAvlNode *toddoInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value) {
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
            return toddoInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ifpAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return toddoInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void toddoInsertIntoAvlTree(ifpAvlNode **root,int value) {
    ifpAvlNode *z = toddoInsertAtRightPlace(root,*root,value);
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
                toddoRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,z->right == null?0:z->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                toddoRotateNodes(y,x);
                toddoRotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,z->right == null?0:z->right->height);
                x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z->height = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}

//Tested
void getTwoOddOccurenceInorderAvlTree(ifpAvlNode *ptr,iPair *result) {
    if(ptr == null) {
        return;
    }
    getTwoOddOccurenceInorderAvlTree(ptr->left,result);
    if(ptr->frequency%2 == 1) {
        if(result->firstValue == INT_MIN) {
            result->firstValue = ptr->value;
        } else {
            result->secondValue = ptr->value;
        }
    }
    getTwoOddOccurenceInorderAvlTree(ptr->right,result);
}

//Tested
iPair *getTwoOddOccurenceAvlTree(vector<int> userInput) {
    if(userInput.size() < 2) {
        return null;
    }
    ifpAvlNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        toddoInsertIntoAvlTree(&root,userInput[counter]);
    }
    iPair *result = new iPair(INT_MIN,INT_MIN);
    getTwoOddOccurenceInorderAvlTree(root,result);
    return result;
}

//Tested
void toddoRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ifRbTreeNode *grandParent = parent->parent;
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
ifRbTreeNode *toddoInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ifRbTreeNode(value);
        (*root)->isRedNode = false;
        return null;
    }
    if(currentNode->value == value) {
        currentNode->frequency += 1;
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ifRbTreeNode(value);
            currentNode->left->parent = currentNode;
            return currentNode->left;
        } else {
            return toddoInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ifRbTreeNode(value);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return toddoInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void toddoReorganizePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode) {
    if(*root == null || currentNode == null) {
        return;
    }
    ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
    if(!parent->isRedNode) {
        return;
    }
    if(grandParent->left == parent) {
        if(grandParent->right == null || !grandParent->right->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            toddoRotateNodes(grandParent,parent);
            parent->isRedNode = false;
            grandParent->isRedNode = true;
            return;
        } else {
            grandParent->isRedNode = false;
            grandParent->left->isRedNode = true;
            grandParent->right->isRedNode = true;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            toddoReorganizePostInsertion(root,grandParent);
        }
    } else {
        if(grandParent->left == null || !grandParent->left->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            toddoRotateNodes(grandParent,parent);
            parent->isRedNode = false;
            grandParent->isRedNode = true;
            return;
        } else {
            grandParent->isRedNode = false;
            grandParent->left->isRedNode = true;
            grandParent->right->isRedNode = true;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            toddoReorganizePostInsertion(root,grandParent);
        }
    }
}

//Tested
void toddoInsertIntoRBTree(ifRbTreeNode **root,int value) {
    ifRbTreeNode *ptrToKey = toddoInsertAtRightPlace(root,*root,value);
    if(ptrToKey == null) {
        return;
    }
    if(!ptrToKey->parent->isRedNode) {
        return;
    }
    toddoReorganizePostInsertion(root,ptrToKey);
}

//Tested
void setTwoOddOccurenceRbTreeInorder(ifRbTreeNode *ptr,iPair *result) {
    if(ptr == null) {
        return;
    }
    setTwoOddOccurenceRbTreeInorder(ptr->left,result);
    if(ptr->frequency % 2 == 1) {
        if(result->firstValue == INT_MIN) {
            result->firstValue = ptr->value;
        } else {
            result->secondValue = ptr->value;
        }
    }
    setTwoOddOccurenceRbTreeInorder(ptr->right,result);
}

//Tested
iPair *getTwoOddOccurenceRbTree(vector<int> userInput) {
    if(userInput.size() < 2) {
        return null;
    }
    ifRbTreeNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        toddoInsertIntoRBTree(&root,userInput[counter]);
    }
    iPair *result = new iPair(INT_MIN,INT_MIN);
    setTwoOddOccurenceRbTreeInorder(root,result);
    return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *twoOddOccurenceON2(vector<int> userInput) {
    if(userInput.size() < 2) {
        return 0;
    }
    unsigned int frequency = 0;
    iPair *result = new iPair(INT_MIN,INT_MIN);
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        frequency = 0;
        for(unsigned int innerCounter = 0; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[outerCounter] == userInput[innerCounter]) {
                frequency++;
            }
        }
        if(frequency%2 == 1) {
            if(result->firstValue != userInput[outerCounter]) {
                if(result->firstValue == INT_MIN) {
                    result->firstValue = userInput[outerCounter];
                } else {
                    result->secondValue = userInput[outerCounter];
                    return result;
                }
            }
        }
    }
    return null;
}

#endif /* TWOODDOCCURENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
