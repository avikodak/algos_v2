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
