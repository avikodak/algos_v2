/****************************************************************************************************************************************************
 *  File Name   		: sortbyfrequency.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\sortbyfrequency.h
 *  Created on			: Nov 24, 2014 :: 11:28:10 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/sort-elements-by-frequency/
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

#ifndef SORTBYFREQUENCY_H_
#define SORTBYFREQUENCY_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int divideStepQuickSortFrequencyVector(vector<iFrequency *> &valueFrequency,int startIndex,int endIndex) {
    unsigned int key = valueFrequency[endIndex]->frequency;
    int pivotIndex = endIndex;
    while(startIndex < endIndex) {
        while(valueFrequency[startIndex]->frequency < key) {
            startIndex++;
        }
        while(startIndex < endIndex && valueFrequency[endIndex]->frequency >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(valueFrequency[startIndex],valueFrequency[endIndex]);
        }
    }
    swap(valueFrequency[pivotIndex],valueFrequency[endIndex]);
    return endIndex;
}

//Tested
void quickSortFrequencyVector(vector<iFrequency *> &valueFrequency,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return;
    }
    int dividingIndex = divideStepQuickSortFrequencyVector(valueFrequency,startIndex,endIndex);
    quickSortFrequencyVector(valueFrequency,startIndex,dividingIndex-1);
    quickSortFrequencyVector(valueFrequency,dividingIndex+1,endIndex);
}

//Tested
void sortByFrequency(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()) {
            frequencyMap[userInput[counter]] = 1;
        } else {
            frequencyMap[userInput[counter]] += 1;
        }
    }
    vector<iFrequency *> valueFrequency;
    for(itToFrequencyMap = frequencyMap.begin(); itToFrequencyMap != frequencyMap.end(); itToFrequencyMap++) {
        valueFrequency.push_back(new iFrequency(itToFrequencyMap->first,itToFrequencyMap->second));
    }
    quickSortFrequencyVector(valueFrequency,0,valueFrequency.size()-1);
    int fillCounter = -1;
    for(unsigned int counter = 0; counter < valueFrequency.size(); counter++) {
        while(valueFrequency[counter]->frequency--) {
            userInput[++fillCounter] = valueFrequency[counter]->value;
        }
    }
}

//Tested
void sbfRotateNodes(ifpAvlNode *parent,ifpAvlNode *child) {
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
void sbfInsertIntoAvlTre(ifpAvlNode **root,int value) {
    ifpAvlNode *z = sbfInsertAtRightPlace(root,*root,value);
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
                sbfRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                sbfRotateNodes(y,x);
                sbfRotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z = z->parent;
    }
}

//Tested
void setValueFrequencyInVectorAvlTree(ifpAvlNode *ptr,vector<iFrequency *> &valueFrequency) {
    if(ptr == null) {
        return;
    }
    setValueFrequencyInVectorAvlTree(ptr->left,valueFrequency);
    valueFrequency.push_back(new iFrequency(ptr->value,ptr->frequency));
    setValueFrequencyInVectorAvlTree(ptr->right,valueFrequency);
}

//Tested
void sortByFrequencyAvlTree(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    ifpAvlNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sbfInsertIntoAvlTre(&root,userInput[counter]);
    }
    vector<iFrequency *> valueFrequency;
    setValueFrequencyInVectorAvlTree(root,valueFrequency);
    quickSortFrequencyVector(valueFrequency,0,valueFrequency.size()-1);
    int fillCounter = -1;
    for(unsigned int counter = 0; counter < valueFrequency.size(); counter++) {
        while(valueFrequency[counter]->frequency--) {
            userInput[++fillCounter] = valueFrequency[counter]->value;
        }
    }
}

//Tested
void sbfRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child) {
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
ifRbTreeNode *sbfInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value) {
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
            return sbfInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ifRbTreeNode(value);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return sbfInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

//Tested
void sbfReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode) {
    if(currentNode == null) {
        return;
    }
    ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
    if(grandParent->left == parent) {
        if(grandParent->right == null || !grandParent->right->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            sbfRotateNodes(grandParent,parent);
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
            sbfReorganizeTreePostInsertion(root,grandParent);
        }
    } else {
        if(grandParent->left == null || !grandParent->left->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            sbfRotateNodes(grandParent,parent);
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
            sbfReorganizeTreePostInsertion(root,grandParent);
        }
    }
}

//Tested
void sbfInsertIntoRbTree(ifRbTreeNode **root,int value) {
    ifRbTreeNode *ptrToKey = sbfInsertAtRightPlace(root,*root,value);
    if(ptrToKey == null) {
        return;
    }
    if(!ptrToKey->parent->isRedNode) {
        return;
    }
    sbfReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
void setValueFrequencyInVectorRbTree(ifRbTreeNode *ptr,vector<iFrequency *> &valueFrequency) {
    if(ptr == null) {
        return;
    }
    setValueFrequencyInVectorRbTree(ptr->left,valueFrequency);
    valueFrequency.push_back(new iFrequency(ptr->value,ptr->frequency));
    setValueFrequencyInVectorRbTree(ptr->right,valueFrequency);
}

//Tested
void sbSortByFrequencyRbTree(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    ifRbTreeNode *root = null;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sbfInsertIntoRbTree(&root,userInput[counter]);
    }
    vector<iFrequency *> valueFrequency;
    setValueFrequencyInVectorRbTree(root,valueFrequency);
    quickSortFrequencyVector(valueFrequency,0,valueFrequency.size()-1);
    int fillCounter = -1;
    for(unsigned int counter = 0; counter < valueFrequency.size(); counter++) {
        while(valueFrequency[counter]->frequency--) {
            userInput[++fillCounter] = valueFrequency[counter]->value;
        }
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SORTBYFREQUENCY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
