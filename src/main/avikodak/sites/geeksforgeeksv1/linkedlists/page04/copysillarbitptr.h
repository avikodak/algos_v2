/****************************************************************************************************************************************************
 *  File Name                   : copysillarbitptr.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\copysillarbitptr.h
 *  Created on                  : Oct 14, 2014 :: 1:17:58 PM
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

#ifndef COPYSILLARBITPTR_H_
#define COPYSILLARBITPTR_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillArbitNode *copySillArbitPtrHashmap(sillArbitNode *ptr) {
    if(ptr == null) {
        return null;
    }
    hash_map<intptr_t,unsigned int> nodeIndexMapOriginalSill;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    hash_map<unsigned int,sillArbitNode *> indexNodeMap;
    hash_map<unsigned int,sillArbitNode *>::iterator itToIndexNodeMap;
    hash_map<intptr_t,sillArbitNode *> nodesArbitPtrsMap;
    sillArbitNode *crawler = ptr,*copiedSillHead = null,*copiedSillCrawler = null;
    unsigned int indexCounter = 0;
    while(crawler != null) {
        if(copiedSillHead == null) {
            copiedSillHead = new sillArbitNode(crawler->value);
            copiedSillCrawler = copiedSillHead;
        } else {
            copiedSillCrawler->next = new sillArbitNode(crawler->value);
            copiedSillCrawler = copiedSillCrawler->next;
        }
        indexNodeMap.insert(pair<unsigned int,sillArbitNode *>(indexCounter,copiedSillCrawler));
        nodeIndexMapOriginalSill.insert(pair<intptr_t,unsigned int>((intptr_t)crawler,indexCounter));
        crawler = crawler->next;
    }
    crawler = ptr;
    while(crawler != null) {
        if(crawler->arbitraryPtr != null) {
            itToNodeIndexMap = nodeIndexMapOriginalSill.find((intptr_t)crawler->arbitraryPtr);
            itToIndexNodeMap = indexNodeMap.find(itToNodeIndexMap->second);
            copiedSillCrawler->arbitraryPtr = itToIndexNodeMap->second;
        }
        crawler = crawler->next;
        copiedSillCrawler = copiedSillCrawler->next;
    }
    return copiedSillHead;
}

sillArbitNode *copySillArbitPtr(sillArbitNode *ptr) {
    if(ptr == null) {
        return null;
    }
    hash_map<intptr_t,sillArbitNode *> originalArbitPtrMap;
    hash_map<intptr_t,sillArbitNode *> itToOriginalArbitPtrMap;
    sillArbitNode *crawler = ptr,*copiedHead,*copiedCrawler,*temp,*temp2;
    while(crawler != null) {
        originalArbitPtrMap.insert(pair<intptr_t,sillArbitNode *>((intptr_t)crawler,crawler->arbitraryPtr));
        crawler = crawler->next;
    }
    crawler = ptr;
    while(crawler != null) {
        if(copiedHead == null) {
            copiedHead = new sillArbitNode(crawler->value);
            copiedCrawler = copiedHead;
        } else {
            copiedCrawler->next = new sillArbitNode(crawler->value);
            copiedCrawler = copiedCrawler->next;
        }
        crawler->arbitraryPtr = copiedCrawler;
        copiedCrawler->arbitraryPtr = crawler;
        crawler = crawler->next;
    }
    crawler = copiedHead;
    while(crawler != null) {
        temp = originalArbitPtrMap.find((intptr_t)crawler->arbitraryPtr);
        temp2 = crawler->arbitraryPtr;
        crawler->arbitraryPtr = temp->arbitraryPtr;
        temp2->arbitraryPtr = temp;
        crawler = crawler->next;
    }
    return copiedHead;
}

sillArbitNode *copySillArbitPtrMidInsertion(sillArbitNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillArbitNode *crawler = ptr,*temp,*copiedSillHead,*copiedCrawler;
    while(crawler != null) {
        temp = new sillArbitNode(crawler->value);
        temp->next = crawler->next;
        crawler->next = temp;
        crawler = crawler->next->next;
    }
    crawler = ptr;
    while(crawler != null) {
        crawler->next->arbitraryPtr = crawler->arbitraryPtr->next;
        crawler = crawler->next->next;
    }
    crawler = ptr;
    while(crawler != null) {
        if(copiedSillHead == null) {
            copiedSillHead = crawler->next;
            copiedCrawler = copiedCrawler;
        } else {
            copiedCrawler->next = crawler->next;
            copiedCrawler = copiedCrawler->next;
        }
        crawler->next = crawler->next->next;
        crawler = crawler->next;
    }
    return copiedSillHead;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillArbitNode *copySillArbitPtrON2(sillArbitNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillArbitNode *crawler = ptr,*copiedHead,*copiedCrawler,*outerCrawler,*innerCrawler;
    while(crawler != null) {
        if(copiedHead == null) {
            copiedHead = new sillArbitNode(crawler->value);
            copiedCrawler = copiedHead;
        } else {
            copiedCrawler->next = new sillArbitNode(crawler->value);
            copiedCrawler = copiedCrawler->next;
        }
        crawler = crawler->next;
    }
    unsigned int counter,arbitrartyCrawler;
    crawler = ptr;
    copiedCrawler = copiedHead;
    while(crawler != null) {
        outerCrawler = crawler->arbitraryPtr;
        counter = 0;
        innerCrawler = ptr;
        while(innerCrawler != ptr) {
            counter++;
            innerCrawler = innerCrawler->next;
        }
        innerCrawler = copiedHead;
        while(counter--) {
            innerCrawler = innerCrawler->next;
        }
        copiedCrawler->arbitraryPtr = innerCrawler;
        crawler = crawler->next;
        copiedCrawler = copiedCrawler->next;
    }
    return copiedHead;
}

#endif /* COPYSILLARBITPTR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
