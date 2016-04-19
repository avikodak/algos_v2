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

#ifndef NUMBEROFISLANDS_H_
#define NUMBEROFISLANDS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isSafe(vector<vector<bool> > userInput,vector<vector<bool> > visitedMatrix,int row,int column) {
    if(row < 0 || row >= (int)userInput.size()) {
        return false;
    }
    if(column < 0 || column >= (int)userInput[0].size()) {
        return false;
    }
    return !visitedMatrix[row][column] && userInput[row][column];
}

//Tested
void noiDFS(vector<vector<bool> > userInput,vector<vector<bool> > &visitedMatrix,int row,int column) {
    if(userInput.size() == 0 || userInput[0].size() == 0 || userInput.size() != visitedMatrix.size() || userInput[0].size() != visitedMatrix[0].size()) {
        return;
    }
    int reachableRows[] = {-1,-1,-1,0,1,1,1,0};
    int reachableColumns[] = {-1,0,1,1,1,0,-1,-1};
    visitedMatrix[row][column] = true;
    for(unsigned int counter = 0; counter < 8; counter++) {
        if(isSafe(userInput,visitedMatrix,row + reachableRows[counter],column + reachableColumns[counter])) {
            noiDFS(userInput,visitedMatrix,row+reachableRows[counter],column + reachableColumns[counter]);
        }
    }
}

//Tested
int numberOfIslands(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return 0;
    }
    vector<vector<bool> > visitedMatrix(userInput.size());
    for(unsigned int counter = 0; counter < visitedMatrix.size(); counter++) {
        visitedMatrix[counter].assign(userInput[0].size(),false);
    }
    int islandCount = 0;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter] && !visitedMatrix[rowCounter][columnCounter]) {
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
