/****************************************************************************************************************************************************
 *  File Name                   : removeduplicatesunsortedsill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\removeduplicatesunsortedsill.h
 *  Created on                  : Oct 17, 2014 :: 1:09:07 PM
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

#ifndef REMOVEDUPLICATESUNSORTEDSILL_H_
#define REMOVEDUPLICATESUNSORTEDSILL_H_


/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void removeDuplicatesON(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    sillNode *crawler = ptr,*temp;
    while(crawler != null) {
        if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()) {
            frequencyMap[crawler->value] += 1;
        } else {
            frequencyMap[crawler->value] = 1;
        }
        crawler = crawler->next;
    }
    crawler = ptr;
    while(crawler != null) {
        itToFrequencyMap = frequencyMap.find(crawler->value);
        if(itToFrequencyMap->second > 1) {
            crawler->value = crawler->next->value;
            temp = crawler->next;
            crawler->next = crawler->next->next;
            free(temp);
            frequencyMap[crawler->value] -= 1;
        } else {
            crawler = crawler->next;
        }
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
void removeDuplicatesON2(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *outerCrawler = ptr,*innerCrawler;
    bool isDuplicate;
    while(outerCrawler != null) {
        innerCrawler = outerCrawler->next;
        isDuplicate = false;
        while(innerCrawler != null) {
            if(innerCrawler->value == outerCrawler->value) {
                isDuplicate = true;
                break;
            }
        }
        if(isDuplicate) {
            outerCrawler->value = outerCrawler->next->value;
            innerCrawler = outerCrawler->next;
            outerCrawler->next = outerCrawler->next->next;
            free(innerCrawler);
        } else {
            outerCrawler = outerCrawler->next;
        }
    }
}

void removeDuplicatesBSTON2(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    iftNode *frequencyBST = utils->getFBSTFromSill(ptr);
    iftNode *temp;
    sillNode *crawler = ptr,*nodeToBeDeleted;
    while(crawler != null) {
        temp = utils->searchForValueBST(frequencyBST,crawler->value);
        if(crawler->value > 1) {
            temp->value -= 1;
            nodeToBeDeleted = crawler->next;
            crawler->value = crawler->next->value;
            crawler->next = crawler->next->next;
            free(nodeToBeDeleted);
        } else {
            crawler = crawler->next;
        }
    }
}

#endif /* REMOVEDUPLICATESUNSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
