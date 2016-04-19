/****************************************************************************************************************************************************
 *  File Name                   : gbfs.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\gbfs.h
 *  Created on                  : Dec 15, 2014 :: 6:08:11 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
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

#ifndef GBFS_H_
#define GBFS_H_

//Tested
vector<int> gGetBfsLevel(vector<vector<int> > adjacencyList,int sourceVertex) {
    vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
    if(adjacencyList.size() == 0) {
        return bfsLevels;
    }
    queue<int> auxSpace;
    int currentIndex;
    auxSpace.push(sourceVertex);
    bfsLevels[sourceVertex] = 0;
    while(!auxSpace.empty()) {
        currentIndex = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentIndex].size(); counter++) {
            if(bfsLevels[adjacencyList[currentIndex][counter]] == INT_MIN) {
                bfsLevels[adjacencyList[currentIndex][counter]] = bfsLevels[currentIndex] + 1;
                auxSpace.push(adjacencyList[currentIndex][counter]);
            }
        }
    }
    return bfsLevels;
}

vector<int> gGetBfsLevelAdjacencyMatrix(vector<vector<bool> > adjacencyMatrix,int sourceVertex) {
    vector<int> bfsLevels(adjacencyMatrix.size(),INT_MIN);
    if(adjacencyMatrix.size() == 0) {
        return bfsLevels;
    }
    queue<int> auxSpace;
    auxSpace.push(sourceVertex);
    int currentVertex,currentVertexLevel;
    bfsLevels[0] = 0;
    while(!auxSpace.empty()) {
        currentVertex = auxSpace.front();
        auxSpace.pop();
        currentVertexLevel = bfsLevels[currentVertex];
        for(unsigned int counter = 0; counter < adjacencyMatrix[currentVertex].size(); counter++) {
            if(adjacencyMatrix[currentVertex][counter] == INT_MIN) {
                bfsLevels[adjacencyMatrix[currentVertex][counter]] = currentVertexLevel+1;
            }
        }
    }
    return bfsLevels;
}

#endif /* GBFS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
