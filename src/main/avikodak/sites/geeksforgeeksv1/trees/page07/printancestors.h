/****************************************************************************************************************************************************
 *  File Name                   : printancestors.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\printancestors.h
 *  Created on                  : Oct 20, 2014 :: 8:38:49 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
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

#ifndef PRINTANCESTORS_H_
#define PRINTANCESTORS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printAncestorsForValue(itNode *ptr,int value,stack<itNode *> auxSpace) {
    if(ptr == null) {
        return;
    }
    if(ptr->value == value) {
        itNode *currentNode;
        while(!auxSpace.empty()) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t",currentNode->value);
        }
        return;
    }
    auxSpace.push(ptr);
    printAncestorsForValue(ptr->left,value,auxSpace);
    printAncestorsForValue(ptr->right,value,auxSpace);
}

//Tested
bool printAncestors(itNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    }
    if(printAncestors(ptr->left,value) || printAncestors(ptr->right,value)) {
        printf("%d\t",ptr->value);
        return true;
    }
    return false;
}

//Tested
void printStack(stack<itNode *> auxSpace) {
    itNode *currentNode;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        printf("%d\t",currentNode->value);
    }
}

//Tested
void printAncestorsPostOrderTraversalV2(itNode *ptr,int value) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(currentNode->value == value) {
                printStack(auxSpace);
            }
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                if(currentNode->value == value) {
                    printStack(auxSpace);
                }
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isValuePresentInTree(itNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    }
    return isValuePresentInTree(ptr->left,value) || isValuePresentInTree(ptr->right,value);
}

//Tested
void printAncestorsInTree(itNode *ptr,int value) {
    if(ptr == null) {
        return;
    }
    if(isValuePresentInTree(ptr->left,value) || isValuePresentInTree(ptr->right,value)) {
        printf("%d\t",ptr->value);
    }
    printAncestorsInTree(ptr->left,value);
    printAncestorsInTree(ptr->right,value);
}

#endif /* PRINTANCESTORS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
