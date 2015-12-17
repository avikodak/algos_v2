/****************************************************************************************************************************************************
 *  File Name   		: krushkalsalgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\krushkalsalgo.h
 *  Created on			: Dec 26, 2014 :: 9:52:27 AM
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

#ifndef KRUSHKALSALGO_H_
#define KRUSHKALSALGO_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int divideStepQuickSortEdges(vector<wEdge *> &edges,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	int pivotIndex = endIndex;
	int key = edges[pivotIndex]->weight;
	while(startIndex < endIndex){
		while(edges[startIndex]->weight < key){
			startIndex++;
		}
		while(startIndex < endIndex && edges[endIndex]->weight >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(edges[startIndex],edges[endIndex]);
		}
	}
	swap(edges[endIndex],edges[pivotIndex]);
}

void quickSortWeightedEdges(vector<wEdge *> &edges,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = divideStepQuickSortEdges(edges,startIndex,endIndex);
	quickSortWeightedEdges(edges,startIndex,dividingIndex-1);
	quickSortWeightedEdges(edges,dividingIndex+1,endIndex);
}

void mergeStepWeightedEdges(vector<wEdge *> &edges,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	vector<wEdge *> auxSpace;
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(edges[firstCrawler++]);
			}else{
				auxSpace.push_back(edges[secondCrawler++]);
			}
		}else{
			if(edges[firstCrawler]->weight < edges[secondCrawler]->weight){
				auxSpace.push_back(edges[firstCrawler++]);
			}else{
				auxSpace.push_back(edges[secondCrawler++]);
			}
		}
	}
}

void mergeSortWeightedEdges(vector<wEdge *> &edges,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex  = (startIndex + endIndex)/2;
	mergeSortWeightedEdges(edges,startIndex,middleIndex);
	mergeSortWeightedEdges(edges,middleIndex+1,endIndex);
	mergeStepWeightedEdges(edges,startIndex,middleIndex,endIndex);
}

void reorganizeEdgesStraightRadixSort(vector<wEdge *> &weightedEdges,int index){
	if(weightedEdges.size() < 2 ){
		return;
	}
	queue<wEdge *> zeroBucket,oneBucket;
	for(unsigned int counter = 0;counter < weightedEdges.size();counter++){
		if(weightedEdges[counter]->weight & 1 << index){
			oneBucket.push(weightedEdges[counter]);
		}else{
			zeroBucket.push(weightedEdges[counter]);
		}
	}
	int fillCounter = -1;
	while(!zeroBucket.empty()){
		weightedEdges[++fillCounter] = zeroBucket.front();
		zeroBucket.pop();
	}
	while(!oneBucket.empty()){
		weightedEdges[++fillCounter] = oneBucket.front();
		oneBucket.pop();
	}
}

void straightRadixSortWeightedEdges(vector<wEdge *> &weightedEdges){
	if(weightedEdges.size() < 2){
		return;
	}
	wEdge *maxWeightEdge = weightedEdges[0];
	for(unsigned int counter = 1;counter < weightedEdges.size();counter++){
		if(weightedEdges[counter]->weight > maxWeightEdge->weight){
			maxWeightEdge = weightedEdges[counter];
		}
	}
	int totalBits = log2(maxWeightEdge)+1;
	for(unsigned int counter = 0;counter < totalBits;counter++){
		reorganizeEdgesStraightRadixSort(weightedEdges,counter);
	}
}

int divideStepRadixSort(vector<wEdge *> &edges,int startIndex,int endIndex,int index){
	if(edges.size() < 1 || index < 0){
		return;
	}
	while(startIndex <= endIndex){
		while(startIndex <= endIndex && !(edges[startIndex]->weight & 1 << index)){
			startIndex++;
		}
		while(startIndex <= endIndex && (edges[endIndex]->weight & 1 << index)){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(edges[startIndex],edges[endIndex]);
		}
	}
	return endIndex;
}

void radixSortEdges(vector<wEdge *> &edges,int startIndex,int endIndex,int index){
	if(startIndex >= endIndex || index < 0){
		return;
	}
	int dividingIndex = divideStepRadixSort(edges,startIndex,endIndex,index);
	radixSortEdges(edges,startIndex,dividingIndex,index-1);
	radixSortEdges(edges,dividingIndex+1,endIndex,index-1);
}

#endif /* KRUSHKALSALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
