/****************************************************************************************************************************************************
 *  File Name   		: graphrep.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\graphrep.h
 *  Created on			: Dec 26, 2014 :: 10:32:12 AM
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

#ifndef GRAPHREP_H_
#define GRAPHREP_H_

vector<edge *> getEdgeList(bool isDirectedGraph = false){
	int noEdges,sourceVertex,destinationVertex;
	scanf("%d",&noEdges);
	vector<edge *> edgeList;
	while(noEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		edgeList.push_back(new edge(sourceVertex,destinationVertex,!isDirectedGraph));
	}
	return edgeList;
}

vector<vector<int> > getAdjacencyList(bool isDirectedGraph = false){
	int noOfVertices,noOfEdges;
	scanf("%d",&noOfVertices);
	vector<vector<int> > adjacencyList(noOfVertices);
	scanf("%d",&noOfEdges);
	int sourceVertex,destinationVertex;
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyList[sourceVertex].push_back(destinationVertex);
		if(!isDirectedGraph){
			adjacencyList[destinationVertex].push_back(sourceVertex);
		}
	}
	return adjacencyList;
}

vector<vector<bool> > getAdjacencyMatrix(bool isDirectedGraph = false){
	int noOfVertices,noOfEdges;
	scanf("%d",&noOfVertices);
	vector<vector<bool> > adjacencyMatrix(noOfVertices);
	for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
		adjacencyMatrix[counter].assign(noOfVertices,false);
	}
	scanf("%d",&noOfEdges);
	int sourceVertex,destinationVertex;
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyMatrix[sourceVertex][destinationVertex] = true;
		if(!isDirectedGraph){
			adjacencyMatrix[destinationVertex][sourceVertex] = true;
		}
	}
	return adjacencyMatrix;
}

#endif /* GRAPHREP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
