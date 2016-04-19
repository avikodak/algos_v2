/****************************************************************************************************************************************************
 *  File Name   		: deletenodesgreatervalue.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\deletenodesgreatervalue.h
 *  Created on			: Oct 30, 2014 :: 10:38:46 AM
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

#include "../../../geeksforgeeksv1/linkedlists/page05/deleteanodegivenptr.h"
#include "../../../geeksforgeeksv1/linkedlists/page04/reversesill.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DELETENODESGREATERVALUE_H_
#define DELETENODESGREATERVALUE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int deleteNodesGreaterValueRightSide(sillNode *ptr) {
    if(ptr == null) {
        return INT_MIN;
    }
    int greaterValue = deleteNodesGreaterValueRightSide(ptr->next);
    if(greaterValue > ptr->value) {
        deleteNodeGivenPtr(ptr);
        return greaterValue;
    } else {
        return ptr->value;
    }
}

void deleteNodesGreaterValueRightSideReverse(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    reverseSill(&ptr);
    sillNode *currentNode = ptr;
    int maxTillNow = INT_MIN;
    while(currentNode != null) {
        if(maxTillNow > currentNode->value) {
            deleteNodeGivenPtr(currentNode);
        } else {
            maxTillNow = currentNode->value;
            currentNode = currentNode->next;
        }
    }
    reverseSill(&ptr);
}

void deleteNodesGreaterValuesRightSideAuxspace(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    stack<sillNode *> primaryAuxspace,secondaryAuxspace;
    sillNode *currentNode = ptr;
    while(currentNode != null) {
        primaryAuxspace.push(currentNode);
        currentNode = currentNode->next;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void deleteNodesGreaterValueOnRightSideON2(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *outerCrawler = ptr,*innerCrawler;
    int maxValue = INT_MIN;
    while(outerCrawler != null) {
        innerCrawler = outerCrawler->next;
        maxValue = INT_MIN;
        while(innerCrawler != null) {
            maxValue = max(maxValue,innerCrawler->value);
            innerCrawler = innerCrawler->next;
        }
        if(outerCrawler->value > maxValue) {
            outerCrawler = outerCrawler->next;
        } else {
            deleteNodeGivenPtr(outerCrawler);
        }
    }
}


#endif /* DELETENODESGREATERVALUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
