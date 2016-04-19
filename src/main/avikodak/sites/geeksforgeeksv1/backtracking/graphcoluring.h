/****************************************************************************************************************************************************
 *  File Name                   : graphcoluring.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\graphcoluring.h
 *  Created on                  : Jan 7, 2015 :: 8:04:09 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/
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
#define UN_ASSIGNED_GRAPH_COLOR INT_MAX

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef GRAPHCOLURING_H_
#define GRAPHCOLURING_H_

//Tested
bool gcIsSafe(vector<vector<int> > adjacencyMatrix,vector<int> colors,unsigned int vertex,int color) {
    if(vertex >= adjacencyMatrix.size()) {
        return false;
    }
    for(unsigned int counter = 0; counter < adjacencyMatrix[vertex].size(); counter++) {
        if(colors[adjacencyMatrix[vertex][counter]] != UN_ASSIGNED_GRAPH_COLOR && colors[adjacencyMatrix[vertex][counter]] == color) {
            return false;
        }
    }
    return true;
}

//Tested
bool graphColoring(vector<vector<int> > adjacencyMatrix,vector<int> &colors,unsigned int vertex) {
    if(vertex == adjacencyMatrix.size()) {
        return true;
    }
    for(unsigned int colorCounter = 0; colorCounter < adjacencyMatrix.size(); colorCounter++) {
        if(gcIsSafe(adjacencyMatrix,colors,vertex,colorCounter)) {
            colors[vertex] = colorCounter;
            if(graphColoring(adjacencyMatrix,colors,vertex+1)) {
                return true;
            }
            colors[vertex] = UN_ASSIGNED_GRAPH_COLOR;
        }
    }
    return false;
}

//Tested
int minColorsForGraph(vector<vector<int> > adjacencyMatrix) {
    if(adjacencyMatrix.size() == 0 || adjacencyMatrix[0].size() == 0) {
        return 0;
    }
    vector<int> colors(adjacencyMatrix.size(),UN_ASSIGNED_GRAPH_COLOR);
    graphColoring(adjacencyMatrix,colors,0);
    printIVector(colors);
    return *max_element(colors.begin(),colors.end()) + 1;
}

#endif /* GRAPHCOLURING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
