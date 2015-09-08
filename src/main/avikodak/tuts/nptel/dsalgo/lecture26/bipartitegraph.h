/****************************************************************************************************************************************************
 *  File Name   		: bipartitegraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture26\bipartitegraph.h
 *  Created on			: Dec 4, 2014 :: 11:50:36 PM
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

#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphBipartite(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}
	queue<int> auxSpace;
	int currentNode;
	vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
	bfsLevels[0] = 0;
	for(unsigned int counter = 0;counter < bfsLevels.size();counter++){
		if(bfsLevels[counter] == INT_MIN){
			auxSpace.push(counter);
			bfsLevels[counter] = 0;
			while(!auxSpace.empty()){
				currentNode = auxSpace.front();
				auxSpace.pop();
				for(unsigned int adjacentNodeCounter = 0;adjacentNodeCounter < adjacencyList[currentNode].size();adjacentNodeCounter++){
					if(adjacencyList[currentNode][adjacentNodeCounter] == INT_MIN){
						bfsLevels[adjacencyList[currentNode][adjacentNodeCounter]] = 1 + bfsLevels[currentNode];
						auxSpace.push(adjacencyList[currentNode][adjacentNodeCounter]);
					}else{
						if(bfsLevels[adjacencyList[currentNode][adjacentNodeCounter]] == bfsLevels[currentNode]){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

#endif /* BIPARTITEGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
