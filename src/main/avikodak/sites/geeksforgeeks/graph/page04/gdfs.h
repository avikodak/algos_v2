/****************************************************************************************************************************************************
 *  File Name   		: gdfs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\gdfs.h
 *  Created on			: Dec 15, 2014 :: 5:48:57 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
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

#ifndef GDFS_H_
#define GDFS_H_

void dfsMain(vector<vector<int> > adjacencyList,vector<dfsTimes *> &times,int sourceVertex){
	if(sourceVertex >= (int)adjacencyList.size()){
		return;
	}
	static int timeCounter = -1;
	times[sourceVertex]->arrivalTimes = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(times[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MAX){
			dfsMain(adjacencyList,times,adjacencyList[sourceVertex][counter]);
		}
	}
	times[sourceVertex]->departureTimes = ++timeCounter;
}

vector<dfsTimes *> dfs(vector<vector<int> > adjacencyList,int sourceVertex){
	vector<dfsTimes *> times;
	if(adjacencyList.size() == 0){
		return times;
	}
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		times.push_back(new dfsTimes());
	}
	dfsMain(adjacencyList,times,sourceVertex);
	return times;
}

#endif /* GDFS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
