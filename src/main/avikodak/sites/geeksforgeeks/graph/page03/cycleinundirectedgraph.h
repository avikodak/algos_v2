/****************************************************************************************************************************************************
 *  File Name   		: cycleinundirectedgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\cycleinundirectedgraph.h
 *  Created on			: Dec 26, 2014 :: 9:31:13 AM
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

#ifndef CYCLEINUNDIRECTEDGRAPH_H_
#define CYCLEINUNDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool detectCycleInUndirectedGraphBFS(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}
	queue<int> auxSpace;
	vector<int> levels(adjacencyList.size(),INT_MAX);
	auxSpace.push(0);
	levels[0] = INT_MAX;
	int currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentNode].size();counter++){
			if(levels[adjacencyList[currentNode][counter]] != INT_MAX && levels[adjacencyList[currentNode][counter]] != levels[currentNode]){
				return true;
			}
			auxSpace.push(adjacencyList[currentNode][counter]);
			levels[adjacencyList[currentNode][counter]] = 1 + levels[currentNode];
		}
	}
	for(unsigned int counter = 0;counter < levels.size();counter++){
		if(levels[counter] == INT_MAX){
			return true;
		}
	}
	return false;
}

bool detectCycleInUndirectedGraphDFS(vector<vector<int> > adjacencyList,int sourceVertex){
	if(adjacencyList.size() == 0){
		return false;
	}
	static vector<int> predecessor(adjacencyList.size(),INT_MIN);
	predecessor[0] = 0;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(predecessor[adjacencyList[sourceVertex][counter]] == INT_MIN){
			if(detectCycleInUndirectedGraphDFS(adjacencyList,adjacencyList[sourceVertex][counter])){
				return true;
			}
		}else{
			if(predecessor[adjacencyList[sourceVertex][counter]] != sourceVertex){
				return true;
			}
		}
	}
	return false;
}

#endif /* CYCLEINUNDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
