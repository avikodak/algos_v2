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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef PARTITIONEDGESBFS_H_
#define PARTITIONEDGESBFS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<vector<edge *> > partitionOfEdgesInGraph(vector<vector<int> > adjacencyList){
	vector<vector<edge *> > edges(2);
	if(adjacencyList.size() == 0){
		return edges;
	}
	queue<int>	auxSpace;
	vector<int> predecessor(adjacencyList.size(),INT_MIN);
	int currentNode;
	for(unsigned int counter = 0;counter < predecessor.size();counter++){
		if(predecessor[counter] == INT_MIN){
			auxSpace.push(counter);
			while(!auxSpace.empty()){
				currentNode = auxSpace.front();
				auxSpace.pop();
				for(unsigned int adjacentNodeCounter = 0;adjacentNodeCounter < adjacencyList[currentNode].size();adjacentNodeCounter){
					if(predecessor[adjacencyList[currentNode][adjacentNodeCounter]] == INT_MIN){
						edges[0].push_back(new edge(currentNode,adjacencyList[currentNode][adjacentNodeCounter]));
						predecessor[adjacencyList[currentNode][adjacentNodeCounter]] = counter;
						auxSpace.push(adjacencyList[currentNode][adjacentNodeCounter]);
					}else{
						if(predecessor[adjacencyList[currentNode][adjacentNodeCounter]] != currentNode){
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