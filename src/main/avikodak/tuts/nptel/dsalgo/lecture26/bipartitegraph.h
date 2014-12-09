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
