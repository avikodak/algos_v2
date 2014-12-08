/****************************************************************************************************************************************************
 *  File Name   		: edgelist.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\edgelist.h
 *  Created on			: Dec 5, 2014 :: 9:45:34 AM
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

#ifndef EDGELIST_H_
#define EDGELIST_H_

vector<edge *> getEdgeListForUndirectedGraph(){
	vector<edge *> edgeDS;
	int noOfEdges;
	int sourceVertex,destinationVertex;
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		edgeDS.push_back(new edge(sourceVertex,destinationVertex,false));
	}
	return edgeDS;
}

vector<edge *> getEdgeListForDirectedGraph(){
	vector<edge *> edgeDS;
	int noOfEdges;
	int sourceVertex,destinationVertex;
	scanf("%d",&noOfEdges);
	while(noOfEdges--){
		scanf("%d %d",&sourceVertex,&destinationVertex);
		edgeDS.push_back(new edge(sourceVertex,destinationVertex,true));
	}
	return edgeDS;
}

#endif /* EDGELIST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
