/****************************************************************************************************************************************************
 *  File Name   		: maxdifferenceelements.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\maxdifferenceelements.h
 *  Created on			: Dec 30, 2014 :: 7:26:03 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-difference-between-two-elements/
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

#ifndef MAXDIFFERENCEELEMENTS_H_
#define MAXDIFFERENCEELEMENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxDifferenceBetweenValues(vector<int> userInput) {
    if(userInput.size() < 2) {
        return INT_MIN;
    }
    int minVal = userInput[0];
    int maxDifference = INT_MIN;
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(minVal > userInput[counter]) {
            minVal = userInput[counter];
        } else {
            maxDifference = max(maxDifference,userInput[counter] - minVal);
        }
    }
    return maxDifference;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxDifferenceBetweenValuesON2(vector<int> userInput) {
    if(userInput.size() < 2) {
        return INT_MIN;
    }
    int maxDifference = INT_MIN;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
            if(userInput[innerCrawler] > userInput[outerCrawler]) {
                maxDifference = max(maxDifference,userInput[innerCrawler] - userInput[outerCrawler]);
            }
        }
    }
    return maxDifference;
}

#endif /* MAXDIFFERENCEELEMENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
