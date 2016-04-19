/****************************************************************************************************************************************************
 *  File Name                   : arraystack.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\arraystack.h
 *  Created on                  : Oct 18, 2014 :: 1:15:59 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

//Tested
class arrayStack {
private:
    int sizeOfStack;
    int *stack;
    int topIndex;
public:
    arrayStack() {
        sizeOfStack = 1024;
        topIndex = -1;
        this->stack = (int *)malloc(sizeof(int)*sizeOfStack);
    }

    arrayStack(unsigned int sizeOfStack) {
        this->sizeOfStack = sizeOfStack;
        this->stack = (int *)malloc(sizeof(int)*sizeOfStack);
    }

    //Tested
    bool isFull() {
        return this->topIndex >= this->sizeOfStack;
    }

    //Tested
    bool isEmpty() {
        return topIndex == -1;
    }

    //Tested
    void push(int value) {
        if(isFull()) {
            throw "Stack is full";
        }
        stack[++topIndex] = value;
    }

    //Tested
    int top() {
        if(isEmpty()) {
            throw "Stack is empty";
        }
        return stack[this->topIndex];
    }

    //Tested
    void pop() {
        if(isEmpty()) {
            throw "Stack is empty";
        }
        stack[this->topIndex] = 0;
        this->topIndex--;
    }

    //Tested
    unsigned int size() {
        return this->topIndex + 1;
    }
};

#endif /* ARRAYSTACK_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
