/****************************************************************************************************************************************************
 *  File Name                   : numberislands.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\numberislands.h
 *  Created on                  : Jan 11, 2015 :: 10:05:06 PM
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

#ifndef NUMBERISLANDS_H_
#define NUMBERISLANDS_H_

bool icIsSafe(vector<vector<bool> > userInput,vector<vector<bool> > isVisited,int rows,int columns) {
    if(rows < 0 || columns < 0 || rows >= userInput.size() || columns >= userInput.size() || !userInput[rows][columns] || isVisited[rows][columns]) {
        return false;
    }
    return true;
}

void dfsArrayMain(vector<vector<bool> > userInput,vector<vector<bool> > &isVisited,int rows,int columns) {
    if(rows < 0 || columns < 0 || rows >= userInput.size() || columns >= userInput.size()) {
        return;
    }
    int yValues[] = {-1,-1,-1,0,0,1,1,1};
    int xValues[] = {-1,0,1,1,1,0,-1,-1};
    isVisited[rows][columns] = true;
    for(unsigned int counter = 0; counter < 8; counter++) {
        if(userInput,isVisited,rows + yValues[counter],columns + xValues[counter]) {
            dfsArrayMain(userInput,isVisited,rows + yValues[counter],columns + xValues[counter]);
        }
    }
}

int numberOfIslands(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return 0;
    }
    vector<vector<bool> > visitedArray(userInput.size());
    for(unsigned int rowCounter = 0; rowCounter  < userInput[0].size(); rowCounter++) {
        visitedArray[rowCounter].assign(userInput[0].size(),false);
    }
    int islandCounter = 0;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter] && !visitedArray[rowCounter][columnCounter]) {
                islandCounter++;
                dfsArrayMain(userInput,visitedArray,rowCounter,columnCounter);
            }
        }
    }
    return islandCounter;
}

#endif /* NUMBERISLANDS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
