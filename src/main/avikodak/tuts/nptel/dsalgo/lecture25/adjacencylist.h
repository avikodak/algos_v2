/****************************************************************************************************************************************************
 *  File Name   		: adjacencylist.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\adjacencylist.h
 *  Created on			: Dec 5, 2014 :: 8:50:41 AM
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
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<vector<int> > getAdjacencyListForUndirectedGraph(){
	vector<vector<int> > adjacencyList;
	int noOfVertices,noOfEdges;
	int sourceVertex,destinationVertex;
	scanf("%d",&noOfVertices);
	adjacencyList.reserve(noOfVertices);
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyList[sourceVertex].push_back(destinationVertex);
		adjacencyList[destinationVertex].push_back(sourceVertex);
	}
	return adjacencyList;
}

vector<vector<int> > getAdjacencyListForDirectedGraph(){
	vector<vector<int> > adjacencyList;
	int noOfVertices,noOfEdges;
	int sourceVertex,destinationVertex;
	scanf("%d",&noOfVertices);
	adjacencyList.reserve(noOfVertices);
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		adjacencyList[sourceVertex].push_back(destinationVertex);
	}
	return adjacencyList;
}

#endif /* ADJACENCYLIST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
