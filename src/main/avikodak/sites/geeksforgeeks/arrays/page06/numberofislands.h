/****************************************************************************************************************************************************
 *  File Name   		: numberofislands.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\numberofislands.h
 *  Created on			: Jan 3, 2015 :: 10:09:24 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-number-of-islands/
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

#ifndef NUMBEROFISLANDS_H_
#define NUMBEROFISLANDS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isSafe(vector<vector<bool> > userInput,vector<vector<bool> > visitedMatrix,int row,int column){
	if(row < 0 || row >= (int)userInput.size()){
		return false;
	}
	if(column < 0 || column >= (int)userInput[0].size()){
		return false;
	}
	return !visitedMatrix[row][column] && userInput[row][column];
}

//Tested
void noiDFS(vector<vector<bool> > userInput,vector<vector<bool> > &visitedMatrix,int row,int column){
	if(userInput.size() == 0 || userInput[0].size() == 0 || userInput.size() != visitedMatrix.size() || userInput[0].size() != visitedMatrix[0].size()){
		return;
	}
	int reachableRows[] = {-1,-1,-1,0,1,1,1,0};
	int reachableColumns[] = {-1,0,1,1,1,0,-1,-1};
	visitedMatrix[row][column] = true;
	for(unsigned int counter = 0;counter < 8;counter++){
		if(isSafe(userInput,visitedMatrix,row + reachableRows[counter],column + reachableColumns[counter])){
			noiDFS(userInput,visitedMatrix,row+reachableRows[counter],column + reachableColumns[counter]);
		}
	}
}

//Tested
int numberOfIslands(vector<vector<bool> > userInput){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return 0;
	}
	vector<vector<bool> > visitedMatrix(userInput.size());
	for(unsigned int counter = 0;counter < visitedMatrix.size();counter++){
		visitedMatrix[counter].assign(userInput[0].size(),false);
	}
	int islandCount = 0;
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			if(userInput[rowCounter][columnCounter] && !visitedMatrix[rowCounter][columnCounter]){
				islandCount++;
				noiDFS(userInput,visitedMatrix,rowCounter,columnCounter);
			}
		}
	}
	return islandCount;
}

#endif /* NUMBEROFISLANDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
