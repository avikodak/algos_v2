/****************************************************************************************************************************************************
 *  File Name                   : alternatingsplit.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\alternatingsplit.h
 *  Created on                  : Oct 21, 2014 :: 12:44:37 PM
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

#ifndef ALTERNATINGSPLIT_H_
#define ALTERNATINGSPLIT_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *splitSillAlternateNodes(sillNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillNode *result = (sillNode *)malloc(sizeof(sillNode)*2);
    result[0] = ptr;
    result[1] = ptr->next;
    if(ptr->next == null) {
        return result;
    }
    bool flag = true;
    sillNode *firstSillTail = result[0],*secondSillTail = result[1];
    sillNode *crawler = ptr->next->next;
    while(crawler != null) {
        if(flag) {
            firstSillTail->next = crawler;
            firstSillTail = firstSillTail->next;
        } else {
            secondSillTail->next = crawler;
            secondSillTail = secondSillTail->next;
        }
        crawler = crawler->next;
    }
    return result;
}

sillNode *splitSillAlternatinglyAuxspace(sillNode *ptr) {
    if(ptr == null) {
        return null;
    }
    queue<sillNode *> firstAuxspace,secondAuxspace;
    sillNode *crawler = ptr;
    bool flag = true;
    while(crawler != null) {
        if(flag) {
            firstAuxspace.push(crawler);
        } else {
            secondAuxspace.push(crawler);
        }
        crawler = crawler->next;
    }
    sillNode *result = (sillNode *)malloc(sizeof(sillNode)*2);
    result[0] = firstAuxspace.front();
    result[1] = secondAuxspace.front();
    firstAuxspace.pop();
    secondAuxspace.pop();
    sillNode *crawler1 = result[0],*crawler2 = result[1];
    while(!firstAuxspace.empty()) {
        crawler1->next = firstAuxspace.front();
        firstAuxspace.pop();
        crawler1 = crawler1->next;
    }
    while(!secondAuxspace.empty()) {
        crawler2->next = secondAuxspace.front();
        secondAuxspace.pop();
        crawler2 = crawler2->next;
    }
    return result;
}

sillNode *splitSillAlternateNodesHashmap(sillNode *ptr) {
    if(ptr == null) {
        return null;
    }
    sillutils *utils = new sillutils();
    hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1);
    hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
    sillNode *result = (sillNode *)malloc(sizeof(sillNode)*2);
    sillNode *firstCrawler,*secondCrawler;
    result[0] = (indexNodeMap.find(1))->second;
    if(ptr->next == null) {
        result[1] = null;
        return result;
    }
    result[1] = indexNodeMap.find(2)->second;
    firstCrawler = result[0];
    secondCrawler = result[1];
    ptr = ptr->next->next;
    for(unsigned int counter = 3; counter < indexNodeMap.size(); counter++) {
        if(counter%2 == 1) {
            firstCrawler->next = indexNodeMap.find(counter)->second;
            firstCrawler = firstCrawler->next;
        } else {
            secondCrawler->next = indexNodeMap.find(counter)->second;
            secondCrawler = secondCrawler->next;
        }
    }
    return result;
}

#endif /* ALTERNATINGSPLIT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
