/****************************************************************************************************************************************************
 *  File Name   		: addgreatervaluesbst.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page03\addgreatervaluesbst.h
 *  Created on			: Nov 14, 2014 :: 8:22:36 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/add-greater-values-every-node-given-bst/
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

#ifndef ADDGREATERVALUESBST_H_
#define ADDGREATERVALUESBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void addGreaterValuesBST(itNode *ptr) {
    static int prevValue = 0;
    if(ptr == null) {
        return;
    }
    addGreaterValuesBST(ptr->right);
    ptr->value += prevValue;
    prevValue = ptr->value;
    addGreaterValuesBST(ptr->left);
}

//Tested
void addGreaterValueBSTIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    int prevValue = 0;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->right;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            prevValue = currentNode->value += prevValue;
            currentNode = currentNode->left;
        }
    }
}

void gFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    gFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    gFixLeftPtr(ptr->right);
}

void gFixRightPtr(itNode **ptr) {
    if(*ptr == null) {
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

void agConvertTreeToDLLON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = ptr;
    agConvertTreeToDLLON(ptr->left);
    ptr->left = prevNode;
    if(prevNode != null) {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    agConvertTreeToDLLON(ptr->right);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *agConvertTreeToDLLON2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = agConvertTreeToDLLON2(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = agConvertTreeToDLLON2(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

#endif /* ADDGREATERVALUESBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
