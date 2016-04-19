/****************************************************************************************************************************************************
 *  File Name                   : bellmanfordalgo.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\bellmanfordalgo.h
 *  Created on                  : Dec 26, 2014 :: 10:31:58 AM
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

#ifndef BELLMANFORDALGO_H_
#define BELLMANFORDALGO_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int shortestPathBellmanFord(vector<wEdge *> weightedEdges,int noOfVertices,int sourceVertex,int destinationVertex) {
    if(weightedEdges.size() == 0) {
        return INT_MAX;
    }
    vector<int> pathDistances(noOfVertices,INT_MAX);
    pathDistances[sourceVertex] = 0;
    for(unsigned int vertexCounter = 0; vertexCounter < noOfVertices; vertexCounter++) {
        for(unsigned int edgeCounter = 0; edgeCounter < weightedEdges.size(); edgeCounter++) {
            pathDistances[weightedEdges[edgeCounter]->destinationVertex] = min(pathDistances[weightedEdges[edgeCounter]->destinationVertex],weightedEdges[edgeCounter]->weight + pathDistances[weightedEdges[edgeCounter]->sourceVertex]);
        }
    }
    return pathDistances[destinationVertex];
}

#endif /* BELLMANFORDALGO_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
