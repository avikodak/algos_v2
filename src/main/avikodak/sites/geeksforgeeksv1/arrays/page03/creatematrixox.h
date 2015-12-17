/****************************************************************************************************************************************************
 *  File Name   		: creatematrixox.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\creatematrixox.h
 *  Created on			: Jan 4, 2015 :: 6:16:55 PM
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

#ifndef CREATEMATRIXOX_H_
#define CREATEMATRIXOX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void spiralOrderOsXs(vector<vector<bool> > &userInput,bool fill,int startRow,int startColumn,int endRow,int endColumn){
	if(userInput.size() == 0 || userInput[0].size() == 0 || startRow > endRow || startColumn > endColumn){
		return;
	}
	for(unsigned int columnCounter = startColumn;columnCounter <= endColumn;columnCounter++){
		userInput[startRow][columnCounter] = fill;
	}
	for(unsigned int rowCounter = startRow + 1;rowCounter <= endRow;rowCounter++){
		userInput[rowCounter][endColumn] = fill;
	}
	if(startRow < endRow){
		for(int columnCounter;columnCounter >= startColumn;columnCounter--){
			userInput[endRow][columnCounter] = fill;
		}
	}
	if(startColumn < endColumn){
		for(int rowCounter = endRow - 1;rowCounter > startRow;rowCounter--){
			userInput[rowCounter][startColumn] = fill;
		}
	}
	spiralOrderOsXs(userInput,!fill,startRow+1,startColumn+1,endRow-1,endColumn-1);
}

vector<vector<bool> > createMatrixOsXs(int rows,int columns){
	vector<vector<bool> > matrix(rows);
	if(rows == 0 || columns == 0){
		return matrix;
	}
	for(unsigned int counter = 0;counter < columns;counter++){
		matrix[counter].assign(columns,false);
	}
	bool fill = true;
	spiralOrderOsXs(matrix,fill,0,0,rows-1,columns-1);
	return matrix;
}

#endif /* CREATEMATRIXOX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
