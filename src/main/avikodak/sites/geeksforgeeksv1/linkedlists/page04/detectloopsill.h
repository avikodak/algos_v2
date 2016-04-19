/****************************************************************************************************************************************************
 *  File Name   		: detectloopsill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\detectloopsill.h
 *  Created on			: Oct 14, 2014 :: 12:13:04 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DETECTLOOPSILL_H_
#define DETECTLOOPSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool detectLoopHashMap(sillNode *ptr) {
    if(ptr == null) {
        return false;
    }
    hash_map<intptr_t,bool> visitedNodes;
    hash_map<intptr_t,bool>::iterator itToVisitedNodes;
    sillNode *crawler = ptr;
    while(crawler != null && crawler->next != null) {
        if((itToVisitedNodes = visitedNodes.find((intptr_t)crawler->next)) != visitedNodes.end()) {
            return true;
        }
        visitedNodes.insert(pair<intptr_t,bool>((intptr_t)crawler,true));
        crawler = crawler->next;
    }
    return false;
}

bool detectLoopFlags(svillNode *ptr) {
    if(ptr == null) {
        return false;
    }
    while(ptr != null && ptr->next != null) {
        if(!ptr->next->isVisited) {
            return true;
        }
        ptr->isVisited = true;
        ptr = ptr->next;
    }
    return false;
}

//Tested
bool detectLoopTwoPtrs(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return false;
    }
    sillNode *slowCrawler = ptr,*fastCrawler = ptr->next->next;
    while(slowCrawler != null && fastCrawler != null && fastCrawler->next != null) {
        if(slowCrawler == fastCrawler) {
            return true;
        }
        slowCrawler = slowCrawler->next;
        fastCrawler = fastCrawler->next->next;
    }
    return false;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool detectLoopON2(sillNode *ptr) {
    if(ptr == null) {
        return false;
    }
    sillNode *outerCrawler = ptr,*innerCrawler;
    while(outerCrawler != null) {
        innerCrawler = ptr;
        while(innerCrawler != null && innerCrawler != outerCrawler) {
            if(outerCrawler->next == innerCrawler) {
                return true;
            }
            innerCrawler = innerCrawler->next;
        }
        if(innerCrawler == null) {
            return false;
        }
        outerCrawler = outerCrawler->next;
    }
    return false;
}

#endif /* DETECTLOOPSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
