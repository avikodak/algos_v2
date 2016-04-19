/****************************************************************************************************************************************************
 *  File Name   		: medianforstream.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\medianforstream.h
 *  Created on			: Dec 29, 2014 :: 12:01:01 AM
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

#ifndef MEDIANFORSTREAM_H_
#define MEDIANFORSTREAM_H_

/****************************************************************************************************************************************************/
/* 															O(N*LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void msiMinHeapify(vector<int> &minHeap,int index) {
    if(minHeap.size() == 0 || index >= minHeap.size()) {
        return;
    }
    while(2*index + 1 < minHeap.size()) {
        if(2*index + 2 < minHeap.size()) {
            if(minHeap[index] > minHeap[2*index+2] || minHeap[index] > minHeap[2*index+1]) {
                if(minHeap[2*index+1] < minHeap[2*index+2]) {
                    swap(minHeap[index],minHeap[2*index+1]);
                    index = 2*index+1;
                } else {
                    swap(minHeap[index],minHeap[2*index+2]);
                    index = 2*index+2;
                }
            } else {
                return;
            }
        } else {
            if(minHeap[index] > minHeap[2*index+1]) {
                swap(minHeap[index],minHeap[2*index+1]);
                index = 2*index+1;
            } else {
                return;
            }
        }
    }
}

void msiMaxHeapify(vector<int> &maxHeap,int index) {
    if(maxHeap.size() == 0 || index >= maxHeap.size()) {
        return;
    }
    while(2*index + 1 < maxHeap.size()) {
        if(2*index + 2 < maxHeap.size()) {
            if(maxHeap[index] < maxHeap[2*index+2] || maxHeap[index] < maxHeap[2*index+1]) {
                if(maxHeap[2*index+1] > maxHeap[2*index+2]) {
                    swap(maxHeap[2*index+1],maxHeap[index]);
                    index = 2*index + 1;
                } else {
                    swap(maxHeap[index],maxHeap[2*index+2]);
                    index = 2*index+2;
                }
            } else {
                return;
            }
        } else {
            if(maxHeap[index] < maxHeap[2*index+1]) {
                swap(maxHeap[2*index+1],maxHeap[index]);
                index = 2*index + 1;
            } else {
                return;
            }
        }
    }
}

void msiInsertIntoMinHeap(vector<int> &minHeap,int value) {
    minHeap.push_back(value);
    int index = minHeap.size()-1;
    while(index > 0) {
        if(minHeap[index] < minHeap[index/2]) {
            swap(minHeap[index],minHeap[index/2]);
            index /= 2;
        } else {
            break;
        }
    }
}

void msiInsertIntoMaxHeap(vector<int> &maxHeap,int value) {
    maxHeap.push_back(value);
    int index = maxHeap.size() - 1;
    while(index > 0) {
        if(maxHeap[index] > maxHeap[index/2]) {
            swap(maxHeap[index],maxHeap[index/2]);
            index /= 2;
        } else {
            break;
        }
    }
}

int msiGetAndDeleteMin(vector<int> &minHeap) {
    if(minHeap.size() == 0) {
        throw "Heap is empty";
    }
    int minValue = minHeap[0];
    swap(minHeap[minHeap.size()-1],minHeap[0]);
    minHeap.pop_back();
    msiMinHeapify(minHeap,0);
}

int msiGetAndDeleteMax(vector<int> &maxHeap) {
    if(maxHeap.size() == 0) {
        throw "Heap is empty";
    }
    int maxValue = maxHeap[0];
    swap(maxHeap[0],maxHeap[maxHeap.size()-1]);
    maxHeap.pop_back();
    msiMaxHeapify(maxHeap,0);
}

int average(int firstUserInput,int secondUserInput) {
    return (firstUserInput + secondUserInput)/2;
}

int getMedianStreamOfIntegerHeaps(vector<int> &minHeap,vector<int> &maxHeap,int effectiveMedian,int value) {
    int difference = minHeap.size() - maxHeap.size();
    switch(difference) {
    case -1:
        if(value < effectiveMedian) {
            msiInsertIntoMaxHeap(maxHeap,value);
        } else {
            msiInsertIntoMaxHeap(maxHeap,msiGetAndDeleteMin(minHeap));
            msiInsertIntoMinHeap(minHeap,value);
        }
        effectiveMedian = average(minHeap[0],maxHeap[0]);
    case 0:
        if(value < effectiveMedian) {
            msiInsertIntoMaxHeap(maxHeap,value);
            effectiveMedian = maxHeap[0];
        } else {
            msiInsertIntoMinHeap(minHeap,value);
            effectiveMedian = minHeap[0];
        }
    case 1:
        if(value < effectiveMedian) {
            msiInsertIntoMinHeap(minHeap,msiGetAndDeleteMax(maxHeap));
            msiInsertIntoMaxHeap(maxHeap,value);
        } else {
            msiInsertIntoMinHeap(minHeap,value);
        }
        effectiveMedian = average(minHeap[0],maxHeap[0]);
    }
    return effectiveMedian;
}

int medianOfStreamOfIntegerHeaps(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    if(userInput.size() == 1) {
        return userInput[0];
    }
    vector<int> minHeap,maxHeap;
    int effectiveMedian = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        effectiveMedian = getMedianStreamOfIntegerHeaps(minHeap,maxHeap,effectiveMedian,userInput[counter]);
    }
    return effectiveMedian;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int medianForStreamOfIntegersON2(vector<int> userInput,int value) {
    userInput.push_back(value);
    if(userInput.size() == 1) {
        return userInput[0];
    }
    int counter;
    for(counter = userInput.size()-2; counter >= 0; counter--) {
        if(userInput[counter] > value) {
            userInput[counter+1] = userInput[counter];
        } else {
            break;
        }
    }
    userInput[counter+1] = value;
    return userInput.size() % 2 == 1?userInput[userInput.size()/2]:(userInput[userInput.size()/2] + userInput[userInput.size()/2 - 1])/2;
}

#endif /* MEDIANFORSTREAM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
