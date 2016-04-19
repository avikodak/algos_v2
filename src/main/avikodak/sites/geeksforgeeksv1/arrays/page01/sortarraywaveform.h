/****************************************************************************************************************************************************
 *  File Name                   : sortarraywaveform.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\sortarraywaveform.h
 *  Created on                  : Jan 5, 2015 :: 10:24:38 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/sort-array-wave-form-2/
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

#ifndef SORTARRAYWAVEFORM_H_
#define SORTARRAYWAVEFORM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void sawfReorganizeArrayBitPosition(vector<int> &userInput,int bitPosition) {
    if(userInput.size() == 0) {
        return;
    }
    queue<int> zeroIndex,oneIndex;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(!(userInput[counter] & 1 << bitPosition)) {
            zeroIndex.push(userInput[counter]);
        } else {
            oneIndex.push(userInput[counter]);
        }
    }
    int fillCounter = -1;
    while(!zeroIndex.empty()) {
        userInput[++fillCounter] = zeroIndex.front();
        zeroIndex.pop();
    }
    while(!oneIndex.empty()) {
        userInput[++fillCounter] = oneIndex.front();
        oneIndex.pop();
    }
}

//Tested
void waveSortStraightRadixSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int maxVal = *max_element(userInput.begin(),userInput.end());
    unsigned int totalBits = log2(maxVal)+1;
    for(unsigned int counter = 0; counter < totalBits; counter++) {
        sawfReorganizeArrayBitPosition(userInput,counter);
    }
    for(unsigned int counter = 0; counter + 1 < userInput.size(); counter+=2) {
        swap(userInput[counter],userInput[counter+1]);
    }
}

//Tested
int sawfDivideStepRadixSort(vector<int> &userInput,int bitPosition,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return startIndex;
    }
    while(startIndex < endIndex) {
        while(startIndex <= endIndex && !(userInput[startIndex] & 1 << bitPosition)) {
            startIndex++;
        }
        while(startIndex <= endIndex && (userInput[endIndex] & 1 << bitPosition)) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    return endIndex;
}

//Tested
void sawfRadixSortMain(vector<int> &userInput,int bitPosition,int startIndex,int endIndex) {
    if(startIndex >= endIndex || bitPosition < 0) {
        return;
    }
    int dividingIndex = sawfDivideStepRadixSort(userInput,bitPosition,startIndex,endIndex);
    sawfRadixSortMain(userInput,bitPosition-1,startIndex,dividingIndex);
    sawfRadixSortMain(userInput,bitPosition-1,dividingIndex+1,endIndex);
}

//Tested
void waveSortRadixSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int maxVal = *max_element(userInput.begin(),userInput.end());
    int bitPosition = log2(maxVal);
    sawfRadixSortMain(userInput,bitPosition,0,userInput.size()-1);
    for(unsigned int counter = 0; counter+1 < userInput.size(); counter += 2) {
        swap(userInput[counter],userInput[counter+1]);
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void sawfMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    vector<int> auxSpace;
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace.push_back(userInput[firstCrawler++]);
            } else {
                auxSpace.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
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
void sawfMergeSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    sawfMergeSort(userInput,startIndex,middleIndex);
    sawfMergeSort(userInput,middleIndex+1,endIndex);
    sawfMergeStep(userInput,startIndex,middleIndex,endIndex);
}

//Tested
void sortWaveSortMergeSort(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    sawfMergeSort(userInput,0,userInput.size()-1);
    for(unsigned int counter = 0; counter + 1 < userInput.size(); counter += 2) {
        swap(userInput[counter],userInput[counter+1]);
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int sawfDivideStepQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    int key = userInput[pivotIndex];
    while(startIndex < endIndex) {
        while(userInput[startIndex] < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[pivotIndex],userInput[endIndex]);
    return endIndex;
}

//Tested
void sawfQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = sawfDivideStepQuickSort(userInput,startIndex,endIndex);
    sawfQuickSort(userInput,startIndex,dividingIndex-1);
    sawfQuickSort(userInput,dividingIndex+1,endIndex);
}

//Tested
void sortArrayWaveFormQuickSort(vector<int> &userInput) {
    if(userInput.size() <  2) {
        return;
    }
    sawfQuickSort(userInput,0,userInput.size()-1);
    for(unsigned int counter = 0; counter + 1 < userInput.size(); counter += 2) {
        swap(userInput[counter],userInput[counter+1]);
    }
}

#endif /* SORTARRAYWAVEFORM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
