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
