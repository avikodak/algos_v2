/****************************************************************************************************************************************************
 *  File Name   		: tripletforsum.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\tripletforsum.h
 *  Created on			: Nov 27, 2014 :: 7:58:22 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
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

#ifndef TRIPLETFORSUM_H_
#define TRIPLETFORSUM_H_

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iTriplet *getTripletForSumON3(vector<int> userInput,int sum) {
    if(userInput.size() < 3) {
        return null;
    }
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-2; outerCounter++) {
        for(unsigned int middleCounter = outerCounter+1; middleCounter < userInput.size()-1; middleCounter++) {
            for(unsigned int innerCounter = middleCounter+1; innerCounter < userInput.size(); innerCounter++) {
                if(userInput[outerCounter] + userInput[middleCounter] + userInput[innerCounter] == sum) {
                    return new iTriplet(userInput[outerCounter],userInput[middleCounter],userInput[innerCounter]);
                }
            }
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iTriplet *getTripletForSumON2(vector<int> userInput,int sum) {
    if(userInput.size() < 3) {
        return null;
    }
    sort(userInput.begin(),userInput.end());
    int currentSum;
    unsigned int startCrawler,endCrawler;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-2; outerCounter++) {
        startCrawler = outerCounter + 1;
        endCrawler = userInput.size()-1;
        while(startCrawler < endCrawler) {
            currentSum = userInput[outerCounter] + userInput[startCrawler] + userInput[endCrawler];
            if(currentSum  == sum) {
                return new iTriplet(userInput[outerCounter],userInput[startCrawler],userInput[endCrawler]);
            } else if(currentSum > sum) {
                endCrawler--;
            } else {
                startCrawler++;
            }
        }
    }
    return null;
}

#endif /* TRIPLETFORSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
