/****************************************************************************************************************************************************
 *  File Name                   : cc.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/cc.h
 *  Created on                  : 14-Oct-2015 :: 6:51:41 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/CC
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <stdint.h>
#include <iomanip>
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef CC_H_
#define CC_H_

void getTotalConnectedComponents(unsigned int noOfVertices) {
    vector<vector<unsigned int> > adjacencyList(noOfVertices);
    vector<unsigned int> flags;
    flags.assign(noOfVertices,0);
    unsigned int noOfEdges,sourceVertex,destinationVertex;
    scanf("%u",&noOfEdges);
    while(noOfEdges--) {
        scanf("%u %u",&sourceVertex,&destinationVertex);
        adjacencyList[sourceVertex].push_back(destinationVertex);
    }
    unsigned int connectedComponents = 0;
    for(unsigned int counter = 0; counter < flags.size(); counter++) {
        if(flags[counter] == 0) {
            flags[counter] = ++connectedComponents;
            for(unsigned int adjacentVertexCounter = 0; adjacentVertexCounter < adjacencyList[counter].size(); adjacentVertexCounter++) {
                if(flags[adjacencyList[counter][adjacentVertexCounter]] == 0) {
                    flags[adjacencyList[counter][adjacentVertexCounter]] = flags[counter];
                }
            }
        }
    }
    printf("%u\n",connectedComponents);
}

void printResults() {
    unsigned int testCases,noOfVertices;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&noOfVertices);
        getTotalConnectedComponents(noOfVertices);
    }
}

#endif /* CC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
