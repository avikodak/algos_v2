/****************************************************************************************************************************************************
 *  File Name   		: chainmatrixmultipliation.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\chainmatrixmultipliation.h
 *  Created on			: Dec 11, 2014 :: 12:49:52 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
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

#ifndef CHAINMATRIXMULTIPLIATION_H_
#define CHAINMATRIXMULTIPLIATION_H_

//Tested
int matrixChainMultiplicationMemoization(vector<matrixsize *> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(userInput.size());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace[counter].assign(userInput.size(),0);
	}
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		auxSpace[counter][counter+1] = userInput[counter]->rows * userInput[counter]->columns * userInput[counter+1]->columns;
	}
	int minValue;
	for(int rowCounter = userInput.size()-2;rowCounter >= 0;rowCounter--){
		for(unsigned int columnCounter = rowCounter+2;columnCounter < userInput.size();columnCounter++){
			minValue = INT_MAX;
			for(unsigned int counter = rowCounter;counter < columnCounter;counter++){
				minValue = min(minValue,auxSpace[rowCounter][counter] + auxSpace[counter+1][columnCounter] + userInput[rowCounter]->rows * userInput[counter]->columns * userInput[columnCounter]->columns);
			}
			auxSpace[rowCounter][columnCounter] = minValue;
		}
	}
	return auxSpace[0][auxSpace.size()-1];
}

//Tested
int minChainMatrixMultiplication(vector<matrixsize *> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(startIndex == endIndex){
		return 0;
	}
	int minOperations = INT_MAX;
	for(int counter = startIndex;counter < endIndex;counter++){
		minOperations = min(minOperations,minChainMatrixMultiplication(userInput,startIndex,counter) + minChainMatrixMultiplication(userInput,counter+1,endIndex) + userInput[startIndex]->rows*userInput[counter]->columns*userInput[endIndex]->columns);
	}
	return minOperations;
}

#endif /* CHAINMATRIXMULTIPLIATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
