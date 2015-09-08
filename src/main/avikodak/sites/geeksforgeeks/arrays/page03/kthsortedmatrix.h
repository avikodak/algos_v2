/****************************************************************************************************************************************************
 *  File Name   		: kthsortedmatrix.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\kthsortedmatrix.h
 *  Created on			: Dec 22, 2014 :: 8:00:40 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
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

#ifndef KTHSORTEDMATRIX_H_
#define KTHSORTEDMATRIX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void heapify(vector<iRowColumn *> &heap,unsigned int index){
	if(index >= heap.size()){
		throw "Heap is empty";
	}
	while(index < heap.size()){
		if(2*index+2 < heap.size()){
			if(heap[index]->value > heap[2*index+2]->value || heap[index]->value > heap[2*index+1]->value){
				if(heap[2*index+1]->value < heap[2*index+2]->value){
					swap(heap[index],heap[2*index+1]);
					index = 2*index+1;
				}else{
					swap(heap[index],heap[2*index+2]);
					index = 2*index+2;
				}
			}else{
				return;
			}
		}else if(2*index + 1 < heap.size()){
			if(heap[index]->value > heap[2*index+1]->value){
				swap(heap[index],heap[2*index+1]);
				index = 2*index+1;
			}else{
				return;
			}
		}else{
			return;
		}
	}
}

//Tested
void deleteMin(vector<iRowColumn *> &heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	swap(heap[0],heap[heap.size()-1]);
	heap.erase(heap.begin() + heap.size() - 1);
	if(heap.size() > 0){
		heapify(heap,0);
	}
}

//Tested
iRowColumn *getMin(vector<iRowColumn *> heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	return	heap[0];
}

//Tested
void insertIntoHeap(vector<iRowColumn *> &heap,iRowColumn *key){
	heap.push_back(key);
	int index = heap.size()-1;
	while(index > 0){
		if(heap[index]->value < heap[index/2]->value){
			swap(heap[index],heap[index/2]);
			index = index/2;
		}else{
			break;
		}
	}
}

//Tested
int kthValInSortedMatrix(vector<vector<int> > userInput,unsigned int kValue){
	if(userInput.size() == 0 || userInput[0].size() == 0 || kValue >= userInput.size() * userInput[0].size()){
		return INT_MIN;
	}
	vector<iRowColumn *> heap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		heap.push_back(new iRowColumn(userInput[counter][0],counter,0));
	}
	for(int counter = heap.size()/2;counter > 0;counter--){
		heapify(heap,counter);
	}
	iRowColumn *temp;
	while(heap.size() > 0 && --kValue){
		temp = getMin(heap);
		deleteMin(heap);
		if(temp->column + 1 < (int)userInput[temp->row].size()){
			temp->value = userInput[temp->row][temp->column+1];
			temp->column += 1;
			insertIntoHeap(heap,temp);
		}
	}
	return getMin(heap)->value;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int kthValueSortedMatrix(vector<vector<int> > userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	vector<int> mergedArray;
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[rowCounter].size();columnCounter++){
			mergedArray.push_back(userInput[rowCounter][columnCounter]);
		}
	}
	sort(mergedArray.begin(),mergedArray.end());
	return mergedArray.size() < kValue?INT_MIN:mergedArray[kValue-1];
}

#endif /* KTHSORTEDMATRIX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
