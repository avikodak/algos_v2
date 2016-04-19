/****************************************************************************************************************************************************
 *  File Name                   : convertTreeToDllON.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\convertTreeToDllON.h
 *  Created on                  : Nov 13, 2014 :: 9:19:24 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
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

#ifndef CONVERTTREETODLLON_H_
#define CONVERTTREETODLLON_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void oFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    oFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    oFixLeftPtr(ptr->right);
}

//Tested
void oFixRightPtr(itNode **ptr) {
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

//Tested
void oConvertTreeToDLLONFixing(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    oFixLeftPtr(ptr);
    oFixRightPtr(&ptr);
    while(ptr !=null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

//Tested
void oConvertTreeToDLLONMain(itNode *ptr,itNode **head) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    oConvertTreeToDLLONMain(ptr->left,head);
    ptr->left = prevNode;
    if(prevNode == null) {
        (*head) = ptr;
    } else {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    oConvertTreeToDLLONMain(ptr->right,head);
}

//Tested
void oConvertTreeToDll(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *head =  null;
    oConvertTreeToDLLONMain(ptr,&head);
    while(head != null) {
        printf("%d\t",head->value);
        head = head->right;
    }
}

#endif /* CONVERTTREETODLLON_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
