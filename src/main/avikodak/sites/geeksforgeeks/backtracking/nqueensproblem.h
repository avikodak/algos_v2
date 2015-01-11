/****************************************************************************************************************************************************
 *  File Name   		: nqueensproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\nqueensproblem.h
 *  Created on			: Jan 7, 2015 :: 6:59:03 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
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

//Tested
bool nqIsSafe(vector<vector<bool> > currentConfiguration,int row,int column){
	if(row < 0 || row >= (int)currentConfiguration.size() || column < 0 || column >= (int)currentConfiguration[0].size()){
		return false;
	}
	for(int rowCounter = 0;rowCounter < row;rowCounter++){
		if(currentConfiguration[rowCounter][column]){
			return false;
		}
	}
	int rowCounter = row - 1,columnCounter = column - 1;
	while(rowCounter >= 0 && columnCounter >= 0){
		if(currentConfiguration[rowCounter][columnCounter]){
			return false;
		}
		rowCounter--;
		columnCounter--;
	}
	return true;
}

//Tested
bool nQueenProblemMain(vector<vector<bool> > currentConfiguration,unsigned int queen){
	if(queen == currentConfiguration.size()){
		printIVector(currentConfiguration);
		return true;
	}
	for(unsigned int columnCounter = 0;columnCounter < currentConfiguration[queen].size();columnCounter++){
		if(nqIsSafe(currentConfiguration,queen,columnCounter)){
			currentConfiguration[queen][columnCounter] = true;
			if(nQueenProblemMain(currentConfiguration,queen+1)){
				return true;
			}
			currentConfiguration[queen][columnCounter] = false;
		}
	}
	return false;
}

//Tested
void nQueenProblem(unsigned int queenCount){
	vector<vector<bool> > board(queenCount);
	for(unsigned int counter = 0;counter < queenCount;counter++){
		board[counter].assign(queenCount,false);
	}
	nQueenProblemMain(board,0);
}

#endif /* NQUEENSPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
