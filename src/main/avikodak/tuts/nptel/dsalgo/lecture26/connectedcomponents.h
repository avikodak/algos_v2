/****************************************************************************************************************************************************
 *  File Name   		: connectedcomponents.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture26\connectedcomponents.h
 *  Created on			: Dec 5, 2014 :: 12:13:03 AM
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

#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int getNumberOfConnectedComponents(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return 0;
	}
	queue<int> auxSpace;
	vector<int> connectedComponents(adjacencyList.size(),INT_MIN);
	int componentCounter = -1,currentNode;
	for(unsigned int counter = 0;counter < connectedComponentCounter.size();counter++){
		if(connectedComponents[counter] == INT_MIN){
			auxSpace.push(counter);
			connectedComponents[counter] = ++componentCounter;
			while(!auxSpace.empty()){
				currentNode = auxSpace.front();
				auxSpace.pop();
				for(unsigned int adjacentNodeCounter = 0;adjacentNodeCounter < adjacencyList[currentNode].size();counter++){
					if(adjacencyList[counter][adjacentNodeCounter] == INT_MIN){
						connectedComponents[adjacencyList[counter][adjacentNodeCounter]] = connectedComponents[counter];
						auxSpace.push(adjacencyList[counter][adjacentNodeCounter]);
					}
				}
			}
		}
	}
	return componentCounter;
}

#endif /* CONNECTEDCOMPONENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
