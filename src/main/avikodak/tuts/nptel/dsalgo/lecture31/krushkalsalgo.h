/****************************************************************************************************************************************************
 *  File Name   		: krushkalsalgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture31\krushkalsalgo.h
 *  Created on			: Dec 9, 2014 :: 12:32:24 PM
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

#ifndef KRUSHKALSALGO_H_
#define KRUSHKALSALGO_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void eMerge(vector<wEdge *> &edgeList,int startIndex,int middleIndex,int endIndex){
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	vector<wEdge *> auxSpace;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(edgeList[firstCrawler++]);
			}else{
				auxSpace.push_back(edgeList[secondCrawler++]);
			}
		}else{
			if(edgeList[firstCrawler]->weight < edgeList[secondCrawler]->weight){
				auxSpace.push_back(edgeList[firstCrawler++]);
			}else{
				auxSpace.push_back(edgeList[secondCrawler++]);
			}
		}
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		edgeList[startIndex + counter] = auxSpace[counter];
	}
}

void eMergeSort(vector<wEdge *> edgeList,int startIndex,int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	eMergeSort(edgeList,startIndex,middleIndex);
	eMergeSort(edgeList,middleIndex+1,endIndex);
	eMerge(edgeList,startIndex,middleIndex,endIndex);
}

int eQuickDivideStep(vector<wEdge *> edgeList,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int key = edgeList[pivotIndex]->weight;
	wEdge *temp;
	while(startIndex < endIndex){
		while(edgeList[startIndex]->weight < key){
			startIndex++;
		}
		while(startIndex < endIndex && edgeList[endIndex]->weight >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			temp = edgeList[startIndex];
			edgeList[startIndex] = edgeList[endIndex];
			edgeList[endIndex] = temp;
		}
	}
	temp = edgeList[pivotIndex];
	edgeList[pivotIndex] = edgeList[endIndex];
	edgeList[endIndex] = temp;
	return endIndex;
}

void eQuickSort(vector<wEdge *> edgeList,int startIndex,int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int dividingIndex = eQuickDivideStep(edgeList,startIndex,endIndex);
	eQuickSort(edgeList,startIndex,dividingIndex-1);
	eQuickSort(edgeList,dividingIndex+1,endIndex);
}

ncUnionfind *findInUnionDS(vector<ncUnionfind *> unionDs,int vertex){
	if(vertex >= unionDs.size()){
		return null;
	}
	ncUnionfind *ptrToVertex = unionDs[vertex];
	while(ptrToVertex->parentVertex != ptrToVertex->vertex){
		ptrToVertex = ptrToVertex->parentVertex;
	}
	return ptrToVertex;
}

void unionOfComponents(ncUnionfind *firstComponent,ncUnionfind *secondComponent){
	if(firstComponent->nodeCounter < secondComponent->nodeCounter){
		firstComponent->parentVertex = secondComponent->vertex;
	}else{
		secondComponent->parentVertex = firstComponent->vertex;
	}
}

vector<wEdge *> krushkalsMinSpanningTree(vector<wEdge *> edgeList,int noOfVertices){
	vector<wEdge *> minEdges;
	eMergeSort(edgeList,0,edgeList.size()-1);
	vector<ncUnionfind *> components(noOfVertices);
	for(unsigned int counter = 0;counter < noOfVertices;components++){
		components[counter]->vertex = counter;
		components[counter]->parentVertex = counter;
	}
	ncUnionfind *ptrToSourceVertex,*ptrToDestinationVertex;
	for(unsigned int counter = 0;counter < edgeList.size();counter++){
		ptrToSourceVertex = findInUnionDS(edgeList[counter]->sourceVertex);
		ptrToDestinationVertex = findInUnionDS(edgeList[counter]->destinationVertex);
		if(ptrToSourceVertex != ptrToDestinationVertex){
			minEdges.push_back(edgeList[counter]);
			unionOfComponents(ptrToSourceVertex,ptrToDestinationVertex);
		}
	}
	return minEdges;
}

#endif /* KRUSHKALSALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
