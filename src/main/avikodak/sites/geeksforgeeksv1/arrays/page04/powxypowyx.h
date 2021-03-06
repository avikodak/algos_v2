/****************************************************************************************************************************************************
 *  File Name                   : powxypowyx.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\powxypowyx.h
 *  Created on                  : Dec 22, 2014 :: 10:03:29 PM
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

#ifndef POWXYPOWYX_H_
#define POWXYPOWYX_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int numberOfPairsXYYX(vector<int> xUserInput,vector<int> yUserInput,int x,int y) {
    if(xUserInput.size() == 0 || yUserInput.size() == 0) {
        return 0;
    }
    int pairCounter = 0;
    for(unsigned int xCounter = 0; xCounter < xUserInput.size(); xCounter++) {
        for(unsigned int yCounter = 0; yCounter < yUserInput.size(); yCounter++) {
            if(pow(xUserInput[xCounter],yUserInput[yCounter]) > pow(yUserInput[xCounter],xUserInput[yCounter])) {
                pairCounter += 1;
            }
        }
    }
    return pairCounter;
}

#endif /* POWXYPOWYX_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
