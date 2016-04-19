/****************************************************************************************************************************************************
 *  File Name                   : adjacencymatrix.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\adjacencymatrix.h
 *  Created on                  : Dec 5, 2014 :: 9:26:06 AM
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

#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

//Tested
vector<vector<bool> > getAdjacencyMatrixForUndirectedGraph() {
    int noOfVertices;
    scanf("%d",&noOfVertices);
    vector<vector<bool> > adjacencyMatrix(noOfVertices);
    for(int outerCounter = 0; outerCounter < noOfVertices; outerCounter++) {
        adjacencyMatrix[outerCounter].resize(noOfVertices);
        for(int innerCounter = 0; innerCounter < noOfVertices; innerCounter++) {
            adjacencyMatrix[outerCounter][innerCounter] = false;
        }
    }
    int noOfEdges,sourceVertex,destinationVertex;
    scanf("%d",&noOfEdges);
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyMatrix[sourceVertex][destinationVertex] = true;
        adjacencyMatrix[destinationVertex][sourceVertex] = true;
    }
    return adjacencyMatrix;
}

//Tested
vector<vector<bool> > getAdjacencyMatrixForDirectedGraph() {
    int noOfVertices;
    scanf("%d",&noOfVertices);
    vector<vector<bool> > adjacencyMatrix(noOfVertices);
    for(int outerCounter = 0; outerCounter < noOfVertices; outerCounter++) {
        adjacencyMatrix[outerCounter].resize(noOfVertices);
        for(int innerCounter = 0; innerCounter < noOfVertices; innerCounter++) {
            adjacencyMatrix[outerCounter][innerCounter] = false;
        }
    }
    int noOfEdges,sourceVertex,destinationVertex;
    scanf("%d",&noOfEdges);
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyMatrix[sourceVertex][destinationVertex] = true;
    }
    return adjacencyMatrix;
}

#endif /* ADJACENCYMATRIX_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
