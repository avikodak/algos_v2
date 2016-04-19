/****************************************************************************************************************************************************
 *  File Name   		: reverseinordertraversal.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\reverseinordertraversal.h
 *  Created on			: Nov 11, 2014 :: 5:35:13 PM
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

#ifndef REVERSEINORDERTRAVERSAL_H_
#define REVERSEINORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseInOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    reverseInOrderTraversal(ptr->right);
    printf("%d\t",ptr->value);
    reverseInOrderTraversal(ptr->left);
}

//Tested
void reverseInOrderTraversalIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

//Tested
void reverseMorrisInOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    while(currentNode != null) {
        if(currentNode->right != null) {
            temp = currentNode->right;
            while(temp->left != null && temp->left != currentNode) {
                temp = temp->left;
            }
            if(temp->left == null) {
                temp->left = currentNode;
                currentNode = currentNode->right;
            } else {
                temp->left = null;
                printf("%d\t",currentNode->value);
                currentNode = currentNode->left;
            }
        } else {
            printf("%d\t",currentNode->value);
            currentNode = currentNode->left;
        }
    }
}

//Tested
void reverseInOrderTraversalAuxspace(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    vector<int> valuesInorder = utils->getValuesInInorder(ptr);
    for(int counter = valuesInorder.size()-1; counter >= 0; counter--) {
        printf("%d\t",valuesInorder[counter]);
    }
}

//Tested
void rFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    rFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    rFixLeftPtr(ptr->right);
}

//Tested
void rFixRightPtr(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    itNode *currentNode = *ptr,*prevNode = null;
    while(currentNode != null) {
        (*ptr) = currentNode;
        currentNode = currentNode->right;
    }
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
    }
}

//Tested
void reverseInOrderByFixingPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    rFixLeftPtr(ptr);
    rFixRightPtr(&ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->left;
    }
}

//Tested
void treeToDllON(itNode **root,itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    treeToDllON(root,ptr->left);
    ptr->left = prevNode;
    if(prevNode != null) {
        prevNode->right = ptr;
    }
    (*root) = ptr;
    prevNode = ptr;
    treeToDllON(root,ptr->right);
}

//Tested
void reverseInOrderTraversalDllConversionON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeToDllON(&ptr,ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->left;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *rTreeToDllON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    if(ptr->left != null) {
        itNode *leftSubtree = rTreeToDllON2Main(ptr->left);
        while(leftSubtree->right != null) {
            leftSubtree = leftSubtree->right;
        }
        leftSubtree->right = ptr;
        ptr->left = leftSubtree;
    }
    if(ptr->right != null) {
        itNode *rightSubtree = rTreeToDllON2Main(ptr->right);
        while(rightSubtree->left != null) {
            rightSubtree = rightSubtree->left;
        }
        rightSubtree->left = ptr;
        ptr->right = rightSubtree;
    }
    return ptr;
}

//Tested
void reverseInorderTraversalDllConversion(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    rTreeToDllON2Main(ptr);
    while(ptr->right != null) {
        ptr = ptr->right;
    }
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->left;
    }
}

#endif /* REVERSEINORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
