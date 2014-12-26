/****************************************************************************************************************************************************
 *  File Name   		: bellmanfordalgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\bellmanfordalgo.h
 *  Created on			: Dec 26, 2014 :: 10:31:58 AM
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

#ifndef BELLMANFORDALGO_H_
#define BELLMANFORDALGO_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int shortestPathBellmanFord(vector<wEdge *> weightedEdges,int noOfVertices,int sourceVertex,int destinationVertex){
	if(weightedEdges.size() == 0){
		return INT_MAX;
	}
	vector<int> pathDistances(noOfVertices,INT_MAX);
	pathDistances[sourceVertex] = 0;
	for(unsigned int vertexCounter = 0;vertexCounter < noOfVertices;vertexCounter++){
		for(unsigned int edgeCounter = 0;edgeCounter < weightedEdges.size();edgeCounter++){
			pathDistances[weightedEdges[edgeCounter]->destinationVertex] = min(pathDistances[weightedEdges[edgeCounter]->destinationVertex],weightedEdges[edgeCounter]->weight + pathDistances[weightedEdges[edgeCounter]->sourceVertex]);
		}
	}
	return pathDistances[destinationVertex];
}

#endif /* BELLMANFORDALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
