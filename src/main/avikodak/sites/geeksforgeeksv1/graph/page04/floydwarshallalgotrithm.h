/****************************************************************************************************************************************************
 *  File Name                   : floydwarshallalgotrithm.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\floydwarshallalgotrithm.h
 *  Created on                  : Dec 26, 2014 :: 9:14:13 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
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

#define GRAPH_EDGE_INFINITY 99999

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FLOYDWARSHALLALGOTRITHM_H_
#define FLOYDWARSHALLALGOTRITHM_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int shortestDistanceFloydWarshall(vector<wEdge *> edgeList,unsigned int noOfVertices,int sourceVertex,int destinationVertex) {
    if(edgeList.size() == 0) {
        return INT_MIN;
    }
    vector<vector<int> > adjacencyMatrix(noOfVertices);
    for(unsigned int counter = 0; counter < adjacencyMatrix.size(); counter++) {
        adjacencyMatrix[counter].assign(noOfVertices,GRAPH_EDGE_INFINITY);
    }
    wEdge *temp;
    for(unsigned int outerCounter = 0; outerCounter < edgeList.size(); outerCounter++) {
        temp = edgeList[outerCounter];
        adjacencyMatrix[temp->sourceVertex][temp->destinationVertex] = temp->weight;
    }
    for(unsigned int counter = 0; counter < noOfVertices; counter++) {
        if(adjacencyMatrix[counter][counter] == GRAPH_EDGE_INFINITY)
            adjacencyMatrix[counter][counter] = 0;
    }
    for(unsigned int counter = 0; counter < noOfVertices; counter++) {
        for(unsigned int rowCounter = 0; rowCounter < noOfVertices; rowCounter++) {
            for(unsigned int columnCounter = 0; columnCounter < noOfVertices; columnCounter++) {
                adjacencyMatrix[rowCounter][columnCounter] = min(adjacencyMatrix[rowCounter][columnCounter],adjacencyMatrix[rowCounter][counter] + adjacencyMatrix[counter][columnCounter]);
            }
        }
    }
    return adjacencyMatrix[sourceVertex][destinationVertex];
}

#endif /* FLOYDWARSHALLALGOTRITHM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
