/****************************************************************************************************************************************************
 *  File Name                   : checkforpath.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture25\checkforpath.h
 *  Created on                  : Dec 4, 2014 :: 10:36:56 PM
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef CHECKFORPATH_H_
#define CHECKFORPATH_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N+M) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool checkForPath(vector<vector<int> > adjacencyList,int sourceVertex,int destinationVertex) {
    if(sourceVertex >= (int)adjacencyList.size()) {
        return false;
    }
    vector<bool> visitedFlags(adjacencyList.size(),false);
    queue<int> auxSpace;
    auxSpace.push(sourceVertex);
    int currentIndex;
    while(!auxSpace.empty()) {
        currentIndex = auxSpace.front();
        auxSpace.pop();
        for(unsigned int counter = 0; counter < adjacencyList[currentIndex].size(); counter++) {
            if(!visitedFlags[adjacencyList[currentIndex][counter]]) {
                if(adjacencyList[currentIndex][counter] == destinationVertex) {
                    return true;
                }
                visitedFlags[adjacencyList[currentIndex][counter]] = true;
                auxSpace.push(adjacencyList[currentIndex][counter]);
            }
        }
    }
    return false;
}

#endif /* CHECKFORPATH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
