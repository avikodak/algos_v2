/****************************************************************************************************************************************************
 *  File Name                   : kthSmallestBST.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\kthSmallestBST.h
 *  Created on                  : Oct 20, 2014 :: 7:17:27 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
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

#ifndef KTHSMALLESTBST_H_
#define KTHSMALLESTBST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *getKthSmallestBST(itNode *ptr,unsigned int &kValue) {
    if(ptr == null) {
        return null;
    }
    itNode *leftResult = getKthSmallestBST(ptr->left,kValue);
    if(leftResult != null) {
        return leftResult;
    }
    kValue--;
    if(kValue == 0) {
        return ptr;
    }
    return getKthSmallestBST(ptr->right,kValue);
}

//Tested
itAuxNode *getKthSmallestBst(itAuxNode *ptr,unsigned int kValue) {
    if(ptr == null) {
        return null;
    }
    if(ptr->auxValue + 1 == kValue) {
        return ptr;
    }
    if(ptr->auxValue + 1 > kValue) {
        return getKthSmallestBst(ptr->left,kValue);
    } else {
        return getKthSmallestBst(ptr->right,kValue - ptr->auxValue - 1);
    }
}

//Tested
void kFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    kFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    kFixLeftPtr(ptr->right);
}

//Tested
void kFixRightPtr(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    itNode *currentNode = *ptr;
    itNode *prevNode = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
    *ptr = prevNode;
}

//Tested
itNode *getKthSmallestBSTDllConversion(itNode *ptr,unsigned int kValue) {
    if(ptr == null) {
        return null;
    }
    kFixLeftPtr(ptr);
    kFixRightPtr(&ptr);
    while(ptr != null && --kValue) {
        ptr = ptr->right;
    }
    return ptr;
}

//Tested
void convertTreeToDLLON(itNode *ptr,itNode **head) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    convertTreeToDLLON(ptr->left,head);
    ptr->left = prevNode;
    if(prevNode == null) {
        (*head) = ptr;
    } else {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    convertTreeToDLLON(ptr->right,head);
}

//Tested
itNode *getKthSmallestBSTDllConversionON(itNode *ptr,unsigned int kValue) {
    if(ptr == null) {
        return null;
    }
    convertTreeToDLLON(ptr,&ptr);
    while(ptr != null && --kValue) {
        ptr = ptr->right;
    }
    return ptr;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int getKthSmallestBSTAuxSpace(itNode *ptr,unsigned int kValue) {
    if(ptr == null) {
        return INT_MIN;
    }
    treeutils *utils = new treeutils();
    vector<int> values = utils->getValuesInPreorder(ptr);
    sort(values.begin(),values.end());
    if(kValue > values.size()) {
        return INT_MIN;
    }
    return values[kValue-1];
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *convertTreeToDLLON2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = convertTreeToDLLON2(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = convertTreeToDLLON2(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
itNode *getKthSmallestBSTDllConversionON2(itNode *ptr,unsigned int kValue) {
    if(ptr == null) {
        return null;
    }
    convertTreeToDLLON2(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null && --kValue) {
        ptr = ptr->right;
    }
    return ptr;
}

#endif /* KTHSMALLESTBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
