/****************************************************************************************************************************************************
 *  File Name                   : removeduplicatessortedsill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\removeduplicatessortedsill.h
 *  Created on                  : Oct 17, 2014 :: 1:08:55 PM
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

#ifndef REMOVEDUPLICATESSORTEDSILL_H_
#define REMOVEDUPLICATESSORTEDSILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void removeDuplicatesSortedSillON(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *outerCrawler = ptr,*innerCrawler,*nodeToBeDeleted;
    while(outerCrawler != null) {
        innerCrawler = outerCrawler->next;
        while(innerCrawler != null && innerCrawler->value == outerCrawler->value) {
            nodeToBeDeleted = innerCrawler;
            outerCrawler->next = innerCrawler->next;
            innerCrawler = outerCrawler->next;
            free(nodeToBeDeleted);
        }
        outerCrawler = outerCrawler->next;
    }
}

void removeDuplicatesSortedSillHashmap(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    sillNode *crawler = ptr;
    while(crawler != null) {
        if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()) {
            frequencyMap[crawler->value] += 1;
        } else {
            frequencyMap[crawler->value] = 1;
        }
        crawler = crawler->next;
    }
    while(crawler != null) {

    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Merge sort
//Avl Tree
/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* REMOVEDUPLICATESSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
