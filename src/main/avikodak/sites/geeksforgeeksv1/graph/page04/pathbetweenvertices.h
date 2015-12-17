/****************************************************************************************************************************************************
 *  File Name   		: pathbetweenvertices.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\pathbetweenvertices.h
 *  Created on			: Dec 15, 2014 :: 6:25:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
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

#ifndef PATHBETWEENVERTICES_H_
#define PATHBETWEENVERTICES_H_

//Tested
bool pathBetweenTwoVertices(vector<vector<int> > adjacencyList,int firstVertex,int secondVertex){
	vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
	if(adjacencyList.size() == 0){
		return false;
	}
	queue<int> auxSpace;
	auxSpace.push(firstVertex);
	bfsLevels[firstVertex] = 0;
	int currentIndex;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(adjacencyList[currentIndex][counter] == secondVertex){
				return true;
			}
			if(bfsLevels[adjacencyList[currentIndex][counter]] == INT_MIN){
				bfsLevels[adjacencyList[currentIndex][counter]] = bfsLevels[currentIndex] + 1;
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}
		}
	}
	return false;
}

bool pathBetweenTwoVerticesDFS(vector<vector<int> > adjacencyList,int currentVertex,int destinationVertex){
	if(currentVertex >= adjacencyList.size()){
		return false;
	}
	static vector<int> flags(adjacencyList.size());
	flags[currentVertex] = true;
	for(unsigned int counter = 0;counter < adjacencyList[currentVertex].size();counter++){
		if(!flags[adjacencyList[currentVertex][counter]]){
			if(adjacencyList[currentVertex][counter] == destinationVertex || pathBetweenTwoVerticesDFS(adjacencyList,adjacencyList[currentVertex][counter],destinationVertex)){
				return true;
			}
		}
	}
	return false;
}

#endif /* PATHBETWEENVERTICES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
