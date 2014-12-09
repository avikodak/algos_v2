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
