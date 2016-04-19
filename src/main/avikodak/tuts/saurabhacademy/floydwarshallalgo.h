/****************************************************************************************************************************************************
 *  File Name   		: floydwarshallalgo.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\floydwarshallalgo.h
 *  Created on			: Dec 16, 2014 :: 6:07:40 PM
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

#ifndef FLOYDWARSHALLALGO_H_
#define FLOYDWARSHALLALGO_H_

int getShortestPathFloydWarshallAlgo(vector<vector<int> > adjacencyMatrix,int sourceVertex,int destinationVertex) {
    if(adjacencyMatrix.size() == 0 || sourceVertex >= adjacencyMatrix.size() || destinationVertex >= adjacencyMatrix.size()) {
        return INT_MAX;
    }
    for(unsigned int counter = 0; counter < adjacencyMatrix.size(); counter++) {
        for(unsigned int rowCounter = 0; rowCounter < adjacencyMatrix.size(); rowCounter++) {
            for(unsigned int columnCounter = 0; columnCounter < adjacencyMatrix.size(); columnCounter++) {
                if(adjacencyMatrix[rowCounter][columnCounter] > adjacencyMatrix[rowCounter][counter] + adjacencyMatrix[counter][columnCounter]) {
                    adjacencyMatrix[rowCounter][columnCounter] = adjacencyMatrix[rowCounter][counter] + adjacencyMatrix[counter][columnCounter];
                }
            }
        }
    }
    return adjacencyMatrix[sourceVertex][destinationVertex];
}

#endif /* FLOYDWARSHALLALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
