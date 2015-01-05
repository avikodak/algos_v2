/****************************************************************************************************************************************************
 *  File Name   		: findkclosestelementstogivenvalue.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\findkclosestelementstogivenvalue.h
 *  Created on			: Jan 4, 2015 :: 1:21:14 PM
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

#ifndef FINDKCLOSESTELEMENTSTOGIVENVALUE_H_
#define FINDKCLOSESTELEMENTSTOGIVENVALUE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGK) Algorithm 																    */
/****************************************************************************************************************************************************/
void fkceHeapify(vector<int> &heap,int key,int index){
	if(heap.size() == 0 || index >= heap.size()){
		return;
	}
	while(2*index+1 < heap.size()){
		if(2*index + 2 < heap.size()){
			if(abs(heap[2*index + 2] - key) > abs(heap[2*index + 1] - key) ||  abs(heap[2*index + 1] - key) > abs(heap[2*index + 1] - key)){
				if(abs(heap[2*index + 1] - key) > abs(heap[2*index + 2] - key)){
					swap(heap[2*index + 1],heap[index]);
					index = 2*index + 1;
				}else{
					swap(heap[2*index + 2],heap[index]);
					index = 2*index + 2;
				}
			}else{
				break;
			}
		}else{
			if(abs(heap[2*index + 1] - key) > abs(heap[2*index + 1] - key)){
				swap(heap[2*index + 1],heap[index]);
				index = 2*index + 1;
			}else{
				break;
			}
		}
	}
}

int fkceGetValueMaxDistance(vector<int> &heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	return heap[0];
}

void fkceDeleteMaxDistance(vector<int> &heap,int key){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	fkceHeapify(heap,key,0);
}

void fkceInsertIntoHeap(vector<int> &heap,int key,int value){
	heap.push_back(value);
	int index = heap.size() - 1;
	while(index > 0){
		if(abs(heap[index/2] - key) < abs(heap[index] - key)){
			swap(heap[index/2],heap[index]);
		}else{
			break;
		}
	}
}

vector<int> findKClosestElementsGivenValue(vector<int> userInput,int key,int kValue){
	vector<int> kClosestValues;
	if(userInput.size() < kValue){
		return kClosestValues;
	}
	for(unsigned int counter = 0;counter < kValue;counter++){
		kClosestValues.push_back(userInput[counter]);
	}
	for(int counter = kClosestValues.size()/2;counter >= 0;counter--){
		fkceHeapify(kClosestValues,key,counter);
	}
	for(unsigned int counter = kValue;counter < userInput.size();counter++){
		if(fkceGetValueMaxDistance(kClosestValues) > abs(userInput[counter] - key)){
			fkceDeleteMaxDistance(kClosestValues,key);
			fkceInsertIntoHeap(userInput[counter]);
		}
	}
	return kClosestValues;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void fkceMergeStep(vector<int> &userInput,int key,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	vector<int> auxSpace;
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			if(abs(userInput[firstCrawler] - key) < abs(userInput[secondCrawler] - key)){
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

void fkceMergeSort(vector<int> &userInput,int key,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	fkceMergeSort(userInput,key,startIndex,middleIndex);
	fkceMergeSort(userInput,key,middleIndex+1,endIndex);
	fkceMergeStep(userInput,key,startIndex,middleIndex,endIndex);
}

vector<int> getKClosestElementsMergeSort(vector<int> userInput,int key,int kValue){
	vector<int> kClosestPoints;
	if(userInput.size() < kValue){
		return kClosestPoints;
	}
	fkceMergeSort(userInput,key,0,userInput.size()-1);
	for(unsigned int counter = 0;counter < kValue;counter++){
		kClosestPoints.push_back(userInput[counter]);
	}
	return kClosestPoints;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int fkceDivideStepQuickSort(vector<int> &userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int dividingKey = abs(userInput[pivotIndex] - key);
	while(startIndex < endIndex){
		while(abs(userInput[startIndex] - key) < dividingKey){
			startIndex++;
		}
		while(startIndex < endIndex && abs(userInput[endIndex] - key) >= dividingKey){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[endIndex],userInput[pivotIndex]);
	return endIndex;
}

void fkceQuickSort(vector<int> &userInput,int key,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = fkceDivideStepQuickSort(userInput,key,startIndex,endIndex);
	fkceQuickSort(userInput,key,startIndex,dividingIndex-1);
	fkceQuickSort(userInput,key,dividingIndex+1,endIndex);
}

vector<int> getKClosestElementsQuickSort(vector<int> userInput,int key,int kValue){
	vector<int> kClosestPoints;
	if(userInput.size() < kValue){
		return kClosestPoints;
	}
	fkceQuickSort(userInput,key,0,userInput.size()-1);
	for(unsigned int counter = 0;counter < kValue;counter++){
		kClosestPoints.push_back(userInput[counter]);
	}
	return kClosestPoints;
}

#endif /* FINDKCLOSESTELEMENTSTOGIVENVALUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
