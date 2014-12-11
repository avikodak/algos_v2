/****************************************************************************************************************************************************
 *  File Name   		: classifyedges.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture29\classifyedges.h
 *  Created on			: Dec 5, 2014 :: 12:03:06 PM
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

#ifndef CLASSIFYEDGES_H_
#define CLASSIFYEDGES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setEdgeTypesInDFS(vector<vector<int> > adjacencyList,int sourceVertex,vector<vector<edge *> > &edgeTypes){
	if(adjacencyList.size() == 0 || sourceVertex  >= adjacencyList.size()){
		return;
	}
	static vector<dfsTimes *> arrivalDepartureTimes(adjacencyList.size());
	static int timeCounter = -1;
	static vector<int> predecessor(adjacencyList.size());
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MIN){

		}else{

		}
	}
	return;
}

vector<vector<edge *> > classifyEdgesInEdges(vector<vector<int> > adjacencyList,int sourceVertex){
	vector<vector<edge *> > edgeTypes;
	if(adjacencyList.size() == 0){
		return edgeTypes;
	}
	setEdgeTypesInDFS(adjacencyList,sourceVertex,edgeTypes);
	return edgeTypes;
}

#endif /* CLASSIFYEDGES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
