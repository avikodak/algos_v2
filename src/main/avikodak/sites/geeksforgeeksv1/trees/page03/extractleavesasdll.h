/****************************************************************************************************************************************************
 *  File Name                   : extractleavesasdll.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page03\extractleavesasdll.h
 *  Created on                  : Nov 15, 2014 :: 4:36:54 PM
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

#ifndef EXTRACTLEAVESASDLL_H_
#define EXTRACTLEAVESASDLL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *extractLeavesAsDLL(itNode *ptr,itNode **head) {
    if(ptr == null) {
        return null;
    }
    if(ptr->left == null && ptr->right == null) {
        ptr->right = (*head);
        if(*head != null) {
            (*head)->left = ptr;
        }
        (*head) = ptr;
        return null;
    }
    ptr->right = extractLeavesAsDLL(ptr->right,head);
    ptr->left = extractLeavesAsDLL(ptr->left,head);
    return ptr;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void connectAllLeaves(itNode *ptr,itNode **head) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode;
    if(ptr->left == null && ptr->right == null) {
        if(*head == null) {
            (*head) = ptr;
            prevNode = ptr;
        } else {
            ptr->right = prevNode;
            prevNode->left = ptr;
        }
        return;
    }
    connectAllLeaves(ptr->left,head);
    connectAllLeaves(ptr->right,head);
}

void disconnectAllLeavesAfterConnecting(itNode *ptr) {
    if(ptr == null || ptr->left == null || ptr->right == null) {
        return;
    }
    if(ptr->left->right->left == ptr) {
        ptr->left = null;
        return;
    }
    if(ptr->right->right->left == ptr) {
        ptr->right = null;
        return;
    }
    disconnectAllLeavesAfterConnecting(ptr->left);
    disconnectAllLeavesAfterConnecting(ptr->right);
}

itNode *extractLeavesV2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *head = null;
    connectAllLeaves(ptr,&head);
    disconnectAllLeavesAfterConnecting(ptr);
    return head;
}

#endif /* EXTRACTLEAVESASDLL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
