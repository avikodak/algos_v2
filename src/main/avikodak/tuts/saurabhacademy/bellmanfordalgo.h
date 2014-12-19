/****************************************************************************************************************************************************
 *  File Name   		: bellmanfordalgo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\bellmanfordalgo.h
 *  Created on			: Dec 19, 2014 :: 8:12:38 AM
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

#ifndef BELLMANFORDALGO_H_
#define BELLMANFORDALGO_H_

int shortestPathBellmanFord(vector<wEdge *> edgeList,int noOfVertices,int sourceVertex,int destinationVertex){
	if(noOfVertices == 0 || sourceVertex >= noOfVertices || destinationVertex >= noOfVertices){
		return INT_MAX;
	}
	vector<int> distanceLabels(noOfVertices,INT_MAX);
	distanceLabels[sourceVertex] = 0;
	for(unsigned int counter = 0;counter < noOfVertices;counter++){
		for(unsigned int edgeCounter = 0;edgeCounter < edgeList.size();edgeCounter++){
			distanceLabels[edgeList[edgeCounter]->destinationVertex] = min(distanceLabels[edgeList[edgeCounter]->destinationVertex],edgeList[edgeCounter]->weight + distanceLabels[edgeList[edgeCounter]->sourceVertex]);
		}
	}
	return distanceLabels[destinationVertex];
}

#endif /* BELLMANFORDALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
