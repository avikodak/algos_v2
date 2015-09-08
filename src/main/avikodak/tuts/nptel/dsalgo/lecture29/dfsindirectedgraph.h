/****************************************************************************************************************************************************
 *  File Name   		: dfsindirectedgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture29\dfsindirectedgraph.h
 *  Created on			: Dec 5, 2014 :: 12:03:18 PM
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

#ifndef DFSINDIRECTEDGRAPH_H_
#define DFSINDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setDfsTimesInDirectedGraphMain(vector<vector<int> > adjacencyList,int sourceVertex,vector<dfsTimes *> &arrivalDepartureTimes){
	if(adjacencyList.size() == 0 || sourceVertex  >= adjacencyList.size()){
		return;
	}
	static int timeCounter = -1;
	arrivalDepartureTimes[sourceVertex]->arrivalTimes = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MIN){
			setDfsTimesInDirectedGraphMain(adjacencyList,adjacencyList[sourceVertex][counter],arrivalDepartureTimes);
		}
	}
	arrivalDepartureTimes[sourceVertex]->departureTimes = ++timeCounter;
}

vector<dfsTimes *> getDfsTimesInDirectedGraph(vector<vector<int> > adjacencyList,int sourceVertex){
	vector<dfsTimes *> arrivalDepartureTimes;
	if(adjacencyList.size() == 0){
		return arrivalDepartureTimes;
	}
	setDfsTimesInDirectedGraphMain(adjacencyList,sourceVertex,arrivalDepartureTimes);
	return arrivalDepartureTimes;
}

#endif /* DFSINDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
