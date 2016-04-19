/****************************************************************************************************************************************************
 *  File Name                   : optimalcostbst.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\optimalcostbst.h
 *  Created on                  : Jan 12, 2015 :: 4:46:32 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
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

#ifndef OPTIMALCOSTBST_H_
#define OPTIMALCOSTBST_H_

//Tested
int optimalCostBSTMain(vector<int> frequencies,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return 0;
    }
    if(startIndex == endIndex) {
        return frequencies[startIndex];
    }
    int sumFrequencies = 0,minCost = INT_MAX;
    for(int counter = startIndex; counter <= endIndex; counter++) {
        sumFrequencies += frequencies[counter];
    }
    for(int counter = startIndex; counter <= endIndex; counter++) {
        minCost = min(minCost,optimalCostBSTMain(frequencies,startIndex,counter-1) + optimalCostBSTMain(frequencies,counter+1,endIndex));
    }
    return sumFrequencies + minCost;
}

#endif /* OPTIMALCOSTBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
