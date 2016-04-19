/****************************************************************************************************************************************************
 *  File Name   		: heapsort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture21\heapsort.h
 *  Created on			: Dec 1, 2014 :: 10:14:57 PM
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

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void hsHeapify(vector<int> &userInput,int index,int size = INT_MIN) {
    if(size == INT_MIN) {
        size = userInput.size();
    }
    if(index > size) {
        return;
    }
    int temp;
    while(2*index+1 < size) {
        if(2*index + 2 < size) {
            if(userInput[2*index+1] < userInput[2*index+2]) {
                temp = userInput[2*index+1];
                userInput[2*index+1] = userInput[index];
                userInput[index] = temp;
            } else {
                temp = userInput[2*index+2];
                userInput[2*index+2] = userInput[index];
                userInput[index] = temp;
            }
        } else {
            temp = userInput[2*index+1];
            userInput[2*index+1] = userInput[index];
            userInput[index] = temp;
        }
    }
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void heapSort(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(int counter = userInput.size()/2; counter >= 0; counter--) {
        hsHeapify(userInput,counter);
    }
    int tempForSwap;
    for(int counter = 0; counter < userInput.size(); counter++) {
        tempForSwap = userInput[0];
        userInput[userInput.size()-1-counter] = userInput[0];
        userInput[userInput.size()-1-counter] = tempForSwap;
        hsHeapify(userInput,0,userInput.size()-counter);
    }
    reverse(userInput.begin(),userInput.end());
}


#endif /* HEAPSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
