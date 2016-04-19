/****************************************************************************************************************************************************
 *  File Name   		: sillqueue.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\sillqueue.h
 *  Created on			: Oct 20, 2014 :: 2:08:14 PM
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

#ifndef SILLQUEUE_H_
#define SILLQUEUE_H_

class sillqueue {
private:
    sillNode *head,*tail;
public:
    sillqueue() {
        this->head = null;
        this->tail = null;
    }

    bool isEmpty() {
        return head == null;
    }

    void push(int value) {
        if(head == null) {
            head = new sillNode(value);
            tail = head;
        } else {
            tail->next = new sillNode(value);
            tail = tail->next;
        }
    }

    void pop() {
        if(isEmpty()) {
            throw "Queue empty";
        }
        sillNode *temp = head;
        head = head->next;
        free(temp);
    }

    unsigned int size() {
        sillNode *crawler = head;
        unsigned int counter = 0;
        while(crawler != null) {
            counter++;
            crawler = crawler->next;
        }
        return counter;
    }

    int front() {
        if(isEmpty()) {
            throw "Queue empty";
        }
        return head->value;
    }
};

#endif /* SILLQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
