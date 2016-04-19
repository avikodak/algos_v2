/****************************************************************************************************************************************************
 *  File Name   		: knighttourprolem.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\knighttourprolem.h
 *  Created on			: Dec 5, 2014 :: 12:35:12 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define KNP_UN_ASSIGNED INT_MAX

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KNIGHTTOURPROLEM_H_
#define KNIGHTTOURPROLEM_H_

//Tested
bool ktpIsSafe(vector<vector<int> > solution,int xValue,int yValue) {
    if(xValue < 0 || xValue >= (int)solution[0].size() || yValue < 0 || yValue >= (int)solution.size() || solution[xValue][yValue] != KNP_UN_ASSIGNED) {
        return false;
    }
    return true;
}

//Tested
bool solveKnightTourProblemMain(vector<vector<int> > solution,unsigned int moveCounter,int xValue,int yValue) {
    if(moveCounter == solution.size() * solution.size()) {
        printIVector(solution);
        return true;
    }
    int validXValues[] = {2,1,-1,-2,-2,-1,1,2};
    int validYValues[] = {1,2,2,1,-1,-2,-2,-1};
    for(unsigned int counter = 0; counter < 8; counter++) {
        if(ktpIsSafe(solution,xValue + validXValues[counter],yValue+validYValues[counter])) {
            solution[xValue + validXValues[counter]][yValue+validYValues[counter]] = moveCounter;
            if(solveKnightTourProblemMain(solution,moveCounter+1,xValue + validXValues[counter],yValue + validYValues[counter])) {
                return true;
            }
            solution[xValue + validXValues[counter]][yValue+validYValues[counter]] = KNP_UN_ASSIGNED;
        }
    }
    return false;
}

//Tested
void solveKnightTourProblem(int rows,int columns) {
    if(rows < 0 || columns < 0) {
        return;
    }
    vector<vector<int> > board(rows);
    for(int rowCounter = 0; rowCounter < rows; rowCounter++) {
        board[rowCounter].assign(columns,KNP_UN_ASSIGNED);
    }
    board[0][0] = 1;
    solveKnightTourProblemMain(board,1,0,0);
}

#endif /* KNIGHTTOURPROLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
