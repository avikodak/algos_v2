/****************************************************************************************************************************************************
 *  File Name   		: transitiveclosureofgraph.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\transitiveclosureofgraph.h
 *  Created on			: Dec 26, 2014 :: 11:05:12 AM
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

#ifndef TRANSITIVECLOSUREOFGRAPH_H_
#define TRANSITIVECLOSUREOFGRAPH_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphTransitiveClosureFloydWarshallAlgo(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	vector<vector<bool> > auxSpace(adjacencyList.size());
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].assign(adjacencyList.size(),false);
	}
	for(unsigned int outerCrawler = 0;outerCrawler < adjacencyList.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler < adjacencyList[outerCrawler].size();innerCrawler++){
			auxSpace[outerCrawler][adjacencyList[outerCrawler][innerCrawler]] = true;
		}
	}
	for(unsigned int vertexCounter = 0;vertexCounter < adjacencyList.size();vertexCounter++){
		for(unsigned int outerCounter = 0;outerCounter < adjacencyList.size();outerCounter++){
			for(unsigned int innerCounter = 0;innerCounter < adjacencyList[outerCounter].size();innerCounter++){
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter][innerCounter] || (auxSpace[outerCounter][vertexCounter] && auxSpace[vertexCounter][innerCounter]);
			}
		}
	}
	for(unsigned int outerCounter = 0;outerCounter < adjacencyList.size();outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < adjacencyList[outerCounter].size();innerCounter++){
			if(outerCounter != innerCounter){
				if(!auxSpace[outerCounter][innerCounter]){
					return false;
				}
			}
		}
	}
	return true;
}


/****************************************************************************************************************************************************/
/* 																O(N^N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphTransitiveClosure(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	queue<int> auxSpace;
	vector<int> bfsLevels(adjacencyList.size(),INT_MAX);
	int currentNode;
	for(unsigned int vertexCounter = 0;vertexCounter < adjacencyList.size();vertexCounter++){
		bfsLevels.assign(adjacencyList.size(),INT_MAX);
		auxSpace.push(vertexCounter);
		bfsLevels[vertexCounter] = 0;
		while(!auxSpace.empty()){
			currentNode = auxSpace.front();
			auxSpace.pop();
			for(unsigned int counter = 0;counter < adjacencyList[currentNode].size();counter++){
				if(bfsLevels[adjacencyList[currentNode][counter]] == INT_MAX){
					bfsLevels[adjacencyList[currentNode][counter]] = 1 + bfsLevels[currentNode];
					auxSpace.push(adjacencyList[currentNode][counter]);
				}
			}
		}
		for(unsigned int counter = 0;counter < bfsLevels.size();counter++){
			if(bfsLevels[counter] == INT_MAX){
				return false;
			}
		}
	}
	return true;
}

#endif /* TRANSITIVECLOSUREOFGRAPH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
