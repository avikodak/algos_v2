/****************************************************************************************************************************************************
 *  File Name   		: sudoku.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\sudoku.h
 *  Created on			: Jan 7, 2015 :: 8:03:55 PM
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
#define SUDOKU_UNASSIGNED INT_MAX

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SUDOKU_H_
#define SUDOKU_H_

bool findGetUnassignedCell(vector<vector<int> > currentConfiguration,int &row,int &column){
	if(currentConfiguration.size() == 0 || currentConfiguration[0].size() == 0){
		return false;
	}
	for(unsigned int rowCounter = 0;rowCounter < currentConfiguration.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < currentConfiguration[0].size();columnCounter++){
			if(currentConfiguration[rowCounter][columnCounter] == SUDOKU_UNASSIGNED){
				row = rowCounter;
				column = columnCounter;
				return true;
			}
		}
	}
	return false;
}

bool sudokuIsRowSafe(vector<vector<int> > currentConfiguration,int key,int row){
	for(unsigned int columnCounter = 0;columnCounter < currentConfiguration[0].size();columnCounter++){
		if(currentConfiguration[row][columnCounter] == key){
			return false;
		}
	}
	return true;
}

bool sudokuIsColumnSafe(vector<vector<int> > currentConfiguration,int key,int column){
	for(unsigned int rowCounter = 0;rowCounter < currentConfiguration.size();rowCounter++){
		if(currentConfiguration[rowCounter][column] == key){
			return false;
		}
	}
	return true;
}

bool sudokuIsSubBoxSafe(vector<vector<int> > currentConfiguration,int key,int row,int column){
	int boxStartRow = row - row%3;
	int boxStartColumn = column - column%3;
	for(unsigned int rowCounter = 0;rowCounter < 3;rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < 3;columnCounter++){
			if(currentConfiguration[boxStartRow + rowCounter][boxStartColumn + columnCounter] == key){
				return false;
			}
		}
	}
	return true;
}

bool sudokuIsSafe(vector<vector<int> > currentConfiguration,int key,int row,int column){
	return sudokuIsRowSafe(currentConfiguration,key,row) && sudokuIsColumnSafe(currentConfiguration,key,column) && sudokuIsSubBoxSafe(currentConfiguration,key,row,column);
}

bool solveSudokuBacktracking(vector<vector<int> > currentConfiguration){
	int row,column;
	if(!findGetUnassignedCell(currentConfiguration,row,column)){
		printIVector(currentConfiguration);
		return false;
	}
	for(int counter = 1;counter < 10;counter++){
		currentConfiguration[row][column] = counter;
		if(solveSudokuBacktracking(currentConfiguration)){
			return true;
		}
		currentConfiguration[row][column] = SUDOKU_UNASSIGNED;
	}
	return false;
}

#endif /* SUDOKU_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
