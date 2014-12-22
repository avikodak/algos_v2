/****************************************************************************************************************************************************
 *  File Name   		: nqueensproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\nqueensproblem.h
 *  Created on			: Dec 19, 2014 :: 12:19:43 PM
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

#ifndef NQUEENSPROBLEM_H_
#define NQUEENSPROBLEM_H_

bool isSafeMove(vector<vector<bool> > userInput,int keyRow,int keyColumn){
	int columnCounter = 0,rowCounter;
	for(rowCounter = 0;rowCounter < keyRow;rowCounter++){
		if(userInput[rowCounter][keyColumn]){
			return false;
		}
	}
	rowCounter = keyRow - 1;
	columnCounter = keyColumn - 1;
	while(rowCounter >= 0 && columnCounter >= 0){
		if(userInput[rowCounter][columnCounter]){
			return false;
		}
		rowCounter -= 1;
		columnCounter -= 1;
	}
	return true;
}

bool solveNQueenProblemMain(vector<vector<bool> > userInput,int queenCounter){
	if(queenCounter < 0){
		return false;
	}
	if(queenCounter == 0){
		printIVector(userInput);
		return true;
	}
	for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
		if(isSafeMove(userInput,queenCounter,columnCounter)){
			userInput[queenCounter][columnCounter] = true;
			if(solveNQueenProblemMain(userInput,queenCounter+1)){
				return true;
			}
			userInput[queenCounter][columnCounter] = false;
		}
	}
	return false;
}

void solveNQueenProblem(int queenCount){
	if(queenCount < 4){
		return;
	}
	vector<vector<bool> > board(queenCount);
	for(unsigned int counter = 0;counter < queenCount;counter++){
		board[counter].resize(queenCount);
	}
	for(unsigned int rowCounter = 0;rowCounter < queenCount;rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < queenCount;columnCounter++){
			board[rowCounter][columnCounter] = false;
		}
	}
	solveNQueenProblemMain(board,queenCount);
}

bool isGoalState(vector<vector<bool> > board){
	if(board.size() == 0 || board[0].size() == 0){
		return true;
	}
	int row,column;
	for(unsigned int rowCounter = 0;rowCounter < board.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < board[0].size();columnCounter++){
			row = rowCounter-1;
			while(row >= 0){
				if(board[row][columnCounter]){
					return false;
				}
			}
			row = rowCounter+1;
			while(row < board.size()){
				if(board[row][columnCounter]){
					return false;
				}
			}
			row = rowCounter-1;
			column = columnCounter - 1;
			while(row >= 0 && column >= 0){
				if(board[row][column]){
					return false;
				}
			}
			row = rowCounter+1;
			column = columnCounter+1;
			while(row < board.size() && column < board[0].size()){
				if(board[row][column]){
					return false;
				}
			}
		}
	}
	return true;
}

void solveNQueenProblemBruteForce(vector<vector<bool> > userInput,int queenCounter){
	if(queenCounter < 0){
		return;
	}
	if(queenCounter == 0){
		if(isGoalState(userInput)){
			printIVector(userInput);
			PRINT_NEW_LINE;
		}
		return;
	}
	for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
		userInput[queenCounter][columnCounter] = true;
		solveNQueenProblemBruteForce(userInput,queenCounter+1);
		userInput[queenCounter][columnCounter] = false;
	}
}

#endif /* NQUEENSPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
