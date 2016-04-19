/****************************************************************************************************************************************************
 *  File Name   		: isgraphconnected.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture28\isgraphconnected.h
 *  Created on			: Dec 5, 2014 :: 11:30:13 AM
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
void setDfsTimes(vector<vector<int> > adjacencyList,int sourceVertex,vector<dfsTimes *> &arrivalDepartureTimes) {
    if(adjacencyList.size() == 0) {
        return;
    }
    static int timeCounter = -1;
    arrivalDepartureTimes[sourceVertex]->arrivalTimes = ++timeCounter;
    for(unsigned int counter = 0; counter < adjacencyList[sourceVertex].size(); counter++) {
        if(arrivalDepartureTimes[adjacencyList[sourceVertex][counter]]->arrivalTimes == INT_MAX) {
            setDfsTimes(adjacencyList,adjacencyList[sourceVertex][counter],arrivalDepartureTimes);
        }
    }
    arrivalDepartureTimes[sourceVertex]->departureTimes = ++timeCounter;
}

bool isGraphConnectedDfs(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    vector<dfsTimes *> arrivalDepartureTimes(adjacencyList.size());
    setDfsTimes(adjacencyList,0,arrivalDepartureTimes);
    for(unsigned int counter = 0; counter < arrivalDepartureTimes.size(); counter++) {
        if(arrivalDepartureTimes[counter]->arrivalTimes == INT_MAX) {
            return false;
        }
    }
    return true;
}

#endif /* ISGRAPHCONNECTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
