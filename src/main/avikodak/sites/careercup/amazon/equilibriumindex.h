/****************************************************************************************************************************************************
 *  File Name                   : equilibriumindex.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\careercup\amazon\equilibriumindex.h
 *  Created on                  : Jan 20, 2015 :: 2:17:09 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.careercup.com/question?id=5680651472732160
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

#ifndef EQUILIBRIUMINDEX_H_
#define EQUILIBRIUMINDEX_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getEquilibriumIndex(vector<int> userInput) {
    if(userInput.size() < 2) {
        return userInput.size();
    }
    int sum = 0,lSum = 0,rSum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sum += userInput[counter];
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        rSum = sum  - lSum - userInput[counter];
        if(lSum == rSum) {
            return counter;
        }
        lSum += userInput[counter];
    }
    return INT_MIN;
}

#endif /* EQUILIBRIUMINDEX_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
