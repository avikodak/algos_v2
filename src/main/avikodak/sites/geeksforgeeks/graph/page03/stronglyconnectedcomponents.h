/****************************************************************************************************************************************************
 *  File Name   		: stronglyconnectedcomponents.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\stronglyconnectedcomponents.h
 *  Created on			: Dec 26, 2014 :: 9:55:45 AM
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

#ifndef STRONGLYCONNECTEDCOMPONENTS_H_
#define STRONGLYCONNECTEDCOMPONENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int isGraphStronglyConnectedMain(vector<vector<int> > adjacencyList,vector<int> &arrivalTimes,int sourceVertex,bool &flag){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size()){
		return INT_MAX;
	}
	static int timeCounter = -1;
	static vector<int> predecessor(adjacencyList.size(),INT_MAX);
	arrivalTimes[sourceVertex] = ++timeCounter;
	int minTime = arrivalTimes[sourceVertex];
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			minTime = min(minTime,isGraphStronglyConnectedMain(adjacencyList,arrivalTimes,adjacencyList[sourceVertex][counter],flag));
		}else{
			if(predecessor[sourceVertex] != adjacencyList[sourceVertex][counter]){
				minTime = min(minTime,arrivalTimes[adjacencyList[sourceVertex][counter]]);
			}
		}
	}
	flag  = sourceVertex == 0?true:minTime < arrivalTimes[sourceVertex];
	return minTime;
}

bool isGraphStronglyConnected(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	vector<int> arrivalTimes(adjacencyList.size(),INT_MAX);
	bool flag = false;
	isGraphStronglyConnectedMain(adjacencyList,arrivalTimes,0,flag);
	return flag;
}

void setDfsLevels(vector<vector<int> > adjacencyList,vector<int> &arrivalTimes,int sourceVertex){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size()){
		return;
	}
	static int timeCounter = -1;
	arrivalTimes[sourceVertex] = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			setDfsLevels(adjacencyList,arrivalTimes,adjacencyList[sourceVertex][counter]);
		}
	}
}

bool checkDfsLevels(vector<int> dfsArrivalTimes){
	if(dfsArrivalTimes.size() == 0){
		return true;
	}
	for(unsigned int counter = 0;counter < dfsArrivalTimes.size();counter++){
		if(dfsArrivalTimes[counter] == INT_MAX){
			return false;
		}
	}
	return true;
}

bool isGraphStronglyConnectedComponentsO2N(vector<vector<int> > adjacencyList,vector<vector<int> > revAdjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}
	vector<int> arrivalTimes(adjacencyList.size());
	arrivalTimes.assign(adjacencyList.size(),INT_MAX);
	setDfsLevels(adjacencyList,arrivalTimes,0);
	if(!checkDfsLevels(arrivalTimes)){
		return false;
	}
	arrivalTimes.assign(adjacencyList.size(),INT_MAX);
	setDfsLevels(revAdjacencyList,arrivalTimes,0);
	return checkDfsLevels(dfsTimes);
}

/****************************************************************************************************************************************************/
/* 																O(N*N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphStronglyConnectedComponentsOMN(vector<vector<int> > adjacencyList,int sourceVertex){
	if(adjacencyList.size() < 1){
		return true;
	}
	vector<int> arrivalTimes;
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		arrivalTimes.assign(adjacencyList.size(),INT_MAX);
		setDfsLevels(adjacencyList,arrivalTimes,counter);
		for(unsigned int innerCounter = 0;innerCounter < arrivalTimes.size();innerCounter++){
			if(arrivalTimes[innerCounter] == INT_MAX){
				return false;
			}
		}
	}
	return true;
}

#endif /* STRONGLYCONNECTEDCOMPONENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
