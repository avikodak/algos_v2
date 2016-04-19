/****************************************************************************************************************************************************
 *  File Name   		: ordereddictionary.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\ordereddictionary.h
 *  Created on			: Nov 19, 2014 :: 12:55:14 AM
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

#ifndef ORDEREDDICTIONARY_H_
#define ORDEREDDICTIONARY_H_

class ordereddict {
private:
    dillNode *head;

    dillNode *getNodeForValue(int value) {
        dillNode *crawler = head;
        while(crawler != null) {
            if(crawler->value == value) {
                return crawler;
            }
        }
        return null;
    }

public:
    void insert(int value) {
        if(head == null) {
            head = new dillNode(value);
            return;
        }
        dillNode *crawler = head;
        while(crawler->value < value) {
            crawler = crawler->next;
        }
        dillNode *newNode = new dillNode(crawler->value);
        crawler->value = value;
        newNode->next = crawler->next;
        crawler->next = newNode;
    }

    void remove(int value) {
        if(head == null) {
            return;
        }
        dillNode *nodeToBeDeleted,*crawler = head;
        if(head->value == value) {
            nodeToBeDeleted = head;
            head = head->next;
            free(nodeToBeDeleted);
            return;
        }
        while(crawler->next != null) {
            if(crawler->next->value == value) {
                nodeToBeDeleted = crawler->next;
                crawler->next = crawler->next->next;
                free(nodeToBeDeleted);
                return;
            }
            crawler = crawler->next;
        }
    }

    void print() {
        dillNode *crawler = head;
        while(crawler != null) {
            printf("%d\t",crawler->value);
            crawler = crawler->next;
        }
    }

    bool search(int value) {
        dillNode *crawler = head;
        while(crawler != null) {
            if(crawler->value == value) {
                return true;
            }
            crawler = crawler->next;
        }
        return false;
    }

    int predecessor(int value) {
        dillNode *ptrToKey = getNodeForValue(value);
        if(ptrToKey == null || ptrToKey->prev == null) {
            return INT_MIN;
        }
        return ptrToKey->prev->value;
    }

    int successor(int value) {
        dillNode *ptrToKey = getNodeForValue(value);
        if(ptrToKey == null || ptrToKey->next == null) {
            return INT_MAX;
        }
        return ptrToKey->next->value;
    }
};

#endif /* ORDEREDDICTIONARY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
