/****************************************************************************************************************************************************
 *  File Name                   : isgraphstronglyconnected.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture30\isgraphstronglyconnected.h
 *  Created on                  : Dec 9, 2014 :: 11:22:18 AM
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

#ifndef ISGRAPHSTRONGLYCONNECTED_H_
#define ISGRAPHSTRONGLYCONNECTED_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int isGraphStronglyConnected(vector<vector<int> > adjacencyList,bool &flag,int sourceVertex = 0) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    static vector<dfsTimes *> arrivalDepartureTimes(adjacencyList.size());
    static vector<int> predecessor(adjacencyList.size());
    static int timeCounter = -1;
    arrivalDepartureTimes[sourceVertex]->arrivalTimes = ++timeCounter;
    int minArrivalTime = arrivalDepartureTimes[sourceVertex]->arrivalTimes;
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]] == INT_MIN) {
            predecessor[adjacencyList[sourceVertex][counter]] = sourceVertex;
            minArrivalTime = min(minArrivalTime,isGraphStronglyConnected(adjacencyList,flag,adjacencyList[sourceVertex][counter]));
            if(!flag) {
                return INT_MAX;
            }
        } else {
            if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]] > arrivalDepartureTimes[sourceVertex]) {
                if(adjacencyList[sourceVertex][counter] != predecessor[sourceVertex]) {
                    minArrivalTime = min(minArrivalTime,arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes);
                }
            }
        }
    }
    arrivalDepartureTimes[sourceVertex]->departureTimes = ++timeCounter;
    flag = sourceVertex == 0?true:minArrivalTime < arrivalDepartureTimes[sourceVertex]->arrivalTimes;
    return minArrivalTime;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N*M) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* ISGRAPHSTRONGLYCONNECTED_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
