/****************************************************************************************************************************************************
 *  File Name                   : eulerianpathundirectedgraph.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page02\eulerianpathundirectedgraph.h
 *  Created on                  : Dec 26, 2014 :: 7:38:49 PM
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

#ifndef EULERIANPATHUNDIRECTEDGRAPH_H_
#define EULERIANPATHUNDIRECTEDGRAPH_H_

bool doesGraphContainEulerianCycle(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    int oddDegreeCounter = 0;
    for(unsigned int outerCounter = 0; outerCounter < adjacencyList.size(); outerCounter++) {
        if(adjacencyList[outerCounter].size() % 2 == 1) {
            oddDegreeCounter++;
        }
    }
    return oddDegreeCounter == 0;
}

bool doesGraphContainEulerianPath(vector<vector<int> > adjacencyList) {
    if(adjacencyList.size() == 0) {
        return true;
    }
    int oddDegreeCounter = 0;
    for(unsigned int outerCounter = 0; outerCounter < adjacencyList.size(); outerCounter++) {
        if(adjacencyList[outerCounter].size() % 2 == 1) {
            oddDegreeCounter++;
        }
    }
    return oddDegreeCounter == 0 || oddDegreeCounter == 2;
}

#endif /* EULERIANPATHUNDIRECTEDGRAPH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
