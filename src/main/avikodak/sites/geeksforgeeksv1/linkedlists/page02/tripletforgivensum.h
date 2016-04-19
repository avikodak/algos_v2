/****************************************************************************************************************************************************
 *  File Name                   : tripletforgivensum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\tripletforgivensum.h
 *  Created on                  : Oct 31, 2014 :: 12:08:14 PM
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef TRIPLETFORGIVENSUM_H_
#define TRIPLETFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

void frontBackSplit(sillNode *ptr,sillNode **firstPtr,sillNode **secondPtr) {
    if(ptr == null || ptr->next == null) {
        (*firstPtr) = ptr;
        (*secondPtr) = null;
        return;
    }
    sillNode *fastPtr = ptr->next,*slowPtr = ptr;
    while(fastPtr != null) {
        fastPtr = fastPtr->next;
        if(fastPtr != null) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }
    (*secondPtr) = slowPtr->next;
    slowPtr->next = null;
    (*firstPtr) = ptr;
}

sillNode *merge(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return firstPtr == null?secondPtr:firstPtr;
    }
    sillNode *result = null;
    if(firstPtr->value < secondPtr->value) {
        result = a;
        result->next = merge(firstPtr->next,secondPtr);
    } else {
        result = b;
        result->next = merge(firstPtr,secondPtr->next);
    }
    return result;
}

void mergeSort(sillNode **ptr) {
    if(*ptr == null || (*ptr)->next == null) {
        return;
    }
    sillNode *firstPtr = null,*secondPtr = null;
    frontBackSplit(*ptr,&firstPtr,&secondPtr);
    mergeSort(&firstPtr);
    mergeSort(&secondPtr);
    (*ptr) = merge(firstPtr,secondPtr);
}

iTriplet *getTripletForGivenSum(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int value) {
    if(firstPtr == null || secondPtr == null || thirdPtr == null) {
        return null;
    }
    mergeSort(&firstPtr);
    mergeSort(&secondPtr);
    mergeSort(&thirdPtr);
    reverseSill(&thirdPtr);
    sillNode *firstCrawler = firstPtr,*secondCrawler,*thirdCrawler;
    int sum;
    while(firstCrawler != null) {
        secondCrawler = secondPtr;
        thirdCrawler = thirdPtr;
        while(secondCrawler != null && thirdCrawler != null) {
            sum = firstCrawler->value + secondCrawler->value + thirdCrawler->value;
            if(sum == value) {
                iTriplet *result = new iTriplet(firstCrawler->value,secondCrawler->value,thirdCrawler->value);
                return result;
            }
            if(sum > value) {
                thirdCrawler = thirdCrawler->next;
            } else {
                secondCrawler = secondCrawler->next;
            }
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
iTriplet *getTripletForGivenSum(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int value) {
    if(firstPtr == null || secondPtr == null || thirdPtr == null) {
        return null;
    }
    sillNode *firstCrawler = firstPtr,*secondCrawler = null,*thirdCrawler = null;
    while(firstCrawler != null) {
        secondCrawler = secondPtr;
        while(secondCrawler != null) {
            thirdCrawler = thirdPtr;
            while(thirdCrawler != null) {
                if(firstCrawler->value + secondCrawler->value + thirdCrawler->value == value) {
                    iTriplet *result = new iTriplet(firstCrawler->value,secondCrawler->value,thirdCrawler->value);
                    return result;
                }
                thirdCrawler = thirdCrawler->next;
            }
            secondCrawler = secondCrawler->next;
        }
        firstCrawler = firstCrawler->next;
    }
    return null;
}

#endif /* TRIPLETFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
