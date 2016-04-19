/****************************************************************************************************************************************************
 *  File Name                   : cycleinundirectedgraph.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\cycleinundirectedgraph.h
 *  Created on                  : Dec 26, 2014 :: 9:31:13 AM
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

#ifndef CYCLEINUNDIRECTEDGRAPH_H_
#define CYCLEINUNDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool detectCycleInUndirectedGraphBFS(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return false;
    }
    queue<int> auxSpace;
    vector<int> levels(adjacencyList.size(),INT_MAX);
    auxSpace.push(0);
    levels[0] = INT_MAX;
    int currentNode;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentNode].size(); counter++) {
            if(levels[adjacencyList[currentNode][counter]] != INT_MAX && levels[adjacencyList[currentNode][counter]] != levels[currentNode]) {
                return true;
            }
            auxSpace.push(adjacencyList[currentNode][counter]);
            levels[adjacencyList[currentNode][counter]] = 1 + levels[currentNode];
        }
    }
    for(unsigned int counter = 0; counter < levels.size(); counter++) {
        if(levels[counter] == INT_MAX) {
            return true;
        }
    }
    return false;
}

bool detectCycleInUndirectedGraphDFS(vector<vector<int> > adjacencyList,int sourceVertex) {
    if(adjacencyList.size() == 0) {
        return false;
    }
    static vector<int> predecessor(adjacencyList.size(),INT_MIN);
    predecessor[0] = 0;
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(predecessor[adjacencyList[sourceVertex][counter]] == INT_MIN) {
            if(detectCycleInUndirectedGraphDFS(adjacencyList,adjacencyList[sourceVertex][counter])) {
                return true;
            }
        } else {
            if(predecessor[adjacencyList[sourceVertex][counter]] != sourceVertex) {
                return true;
            }
        }
    }
    return false;
}

#endif /* CYCLEINUNDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
