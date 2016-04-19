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

#ifndef BFS_H_
#define BFS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> getBfsLevels(vector<vector<int> > adjacencyList,unsigned int sourceVertex) {
    if(sourceVertex >= adjacencyList.size()) {
        throw "Invalid vertex";
    }
    vector<int> bfsLevelsForVertex(adjacencyList.size(),INT_MIN);
    vector<int> predecessor(adjacencyList.size(),INT_MIN);
    bfsLevelsForVertex[sourceVertex] = 0;
    queue<int> auxSpace;
    auxSpace.push(sourceVertex);
    int currentVertex;
    while(!auxSpace.empty()) {
        currentVertex = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentVertex].size(); counter++) {
            if(bfsLevelsForVertex[adjacencyList[currentVertex][counter]] == INT_MIN) {
                bfsLevelsForVertex[adjacencyList[currentVertex][counter]] = bfsLevelsForVertex[currentVertex] + 1;
                auxSpace.push(adjacencyList[currentVertex][counter]);
                predecessor[adjacencyList[currentVertex][counter]] = currentVertex;
            }
        }
    }
    return bfsLevelsForVertex;
}

//Tested
vector<int> getBfsLevels(vector<vector<bool> > adjacencyMatrix,unsigned int sourceVertex) {
    if(sourceVertex >= adjacencyMatrix.size()) {
        throw "Invalid vertex";
    }
    vector<int> bfsLevelsForVertex(adjacencyMatrix.size(),INT_MIN);
    vector<int> predecessor(adjacencyMatrix.size(),INT_MIN);
    bfsLevelsForVertex[sourceVertex] = 0;
    queue<int> auxSpace;
    auxSpace.push(sourceVertex);
    int currentVertex;
    while(!auxSpace.empty()) {
        currentVertex = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyMatrix.size(); counter++) {
            if(adjacencyMatrix[currentVertex][counter] && bfsLevelsForVertex[counter] == INT_MIN) {
                bfsLevelsForVertex[counter] = bfsLevelsForVertex[currentVertex] + 1;
                auxSpace.push(counter);
                predecessor[counter] = currentVertex;
            }
        }
    }
    return bfsLevelsForVertex;
}

vector<int> getBfsLevels(vector<edge *> edgeList,int sourceVertex,int noOfVertices) {
    vector<int> bfsLevelsForVertex(noOfVertices,INT_MIN);
    vector<int> predecessor(noOfVertices,INT_MIN);
    bfsLevelsForVertex[sourceVertex] = 0;
    queue<int> auxSpace;
    auxSpace.push(sourceVertex);
    int currentVertex,adjacentVertex;
    while(!auxSpace.empty()) {
        currentVertex = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < edgeList.size(); counter++) {
            if(edgeList[counter]->sourceVertex == currentVertex || (edgeList[counter]->isUndirectedEdge && edgeList[counter]->destinationVertex == currentVertex)) {
                adjacentVertex = currentVertex ^ edgeList[counter]->sourceVertex ^ edgeList[counter]->destinationVertex;
                if(bfsLevelsForVertex[adjacentVertex] == INT_MIN) {
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
