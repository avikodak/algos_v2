/****************************************************************************************************************************************************
 *  File Name   		: graphutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\graphutil.h
 *  Created on			: Dec 5, 2014 :: 9:00:12 AM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/ds/graphds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GRAPHUTIL_H_
#define GRAPHUTIL_H_

class graphutil {
private:
public:
	//Tested
	vector<vector<int> > getAdjacencyList(bool forUndirectedGraph = true){
		int noOfVertices,noOfEdges;
		int sourceVertex,destinationVertex;
		scanf("%d",&noOfVertices);
		vector<vector<int> > adjacencyList(noOfVertices);
		scanf("%d",&noOfEdges);
		while(noOfEdges--){
			scanf("%d %d",&sourceVertex,&destinationVertex);
			adjacencyList[sourceVertex].push_back(destinationVertex);
			if(forUndirectedGraph){
				adjacencyList[destinationVertex].push_back(sourceVertex);
			}
		}
		return adjacencyList;
	}

	vector<vector<bool> > getAdjacencyMatrix(bool forUndirectedGraph = true){
		int noOfVertices,noOfEdges;
		int sourceVertex,destinationVertex;
		scanf("%d",&noOfVertices);
		vector<vector<bool> > adjacencyMatrix(noOfVertices);
		for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
			adjacencyMatrix[counter].assign(noOfVertices,false);
		}
		for(unsigned int rowCounter = 0;rowCounter < noOfVertices;rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < noOfVertices;columnCounter++){
				adjacencyMatrix[rowCounter][columnCounter] = false;
			}
		}
		scanf("%d",&noOfEdges);
		while(noOfEdges--){
			scanf("%d %d",&sourceVertex,&destinationVertex);
			adjacencyMatrix[sourceVertex][destinationVertex] = true;
			if(forUndirectedGraph){
				adjacencyMatrix[destinationVertex][sourceVertex] = true;
			}
		}
		return adjacencyMatrix;
	}

	vector<edge *> getEdgeList(bool forUndirectedGraph){
		vector<edge *> edgeDS;
		int noOfEdges;
		int sourceVertex,destinationVertex;
		scanf("%d",&noOfEdges);
		while(noOfEdges--){
			scanf("%d %d",&sourceVertex,&destinationVertex);
			edgeDS.push_back(new edge(sourceVertex,destinationVertex,forUndirectedGraph));
		}
		return edgeDS;
	}

	vector<wEdge *> getWEdgeList(bool forUndirectedGraph){
		vector<wEdge *> edgeDS;
		int noOfEdges;
		int sourceVertex,destinationVertex,weight;
		scanf("%d",&noOfEdges);
		while(noOfEdges--){
			scanf("%d %d %d",&sourceVertex,&destinationVertex,&weight);
			edgeDS.push_back(new wEdge(sourceVertex,destinationVertex,weight,forUndirectedGraph));
		}
		return edgeDS;
	}
};

#endif /* GRAPHUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
