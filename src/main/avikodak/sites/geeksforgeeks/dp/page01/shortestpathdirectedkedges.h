/****************************************************************************************************************************************************
 *  File Name   		: shortestpathdirectedkedges.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\shortestpathdirectedkedges.h
 *  Created on			: Jan 12, 2015 :: 10:46:37 PM
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

#ifndef SHORTESTPATHDIRECTEDKEDGES_H_
#define SHORTESTPATHDIRECTEDKEDGES_H_

int shortestPathDirectedKEdges(vector<vector<int> > adjacencyMatrix,int kValue,int sourceVertex,int destinationVertex){
	if(kValue == 0 && sourceVertex == destinationVertex){
		return adjacencyMatrix[sourceVertex][sourceVertex];
	}
	if(kValue <= 0){
		return INT_MAX;
	}
	if(kValue == 1){
		return adjacencyMatrix[sourceVertex][destinationVertex];
	}
	int minCost = INT_MAX,result;
	for(unsigned int counter = 0;counter < adjacencyMatrix.size(); counter++){
		if(adjacencyMatrix[sourceVertex][counter] != INT_MAX){
			result = shortestPathDirectedKEdges(adjacencyMatrix,kValue-1,counter,destinationVertex);
			if(result != INT_MAX){
				minCost = min(minCost,result + adjacencyMatrix[sourceVertex][counter]);
			}
		}
	}
	return minCost;
}

#endif /* SHORTESTPATHDIRECTEDKEDGES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
