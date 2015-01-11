/****************************************************************************************************************************************************
 *  File Name   		: graphcoluring.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\graphcoluring.h
 *  Created on			: Jan 7, 2015 :: 8:04:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/
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
#define UN_ASSIGNED_GRAPH_COLOR INT_MAX

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GRAPHCOLURING_H_
#define GRAPHCOLURING_H_

//Tested
bool gcIsSafe(vector<vector<int> > adjacencyMatrix,vector<int> colors,unsigned int vertex,int color){
	if(vertex >= adjacencyMatrix.size()){
		return false;
	}
	for(unsigned int counter = 0;counter < adjacencyMatrix[vertex].size();counter++){
		if(colors[adjacencyMatrix[vertex][counter]] != UN_ASSIGNED_GRAPH_COLOR && colors[adjacencyMatrix[vertex][counter]] == color){
			return false;
		}
	}
	return true;
}

//Tested
bool graphColoring(vector<vector<int> > adjacencyMatrix,vector<int> &colors,unsigned int vertex){
	if(vertex == adjacencyMatrix.size()){
		return true;
	}
	for(unsigned int colorCounter = 0;colorCounter < adjacencyMatrix.size();colorCounter++){
		if(gcIsSafe(adjacencyMatrix,colors,vertex,colorCounter)){
			colors[vertex] = colorCounter;
			if(graphColoring(adjacencyMatrix,colors,vertex+1)){
				return true;
			}
			colors[vertex] = UN_ASSIGNED_GRAPH_COLOR;
		}
	}
	return false;
}

//Tested
int minColorsForGraph(vector<vector<int> > adjacencyMatrix){
	if(adjacencyMatrix.size() == 0 || adjacencyMatrix[0].size() == 0){
		return 0;
	}
	vector<int> colors(adjacencyMatrix.size(),UN_ASSIGNED_GRAPH_COLOR);
	graphColoring(adjacencyMatrix,colors,0);
	printIVector(colors);
	return *max_element(colors.begin(),colors.end()) + 1;
}

#endif /* GRAPHCOLURING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
