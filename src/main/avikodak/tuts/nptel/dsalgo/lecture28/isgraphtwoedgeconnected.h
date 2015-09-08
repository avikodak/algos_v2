/****************************************************************************************************************************************************
 *  File Name   		: isgraphtwoedgeconnected.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture28\isgraphtwoedgeconnected.h
 *  Created on			: Dec 5, 2014 :: 11:32:34 AM
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

#ifndef ISGRAPHTWOEDGECONNECTED_H_
#define ISGRAPHTWOEDGECONNECTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int isGraphTwoEdgeConnectedMain(vector<vector<int> > adjacencyList,int sourceVertex,bool &flag){
	if(adjacencyList.size() == 0){
		return INT_MIN;
	}
	static vector<dfsTimes *> arrivalDepartureTimes(adjacencyList.size());
	static vector<int> predecessor(adjacencyList.size(),INT_MIN);
	static int timeCounter = -1;
	arrivalDepartureTimes[sourceVertex]->arrivalTimes = ++timeCounter;
	int minTime = arrivalDepartureTimes[sourceVertex]->arrivalTimes;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(predecessor[adjacencyList[sourceVertex][counter]] == INT_MIN){
			predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
			minTime = min(minTime,isGraphTwoEdgeConnectedMain(adjacencyList,adjacencyList[sourceVertex][counter]));
		}else{
			if(predecessor[sourceVertex] != adjacencyList[sourceVertex][counter]){
				minTime = min(minTime,arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes);
			}
		}
	}
	arrivalDepartureTimes[sourceVertex]->departureTimes = ++timeCounter;
	flag = sourceVertex == 0?true:arrivalDepartureTimes[sourceVertex]->arrivalTimes > minTime;
	return minTime;
}

#endif /* ISGRAPHTWOEDGECONNECTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
