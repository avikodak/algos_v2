/****************************************************************************************************************************************************
 *  File Name                   : unionintersection.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\unionintersection.h
 *  Created on                  : Oct 31, 2014 :: 11:30:12 AM
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

#ifndef UNIONINTERSECTION_H_
#define UNIONINTERSECTION_H_


/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *getUnionAndIntersectionSill(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return null;
    }
    if(firstPtr == null || secondPtr == null) {
        return firstPtr != null?firstPtr:secondPtr;
    }
    hash_map<int,unsigned int> frequencyMapFirstSill,frequencyMapSecondSill;
    hash_map<int,unsigned int>::iterator itToFrequencyMapFirstSill,itToFrequencyMapSecondSill;
    sillNode *crawler = firstPtr;
    while(crawler != null) {
        if((itToFrequencyMapFirstSill = frequencyMapFirstSill.find(crawler->value)) == frequencyMapFirstSill.end()) {
            frequencyMapFirstSill[crawler->value] = 1;
        } else {
            frequencyMapFirstSill[crawler->value] += 1;
        }
        crawler = crawler->next;
    }
    crawler = secondPtr;
    while(crawler != null) {
        if((itToFrequencyMapSecondSill = frequencyMapSecondSill.find(crawler->value)) == frequencyMapSecondSill.end()) {
            frequencyMapSecondSill[crawler->value] = 1;
        } else {
            frequencyMapSecondSill[crawler->value] += 1;
        }
        crawler = crawler->next;
    }
    sillNode *unionOfSill = null,*intersectionOfSill = null,*unionCrawler,*intersectionCrawler;
    unsigned int minFrequency;
    for(itToFrequencyMapFirstSill = frequencyMapFirstSill.begin(); itToFrequencyMapFirstSill != frequencyMapFirstSill.end(); itToFrequencyMapFirstSill++) {
        if((itToFrequencyMapSecondSill = frequencyMapSecondSill.find(itToFrequencyMapFirstSill->first)) != frequencyMapFirstSill.end()) {
            minFrequency = min(itToFrequencyMapFirstSill->second,itToFrequencyMapSecondSill->second);
            while(minFrequency--) {
                if(intersectionOfSill == null) {
                    intersectionOfSill = new sillNode(itToFrequencyMapFirstSill->first);
                    intersectionCrawler = intersectionOfSill;
                } else {
                    intersectionCrawler->next = new sillNode(itToFrequencyMapFirstSill->first);
                    intersectionCrawler = intersectionCrawler->next;
                }
            }
            frequencyMapSecondSill.erase(itToFrequencyMapFirstSill->first);
        }
        if(unionOfSill == null) {
            unionOfSill = new sillNode(itToFrequencyMapFirstSill->first);
            unionCrawler = unionOfSill;
        } else {
            unionCrawler->next = new sillNode(itToFrequencyMapFirstSill->first);
            unionCrawler = unionCrawler->next;
        }
    }
    for(itToFrequencyMapSecondSill = frequencyMapSecondSill.begin(); itToFrequencyMapSecondSill != frequencyMapSecondSill.end(); itToFrequencyMapSecondSill++) {
        if(unionOfSill == null) {
            unionOfSill = new sillNode(itToFrequencyMapSecondSill->first);
            unionCrawler = unionOfSill;
        } else {
            unionCrawler->next = new sillNode(itToFrequencyMapSecondSill->first);
            unionCrawler = unionCrawler->next;
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *merge(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return firstPtr == null?secondPtr:firstPtr;
    }
    sillNode *result;
    if(firstPtr->value < secondPtr->value) {
        result = firstPtr;
        result->next = merge(firstPtr->next,secondPtr);
    } else {
        result = secondPtr;
        result->next = merge(firstPtr,secondPtr->next);
    }
    return result;
}

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
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
    }
    (*secondPtr) = slowPtr->next;
    slowPtr->next = null;
    (*firstPtr) = ptr;
}

void mergeSort(sillNode **ptr) {
    if(*ptr == null || (*ptr)->next == null) {
        return;
    }
    sillNode *firstPtr,*secondPtr;
    frontBackSplit(*ptr,&firstPtr,&secondPtr);
    mergeSort(&firstPtr);
    mergeSort(&secondPtr);
    (*ptr) = merge(firstPtr,secondPtr);

}

sillNode *getUnionAndIntersectionSillONLOGN(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return null;
    }
    mergeSort(&firstPtr);
    mergeSort(&secondPtr);

}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *getUnionAndIntersectionSillON2(sillNode *firstPtr,sillNode *secondPtr) {

}

#endif /* UNIONINTERSECTION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
