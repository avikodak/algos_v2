/****************************************************************************************************************************************************
 *  File Name   		: bridgesingraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\bridgesingraph.h
 *  Created on			: Dec 26, 2014 :: 5:49:35 PM
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

#ifndef BRIDGESINGRAPH_H_
#define BRIDGESINGRAPH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int twoEdgeConnectivityMain(vector<vector<int> > adjacencyList,int sourceVertex,bool &flag){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size()){
		return INT_MAX;
	}
	static int timeCounter = -1;
	static vector<int> arrivalTimes(adjacencyList.size(),INT_MAX);
	static vector<int> predecessor(adjacencyList.size(),INT_MAX);
	arrivalTimes[sourceVertex] = ++timeCounter;
	int minArrivalTime = arrivalTimes[sourceVertex];
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			minArrivalTime = min(minArrivalTime,twoEdgeConnectivityMain(adjacencyList,adjacencyList[sourceVertex][counter],flag));
		}else{
			if(predecessor[sourceVertex] != adjacencyList[sourceVertex][counter]){
				minArrivalTime = min(minArrivalTime,arrivalTimes[adjacencyList[sourceVertex][counter]]);
			}
		}
	}
	flag = sourceVertex == 0?flag:arrivalTimes[sourceVertex] != minArrivalTime;
	return minArrivalTime;
}

bool isGraphTwoEdgeConnectivity(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	bool flag = false;
	twoEdgeConnectivityMain(adjacencyList,0,flag);
	return flag;
}

/****************************************************************************************************************************************************/
/* 																O(N*E) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* BRIDGESINGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
