/****************************************************************************************************************************************************
 *  File Name                   : reversesill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\reversesill.h
 *  Created on                  : Oct 14, 2014 :: 12:12:52 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef REVERSESILL_H_
#define REVERSESILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
sillNode *reverseSillMain(sillNode *ptr,sillNode **head) {
    if(ptr == null) {
        return null;
    }
    if(ptr->next == null) {
        (*head) = ptr;
        return ptr;
    }
    reverseSillMain(ptr->next,head);
    ptr->next->next = ptr;
    return ptr;
}

//Tsted
void reverseSill(sillNode **ptr) {
    if(*ptr == null || (*ptr)->next == null) {
        return;
    }
    sillNode *lastNode = reverseSillMain(*ptr,ptr);
    lastNode->next = null;
}

//Tested
void reverseSill(sillNode *ptr,sillNode **reversedHead) {
    if(ptr == null) {
        return;
    }
    if(ptr->next == null) {
        (*reversedHead) = ptr;
    }
    static sillNode *prevNode = null;
    sillNode *temp = ptr->next;
    ptr->next = prevNode;
    prevNode = ptr;
    reverseSill(temp,reversedHead);
}

//Tested
sillNode *reverseSillIterative(sillNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillNode *crawler = ptr;
    sillNode *prevNode = null,*temp;
    while(crawler->next != null) {
        temp = crawler->next;
        crawler->next = prevNode;
        prevNode = crawler;
        crawler = temp;
    }
    crawler->next = prevNode;
    return crawler;
}

//Tested
sillNode *reverseSillNewSill(sillNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillNode *reverseHead = null,*temp;
    while(ptr != null) {
        if(reverseHead == null) {
            reverseHead = new sillNode(ptr->value);
        } else {
            temp = new sillNode(ptr->value);
            temp->next = reverseHead;
            reverseHead = temp;
        }
        ptr = ptr->next;
    }
    return reverseHead;
}

//Tested
void reverseSillAuxspace(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<int> auxSpace;
    sillNode *crawler = ptr;
    while(crawler != null) {
        auxSpace.push(crawler->value);
        crawler = crawler->next;
    }
    crawler = ptr;
    while(!auxSpace.empty()) {
        crawler->value = auxSpace.top();
        auxSpace.pop();
        crawler = crawler->next;
    }
}

//Tested
void reverseSillStack(sillNode **ptr) {
    if(*ptr ==  null) {
        return;
    }
    sillNode *crawler = *ptr;
    stack<sillNode *> auxSpace;
    while(crawler != null) {
        auxSpace.push(crawler);
        crawler = crawler->next;
    }
    (*ptr) = auxSpace.top();
    sillNode *prevNode = null;
    while(!auxSpace.empty()) {
        if(prevNode != null) {
            prevNode->next = auxSpace.top();
        }
        prevNode = auxSpace.top();
        auxSpace.pop();
    }
    prevNode->next = null;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* REVERSESILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
