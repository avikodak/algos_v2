/****************************************************************************************************************************************************
 *  File Name   		: countinversions.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\countinversions.h
 *  Created on			: Nov 27, 2014 :: 6:30:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/counting-inversions/
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

#ifndef COUNTINVERSIONS_H_
#define COUNTINVERSIONS_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int icMerge(vector<int> &userInput,int startIndex,int midIndex,int endIndex) {
    int firstCrawler = startIndex,secondCrawler = midIndex+1;
    vector<int> temp;
    unsigned int inversionCount = 0;
    while(firstCrawler <= midIndex || secondCrawler <= endIndex) {
        if(firstCrawler > midIndex || secondCrawler > endIndex) {
            if(firstCrawler <= midIndex) {
                temp.push_back(userInput[firstCrawler++]);
            } else {
                temp.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
                temp.push_back(userInput[firstCrawler++]);
            } else {
                temp.push_back(userInput[secondCrawler++]);
                inversionCount += midIndex + 1 - firstCrawler;
            }
        }
    }
    for(unsigned int counter = 0; counter < temp.size(); counter++) {
        userInput[startIndex + counter] = temp[counter];
    }
    return inversionCount;
}

//Tested
unsigned int inversionCount(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return 0;
    }
    int middleIndex = (startIndex + endIndex)/2;
    unsigned int counter = inversionCount(userInput,startIndex,middleIndex);
    counter += inversionCount(userInput,middleIndex+1,endIndex);
    counter += icMerge(userInput,startIndex,middleIndex,endIndex);
    return counter;
}

//Tested
unsigned int inversionCountMerging(vector<int> userInput) {
    if(userInput.size() < 2) {
        return 0;
    }
    unsigned int counter = inversionCount(userInput,0,userInput.size()-1);
    return counter;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int countInversionsON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    unsigned int inversionCount = 0;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[outerCounter] > userInput[innerCounter]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

#endif /* COUNTINVERSIONS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
