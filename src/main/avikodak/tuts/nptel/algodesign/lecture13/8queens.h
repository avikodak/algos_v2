/****************************************************************************************************************************************************
 *  File Name                   : 8queens.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture13\8queens.h
 *  Created on                  : Dec 17, 2014 :: 9:07:53 AM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef QUEENS8_H_
#define QUEENS8_H_

bool checkForColumn(vector<vector<bool> > currentConfiguration,int keyRow,int keyColumn) {
    for(unsigned int rowCounter = 0; rowCounter < currentConfiguration.size(); rowCounter++) {
        if(rowCounter == keyRow) {
            continue;
        }
        if(currentConfiguration[rowCounter][keyColumn]) {
            return false;
        }
    }
    return true;
}

bool checkForDiagonal(vector<vector<bool> > currentConfiguration,int keyRow,int keyColumn) {
    int rowCounter = keyRow-1,columnCounter = keyColumn-1;
    while(rowCounter >= 0 && columnCounter >= 0) {
        if(currentConfiguration[rowCounter][columnCounter]) {
            return false;
        }
        rowCounter--;
        columnCounter--;
    }
    rowCounter = keyRow+1;
    columnCounter = keyColumn+1;
    while(rowCounter < currentConfiguration.size() && columnCounter < currentConfiguration.size()) {
        if(currentConfiguration[rowCounter][columnCounter]) {
            return false;
        }
        rowCounter++;
        columnCounter++;
    }
    return true;
}

bool checkConfiguration(vector<vector<bool> > currentConfiguration) {
    if(currentConfiguration.size() == 0) {
        return true;
    }
    for(unsigned int rowCounter = 0; rowCounter < currentConfiguration.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < currentConfiguration.size(); columnCounter++) {
            if(currentConfiguration[rowCounter][columnCounter]) {
                if(!checkForColumn(currentConfiguration,rowCounter,columnCounter) || !checkForDiagonal(currentConfiguration,rowCounter,columnCounter)) {
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

bool queensProblemMain(vector<vector<bool> > currentConfiguration,int currentQueen) {
    if(currentQueen < 0) {
        return;
    }
    unsigned int rowCounter,columnCounter;
    if(currentQueen == 0) {
        if(checkConfiguration(currentConfiguration)) {
            for(rowCounter = 0; rowCounter < currentConfiguration.size(); rowCounter++) {
                for(columnCounter = 0; columnCounter < currentConfiguration.size(); columnCounter++) {
                    printf("%d\t",currentConfiguration[rowCounter][columnCounter]);
                }
                PRINT_NEW_LINE;
            }
            return true;
        }
        return false;
    }
    for(unsigned int columnCounter = 0; columnCounter < currentConfiguration.size(); columnCounter++) {
        currentConfiguration[currentQueen][columnCounter] = true;
        if(queensProblemMain(currentConfiguration,currentQueen-1)) {
            return true;
        }
        currentConfiguration[currentQueen][columnCounter] = false;
    }
    return false;
}

void queensProblems(int queensCount) {
    if(queensCount < 4) {
        return;
    }
    vector<vector<bool> > board(queensCount);
    for(unsigned int rowCounter = 0; rowCounter < queensCount; rowCounter++) {
        board[rowCounter].resize(queensCount);
    }
    for(unsigned int rowCounter = 0; rowCounter < queensCount; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < queensCount; columnCounter++) {
            board[rowCounter][columnCounter] = false;
        }
    }
    queensProblemMain(board,queensCount-1);
}

bool isSafeMove(vector<vector<bool> > currentConfiguration,int keyRow,int keyColumn) {
    int rowCounter = keyRow-1,columnCounter = keyColumn-1;
    while(rowCounter >= 0) {
        if(!currentConfiguration[rowCounter][keyColumn]) {
            return false;
        }
        rowCounter--;
    }
    rowCounter = keyRow - 1;
    while(rowCounter >= 0 && columnCounter >= 0) {
        if(!currentConfiguration[rowCounter][columnCounter]) {
            return false;
        }
        rowCounter -= 1;
        columnCounter -= 1;
    }
    return true;
}

bool solveNQueensProblemMain(vector<vector<bool> > currentConfiguration,int currentQueen) {
    if(currentQueen > currentConfiguration.size()) {
        return false;
    }
    if(currentQueen == currentConfiguration.size()) {
        return true;
    }
    for(unsigned int columnCounter = 0; columnCounter < currentConfiguration[0].size(); columnCounter++) {
        if(isSafeMove(currentConfiguration,currentQueen,columnCounter)) {
            currentConfiguration[currentQueen][columnCounter] = true;
            if(solveNQueensProblemMain(currentConfiguration,currentQueen+1)) {
                return true;
            }
            currentConfiguration[currentQueen][columnCounter] = false;
        }
    }
    return false;
}

void solveNQueensProblem(int queensCount) {
    if(queensCount < 4) {
        return;
    }
    vector<vector<bool> > board(queensCount);
    for(unsigned int rowCounter = 0; rowCounter < board.size(); rowCounter++) {
        board[rowCounter].resize(queensCount);
    }
    for(unsigned int rowCounter = 0; rowCounter < board.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < board.size(); columnCounter++) {
            board[rowCounter][columnCounter] = false;
        }
    }
}

#endif /* 8QUEENS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
