/****************************************************************************************************************************************************
 *  File Name                   : jimandtheorders.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\jimandtheorders.h
 *  Created on                  : Jul 17, 2015 :: 11:35:09 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/jim-and-the-orders
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef JIMANDTHEORDERS_H_
#define JIMANDTHEORDERS_H_

//Tested
struct order {
public:
    unsigned int time;
    unsigned int index;

    order() {
    }

    order(unsigned int time,unsigned int index) {
        this->time = time;
        this->index = index;
    }
};

//Tested
bool sortFunc(order *firstOrder,order *secondOrder) {
    if(firstOrder->time == secondOrder->time) {
        return firstOrder->index < secondOrder->index;
    } else {
        return firstOrder->time < secondOrder->time;
    }
}

//Tested
void getOrderSequence() {
    unsigned int inputSize,arrivalTime,timeToCook;
    scanf("%u",&inputSize);
    vector<order *> userInput;
    order *temp;
    for(unsigned int counter = 0; counter < inputSize; counter++) {
        scanf("%u %u",&arrivalTime,&timeToCook);
        temp = new order(arrivalTime+timeToCook,counter);
        userInput.push_back(temp);
    }
    sort(userInput.begin(),userInput.end(),sortFunc);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d ",userInput[counter]->index+1);
    }
}

#endif /* JIMANDTHEORDERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
