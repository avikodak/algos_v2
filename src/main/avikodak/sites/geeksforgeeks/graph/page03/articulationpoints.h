/****************************************************************************************************************************************************
 *  File Name   		: articulationpoints.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\articulationpoints.h
 *  Created on			: Dec 26, 2014 :: 5:46:22 PM
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

#ifndef ARTICULATIONPOINTS_H_
#define ARTICULATIONPOINTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int setArticulationPointAndDfsTimes(vector<vector<int> > adjacencyList,vector<int> &arrivalTimes,vector<int> &predecessor,vector<int> &articulationPoints,int sourceVertex){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size()){
		return INT_MAX;
	}
	static int timeCounter = -1;
	arrivalTimes[sourceVertex] = ++timeCounter;
	int minArrivalTimes = arrivalTimes[sourceVertex];
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
			minArrivalTimes = min(minArrivalTimes,setArticulationPointAndDfsTimes(adjacencyList,arrivalTimes,predecessor,articulationPoints,adjacencyList[sourceVertex][counter]));
		}
	}
	if(sourceVertex != 0){
		if(minArrivalTimes == arrivalTimes[sourceVertex]){
			articulationPoints.push_back(sourceVertex);
		}
	}
	return minArrivalTimes;
}

int getArticulationPoints(vector<vector<int> > adjacencyList){
	vector<int> articulationPoints;
	if(adjacencyList.size() == 0){
		return articulationPoints;
	}
	vector<int> arrivalTimes(adjacencyList.size(),INT_MAX);
	vector<int> &predecessor(adjacencyList.size(),INT_MAX);
	setArticulationPointAndDfsTimes(adjacencyList,arrivalTimes,parentChildrenMap,articulationPoints,0);

}

/****************************************************************************************************************************************************/
/* 																O(N^N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setDfsLevels(vector<vector<int> > adjacencyList,vector<int> &arrivalTimes,int removedVertex,int sourceVertex){
	if(adjacencyList.size() == 0 || sourceVertex >= adjacencyList.size() || sourceVertex == removedVertex){
		return;
	}
	static int timeCounter = -1;
	arrivalTimes[sourceVertex] = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList[sourceVertex].size();counter++){
		if(adjacencyList[sourceVertex][counter] != removedVertex && arrivalTimes[adjacencyList[sourceVertex][counter]] == INT_MAX){
			setDfsLevels(adjacencyList,arrivalTimes,removedVertex,adjacencyList[sourceVertex][counter]);
		}
	}
}

bool doesGraphContainsArticulationPoints(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}
	vector<int> arrivalTimes;
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		arrivalTimes.assign(adjacencyList.size(),INT_MAX);
		setDfsLevels(adjacencyList,arrivalTimes,counter,0);
		for(unsigned int innerCounter = 0;innerCounter < adjacencyList.size();innerCounter++){
			if(arrivalTimes[innerCounter] == INT_MAX){
				return false;
			}
		}
	}
	return true;
}


#endif /* ARTICULATIONPOINTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
