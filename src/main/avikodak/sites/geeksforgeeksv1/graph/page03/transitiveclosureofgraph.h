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

#ifndef TRANSITIVECLOSUREOFGRAPH_H_
#define TRANSITIVECLOSUREOFGRAPH_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphTransitiveClosureFloydWarshallAlgo(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    vector<vector<bool> > auxSpace(adjacencyList.size());
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        auxSpace[counter].assign(adjacencyList.size(),false);
    }
    for(unsigned int outerCrawler = 0; outerCrawler < adjacencyList.size(); outerCrawler++) {
        for(unsigned int innerCrawler = 0; innerCrawler < adjacencyList[outerCrawler].size(); innerCrawler++) {
            auxSpace[outerCrawler][adjacencyList[outerCrawler][innerCrawler]] = true;
        }
    }
    for(unsigned int vertexCounter = 0; vertexCounter < adjacencyList.size(); vertexCounter++) {
        for(unsigned int outerCounter = 0; outerCounter < adjacencyList.size(); outerCounter++) {
            for(unsigned int innerCounter = 0; innerCounter < adjacencyList[outerCounter].size(); innerCounter++) {
                auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter][innerCounter] || (auxSpace[outerCounter][vertexCounter] && auxSpace[vertexCounter][innerCounter]);
            }
        }
    }
    for(unsigned int outerCounter = 0; outerCounter < adjacencyList.size(); outerCounter++) {
        for(unsigned int innerCounter = 0; innerCounter < adjacencyList[outerCounter].size(); innerCounter++) {
            if(outerCounter != innerCounter) {
                if(!auxSpace[outerCounter][innerCounter]) {
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
bool isGraphTransitiveClosure(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    queue<int> auxSpace;
    vector<int> bfsLevels(adjacencyList.size(),INT_MAX);
    int currentNode;
    for(unsigned int vertexCounter = 0; vertexCounter < adjacencyList.size(); vertexCounter++) {
        bfsLevels.assign(adjacencyList.size(),INT_MAX);
        auxSpace.push(vertexCounter);
        bfsLevels[vertexCounter] = 0;
        while(!auxSpace.empty()) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            for(unsigned int counter = 0; counter < adjacencyList[currentNode].size(); counter++) {
                if(bfsLevels[adjacencyList[currentNode][counter]] == INT_MAX) {
                    bfsLevels[adjacencyList[currentNode][counter]] = 1 + bfsLevels[currentNode];
                    auxSpace.push(adjacencyList[currentNode][counter]);
                }
            }
        }
        for(unsigned int counter = 0; counter < bfsLevels.size(); counter++) {
            if(bfsLevels[counter] == INT_MAX) {
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
