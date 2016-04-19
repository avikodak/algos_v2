/****************************************************************************************************************************************************
 *  File Name   		: circularsill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\circularsill.h
 *  Created on			: Oct 20, 2014 :: 2:07:37 PM
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

#ifndef CIRCULARSILL_H_
#define CIRCULARSILL_H_

class circularsill {
private:
    sillNode *head;
public:
    circularsill() {
        head = null;
    }

    bool isEmpty() {
        return head == null;
    }

    void push(int value) {
        if(head == null) {
            head = new sillNode(value);
            head->next = head;
        } else {
            sillNode *newNode = new sillNode(head->value);
            newNode->next = head->next;
            head->value = value;
            head->next = newNode;
        }
    }

    void pop() {
        if(isEmpty()) {
            throw "Stack is empty";
        }
        sillNode *nodeToBeDeleted = null;
        if(head->next == head) {
            nodeToBeDeleted = head;
            *head = null;
        } else {
            head->value = head->next->value;
            nodeToBeDeleted = head->next;
            head->next = head->next->next;
        }
        free(nodeToBeDeleted);
    }

    int top() {
        if(isEmpty()) {
            throw "Stack is empty";
        }
        return head->value;
    }

    unsigned int size() {
        sillNode *crawler = head;
        unsigned int counter = 0;
        while(crawler->next != head) {
            crawler = crawler->next;
            counter++;
        }
        return counter;
    }

};


#endif /* CIRCULARSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
