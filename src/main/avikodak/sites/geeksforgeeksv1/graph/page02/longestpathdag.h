/****************************************************************************************************************************************************
 *  File Name   		: longestpathdag.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\longestpathdag.h
 *  Created on			: Jan 22, 2015 :: 7:14:37 PM
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

#ifndef LONGESTPATHDAG_H_
#define LONGESTPATHDAG_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void getTopologicalOrderDFS(vector<vector<int> > adjacencyMatrix,int sourceVertex,stack<int> &auxSpace){
	if(adjacencyMatrix.size() == 0){
		return;
	}
	static vector<int> flags(adjacencyMatrix.size(),false);
	flags[sourceVertex] = true;
	for(unsigned int counter = 0;counter  < adjacencyMatrix[sourceVertex].size();counter++){
		if(adjacencyMatrix[sourceVertex][counter] != INT_MAX && !flags[adjacencyMatrix[sourceVertex][counter]]){
			getTopologicalOrderDFS(adjacencyMatrix,adjacencyMatrix[sourceVertex][counter],auxSpace);
		}
	}
	auxSpace.push(sourceVertex);
}

int getLongestPathDAG(vector<vector<int> > adjacencyMatrix,int source){
	if(adjacencyMatrix.size() == 0){
		return 0;
	}
	vector<int> distance(adjacencyMatrix.size(),INT_MAX);
	stack<int> topologicalOrder;
	getTopologicalOrderDFS(adjacencyMatrix,source,topologicalOrder);
	int currentVertex;
	distance[source] = 0;
	while(!topologicalOrder.empty()){
		currentVertex = topologicalOrder.top();
		topologicalOrder.pop();
		if(distance[currentVertex] != INT_MAX){
			for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
				if(adjacencyMatrix[currentVertex][counter] != INT_MAX){
					distance[counter] = max(distance[counter],distance[currentVertex] + adjacencyMatrix[currentVertex][counter]);
				}
			}
		}
	}
	printIVector(distance);
}

#endif /* LONGESTPATHDAG_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
