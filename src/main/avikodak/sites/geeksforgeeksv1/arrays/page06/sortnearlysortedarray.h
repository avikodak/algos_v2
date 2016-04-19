/****************************************************************************************************************************************************
 *  File Name   		: sortnearlysortedarray.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\sortnearlysortedarray.h
 *  Created on			: Jan 3, 2015 :: 10:07:58 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/nearly-sorted-algorithm/
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

#ifndef SORTNEARLYSORTEDARRAY_H_
#define SORTNEARLYSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(N*K) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void snsaInsertionSort(vector<int> &userInput,int kValue) {
    if(userInput.size() < 2) {
        return;
    }
    int key,innerCrawler;
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        key = userInput[outerCrawler];
        innerCrawler = outerCrawler-1;
        while(innerCrawler >= 0 && innerCrawler > (int)outerCrawler - kValue - 1&& userInput[innerCrawler] > key) {
            userInput[innerCrawler+1] = userInput[innerCrawler];
            innerCrawler--;
        }
        userInput[innerCrawler+1] = key;
    }
}

/****************************************************************************************************************************************************/
/* 																O(NLOGK) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void snsaHeapify(vector<int> &heap,unsigned int index) {
    if(heap.size() == 0 || index >= heap.size()) {
        return;
    }
    while(2*index + 1 < heap.size()) {
        if(2*index + 2 < heap.size()) {
            if(heap[2*index+2] < heap[index] || heap[2*index+1] < heap[index]) {
                if(heap[2*index+1] < heap[2*index+2]) {
                    swap(heap[2*index+1],heap[index]);
                    index = 2*index+1;
                } else {
                    swap(heap[2*index+2],heap[index]);
                    index = 2*index+2;
                }
            } else {
                break;
            }
        } else if(heap[2*index + 1] < heap[index]) {
            swap(heap[2*index+1],heap[index]);
            index = 2*index+1;
        } else {
            break;
        }
    }
}

//Tested
void snsaInsertIntoHeap(vector<int> &heap,int key) {
    heap.push_back(key);
    int index = heap.size()-1;
    while(index > 0) {
        if(heap[index/2] > heap[index]) {
            swap(heap[index/2],heap[index]);
            index /= 2;
        } else {
            break;
        }
    }
}

//Tested
int snsaGetMin(vector<int> heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    return heap[0];
}

//Tested
void snsaDeleteMin(vector<int> &heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    snsaHeapify(heap,0);
}

//Tested
void sortNearlySortedArray(vector<int> &userInput,unsigned int kValue) {
    if(userInput.size() < kValue) {
        return;
    }
    vector<int> heap;
    for(unsigned int counter = 0; counter < kValue; counter++) {
        heap.push_back(userInput[counter]);
    }
    for(int counter = userInput.size()/2; counter >= 0; counter--) {
        snsaHeapify(heap,counter);
    }
    int fillCounter = -1;
    for(unsigned int counter = kValue; counter < userInput.size(); counter++) {
        userInput[++fillCounter] = snsaGetMin(heap);
        snsaDeleteMin(heap);
        snsaInsertIntoHeap(heap,userInput[counter]);
    }
    while(heap.size() > 0) {
        userInput[++fillCounter] = snsaGetMin(heap);
        snsaDeleteMin(heap);
    }
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void snsaMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    vector<int> auxSpace;
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
void snsaMergeSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    snsaMergeSort(userInput,startIndex,middleIndex);
    snsaMergeSort(userInput,middleIndex+1,endIndex);
    snsaMergeStep(userInput,startIndex,middleIndex,endIndex);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int snsaDivideStepQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return startIndex;
    }
    int pivotIndex = endIndex,key = userInput[pivotIndex];
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
void snsaQuickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = snsaDivideStepQuickSort(userInput,startIndex,endIndex);
    snsaQuickSort(userInput,startIndex,dividingIndex-1);
    snsaQuickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* SORTNEARLYSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
