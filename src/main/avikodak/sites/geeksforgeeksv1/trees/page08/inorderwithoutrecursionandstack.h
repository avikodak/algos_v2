/****************************************************************************************************************************************************
 *  File Name   		: inorderwithoutrecursionandstack.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\inorderwithoutrecursionandstack.h
 *  Created on			: Oct 17, 2014 :: 10:30:22 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
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

#ifndef INORDERWITHOUTRECURSIONANDSTACK_H_
#define INORDERWITHOUTRECURSIONANDSTACK_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void imorrisInorderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                printf("%d\t",currentNode->value);
                currentNode = currentNode->right;
            }
        } else {
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

//RECURSIVE PROCEDURES
//Tested
void iFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    iFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    iFixLeftPtr(ptr->right);
}

//Tested
void iFixRightPtr(itNode **ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = *ptr,*prevNode = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
    (*ptr) = prevNode;
}

void inorderTraversalFixingPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    iFixLeftPtr(ptr);
    iFixRightPtr(&ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

//Tested
void inorderTraversalDllConversionONMain(itNode *ptr,itNode **root) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    inorderTraversalDllConversionONMain(ptr->left,root);
    ptr->left = prevNode;
    if(prevNode == null) {
        (*root) = ptr;
    } else {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    inorderTraversalDllConversionONMain(ptr->right,root);
}

//Tested
void inorderTraversalDllConversionON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inorderTraversalDllConversionONMain(ptr,&ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

//Tested
itNode *inorderTraversalDllConversionON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = inorderTraversalDllConversionON2Main(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = inorderTraversalDllConversionON2Main(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
void inorderTraversalDllConversionON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inorderTraversalDllConversionON2Main(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}


#endif /* INORDERWITHOUTRECURSIONANDSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
