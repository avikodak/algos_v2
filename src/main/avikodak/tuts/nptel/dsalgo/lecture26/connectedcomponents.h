/****************************************************************************************************************************************************
 *  File Name                   : connectedcomponents.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture26\connectedcomponents.h
 *  Created on                  : Dec 5, 2014 :: 12:13:03 AM
 *  Author                      : avikodak
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

#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getNumberOfConnectedComponents(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return 0;
    }
    queue<int> auxSpace;
    vector<int> connectedComponents(adjacencyList.size(),INT_MIN);
    int componentCounter = -1,currentNode;
    for(unsigned int counter = 0; counter < connectedComponentCounter.size(); counter++) {
        if(connectedComponents[counter] == INT_MIN) {
            auxSpace.push(counter);
            connectedComponents[counter] = ++componentCounter;
            while(!auxSpace.empty()) {
                currentNode = auxSpace.front();
                auxSpace.pop();
                for(unsigned int adjacentNodeCounter = 0; adjacentNodeCounter < adjacencyList[currentNode].size(); counter++) {
                    if(adjacencyList[counter][adjacentNodeCounter] == INT_MIN) {
                        connectedComponents[adjacencyList[counter][adjacentNodeCounter]] = connectedComponents[counter];
                        auxSpace.push(adjacencyList[counter][adjacentNodeCounter]);
                    }
                }
            }
        }
    }
    return componentCounter;
}

#endif /* CONNECTEDCOMPONENTS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
