/****************************************************************************************************************************************************
 *  File Name   		: removeloopsill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\removeloopsill.h
 *  Created on			: Oct 30, 2014 :: 11:23:05 AM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef REMOVELOOPSILL_H_
#define REMOVELOOPSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeLoop(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *fastPtr = ptr,*slowPtr = ptr;
    while(fastPtr != null && fastPtr->next != null) {
        if(fastPtr == slowPtr) {
            break;
        }
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    if(fastPtr != slowPtr) {
        return;
    }
    unsigned int lengthOfLoop = 0;
    sillNode *crawler = slowPtr;
    while(crawler->next != slowPtr) {
        lengthOfLoop++;
        crawler = crawler->next;
    }
    slowPtr = ptr;
    fastPtr = ptr;
    while(lengthOfLoop--) {
        fastPtr = fastPtr->next;
    }
    while(fastPtr->next == slowPtr) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }
    fastPtr->next = null;
}

void removeLoopHashmap(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *crawler = ptr;
    hash_map<intptr_t,bool> visitedNodeFlags;
    hash_map<intptr_t,bool>::iterator itToVisitedNodeFlags;
    while(crawler != null && crawler->next != null) {
        if((itToVisitedNodeFlags = visitedNodeFlags.find((intptr_t)crawler->next)) != visitedNodeFlags.end()) {
            crawler->next = null;
            return;
        }
        visitedNodeFlags.insert(pair<intptr_t,bool>((intptr_t)crawler,true));
        crawler = crawler->next;
    }
}

void removeLoop(svillNode *ptr) {
    if(ptr == null) {
        return;
    }
    svillNode *crawler;
    while(true) {
        if(crawler->next->isVisited) {
            crawler->next = null;
            return;
        }
        crawler = crawler->next;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeLoopON2(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *fastPtr = ptr,*slowPtr = ptr;
    while(fastPtr != null && fastPtr->next != null) {
        if(fastPtr == slowPtr) {
            break;
        }
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    if(fastPtr != slowPtr) {
        return;
    }
    sillNode *crawler = ptr,*loopCrawler;
    while(true) {
        loopCrawler = slowPtr;
        while(loopCrawler->next != slowPtr) {
            if(loopCrawler->next == crawler) {
                loopCrawler->next = null;
                return;
            }
            loopCrawler = loopCrawler->next;
        }
        crawler = crawler->next;
    }
}

#endif /* REMOVELOOPSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
