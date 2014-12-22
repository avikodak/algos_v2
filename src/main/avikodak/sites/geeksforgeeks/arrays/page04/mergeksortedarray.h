/****************************************************************************************************************************************************
 *  File Name   		: mergeksortedarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\mergeksortedarray.h
 *  Created on			: Dec 22, 2014 :: 9:26:52 AM
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

#ifndef MERGEKSORTEDARRAY_H_
#define MERGEKSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void heapify(vector<vector<int> > userInput,vector<rowColumn *> heap,int index){
	if(index >= heap.size()){
		return;
	}
	while(index < heap.size()){
		if(2*index + 2 < heap.size()){
			if(userInput[heap[2*index+1]->row][heap[2*index+1]->column] < userInput[heap[index]->row][heap[index]->column] || userInput[heap[2*index+2]->row][heap[2*index+2]->column] < userInput[heap[index]->row][heap[index]->column]){
				if(userInput[heap[2*index+1]->row][heap[2*index+1]->column] < userInput[heap[2*index+2]->row][heap[2*index+2]->column]){
					swap(heap[2*index+1],heap[index]);
				}else{
					swap(heap[2*index+2],heap[index]);
				}
			}else{
				return;
			}
		}else if(2*index + 1 < heap.size()){
			if(userInput[heap[2*index+1]->row][heap[2*index+1]->column] < userInput[heap[index]->row][heap[index]->column]){
				swap(heap[index],heap[2*index+1]);
				index = 2*index + 1;
			}else{
				return;
			}
		}
	}
}

void insertIntoHeap(vector<vector<int> > userInput,vector<rowColumn *> heap,rowColumn *key){
	if(key->column >= userInput[key->row].size()){
		return;
	}
	heap.push_back(key);
	int index = heap.size()-1;
	while(index > 0){
		if(userInput[heap[index]->row][heap[index]->column] < userInput[heap[index/2]->row][heap[index/2]->column]){
			swap(heap[index],heap[index/2]);
		}else{
			break;
		}
		index /= 2;
	}
}

rowColumn *getMinHeap(vector<rowColumn *> userInput){
	if(userInput.size() == 0){
		throw "Heap is empty";
	}
	return userInput[0];
}

void deleteMin(vector<vector<int> > userInput,vector<rowColumn *> heap){
	if(heap.size() == 0){
		throw "Heap is empty";
	}
	swap(heap[0],heap[heap.size()-1]);
	heap.erase(heap.size()-1);
	heapify(userInput,heap,0);
}

vector<int> mergeKSortedArray(vector<vector<int> > userInput){
	vector<int> mergedArray;
	if(userInput.size() == 0){
		return mergedArray;
	}
	vector<int> heap(userInput.size());
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		if(userInput[rowCounter].size() > 0){
			heap.insert(new rowColumn(rowCounter,0));
		}
	}
	for(int counter = heap.size()-1;counter >= 0;counter--){
		heapify(userInput,heap,counter);
	}
	rowColumn *key = null;
	while(heap.size() > 0){
		key = getMinHeap(heap);
		deleteMin(userInput,heap);
		mergedArray.push_back(userInput[key->row][key->column]);
		if(key->column + 1 < userInput[key->row].size()){
			key->column += 1;
			insertIntoHeap(userInput,heap,key);
		}
	}
	return mergedArray;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> mergeKSortedArray(vector<vector<int> > userInput){
	vector<int> mergedArray;
	if(userInput.size() < 0){
		return mergedArray;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			mergedArray.push_back(userInput[outerCrawler][innerCrawler]);
		}
	}
	sort(mergedArray.begin(),mergedArray.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* MERGEKSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
