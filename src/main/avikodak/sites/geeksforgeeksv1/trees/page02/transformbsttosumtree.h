/****************************************************************************************************************************************************
 *  File Name                   : transformbsttosumtree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\transformbsttosumtree.h
 *  Created on                  : Nov 16, 2014 :: 8:58:25 AM
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

#ifndef TRANSFORMBSTTOSUMTREE_H_
#define TRANSFORMBSTTOSUMTREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void transformToSumTreeReverseInorder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static int prevVal = 0;
    transformToSumTreeReverseInorder(ptr->right);
    prevVal += ptr->value;
    ptr->value = prevVal - ptr->value;
    transformToSumTreeReverseInorder(ptr->left);
}

void transformToSumTreeReverseInorderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currrentNode = ptr;
    int prevVal = 0;
    while(!auxSpace.empty() || currrentNode != null) {
        if(currrentNode != null) {
            auxSpace.push(currrentNode);
            currrentNode = currrentNode->right;
        } else {
            currrentNode = auxSpace.top();
            auxSpace.pop();
            prevVal += currrentNode->value;
            currrentNode->value = prevVal - currrentNode->value;
            currrentNode = currrentNode->left;
        }
    }
}

void transformToSumTreeReverseMorrisTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    int prevVal = 0;
    while(currentNode != null) {
        if(currentNode->right != null) {
            temp = currentNode->right;
            while(temp->left != null && temp->left != currentNode) {
                currentNode = currentNode->left;
            }
            if(temp->left == null) {
                temp->left = currentNode;
                currentNode = currentNode->right;
            } else {
                temp->left = null;
                prevVal += currentNode->value;
                currentNode->value = prevVal - currentNode->value;
                currentNode = currentNode->left;
            }
        } else {
            prevVal += currentNode->value;
            currentNode->value = prevVal - currentNode->value;
            currentNode = currentNode->left;
        }
    }
}

void tsFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    tsFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    tsFixLeftPtr(ptr->right);
}

void tsFixRightPtr(itNode **ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = *ptr,*prevNode = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    (*ptr) = currentNode;
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
}

void tsConvertTreeToDLLByFixingPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    tsFixLeftPtr(ptr);
    tsFixRightPtr(&ptr); // ptr changes to tail
    int prevVal = 0;
    while(ptr != null) {
        prevVal += ptr->value;
        ptr->value = prevVal - ptr->value;
        ptr = ptr->left;
    }
}

void tsConvertTreeToDllONMain(itNode *ptr,itNode **tail) {
    if(ptr == null) {
        return;
    }
    tsConvertTreeToDllONMain(ptr->left,tail);
    ptr->left = (*tail);
    if((*tail) != null) {
        (*tail)->right = ptr;
    }
    (*tail) = ptr;
    tsConvertTreeToDllONMain(ptr->right,tail);
}

void transformBSTToSumTree(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *tail = null;
    tsConvertTreeToDllONMain(ptr,&tail);
    int prevVal = 0;
    while(tail != null) {
        prevVal += tail->value;
        tail->value = prevVal - tail->value;
        tail = tail->left;
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getSumToReplace(vector<int> userInput,int key) {
    int sum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] > key) {
            sum += userInput[counter];
        }
    }
    return sum;
}

void tsTransformBSTToSumTree(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    vector<int> preOrder = utils->getValuesInPreorder(ptr);
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        currentNode->value = getSumToReplace(preOrder,currentNode->value);
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

itNode *tsConvertTreeToDLLON2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = tsConvertTreeToDLLON2(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = tsConvertTreeToDLLON2(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

#endif /* TRANSFORMBSTTOSUMTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
