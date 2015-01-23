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
