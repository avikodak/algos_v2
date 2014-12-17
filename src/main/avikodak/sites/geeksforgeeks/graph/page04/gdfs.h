/****************************************************************************************************************************************************
 *  File Name   		: gdfs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\gdfs.h
 *  Created on			: Dec 15, 2014 :: 5:48:57 PM
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

#ifndef GDFS_H_
#define GDFS_H_

void dfsMain(vector<vector<int> > adjacencyList,vector<dfsTimes *> &times,int sourceVertex){
	if(sourceVertex >= adjacencyList.size()){
		return;
	}
	static int timeCounter = -1;
	times[sourceVertex]->arrivalTimes = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(times[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MIN){
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
	times.resize(adjacencyList.size());
	dfsMain(adjacencyList,times,sourceVertex);
	return times;
}

#endif /* GDFS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
