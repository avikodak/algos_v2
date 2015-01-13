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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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
