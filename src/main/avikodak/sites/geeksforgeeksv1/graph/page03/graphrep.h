/****************************************************************************************************************************************************
 *  File Name                   : graphrep.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\graphrep.h
 *  Created on                  : Dec 26, 2014 :: 10:32:12 AM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef GRAPHREP_H_
#define GRAPHREP_H_

vector<edge *> getEdgeList(bool isDirectedGraph = false) {
    int noEdges,sourceVertex,destinationVertex;
    scanf("%d",&noEdges);
    vector<edge *> edgeList;
    while(noEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        edgeList.push_back(new edge(sourceVertex,destinationVertex,!isDirectedGraph));
    }
    return edgeList;
}

vector<vector<int> > getAdjacencyList(bool isDirectedGraph = false) {
    int noOfVertices,noOfEdges;
    scanf("%d",&noOfVertices);
    vector<vector<int> > adjacencyList(noOfVertices);
    scanf("%d",&noOfEdges);
    int sourceVertex,destinationVertex;
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyList[sourceVertex].push_back(destinationVertex);
        if(!isDirectedGraph) {
            adjacencyList[destinationVertex].push_back(sourceVertex);
        }
    }
    return adjacencyList;
}

vector<vector<bool> > getAdjacencyMatrix(bool isDirectedGraph = false) {
    int noOfVertices,noOfEdges;
    scanf("%d",&noOfVertices);
    vector<vector<bool> > adjacencyMatrix(noOfVertices);
    for(unsigned int counter = 0; counter < adjacencyMatrix.size(); counter++) {
        adjacencyMatrix[counter].assign(noOfVertices,false);
    }
    scanf("%d",&noOfEdges);
    int sourceVertex,destinationVertex;
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyMatrix[sourceVertex][destinationVertex] = true;
        if(!isDirectedGraph) {
            adjacencyMatrix[destinationVertex][sourceVertex] = true;
        }
    }
    return adjacencyMatrix;
}

#endif /* GRAPHREP_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
