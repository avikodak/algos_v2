/****************************************************************************************************************************************************
 *  File Name   		: primsalgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture33\primsalgo.h
 *  Created on			: Dec 9, 2014 :: 1:18:37 PM
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

#ifndef PRIMSALGO_H_
#define PRIMSALGO_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Works only in directed edges should be slightly modified for undirected
void insertVerticesEdgesIntoHeap(vector<wEdge *> &heap,vector<vector<wVertex *> > adjacencyList,int sourceVertex){
	wEdge *temp;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		heap.push_back(new wEdge(sourceVertex,adjacencyList[sourceVertex][counter]->vertex,adjacencyList[sourceVertex][counter]->weight,false));
		int vertexIndex = heap.size()-1;
		while(vertexIndex > 0){
			if(heap[vertexIndex]->weight < heap[vertexIndex/2]->weight){
				temp = heap[vertexIndex];
				heap[vertexIndex] = heap[vertexIndex/2];
				heap[vertexIndex/2] = temp;
			}else{
				break;
			}
			vertexIndex /= 2;
		}
	}
}

void heapify(vector<wEdge *> &heap,int index){
	while(2*index + 1 < heap.size()){
		if(2*index + 2 < heap.size()){

		}else{

		}
	}
}

void deleteMinEdgeFromHeap(vector<wEdge *> &heap){
	heap[0] = heap[heap.size()-1];
	heap.erase(heap.size()-1);
	heapify(heap,0);
}

wEdge *getMinEdge(vector<wEdge *> heap){
	if(heap.size() == 0){
		return null;
	}
	return heap[0];
}

vector<wEdge *> minSpanningTreePrimsAlgo(vector<vector<wVertex *> > adjacencyList,int noOfVertices){
	vector<bool> flagsForVertices(noOfVertices);
	flagsForVertices[0] = 1;
	vertex<wEdge *> heap;

}

#endif /* PRIMSALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
