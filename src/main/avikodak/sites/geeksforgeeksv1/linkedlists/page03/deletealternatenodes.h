/****************************************************************************************************************************************************
 *  File Name                   : deletealternatenodes.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\deletealternatenodes.h
 *  Created on                  : Oct 21, 2014 :: 12:44:27 PM
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

#ifndef DELETEALTERNATENODES_H_
#define DELETEALTERNATENODES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void deleteAlternateNodes(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    sillNode *nodeToBeDeleted = ptr->next;
    ptr->next = ptr->next->next;
    free(nodeToBeDeleted);
    deleteAlternateNodes(ptr->next);
}

void deleteAlternateNodesIterative(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    sillNode *crawler = ptr,*nodeToBeDeleted;
    while(crawler != null && crawler->next != null) {
        nodeToBeDeleted = crawler->next;
        crawler->next = crawler->next->next;
        free(nodeToBeDeleted);
    }
}

void deleteAlternateNodesHashmap(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    map<unsigned int,sillNode *> indexNodeMap;
    map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
    sillNode *crawler = ptr;
    unsigned int counter = 0;
    while(crawler != null) {
        indexNodeMap.insert(pair<unsigned int,sillNode *>(++counter,crawler));
        crawler = crawler->next;
    }
    bool evenNode = false;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        if(evenNode) {
            free(itToIndexNodeMap->second);
            indexNodeMap.erase(itToIndexNodeMap->first);
        }
        evenNode = !evenNode;
    }
    sillNode *prevNode = indexNodeMap.begin()->second;
    for(itToIndexNodeMap = indexNodeMap.begin()+1; itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        prevNode->next = itToIndexNodeMap->second;
        if(itToIndexNodeMap+1 == indexNodeMap.end()) {
            itToIndexNodeMap->second = null;
        }
    }
}

#endif /* DELETEALTERNATENODES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
