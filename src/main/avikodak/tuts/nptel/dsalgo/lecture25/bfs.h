/****************************************************************************************************************************************************
 *  File Name   		: bfs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\bfs.h
 *  Created on			: Dec 5, 2014 :: 9:54:53 AM
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

#ifndef BFS_H_
#define BFS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getBfsLevels(vector<vector<int> > adjacencyList,unsigned int sourceVertex){
	if(sourceVertex >= adjacencyList.size()){
		throw "Invalid vertex";
	}
	vector<int> bfsLevelsForVertex(adjacencyList.size(),INT_MIN);
	vector<int> predecessor(adjacencyList.size(),INT_MIN);
	bfsLevelsForVertex[sourceVertex] = 0;
	queue<int> auxSpace;
	auxSpace.push(sourceVertex);
	int currentVertex;
	while(!auxSpace.empty()){
		currentVertex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentVertex].size();counter++){
			if(bfsLevelsForVertex[adjacencyList[currentVertex][counter]] == INT_MIN){
				bfsLevelsForVertex[adjacencyList[currentVertex][counter]] = bfsLevelsForVertex[currentVertex] + 1;
				auxSpace.push(adjacencyList[currentVertex][counter]);
				predecessor[adjacencyList[currentVertex][counter]] = currentVertex;
			}
		}
	}
	return bfsLevelsForVertex;
}

//Tested
vector<int> getBfsLevels(vector<vector<bool> > adjacencyMatrix,unsigned int sourceVertex){
	if(sourceVertex >= adjacencyMatrix.size()){
		throw "Invalid vertex";
	}
	vector<int> bfsLevelsForVertex(adjacencyMatrix.size(),INT_MIN);
	vector<int> predecessor(adjacencyMatrix.size(),INT_MIN);
	bfsLevelsForVertex[sourceVertex] = 0;
	queue<int> auxSpace;
	auxSpace.push(sourceVertex);
	int currentVertex;
	while(!auxSpace.empty()){
		currentVertex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
			if(adjacencyMatrix[currentVertex][counter] && bfsLevelsForVertex[counter] == INT_MIN){
				bfsLevelsForVertex[counter] = bfsLevelsForVertex[currentVertex] + 1;
				auxSpace.push(counter);
				predecessor[counter] = currentVertex;
			}
		}
	}
	return bfsLevelsForVertex;
}

vector<int> getBfsLevels(vector<edge *> edgeList,int sourceVertex,int noOfVertices){
	vector<int> bfsLevelsForVertex(noOfVertices,INT_MIN);
	vector<int> predecessor(noOfVertices,INT_MIN);
	bfsLevelsForVertex[sourceVertex] = 0;
	queue<int> auxSpace;
	auxSpace.push(sourceVertex);
	int currentVertex,adjacentVertex;
	while(!auxSpace.empty()){
		currentVertex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < edgeList.size();counter++){
			if(edgeList[counter]->sourceVertex == currentVertex || (edgeList[counter]->isUndirectedEdge && edgeList[counter]->destinationVertex == currentVertex)){
				adjacentVertex = currentVertex ^ edgeList[counter]->sourceVertex ^ edgeList[counter]->destinationVertex;
				if(bfsLevelsForVertex[adjacentVertex] == INT_MIN){
					bfsLevelsForVertex[adjacentVertex] = bfsLevelsForVertex[currentVertex];
					predecessor[adjacentVertex] = currentVertex;
					auxSpace.push(adjacentVertex);
				}
			}
		}
	}
	return bfsLevelsForVertex;
}

#endif /* BFS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
