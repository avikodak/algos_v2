/****************************************************************************************************************************************************
 *  File Name                   : inordertraversal.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\inordertraversal.h
 *  Created on                  : Nov 17, 2014 :: 11:15:04 PM
 *  Author                      : avikodak
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

#ifndef INORDERTRAVERSAL_H_
#define INORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void inorderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inorderTraversal(ptr->left);
    printf("%d\t",ptr->value);
    inorderTraversal(ptr->right);
}

//Tested
void inorderTraversalIterative(itNode *ptr) {
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
void morrisInorderTraversal(itNode *ptr) {
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

//Tested
void tFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    tFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    tFixLeftPtr(ptr->right);
}

//Tested
void tFixRightPtr(itNode **ptr) {
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
void itInorderTraversalDllConversionON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    tFixLeftPtr(ptr);
    tFixRightPtr(&ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

//Tested
void inorderTraversalDllConversionONMain(itNode *ptr,itNode **head) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    inorderTraversalDllConversionONMain(ptr->left,head);
    ptr->left = prevNode;
    if(prevNode == null) {
        (*head) = ptr;
    } else {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    inorderTraversalDllConversionONMain(ptr->right,head);
}

//Tested
void inorderTraversalDllConversionON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *head = null;
    inorderTraversalDllConversionONMain(ptr,&head);
    while(head != null) {
        printf("%d\t",head->value);
        head = head->right;
    }
}

//Tested
itNode *convertTreeToDllON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp = null;
    if(ptr->left != null) {
        temp = convertTreeToDllON2Main(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = convertTreeToDllON2Main(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
void inorderTraversalTreeDllConversionON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    convertTreeToDllON2Main(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

#endif /* INORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
