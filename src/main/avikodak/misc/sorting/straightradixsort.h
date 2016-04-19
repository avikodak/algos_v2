/****************************************************************************************************************************************************
 *  File Name   		: straightradixsort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\straightradixsort.h
 *  Created on			: Dec 11, 2014 :: 1:01:05 PM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef STRAIGHTRADIXSORTV2_H_
#define STRAIGHTRADIXSORTV2_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reorgansizeArray(vector<int> &userInput,int bitPosition) {
    if(userInput.size() < 2) {
        return;
    }
    queue<int> zeroBucket,oneBucket;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] & 1 << bitPosition) {
            oneBucket.push(userInput[counter]);
        } else {
            zeroBucket.push(userInput[counter]);
        }
    }
    int fillCounter = -1;
    while(!zeroBucket.empty()) {
        userInput[++fillCounter] = zeroBucket.front();
        zeroBucket.pop();
    }
    while(!oneBucket.empty()) {
        userInput[++fillCounter] = oneBucket.front();
        oneBucket.pop();
    }
}

//Tested
void straightRadixSortV2(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int maxVal = *max_element(userInput.begin(),userInput.end());
    int noOfBits = log2(maxVal) + 1;
    for(int counter = 0; counter < noOfBits; counter++) {
        reorgansizeArray(userInput,counter);
    }
}

#endif /* STRAIGHTRADIXSORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
