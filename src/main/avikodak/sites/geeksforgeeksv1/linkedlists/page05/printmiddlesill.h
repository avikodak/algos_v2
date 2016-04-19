/****************************************************************************************************************************************************
 *  File Name                   : printmiddlesill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\printmiddlesill.h
 *  Created on                  : Oct 11, 2014 :: 10:56:38 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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

#ifndef PRINTMIDDLESILL_H_
#define PRINTMIDDLESILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printMiddleSill(sillNode *head) {
    if(head == null) {
        return;
    }
    sillNode *slowPtr = head,*fastPtr = head;
    while(slowPtr != null && fastPtr != null && fastPtr->next != null) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    printf("%d\t",slowPtr->value);
}

//Tested
void printMiddleSillByFindingLength(sillNode *ptr,unsigned int index = 0) {
    static unsigned int lengthOfSill= 0,middleIndex;
    if(ptr == null) {
        middleIndex = lengthOfSill/2;
        return;
    }
    lengthOfSill++;
    printMiddleSillByFindingLength(ptr->next,index+1);
    if(index == middleIndex) {
        printf("%d",ptr->value);
    }
}

//Tested
void printMiddleSillByFindingLengthIterative(sillNode *head) {
    if(head == null) {
        return;
    }
    sillutils *utils = new sillutils();
    unsigned int length = utils->lengthOfSill(head);
    length /= 2;
    while(length--) {
        head = head->next;
    }
    printf("%d",head->value);
}

//Tested
void printMiddleSillHashmap(sillNode *head) {
    if(head == null) {
        return;
    }
    sillutils *utils = new sillutils();
    hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(head)->indexNodeMap;
    hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
    itToIndexNodeMap  = indexNodeMap.find(indexNodeMap.size()/2);
    printf("%d",itToIndexNodeMap->second->value);
}

//Tested
void printMiddleSillCounter(sillNode *head) {
    if(head == null) {
        return;
    }
    unsigned int counter = 0;
    sillNode *mid = head;
    while(head != null) {
        if(counter&1) {
            mid = mid->next;
        }
        head = head->next;
        counter+= 1;
    }
    printf("%d",mid->value);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printMiddleSillON2(sillNode *head) {
    if(head == null) {
        return;
    }
    sillNode *outerCrawler = head,*currentNode,*crawler;
    unsigned int leftCounter,rightCounter;
    while(outerCrawler != null) {
        currentNode = outerCrawler;
        crawler = head;
        leftCounter = 0;
        while(crawler != currentNode) {
            crawler = crawler->next;
            leftCounter += 1;
        }
        rightCounter = 0;
        crawler = currentNode->next;
        while(crawler != null) {
            crawler = crawler->next;
            rightCounter += 1;
        }
        if(leftCounter == rightCounter || abs(leftCounter - rightCounter) == 1) {
            printf("%d",outerCrawler->value);
        }
        outerCrawler = outerCrawler->next;
    }
}

#endif /* PRINTMIDDLESILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
