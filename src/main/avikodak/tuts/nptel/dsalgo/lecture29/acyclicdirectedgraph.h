/****************************************************************************************************************************************************
 *  File Name                   : acyclicdirectedgraph.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture29\acyclicdirectedgraph.h
 *  Created on                  : Dec 5, 2014 :: 1:14:10 PM
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

#ifndef ACYCLICDIRECTEDGRAPH_H_
#define ACYCLICDIRECTEDGRAPH_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool isDirectedGraphAcyclic(vector<vector<int> > adjacencyList,int sourceVertex) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    static vector<dfsTimes *> arrivalDepartureTimes(adjacencyList.size());
    static int timeCounter = -1;
    arrivalDepartureTimes[sourceVertex]->arrivalTimes = ++timeCounter;
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MIN) {
            if(!isDirectedGraphAcyclic(adjacencyList,adjacencyList[sourceVertex][counter])) {
                return false;
            }
        } else {
            if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes < arrivalDepartureTimes[sourceVertex]->arrivalTimes
                    && arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->departureTimes == INT_MIN) {
                return false;
            }

        }
    }
    arrivalDepartureTimes[sourceVertex]->departureTimes = ++timeCounter;
    return true;
}

#endif /* ACYCLICDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
