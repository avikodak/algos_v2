/****************************************************************************************************************************************************
 *  File Name   		: arrayqueue.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\arrayqueue.h
 *  Created on			: Oct 20, 2014 :: 2:07:02 PM
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

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

class arrayqueue {
private:
    int *queue;
    int frontIndex,rearIndex;
    int maxSize;
public:
    arrayqueue() {
        this->maxSize = 1024;
        frontIndex = -1;
        rearIndex = 0;
        this->queue = (int *)malloc(sizeof(int)*maxSize);
    }

    arrayqueue(int size) {
        this->maxSize = size;
        this->queue = (int *)malloc(sizeof(int)*maxSize);
        frontIndex = -1;
        rearIndex = 0;
    }

    bool isFull() {
        return (rearIndex+1)%maxSize == frontIndex;
    }

    bool isEmpty() {
        return frontIndex == -1 ||  rearIndex == frontIndex;
    }

    void push(int value) {
        if(isFull()) {
            throw "Queue is full";
        }
        if(frontIndex == -1) {
            frontIndex = 0;
        }
        queue[rearIndex] = value;
        rearIndex = (rearIndex+1)%maxSize;
    }

    void pop() {
        if(isEmpty()) {
            throw "Queue is empty";
        }
        queue[frontIndex] = 0;
        frontIndex = (frontIndex+1)%maxSize;
    }

    int front() {
        if(isEmpty()) {
            throw "Queue is empty";
        }
        return queue[frontIndex];
    }

    unsigned int size() {
        return maxSize - rearIndex + frontIndex;
    }
};

#endif /* ARRAYQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
