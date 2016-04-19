/****************************************************************************************************************************************************
 *  File Name                   : dynamicarray.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\dynamicarray.h
 *  Created on                  : Oct 18, 2014 :: 1:16:17 PM
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
#ifndef DYNAMICSTACK_H_
#define DYNAMICSTACK_H_

//Tested
class dynamicstack {
private:
    sillNode *topNode;
    unsigned int counter;
public:
    dynamicstack() {
        topNode = null;
        counter = 0;
    }

    //Tested
    bool isEmpty() {
        return topNode == null;
    }

    //Tested
    unsigned int size() {
        return counter;
    }

    //Tested
    void push(int value) {
        if(topNode == null) {
            topNode = new sillNode(value);
        } else {
            sillNode *temp = new sillNode(value);
            temp->next = topNode;
            topNode = temp;
        }
        counter++;
    }

    //Tested
    void pop() {
        if(topNode == null) {
            throw "Stack is empty";
        }
        sillNode *temp = topNode;
        topNode = topNode->next;
        free(temp);
        counter--;
    }

    //Tested
    int top() {
        if(isEmpty()) {
            throw "Stack is empty";
        }
        return topNode->value;
    }
};

#endif /* DYNAMICSTACK_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/

