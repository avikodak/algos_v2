/****************************************************************************************************************************************************
 *  File Name                   : countsmallerrightside.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\countsmallerrightside.h
 *  Created on                  : Nov 27, 2014 :: 7:51:13 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/count-smaller-elements-on-right-side/
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

#ifndef COUNTSMALLERRIGHTSIDE_H_
#define COUNTSMALLERRIGHTSIDE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//This does not work with normal bst
void getAuxBSTFromVector(itAuxNode **root,itAuxNode *current,vector<int> userInput,unsigned int counter) {
    if(counter >= userInput.size()) {
        return;
    }
    if(*root == null) {
        (*root) = new itAuxNode(userInput[counter]);
        getAuxBSTFromVector(root,*root,userInput,counter+1);
    } else {
        if(current->value == userInput[counter]) {
            return;
        } else if(current->value > userInput[counter]) {
            if(current->left == null) {
                current->left = new itAuxNode(userInput[counter]);
                current->auxValue += 1;
                getAuxBSTFromVector(root,*root,userInput,counter+1);
            } else {
                current->auxValue += 1;
                getAuxBSTFromVector(root,current->left,userInput,counter);
            }
        } else {
            if(current->right == null) {
                current->right = new itAuxNode(userInput[counter]);
                getAuxBSTFromVector(root,*root,userInput,counter+1);
            } else {
                getAuxBSTFromVector(root,current->right,userInput,counter);
            }
        }
    }
}

itAuxNode *csrSearch(itAuxNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        return ptr;
    } else if(ptr->value > value) {
        return csrSearch(ptr->left,value);
    } else {
        return csrSearch(ptr->right,value);
    }
}

//This does not work with normal bst
vector<int> countSmallerValueRightSideBST(vector<int> userInput) {
    vector<int> countSmallerElements;
    if(userInput.size() == 0) {
        return countSmallerElements;
    }
    itAuxNode *root = null,*temp;
    getAuxBSTFromVector(&root,root,userInput,0);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        temp = csrSearch(root,userInput[counter]);
        countSmallerElements.push_back(temp->auxValue);
    }
    return countSmallerElements;
}

void csrRotateNodes(ipAuxAvlNode *parent,ipAuxAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ipAuxAvlNode *grandParent = parent->parent;
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

ipAuxAvlNode *csrInsertAtRightPlace(ipAuxAvlNode **root,ipAuxAvlNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ipAuxAvlNode(value);
        return null;
    }
    if(currentNode->value == value) {
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ipAuxAvlNode(value);
            currentNode->left->parent = currentNode;
            currentNode->left->auxVal += 1;
            return currentNode;
        } else {
            currentNode->auxVal += 1;
            return csrInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ipAuxAvlNode(value);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return csrInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

void csrInsertIntoAvlTree(ipAuxAvlNode **root,int value) {
    ipAuxAvlNode *z = csrInsertAtRightPlace(root,*root,value);
    if(z == null) {
        return;
    }
    ipAuxAvlNode *y,*x;
    int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight-rightHeight) > 1) {
            y = z->value > value?z->left:z->right;
            x = y->value > value?y->left:y->right;
            if((z->left == y && y->left == x)||(z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                csrRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                csrRotateNodes(y,x);
                csrRotateNodes(z,x);
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

ipAuxAvlNode *csrSearch(ipAuxAvlNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        return ptr;
    } else if(ptr->value > value) {
        return csrSearch(ptr->left,value);
    } else {
        return csrSearch(ptr->right,value);
    }
}

vector<int> countSmallerValueRightSideAVL(vector<int> userInput) {
    vector<int> countSmallerElements;
    if(userInput.size() == 0) {
        return countSmallerElements;
    }
    ipAuxAvlNode *root = null,*temp;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        csrInsertIntoAvlTree(&root,userInput[counter]);
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        temp = csrSearch(root,userInput[counter]);
        countSmallerElements.push_back(temp->auxVal);
    }
    return countSmallerElements;
}


void csrRotateNodes(ipAuxRbTreeNode *parent,ipAuxRbTreeNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ipAuxRbTreeNode *grandParent = parent->parent;
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

ipAuxRbTreeNode *csrInsertAtRightPlace(ipAuxRbTreeNode **root,ipAuxRbTreeNode *currentNode,int value) {
    if(*root == null) {
        (*root) = new ipAuxRbTreeNode(value);
        (*root)->isRedNode = false;
        return null;
    }
    if(currentNode->value == value) {
        return null;
    } else if(currentNode->value > value) {
        if(currentNode->left == null) {
            currentNode->left = new ipAuxRbTreeNode(value);
            currentNode->left->parent = currentNode;
            currentNode->left->auxVal += 1;
            return currentNode->left;
        } else {
            currentNode->auxVal += 1;
            return csrInsertAtRightPlace(root,currentNode->left,value);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new ipAuxRbTreeNode(value);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return csrInsertAtRightPlace(root,currentNode->right,value);
        }
    }
}

void csrReorganizeTreePostInsertion(ipAuxRbTreeNode **root,ipAuxRbTreeNode *currentNode) {
    if(*root == null || currentNode == null) {
        return;
    }
    ipAuxRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
    if(!parent->isRedNode) {
        return;
    }
    if(grandParent->left == null) {
        if(grandParent->right == null && !grandParent->right->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            csrRotateNodes(grandParent,parent);
            parent->isRedNode = false;
            grandParent->isRedNode = true;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            csrReorganizeTreePostInsertion(root,grandParent);
        }
    } else {
        if(grandParent->left == null && !grandParent->left->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            csrRotateNodes(grandParent,parent);
            parent->isRedNode = false;
            grandParent->isRedNode = true;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            csrReorganizeTreePostInsertion(root,grandParent);
        }
    }
}

void csrInsertIntoRbTree(ipAuxRbTreeNode **root,int value) {
    ipAuxRbTreeNode *ptrToKey = csrInsertAtRightPlace(root,*root,value);
    if(ptrToKey == null) {
        return;
    }
    if(!ptrToKey->parent->isRedNode) {
        return;
    }
    csrReorganizeTreePostInsertion(root,ptrToKey);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
vector<int> countSmallerValuesRightSide(vector<int> userInput) {
    vector<int> countSmallerElements;
    if(userInput.size() == 0) {
        return countSmallerElements;
    }
    int count;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-1; outerCounter++) {
        count = 0;
        for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[outerCounter] > userInput[innerCounter]) {
                count += 1;
            }
        }
        countSmallerElements.push_back(count);
    }
    countSmallerElements.push_back(0);
    return countSmallerElements;
}

#endif /* COUNTSMALLERRIGHTSIDE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
