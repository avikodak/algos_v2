/****************************************************************************************************************************************************
 *  File Name   		: floydwarshallalgotrithm.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\floydwarshallalgotrithm.h
 *  Created on			: Dec 26, 2014 :: 9:14:13 AM
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

#ifndef FLOYDWARSHALLALGOTRITHM_H_
#define FLOYDWARSHALLALGOTRITHM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int shortestDistanceFloydWarshall(vector<vector<wEdge *> > adjacencyList,int sourceVertex,int destinationVertex){
	if(adjacencyList.size() == 0){
		return INT_MIN;
	}
	vector<vector<int> > adjacencyMatrix(adjacencyList.size());
	for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
		adjacencyMatrix.reserve(adjacencyList.size(),INT_MIN);
	}
	for(unsigned int outerCounter = 0;outerCounter < adjacencyList.size();outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < adjacencyList[outerCounter].size();innerCounter++){
			adjacencyMatrix[outerCounter][innerCounter] = adjacencyList[outerCounter][adjacencyList[outerCounter][innerCounter]];
		}
	}
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		for(unsigned int rowCounter = 0;rowCounter < adjacencyList.size();rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < adjacencyList[0].size();columnCounter++){
				adjacencyMatrix[rowCounter][columnCounter] = min(adjacencyMatrix[rowCounter][columnCounter],adjacencyMatrix[rowCounter][counter] + adjacencyMatrix[counter][columnCounter]);
			}
		}
	}
	return adjacencyMatrix[sourceVertex][destinationVertex];
}

#endif /* FLOYDWARSHALLALGOTRITHM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
