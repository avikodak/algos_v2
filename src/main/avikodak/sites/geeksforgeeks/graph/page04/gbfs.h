/****************************************************************************************************************************************************
 *  File Name   		: gbfs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\gbfs.h
 *  Created on			: Dec 15, 2014 :: 6:08:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
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

#ifndef GBFS_H_
#define GBFS_H_

//Tested
vector<int> gGetBfsLevel(vector<vector<int> > adjacencyList,int sourceVertex){
	vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
	if(adjacencyList.size() == 0){
		return bfsLevels;
	}
	queue<int> auxSpace;
	int currentIndex;
	auxSpace.push(sourceVertex);
	bfsLevels[sourceVertex] = 0;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(bfsLevels[adjacencyList[currentIndex][counter]] == INT_MIN){
				bfsLevels[adjacencyList[currentIndex][counter]] = bfsLevels[currentIndex] + 1;
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}
		}
	}
	return bfsLevels;
}

vector<int> gGetBfsLevelAdjacencyMatrix(vector<vector<bool> > adjacencyMatrix,int sourceVertex){
	vector<int> bfsLevels(adjacencyMatrix.size(),INT_MIN);
	if(adjacencyMatrix.size() == 0){
		return bfsLevels;
	}
	queue<int> auxSpace;
	auxSpace.push(sourceVertex);
	int currentVertex,currentVertexLevel;
	bfsLevels[0] = 0;
	while(!auxSpace.empty()){
		currentVertex = auxSpace.front();
		auxSpace.pop();
		currentVertexLevel = bfsLevels[currentVertex];
		for(unsigned int counter = 0;counter < adjacencyMatrix[currentVertex].size();counter++){
			if(adjacencyMatrix[currentVertex][counter] == INT_MIN){
				bfsLevels[adjacencyMatrix[currentVertex][counter]] = currentVertexLevel+1;
			}
		}
	}
	return bfsLevels;
}

#endif /* GBFS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
