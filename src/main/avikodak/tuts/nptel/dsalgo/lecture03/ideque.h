/****************************************************************************************************************************************************
 *  File Name                   : ideque.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\ideque.h
 *  Created on                  : Oct 20, 2014 :: 2:08:05 PM
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

#ifndef IDEQUE_H_
#define IDEQUE_H_

class ideque {
private:
    dillNode *front,*rear;
public:
    ideque() {
        front = null;
        rear = null;
    }

    bool isEmpty() {
        return front == null || rear == null;
    }

    int get_front() {
        if(isEmpty()) {
            throw "Deque is empty";
        }
        return front->value;
    }

    int get_rear() {
        if(isEmpty()) {
            throw "Deque is empty";
        }
        return rear->value;
    }

    void push_front(int value) {
        dillNode *newNode = new dillNode(value);
        newNode->next = front;
        if(front != null) {
            front->prev = newNode;
        }
        front = newNode;
        if(rear == null) {
            rear = front;
        }
    }

    void push_back(int value) {
        dillNode *newNode = new dillNode(value);
        newNode->prev = rear;
        if(rear != null) {
            rear->next = newNode;
            rear = newNode;
        }
        if(front == null) {
            front = rear;
        }
    }

    void pop_front() {
        if(isEmpty()) {
            throw "Deque is empty";
        }
        dillNode *temp = front;
        if(front == rear) {
            rear  = null;
        }
        front = front->next;
        free(temp);
    }

    void pop_back() {
        if(isEmpty()) {
            throw "Deque is empty";
        }
        dillNode *temp = rear;
        if(front == rear) {
            front = null;
        }
        rear = rear->prev;
        free(temp);
    }

    unsigned int size() {
        unsigned int counter = 0;
        dillNode *crawler = front;
        while(crawler != null) {
            counter++;
            crawler = crawler->next;
        }
        return counter;
    }
};



#endif /* IDEQUE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
