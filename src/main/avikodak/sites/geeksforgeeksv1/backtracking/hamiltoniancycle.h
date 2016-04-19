/****************************************************************************************************************************************************
 *  File Name   		: hamiltoniancycle.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\hamiltoniancycle.h
 *  Created on			: Jan 12, 2015 :: 9:59:32 AM
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

#ifndef HAMILTONIANCYCLE_H_
#define HAMILTONIANCYCLE_H_

bool hcIsSafe(vector<vector<bool> > adjacencyMatrix,vector<int> &cycle,int vertex,int currentIndex) {
    if(currentIndex >= cycle.size() || adjacencyMatrix.size() == 0 || adjacencyMatrix[0].size() == 0) {
        return false;
    }
    if(!adjacencyMatrix[cycle[currentIndex-1]][vertex]) {
        return false;
    }
    for(unsigned int counter = 0; counter < currentIndex; counter++) {
        if(cycle[counter] == vertex) {
            return false;
        }
    }
    return true;
}

bool hamiltonianCycleMain(vector<vector<bool> > adjacencyMatrix,vector<int> &cycle,int currentIndex) {
    if(adjacencyMatrix.size() == 0 || adjacencyMatrix[0].size() == 0 || currentIndex > cycle.size()) {
        return false;
    }
    if(currentIndex == cycle.size()) {
        return adjacencyMatrix[cycle[currentIndex-1]][0];
    }
    for(unsigned int vertexCounter = 1; vertexCounter < cycle.size(); vertexCounter++) {
        if(hcIsSafe(adjacencyMatrix,cycle,vertexCounter,currentIndex)) {
            cycle[currentIndex] = vertexCounter;
            if(hamiltonianCycleMain(adjacencyMatrix,cycle,currentIndex+1)) {
                return true;
            }
        }
    }
    return false;
}

void printHamiltonianCycle(vector<vector<bool> > adjacencyMatrix) {
    if(adjacencyMatrix.size() == 0 || adjacencyMatrix[0].size() == 0) {
        return;
    }
    vector<int> cycle(adjacencyMatrix.size(),INT_MIN);
    cycle[0] = 0;
    if(hamiltonianCycleMain(adjacencyMatrix,cycle,1)) {
        printIVector(cycle);
    }
}

#endif /* HAMILTONIANCYCLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
