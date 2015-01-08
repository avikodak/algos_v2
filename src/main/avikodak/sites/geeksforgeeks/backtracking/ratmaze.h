/****************************************************************************************************************************************************
 *  File Name   		: ratmaze.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\ratmaze.h
 *  Created on			: Dec 5, 2014 :: 12:35:23 AM
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

#ifndef RATMAZE_H_
#define RATMAZE_H_

bool isSafeMoveRateMaze(vector<vector<bool> > maze,vector<vector<bool> > solution,int xValue,int yValue){
	if(yValue < 0 || yValue >= maze.size() || xValue < 0 || xValue >= maze[0].size() || !maze[xValue][yValue] || !solution[xValue][yValue]){
		return false;
	}
	return true;
}

bool solveRatMazeProblem(vector<vector<bool> > maze,vector<vector<bool> > solution,int xValue,int yValue){
	if(xValue == maze[0].size() || yValue ==  maze.size()){
		printIVector(solution);
		return true;
	}
	int xCoordinates[] = {-1,0,0,1};
	int yCoordinates[] = {0,-1,1,0};
	for(unsigned int counter = 0;counter < 4;counter++){
		if(isSafeMoveRateMaze(maze,solution,xCoordinates[counter],yCoordinates[counter])){
			solution[xCoordinates[counter]][yCoordinates[counter]] = 1;
			if(solveRatMazeProblem(maze,solution,xValue + xCoordinates[counter]),yValue + yCoordinates[counter]){
				return true;
			}
			solution[xCoordinates[counter]][yCoordinates[counter]] = 0;
		}
	}
	return false;
}

#endif /* RATMAZE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
