/****************************************************************************************************************************************************
 *  File Name   		: isgraphconnected.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture26\isgraphconnected.h
 *  Created on			: Dec 5, 2014 :: 10:30:41 AM
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

#ifndef ISGRAPHCONNECTED_H_
#define ISGRAPHCONNECTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isGraphConnected(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    queue<int> auxSpace;
    vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
    auxSpace.push(0);
    bfsLevels[0] = 0;
    int currentNode;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentNode].size(); counter++) {
            if(bfsLevels[adjacencyList[currentNode][counter]] == INT_MIN) {
                bfsLevels[adjacencyList[currentNode][counter]] = 0;
                auxSpace.push(adjacencyList[currentNode][counter]);
            }
        }
    }
    for(unsigned int counter = 0; counter < bfsLevels.size(); counter++) {
        if(bfsLevels[counter] != 0) {
            return false;
        }
    }
    return true;
}

#endif /* ISGRAPHCONNECTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
