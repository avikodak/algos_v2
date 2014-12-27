/****************************************************************************************************************************************************
 *  File Name   		: detectcycleinundirectedgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\detectcycleinundirectedgraph.h
 *  Created on			: Dec 26, 2014 :: 7:39:19 PM
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

#ifndef DETECTCYCLEINUNDIRECTEDGRAPH_H_
#define DETECTCYCLEINUNDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isUndirectedGraphAcyclicBFS(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() < 2){
		return true;
	}
	queue<int> auxSpace;
	int currentNode;
	auxSpace.push(0);
	vector<int> bfsLevels(adjacencyList.size(),INT_MAX);
	bfsLevels[0] = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentNode].size();counter++){
			if(bfsLevels[adjacencyList[currentNode][counter]] == INT_MAX){
				bfsLevels[adjacencyList[currentNode][counter]] = 1 + bfsLevels[currentNode];
				auxSpace.push(adjacencyList[currentNode][counter]);
			}else if(bfsLevels[adjacencyList[currentNode][counter]] < bfsLevels[counter]){
				return false;
			}
		}
	}
	return true;
}

bool isUndirectedGraphAcyclicDFS(vector<vector<int> > adjacencyList,int sourceVertex){
	if(adjacencyList.size() < 2){
		return true;
	}
	if(sourceVertex >= adjacencyList.size()){
		return false;
	}
	static vector<int> predecessor(adjacencyList.size(),INT_MAX);
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(predecessor[adjacencyList[sourceVertex][counter]] == INT_MAX){
			predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
			if(!isUndirectedGraphAcyclicBFS(adjacencyList,adjacencyList[sourceVertex][counter])){
				return false;
			}
		}else if(predecessor[sourceVertex] != adjacencyList[sourceVertex][counter]){
			return false;
		}
	}
	return true;
}

#endif /* DETECTCYCLEINUNDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
