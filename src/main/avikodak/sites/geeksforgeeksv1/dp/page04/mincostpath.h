/****************************************************************************************************************************************************
 *  File Name   		: mincostpath.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\mincostpath.h
 *  Created on			: Dec 5, 2014 :: 12:41:46 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
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

#ifndef MINCOSTPATH_H_
#define MINCOSTPATH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int minCostPathMemoization(vector<vector<int> > costs){
	if(costs.size() == 0 || costs[0].size() == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(costs.size());
	for(unsigned int rowCounter = 0;rowCounter < auxSpace.size();rowCounter++){
		auxSpace[rowCounter].assign(costs[0].size(),0);
	}
	auxSpace[auxSpace.size()-1][auxSpace[0].size()-1] = costs[costs.size()-1][costs[0].size()-1];
	int minCost;
	for(int rowCounter = auxSpace.size()-1;rowCounter >= 0;rowCounter--){
		for(int columnCounter = auxSpace[0].size()-1;columnCounter >= 0;columnCounter--){
			minCost = INT_MAX;
			if(rowCounter+1 < (int)auxSpace.size()){
				minCost = min(minCost,auxSpace[rowCounter+1][columnCounter]);
			}
			if(columnCounter+1 < (int)auxSpace[0].size()){
				minCost = min(minCost,auxSpace[rowCounter][columnCounter+1]);
			}
			if(rowCounter+1 < (int)auxSpace.size() && columnCounter+1 <(int)auxSpace.size()){
				minCost = min(minCost,auxSpace[rowCounter+1][columnCounter+1]);
			}
			if(minCost != INT_MAX){
				auxSpace[rowCounter][columnCounter] = costs[rowCounter][columnCounter] + minCost;
			}
		}
	}
	return auxSpace[0][0];
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int minCostPath(vector<vector<int> > costs,unsigned int currentRowIndex,unsigned int currentColumnIndex){
	if(currentRowIndex >= costs.size() || currentColumnIndex >= costs[0].size()){
		return INT_MAX;
	}
	if(currentRowIndex == costs.size()-1 && currentColumnIndex == costs[0].size()-1){
		return costs[currentRowIndex][currentColumnIndex];
	}
	int minCost = INT_MAX;
	minCost = min(min(minCostPath(costs,currentRowIndex+1,currentColumnIndex),minCostPath(costs,currentRowIndex,currentColumnIndex+1)),minCostPath(costs,currentRowIndex+1,currentColumnIndex+1));
	if(minCost == INT_MAX){
		return INT_MAX;
	}
	return costs[currentRowIndex][currentColumnIndex] + minCost;
}


#endif /* MINCOSTPATH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
