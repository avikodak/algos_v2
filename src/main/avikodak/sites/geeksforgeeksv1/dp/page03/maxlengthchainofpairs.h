/****************************************************************************************************************************************************
 *  File Name                   : maxlengthchainofpairs.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\maxlengthchainofpairs.h
 *  Created on                  : Dec 15, 2014 :: 11:43:32 AM
 *  Author                      : AVINASH
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef MAXLENGTHCHAINOFPAIRS_H_
#define MAXLENGTHCHAINOFPAIRS_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int mlcDivideStepQuickSort(vector<iPair *> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    int key = userInput[pivotIndex]->firstValue;
    while(startIndex < endIndex) {
        while(userInput[startIndex]->firstValue < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex]->firstValue >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[endIndex],userInput[startIndex]);
        }
    }
    swap(userInput[endIndex],userInput[pivotIndex]);
    return endIndex;
}

//Tested
void mlcQuickSort(vector<iPair *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = mlcDivideStepQuickSort(userInput,startIndex,endIndex);
    mlcQuickSort(userInput,startIndex,dividingIndex-1);
    mlcQuickSort(userInput,dividingIndex+1,endIndex);
}

//Tested
int maxLengthChainOfPairs(vector<iPair *> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    mlcQuickSort(userInput,0,userInput.size()-1);
    vector<int> lengths;
    lengths.push_back(1);
    int maxLength = 1;
    for(unsigned int outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        maxLength = 1;
        for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            if(userInput[outerCounter]->firstValue > userInput[innerCounter]->secondValue) {
                maxLength = max(maxLength,1 + lengths[innerCounter]);
            }
        }
        lengths.push_back(maxLength);
    }
    return lengths[lengths.size()-1];
}

#endif /* MAXLENGTHCHAINOFPAIRS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
