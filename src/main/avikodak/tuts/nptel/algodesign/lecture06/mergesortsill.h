/****************************************************************************************************************************************************
 *  File Name                   : mergesortsill.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture06\mergesortsill.h
 *  Created on                  : Dec 12, 2014 :: 2:10:04 PM
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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

#ifndef MERGESORTSILLV1_H_
#define MERGESORTSILLV1_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/


sillNode *mergeSortedSillV2(sillNode *firstCrawler,sillNode *secondCrawler) {
    if(firstCrawler == null && secondCrawler == null) {
        return null;
    }
    if(firstCrawler == null || secondCrawler == null) {
        return firstCrawler == null?secondCrawler:firstCrawler;
    }
    sillNode *result = null,*resultCrawler;
    if(firstCrawler->value < secondCrawler->value) {
        result = new sillNode(firstCrawler->value);
        firstCrawler = firstCrawler->next;
    } else {
        result = new sillNode(secondCrawler->value);
        secondCrawler = secondCrawler->next;
    }
    resultCrawler = result;
    while(firstCrawler != null || secondCrawler != null) {
        if(firstCrawler == null || secondCrawler == null) {
            if(firstCrawler != null) {
                resultCrawler->next = new sillNode(firstCrawler->value);
                firstCrawler = firstCrawler->next;
            } else {
                resultCrawler->next = new sillNode(secondCrawler->value);
                secondCrawler = secondCrawler->next;
            }
        } else {
            if(firstCrawler->value < secondCrawler->value) {
                resultCrawler->next = new sillNode(firstCrawler->value);
                firstCrawler = firstCrawler->next;
            } else {
                resultCrawler->next = new sillNode(secondCrawler->value);
                secondCrawler = secondCrawler->next;
            }
        }
    }
    return result;
}

void getMiddleSillV2(sillNode *ptr,sillNode **firstSill,sillNode **secondSill) {
    if(ptr == null) {
        return;
    }
    sillNode *fastPtr = ptr,*slowPtr = ptr;
    (*firstSill) = ptr;
    while(fastPtr != null) {
        fastPtr = fastPtr->next;
        if(fastPtr->next != null) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
    }
    (*secondSill) = slowPtr->next;
    slowPtr->next = null;
    return;
}

void mergeSortSillV2(sillNode **head) {
    if(*head == null) {
        return;
    }
    sillNode *firstSill = null,*secondSill = null;
    getMiddleSillV2(*head,&firstSill,&secondSill);
    mergeSortSillV2(&firstSill);
    mergeSortSillV2(&secondSill);
    (*head) = mergeSortedSillV2(firstSill,secondSill);
}

#endif /* MERGESORTSILLV1_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
