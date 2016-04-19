/****************************************************************************************************************************************************
 *  File Name                   : detectcycleinundirectedgraph.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\detectcycleinundirectedgraph.h
 *  Created on                  : Dec 26, 2014 :: 7:39:19 PM
 *  Author                      : avikodak
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

#ifndef DETECTCYCLEINUNDIRECTEDGRAPH_H_
#define DETECTCYCLEINUNDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool isUndirectedGraphAcyclicBFS(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() < 2) {
        return true;
    }
    queue<int> auxSpace;
    int currentNode;
    auxSpace.push(0);
    vector<int> bfsLevels(adjacencyList.size(),INT_MAX);
    bfsLevels[0] = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentNode].size(); counter++) {
            if(bfsLevels[adjacencyList[currentNode][counter]] == INT_MAX) {
                bfsLevels[adjacencyList[currentNode][counter]] = 1 + bfsLevels[currentNode];
                auxSpace.push(adjacencyList[currentNode][counter]);
            } else if(bfsLevels[adjacencyList[currentNode][counter]] < bfsLevels[counter]) {
                return false;
            }
        }
    }
    return true;
}

bool isUndirectedGraphAcyclicDFS(vector<vector<int> > adjacencyList,int sourceVertex) {
    if(adjacencyList.size() < 2) {
        return true;
    }
    if(sourceVertex >= adjacencyList.size()) {
        return false;
    }
    static vector<int> predecessor(adjacencyList.size(),INT_MAX);
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(predecessor[adjacencyList[sourceVertex][counter]] == INT_MAX) {
            predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
            if(!isUndirectedGraphAcyclicBFS(adjacencyList,adjacencyList[sourceVertex][counter])) {
                return false;
            }
        } else if(predecessor[sourceVertex] != adjacencyList[sourceVertex][counter]) {
            return false;
        }
    }
    return true;
}

#endif /* DETECTCYCLEINUNDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
