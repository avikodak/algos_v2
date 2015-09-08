/****************************************************************************************************************************************************
 *  File Name   		: biconnectedgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\biconnectedgraph.h
 *  Created on			: Dec 26, 2014 :: 7:29:51 PM
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

#ifndef BICONNECTEDGRAPH_H_
#define BICONNECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphConnectedBFS(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}
	queue<int> auxSpace;
	vector<int> bfsLevels(adjacencyList.size(),INT_MAX);
	auxSpace.push(0);
	int currentVertex;
	while(!auxSpace.empty()){
		currentVertex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
			if(bfsLevels[adjacencyList[currentVertex][counter]] == INT_MAX){
				bfsLevels[adjacencyList[currentVertex][counter]] = 1 + bfsLevels[currentVertex];
				auxSpace.push(adjacencyList[currentVertex][counter]);
			}
		}
	}
	return find(bfsLevels.begin(),bfsLevels.end(),INT_MAX) != bfsLevels.end();
}

int isGraphTwoVertexConnectedMain(vector<vector<int> > adjacencyList,vector<int> &predecessor,bool &flag,int sourceVertex){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size()){
		return INT_MAX;
	}
	static int timeCounter = -1;
	static vector<int> arrivalTimes(adjacencyList.size(),INT_MAX);
	arrivalTimes[sourceVertex] = ++timeCounter;
	int minTime = arrivalTimes[sourceVertex];
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
			isGraphTwoVertexConnectedMain(adjacencyList,predecessor,flag,adjacencyList[sourceVertex][counter]);
		}
	}
	flag = sourceVertex == 0?flag:minTime != arrivalTimes[sourceVertex];
	return minTime;
}

bool isGraphTwoVertexConnected(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() < 2){
		return true;
	}
	vector<int> predecessor;
	bool flag = false;
	isGraphTwoVertexConnectedMain(adjacencyList,predecessor,flag,0);
	return flag && count(predecessor.begin(),predecessor.end(),0) !=  1;
}

bool isGraphBiconnected(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() < 2){
		return true;
	}
	return isGraphConnectedBFS(adjacencyList) && isGraphTwoVertexConnected(adjacencyList);
}

#endif /* BICONNECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
