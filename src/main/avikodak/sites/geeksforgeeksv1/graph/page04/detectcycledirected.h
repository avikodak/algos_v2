/****************************************************************************************************************************************************
 *  File Name                   : detectcycledirected.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\detectcycledirected.h
 *  Created on                  : Dec 15, 2014 :: 6:22:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
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

#ifndef DETECTCYCLEDIRECTED_H_
#define DETECTCYCLEDIRECTED_H_

//Tested
bool isGraphAcyclic(vector<vector<int> > adjacencyList,unsigned int currentIndex = 0) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    static vector<int> arrivalTimes(adjacencyList.size(),INT_MIN);
    static int timeCounter = -1;
    arrivalTimes[currentIndex] = ++timeCounter;
    for(unsigned int counter = 0; counter < adjacencyList[currentIndex].size(); counter++) {
        if(arrivalTimes[adjacencyList[currentIndex][counter]] == INT_MIN) {
            if(!isGraphAcyclic(adjacencyList,adjacencyList[currentIndex][counter])) {
                return false;
            }
        } else if(arrivalTimes[adjacencyList[currentIndex][counter]] < arrivalTimes[currentIndex]) {
            return false;
        }
    }
    return true;
}

#endif /* DETECTCYCLEDIRECTED_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
