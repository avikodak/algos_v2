/****************************************************************************************************************************************************
 *  File Name   		: adjacencylist.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\adjacencylist.h
 *  Created on			: Dec 5, 2014 :: 8:50:41 AM
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<vector<int> > getAdjacencyListForUndirectedGraph() {
    int noOfVertices,noOfEdges;
    int sourceVertex,destinationVertex;
    scanf("%d",&noOfVertices);
    vector<vector<int> > adjacencyList(noOfVertices);
    scanf("%d",&noOfEdges);
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyList[sourceVertex].push_back(destinationVertex);
        adjacencyList[destinationVertex].push_back(sourceVertex);
    }
    return adjacencyList;
}

//Tested
vector<vector<int> > getAdjacencyListForDirectedGraph() {
    int noOfVertices,noOfEdges;
    int sourceVertex,destinationVertex;
    scanf("%d",&noOfVertices);
    vector<vector<int> > adjacencyList(noOfVertices);
    scanf("%d",&noOfEdges);
    while(noOfEdges--) {
        scanf("%d %d",&sourceVertex,&destinationVertex);
        adjacencyList[sourceVertex].push_back(destinationVertex);
    }
    return adjacencyList;
}

#endif /* ADJACENCYLIST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
