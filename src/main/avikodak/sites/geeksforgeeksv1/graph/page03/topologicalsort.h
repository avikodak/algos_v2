/****************************************************************************************************************************************************
 *  File Name                   : topologicalsort.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\topologicalsort.h
 *  Created on                  : Dec 15, 2014 :: 6:54:52 PM
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

#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

void topologicalSort(vector<vector<int> > adjacencyList,int sourceVertex,stack<int> &sortedOrder) {
    if(adjacencyList.size() == 0 || sortedOrder >= adjacencyList.size()) {
        return;
    }
    static vector<bool> visitedFlags(adjacencyList.size(),INT_MIN);
    visitedFlags[sourceVertex] = true;
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(!visitedFlags[adjacencyList[sourceVertex][counter]]) {
            topologicalSort(adjacencyList,adjacencyList[sourceVertex][counter],sortedOrder);
        }
    }
    sortedOrder.push_back(sourceVertex);
}

#endif /* TOPOLOGICALSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
