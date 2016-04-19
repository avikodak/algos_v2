/****************************************************************************************************************************************************
 *  File Name                   : maxlenchainofpairs.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\maxlenchainofpairs.h
 *  Created on                  : Dec 1, 2014 :: 3:30:35 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-20-maximum-length-chain-of-pairs/
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef MAXLENCHAINOFPAIRS_H_
#define MAXLENCHAINOFPAIRS_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void mergePairs(vector<iPair *> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    vector<iPair *> auxSpace;
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler]->firstValue < userInput[secondCrawler]->firstValue) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        }
    }
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        userInput[startIndex + counter] = auxSpace[counter];
    }
}

//Tested
void mergeSortPairs(vector<iPair *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    mergeSortPairs(userInput,startIndex,middleIndex);
    mergeSortPairs(userInput,middleIndex+1,endIndex);
    mergePairs(userInput,startIndex,middleIndex,endIndex);
}

//Tested
int getMaxLengthChainOfPairs(vector<iPair *> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    if(userInput.size() == 1) {
        return 1;
    }
    vector<int> lengths;
    lengths.push_back(1);
    int maxLength;
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        maxLength = 1;
        for(unsigned int innerCrawler = 0; innerCrawler < outerCrawler; innerCrawler++) {
            if(userInput[outerCrawler]->firstValue > userInput[innerCrawler]->secondValue) {
                maxLength  = max(maxLength,1+lengths[innerCrawler]);
            }
        }
        lengths.push_back(maxLength);
    }
    return lengths[lengths.size()-1];
}

//Tested
int maxLengthChainOfPairs(vector<iPair *> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    mergeSortPairs(userInput,0,userInput.size()-1);
    printIVector(userInput);
    return getMaxLengthChainOfPairs(userInput);
}

#endif /* MAXLENCHAINOFPAIRS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
