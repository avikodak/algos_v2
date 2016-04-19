/****************************************************************************************************************************************************
 *  File Name   		: alternatingpositivenegative.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\alternatingpositivenegative.h
 *  Created on			: Jan 5, 2015 :: 11:24:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
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

#ifndef ALTERNATINGPOSITIVENEGATIVE_H_
#define ALTERNATINGPOSITIVENEGATIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void alternatePositiveNegativeNumbers(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    queue<int> negBucket,posBucket;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] < 0) {
            negBucket.push(userInput[counter]);
        } else {
            posBucket.push(userInput[counter]);
        }
    }
    int fillCounter = -1;
    while(!negBucket.empty() && !posBucket.empty()) {
        userInput[++fillCounter] = negBucket.front();
        userInput[++fillCounter] = posBucket.front();
        negBucket.pop();
        posBucket.pop();
    }
    while(!negBucket.empty()) {
        userInput[++fillCounter] = negBucket.front();
        negBucket.pop();
    }
    while(!posBucket.empty()) {
        userInput[++fillCounter] = posBucket.front();
        posBucket.pop();
    }
}

//Tested
int alternatePositiveDivideStep(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return INT_MIN;
    }
    while(startIndex < endIndex) {
        while(startIndex < endIndex && userInput[startIndex] < 0) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= 0) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    return startIndex;
}

//Tested
void alternatePositiveNegative(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int pivotIndex = alternatePositiveDivideStep(userInput,0,userInput.size()-1);
    unsigned int counter = 1;
    while(counter < userInput.size() && pivotIndex < (int)userInput.size()) {
        if(userInput[counter] < 0) {
            swap(userInput[counter],userInput[pivotIndex]);
            counter += 2;
            pivotIndex += 1;
        } else {
            break;
        }
    }
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void posNegMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    vector<int> auxSpace;
    while(firstCrawler <= middleIndex && userInput[firstCrawler] < 0) {
        auxSpace.push_back(userInput[firstCrawler++]);
    }
    while(secondCrawler <= endIndex && userInput[secondCrawler] < 0) {
        auxSpace.push_back(userInput[secondCrawler++]);
    }
    while(firstCrawler <= middleIndex && userInput[firstCrawler] >= 0) {
        auxSpace.push_back(userInput[firstCrawler++]);
    }
    while(secondCrawler <= endIndex && userInput[secondCrawler] >= 0) {
        auxSpace.push_back(userInput[secondCrawler++]);
    }
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        userInput[startIndex + counter] = auxSpace[counter];
    }
}

//Tested
void positiveNegativeMergeSortMain(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    positiveNegativeMergeSortMain(userInput,startIndex,middleIndex);
    positiveNegativeMergeSortMain(userInput,middleIndex+1,endIndex);
    posNegMergeStep(userInput,startIndex,middleIndex,endIndex);
}

//Tested
int firstPositiveIndex(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex] > 0?startIndex:INT_MIN;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] > 0) {
        if(middleIndex-1 >= startIndex && userInput[middleIndex-1] > 0) {
            return firstPositiveIndex(userInput,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    } else {
        return firstPositiveIndex(userInput,middleIndex+1,endIndex);
    }
}

//Tested
void alternatePositiveNegativeMerge(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    positiveNegativeMergeSortMain(userInput,0,userInput.size()-1);
    int pivotIndex = firstPositiveIndex(userInput,0,userInput.size()-1);
    unsigned int counter = 1;
    while(counter < userInput.size() && pivotIndex < (int)userInput.size()) {
        if(userInput[counter] < 0) {
            swap(userInput[counter],userInput[pivotIndex]);
            counter += 2;
            pivotIndex += 1;
        } else {
            break;
        }
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void alternatePositiveNegativeON2(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    bool shouldBePositive = false;
    unsigned int innerCounter;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        if(shouldBePositive) {
            if(userInput[outerCounter] < 0) {
                for(innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
                    if(userInput[innerCounter] > 0) {
                        break;
                    }
                }
                if(innerCounter >= userInput.size()) {
                    break;
                }
                swap(userInput[outerCounter],userInput[innerCounter]);
            }
        } else {
            if(userInput[outerCounter] > 0) {
                for(innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
                    if(userInput[innerCounter] < 0) {
                        break;
                    }
                }
                if(innerCounter >= userInput.size()) {
                    break;
                }
                swap(userInput[outerCounter],userInput[innerCounter]);
            }
        }
        shouldBePositive = !shouldBePositive;
    }
}

#endif /* ALTERNATINGPOSITIVENEGATIVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
