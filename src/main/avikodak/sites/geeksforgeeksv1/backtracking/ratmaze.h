/****************************************************************************************************************************************************
 *  File Name                   : ratmaze.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\ratmaze.h
 *  Created on                  : Dec 5, 2014 :: 12:35:23 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef RATMAZE_H_
#define RATMAZE_H_

//Tested
bool isSafeMoveRateMaze(vector<vector<bool> > maze,vector<vector<bool> > solution,int xValue,int yValue) {
    if(yValue < 0 || yValue >= (int)maze.size() || xValue < 0 || xValue >= (int)maze[0].size() || !maze[xValue][yValue] || solution[xValue][yValue]) {
        return false;
    }
    return true;
}

//Tested
bool solveRatMazeProblemMain(vector<vector<bool> > maze,vector<vector<bool> > solution,int xValue,int yValue) {
    if(xValue == (int)maze[0].size()-1 && yValue ==  (int)maze.size()-1) {
        printIVector(solution);
        return true;
    }
    int xCoordinates[] = {-1,0,0,1};
    int yCoordinates[] = {0,-1,1,0};
    for(unsigned int counter = 0; counter < 4; counter++) {
        if(isSafeMoveRateMaze(maze,solution,xValue + xCoordinates[counter],yValue + yCoordinates[counter])) {
            solution[xValue + xCoordinates[counter]][yValue + yCoordinates[counter]] = true;
            if(solveRatMazeProblemMain(maze,solution,xValue + xCoordinates[counter],yValue + yCoordinates[counter])) {
                return true;
            }
            solution[xValue + xCoordinates[counter]][yValue + yCoordinates[counter]] = false;
        }
    }
    return false;
}

//Tested
void solveRatProblem(vector<vector<bool> > maze) {
    if(maze.size() == 0 || maze[0].size() == 0) {
        return;
    }
    vector<vector<bool> > solution(maze.size());
    for(unsigned int counter = 0; counter < maze.size(); counter++) {
        solution[counter].assign(maze[0].size(),false);
    }
    solution[0][0] = true;
    solveRatMazeProblemMain(maze,solution,0,0);
}

#endif /* RATMAZE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
