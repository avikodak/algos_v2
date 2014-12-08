/****************************************************************************************************************************************************
 *  File Name   		: graphutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\graphutil.h
 *  Created on			: Dec 5, 2014 :: 9:00:12 AM
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
#include <algorithm/ds/graphds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GRAPHUTIL_H_
#define GRAPHUTIL_H_

struct edge{
	int sourceVertex;
	int destinationVertex;
	bool isUndirectedEdge;

	edge(){

	}

	edge(int sourceVertex,int destinationVertex,bool isUndirectedEdge){
		this->sourceVertex = sourceVertex;
		this->destinationVertex = destinationVertex;
		this->isUndirectedEdge = isUndirectedEdge;
	}
};


#endif /* GRAPHUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
