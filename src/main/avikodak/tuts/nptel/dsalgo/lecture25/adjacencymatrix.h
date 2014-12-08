/****************************************************************************************************************************************************
 *  File Name   		: adjacencymatrix.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\adjacencymatrix.h
 *  Created on			: Dec 5, 2014 :: 9:26:06 AM
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

#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

//Tested
vector<vector<bool> > getAdjacencyMatrixForUndirectedGraph(){
	int noOfVertices;
	scanf("%d",&noOfVertices);
	vector<vector<bool> > adjacencyMatrix(noOfVertices);
	for(int outerCounter = 0;outerCounter < noOfVertices;outerCounter++){
		adjacencyMatrix[outerCounter].resize(noOfVertices);
		for(int innerCounter = 0;innerCounter < noOfVertices;innerCounter++){
			adjacencyMatrix[outerCounter][innerCounter] = false;
		}
	}
	int noOfEdges,sourceVertex,destinationVertex;
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyMatrix[sourceVertex][destinationVertex] = true;
		adjacencyMatrix[destinationVertex][sourceVertex] = true;
	}
	return adjacencyMatrix;
}

//Tested
vector<vector<bool> > getAdjacencyMatrixForDirectedGraph(){
	int noOfVertices;
	scanf("%d",&noOfVertices);
	vector<vector<bool> > adjacencyMatrix(noOfVertices);
	for(int outerCounter = 0;outerCounter < noOfVertices;outerCounter++){
		adjacencyMatrix[outerCounter].resize(noOfVertices);
		for(int innerCounter = 0;innerCounter < noOfVertices;innerCounter++){
			adjacencyMatrix[outerCounter][innerCounter] = false;
		}
	}
	int noOfEdges,sourceVertex,destinationVertex;
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyMatrix[sourceVertex][destinationVertex] = true;
	}
	return adjacencyMatrix;
}

#endif /* ADJACENCYMATRIX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
