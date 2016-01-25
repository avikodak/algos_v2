/****************************************************************************************************************************************************
 *  File Name   		: shortestdirectedgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\shortestdirectedgraph.h
 *  Created on			: Dec 15, 2014 :: 6:54:42 PM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SHORTESTDIRECTEDGRAPH_H_
#define SHORTESTDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(M) Algorithm 																    */
/****************************************************************************************************************************************************/
int shortestDistanceDirectedGraph(vector<vector<int> > adjacencyList,int sourceVertex,int destinationVertex){
	if(adjacencyList.size() == 0){
		return INT_MAX;
	}
	vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
	queue<int> auxSpace;
	int currentIndex;
	auxSpace.push(sourceVertex);
	bfsLevels[sourceVertex] = 0;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(bfsLevels[adjacencyList[currentIndex][counter]] == INT_MIN){
				if(adjacencyList[currentIndex][counter] == destinationVertex){
					return 1 + bfsLevels[adjacencyList[currentIndex][counter]];
				}
				auxSpace.push(adjacencyList[currentIndex][counter]);
				bfsLevels[adjacencyList[currentIndex][counter]] = 1 + bfsLevels[currentIndex];
			}
		}
	}
	return INT_MAX;
}

#endif /* SHORTESTDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/