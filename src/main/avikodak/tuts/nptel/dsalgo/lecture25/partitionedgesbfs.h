/****************************************************************************************************************************************************
 *  File Name   		: partitionedgesbfs.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\partitionedgesbfs.h
 *  Created on			: Dec 5, 2014 :: 12:31:02 AM
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef PARTITIONEDGESBFS_H_
#define PARTITIONEDGESBFS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<vector<edge *> > partitionOfEdgesInGraph(vector<vector<int> > adjacencyList) {
    vector<vector<edge *> > edges(2);
    if(adjacencyList.size() == 0) {
        return edges;
    }
    queue<int>	auxSpace;
    vector<int> predecessor(adjacencyList.size(),INT_MIN);
    int currentNode;
    for(unsigned int counter = 0; counter < predecessor.size(); counter++) {
        if(predecessor[counter] == INT_MIN) {
            auxSpace.push(counter);
            while(!auxSpace.empty()) {
                currentNode = auxSpace.front();
                auxSpace.pop();
                for(unsigned int adjacentNodeCounter = 0; adjacentNodeCounter < adjacencyList[currentNode].size(); adjacentNodeCounter) {
                    if(predecessor[adjacencyList[currentNode][adjacentNodeCounter]] == INT_MIN) {
                        edges[0].push_back(new edge(currentNode,adjacencyList[currentNode][adjacentNodeCounter]));
                        predecessor[adjacencyList[currentNode][adjacentNodeCounter]] = counter;
                        auxSpace.push(adjacencyList[currentNode][adjacentNodeCounter]);
                    } else {
                        if(predecessor[adjacencyList[currentNode][adjacentNodeCounter]] != currentNode) {
                            edges[1].push_back(new edge(currentNode,adjacencyList[currentNode][adjacentNodeCounter]));
                        }
                    }
                }
            }
        }
    }
    return edges;
}

#endif /* PARTITIONEDGESBFS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
