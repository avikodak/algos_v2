/****************************************************************************************************************************************************
 *  File Name   		: mincostpath.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\mincostpath.h
 *  Created on			: Dec 5, 2014 :: 12:41:46 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
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

#ifndef MINCOSTPATH_H_
#define MINCOSTPATH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int minCostPath(vector<vector<int> > costs){
	if(costs.size() == 0 || costs[0].size() == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(costs.size());
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
