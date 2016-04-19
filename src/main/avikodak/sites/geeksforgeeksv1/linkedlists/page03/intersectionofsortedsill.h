/****************************************************************************************************************************************************
 *  File Name                   : intersectionofsortedsill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\intersectionofsortedsill.h
 *  Created on                  : Oct 19, 2014 :: 4:37:34 PM
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

#ifndef INTERSECTIONOFSORTEDSILL_H_
#define INTERSECTIONOFSORTEDSILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *intersectionOfSortedSill(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return null;
    }
    sillNode *intersectionOfSill = null,*intersectionCrawler = null;
    while(firstPtr != null && secondPtr != null) {
        if(firstPtr->value == secondPtr->value) {
            if(intersectionOfSill == null) {
                intersectionOfSill = new sillNode(firstPtr->value);
                intersectionCrawler = intersectionOfSill;
            } else {
                intersectionCrawler->next = new sillNode(firstPtr->value);
            }
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        } else {
            if(firstPtr->value > secondPtr->value) {
                secondPtr = secondPtr->next;
            } else {
                firstPtr = firstPtr->next;
            }
        }
    }
    return intersectionOfSill;
}

sillNode *getIntersectionOfSortedSillHashmap(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return null;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    sillNode *crawler = firstPtr,*intersectionHead = null,*intersectionCrawler;
    while(crawler != null) {
        if(frequencyMap.find(crawler->value) == frequencyMap.end()) {
            frequencyMap[crawler->value] = 1;
        } else {
            frequencyMap[crawler->value] += 1;
        }
        crawler = crawler->next;
    }
    crawler = secondPtr;
    while(crawler != null) {
        itToFrequencyMap = frequencyMap.find(crawler->value);
        if(itToFrequencyMap != frequencyMap.end()) {
            if(itToFrequencyMap->second == 1) {
                frequencyMap.erase(crawler->value);
            } else {
                itToFrequencyMap->second -= 1;
            }
            if(intersectionHead == null) {
                intersectionHead = new sillNode(crawler->value);
                intersectionCrawler = intersectionHead;
            } else {
                intersectionCrawler->next = new sillNode(crawler->value);
            }
        }
    }
    return intersectionHead;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *intersectionOfSortedSillON2(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return null;
    }
    unsigned int prevElementFrequency = 0;
    sillNode *firstSillCrawler = firstPtr,*secondSillCrawler = secondPtr;
    sillNode *intersectionSill = null;
    while(firstSillCrawler != null) {
        secondSillCrawler = secondPtr;
        while(secondSillCrawler != null) {

        }
        firstSillCrawler = firstSillCrawler->next;
    }
}
#endif /* INTERSECTIONOFSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/

