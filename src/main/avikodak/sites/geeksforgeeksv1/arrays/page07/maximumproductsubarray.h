/****************************************************************************************************************************************************
 *  File Name   		: maximumproductsubarray.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maximumproductsubarray.h
 *  Created on			: Jan 2, 2015 :: 12:33:38 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-product-subarray/
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

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maximumProductSubarray(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MAX;
    }
    int negativeProduct = 1,positiveProduct = 1,maxProduct = INT_MIN,temp;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] > 0) {
            positiveProduct *= userInput[counter];
            negativeProduct = min(1,negativeProduct * userInput[counter]);
        } else if(userInput[counter] == 0) {
            negativeProduct = 1;
            positiveProduct = 1;
        } else if(userInput[counter] < 0) {
            temp = maxProduct;
            maxProduct = max(1,negativeProduct * userInput[counter]);
            negativeProduct = min(negativeProduct,temp * userInput[counter]);
        }
        maxProduct = max(maxProduct,positiveProduct);
    }
    return maxProduct;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxProductSubArrayON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MAX;
    }
    int maxProduct = INT_MIN,currentProduct;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        currentProduct = 1;
        for(unsigned int innerCounter = outerCounter; innerCounter < userInput.size(); innerCounter++) {
            currentProduct *= userInput[innerCounter];
            maxProduct = max(maxProduct,currentProduct);
        }
    }
    return maxProduct;
}

#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
