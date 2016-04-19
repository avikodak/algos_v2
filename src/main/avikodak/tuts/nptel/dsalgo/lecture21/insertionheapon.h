/****************************************************************************************************************************************************
 *  File Name   		: insertionheapon.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture21\insertionheapon.h
 *  Created on			: Dec 1, 2014 :: 10:15:06 PM
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

#ifndef INSERTIONHEAPON_H_
#define INSERTIONHEAPON_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void heapify(vector<int> &userInput,int index) {
    int temp;
    while(2*index + 1 < userInput.size()) {
        if(2*index + 2 < userInput.size()) {
            if(userInput[index] > userInput[2*index + 1] || userInput[index] > userInput[2*index+2]) {
                if(userInput[2*index+1] < userInput[2*index+2]) {
                    temp = userInput[2*index+1];
                    userInput[2*index+1] = userInput[index];
                    userInput[index] = temp;
                    index = 2*index+1;
                } else {
                    temp = userInput[2*index+2];
                    userInput[2*index+2] = userInput[index];
                    userInput[index] = temp;
                    index = 2*index+2;
                }
            }
        } else {
            temp = userInput[2*index+1];
            userInput[2*index+1] = userInput[index];
            userInput[index] = temp;
            index = 2*index+1;
        }

    }
}

void insertionHeapON(vector<int> &userInput) {
    for(int counter = userInput.size()/2; counter >= 0; counter--) {
        heapify(userInput,counter);
    }
}

#endif /* INSERTIONHEAPON_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
