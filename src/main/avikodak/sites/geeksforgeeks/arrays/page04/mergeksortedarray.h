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
void heapify(vector<vector<int> > userInput,vector<int> heap,int index){
	if(index >= heap.size()){
		return;
	}
}

void insertIntoHeap(vector<vector<int> > userInput,vector<int> heap,int rowIndex){

}

int getMinHeap(vector<int> userInput){
	if(userInput.size() == 0){
		throw "Heap is empty";
	}
	return userInput[0];
}

int deleteMin(vector<vector<int> > userInput,vector<int> heap){
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
