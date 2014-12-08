/****************************************************************************************************************************************************
 *  File Name   		: checkforpath.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\checkforpath.h
 *  Created on			: Dec 4, 2014 :: 10:36:56 PM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef CHECKFORPATH_H_
#define CHECKFORPATH_H_

/****************************************************************************************************************************************************/
/* 																O(N+M) Algorithm 																    */
/****************************************************************************************************************************************************/
bool checkForPath(vector<vector<int> > adjacencyList,int sourceVertex,int destinationVertex){
	if(sourceVertex >= adjacencyList.size()){
		return false;
	}
	vector<bool> visitedFlags(adjacencyList.size(),false);
	queue<int> auxSpace;
	auxSpace.push(sourceVertex);
	int currentIndex;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(!visitedFlags[adjacencyList[currentIndex][counter]]){
				if(adjacencyList[currentIndex][counter] == destinationVertex){
					return true;
				}
				visitedFlags[adjacencyList[currentIndex][counter]] = true;
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}
		}
	}
	return false;
}

#endif /* CHECKFORPATH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
