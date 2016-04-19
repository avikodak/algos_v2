/****************************************************************************************************************************************************
 *  File Name                   : findfirstcirculartour.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\findfirstcirculartour.h
 *  Created on                  : Jan 21, 2015 :: 9:29:44 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
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

#ifndef FINDFIRSTCIRCULARTOUR_H_
#define FINDFIRSTCIRCULARTOUR_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getFirstStartingPoint(vector<petrolPump *> userInput) {
    if(userInput.size() == 0) {
        return -1;
    }
    int startIndex = 0;
    int endIndex = 1;
    int currentDistance = userInput[0]->petrol - userInput[0]->nextDistance;
    while(startIndex != endIndex || currentDistance < 0) {
        while(currentDistance < 0 && endIndex != startIndex) {
            currentDistance = currentDistance - userInput[startIndex]->petrol + userInput[startIndex]->nextDistance;
            startIndex = (startIndex + 1)%(userInput.size());
            if(startIndex == 0) {
                return -1;
            }
        }
        currentDistance += userInput[endIndex]->petrol - userInput[endIndex]->nextDistance;
        endIndex = (endIndex+1)%(userInput.size());
    }
    return startIndex;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* FINDFIRSTCIRCULARTOUR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
