/****************************************************************************************************************************************************
 *  File Name   		: kthsmallest.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\kthsmallest.h
 *  Created on			: Jan 5, 2015 :: 8:53:08 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KTHSMALLEST_H_
#define KTHSMALLEST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(B*N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void kthsReorganizeArray(vector<int> &userInput,int bitPosition){
	if(userInput.size() == 0){
		return;
	}
	queue<int> zeroBitBucket,oneBitBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & 1 << bitPosition){
			oneBitBucket.push(userInput[counter]);
		}else{
			zeroBitBucket.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	while(!zeroBitBucket.empty()){
		userInput[++fillCounter] = zeroBitBucket.front();
		zeroBitBucket.pop();
	}
	while(!oneBitBucket.empty()){
		userInput[++fillCounter] = oneBitBucket.front();
		oneBitBucket.pop();
	}
}

//Tested
int getkthsStraightRadixSort(vector<int> userInput,unsigned int kValue){
	if(userInput.size() < kValue || kValue == 0){
		return INT_MIN;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	unsigned int noOfBits = log2(maxVal)+1;
	for(unsigned int counter = 0;counter < noOfBits;counter++){
		kthsReorganizeArray(userInput,counter);
	}
	return userInput[kValue-1];
}

//Tested
int kthsDivideStepRadixSort(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex > endIndex || bitPosition < 0){
		return INT_MIN;
	}
	while(startIndex < endIndex){
		while(startIndex <= endIndex && !(userInput[startIndex] & 1 << bitPosition)){
			startIndex++;
		}
		while(startIndex <= endIndex && (userInput[endIndex] & 1 << bitPosition)){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}

//Tested
void kthsRadixSortMain(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex >= endIndex || bitPosition < 0){
		return;
	}
	int dividingIndex = kthsDivideStepRadixSort(userInput,bitPosition,startIndex,endIndex);
	kthsRadixSortMain(userInput,bitPosition-1,startIndex,dividingIndex);
	kthsRadixSortMain(userInput,bitPosition-1,dividingIndex+1,endIndex);
}

//Tested
int getKthSmallestByRadixSort(vector<int> userInput,unsigned int kValue){
	if(userInput.size() < kValue){
		return INT_MIN;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	int bitPosition = log2(maxVal);
	kthsRadixSortMain(userInput,bitPosition,0,userInput.size()-1);
	return userInput[kValue-1];
}

/****************************************************************************************************************************************************/
/* 																O(NLOGK) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void kthsMaxHeapify(vector<int> &heap,unsigned int index){
	if(heap.size() <= index){
		return;
	}
	while(2*index + 1 < heap.size()){
		if(2*index + 2 < heap.size()){
			if(heap[index] < heap[2*index + 2] || heap[index] < heap[2*index+1]){
				if(heap[2*index + 1] > heap[2*index + 2]){
					swap(heap[index],heap[2*index+1]);
					index = 2 * index + 1;
				}else{
					swap(heap[index],heap[2*index+2]);
					index = 2 * index + 2;
				}
			}else{
				break;
			}
		}else{
			if(heap[index] < heap[2*index + 1]){
				swap(heap[index],heap[2*index+1]);
				index = 2 * index + 1;
			}else{
				break;
			}
		}
	}
}

//Tested
int kthsGetMax(vector<int> &heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	return heap[0];
}

//Tested
void kthsDeleteMax(vector<int> &heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	kthsMaxHeapify(heap,0);
}

//Tested
void kthsInsertIntoMaxHeap(vector<int> &heap,int key){
	heap.push_back(key);
	int index = heap.size() - 1;
	while(index > 0){
		if(heap[index/2] < heap[index]){
			swap(heap[index/2],heap[index]);
			index /= 2;
		}else{
			break;
		}
	}
}

//Tested
int kthSmallestValMaxHeap(vector<int> userInput,unsigned int kValue){
	if(userInput.size() < kValue){
		return INT_MIN;
	}
	vector<int> heap;
	for(unsigned int counter = 0;counter < kValue;counter++){
		heap.push_back(userInput[counter]);
	}
	for(int counter = heap.size()/2;counter >= 0;counter--){
		kthsMaxHeapify(heap,counter);
	}
	for(unsigned int counter = kValue;counter < userInput.size();counter++){
		if(kthsGetMax(heap) > userInput[counter]){
			kthsDeleteMax(heap);
			kthsInsertIntoMaxHeap(heap,userInput[counter]);
		}
	}
	return kthsGetMax(heap);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void kthsMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int firstCrawler = startIndex,secondCrawler = middleIndex + 1;
	vector<int> auxSpace;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

//Tested
void kthsMergeSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	kthsMergeSort(userInput,startIndex,middleIndex);
	kthsMergeSort(userInput,middleIndex+1,endIndex);
	kthsMergeStep(userInput,startIndex,middleIndex,endIndex);
}

//Tested
int getKthSmallestUsingMergeSort(vector<int> userInput,unsigned int kValue){
	if(userInput.size() < kValue){
		return INT_MIN;
	}
	kthsMergeSort(userInput,0,userInput.size()-1);
	return userInput[kValue-1];
}

//Tested
void kthsMinHeapify(vector<int> &heap,unsigned int index){
	if(index >= heap.size()){
		return;
	}
	while(2*index + 1 < heap.size()){
		if(2*index + 2 < heap.size()){
			if(heap[2*index+2] < heap[index] || heap[2*index + 1] < heap[index]){
				if(heap[2*index+1] < heap[2*index+2]){
					swap(heap[index],heap[2*index+1]);
					index = 2 * index + 1;
				}else{
					swap(heap[index],heap[2*index+2]);
					index = 2 * index + 2;
				}
			}else{
				break;
			}
		}else{
			if(heap[2*index + 1] < heap[index]){
				swap(heap[index],heap[2*index+1]);
				index = 2 * index + 1;
			}else{
				break;
			}
		}
	}
}

//Tested
int kthsGetMin(vector<int> heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	return heap[0];
}

//Tested
void kthsDeleteMin(vector<int> &heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	kthsMinHeapify(heap,0);
}

//Tested
int kthSmallestMinHeap(vector<int> userInput,unsigned int kValue){
	if(userInput.size() < kValue){
		return INT_MIN;
	}
	for(int counter = userInput.size()/2;counter >= 0;counter--){
		kthsMinHeapify(userInput,counter);
	}
	int kthMinVal;
	while(kValue--){
		kthMinVal = kthsGetMin(userInput);
		kthsDeleteMin(userInput);
	}
	return kthMinVal;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int kthsQuickSortDivideStep(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int key = userInput[pivotIndex];
	while(startIndex < endIndex){
		while(userInput[startIndex] < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[pivotIndex],userInput[endIndex]);
	return endIndex;
}

//Tested
int getKthSmallestPartialQuickSort(vector<int> &userInput,int kValue,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int dividingIndex = kthsQuickSortDivideStep(userInput,startIndex,endIndex);
	if(dividingIndex == kValue - 1){
		return userInput[dividingIndex];
	}
	if(kValue - 1 < dividingIndex){
		return getKthSmallestPartialQuickSort(userInput,kValue,startIndex,dividingIndex-1);
	}else{
		return getKthSmallestPartialQuickSort(userInput,kValue,dividingIndex+1,endIndex);
	}
}

#endif /* KTHSMALLEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
