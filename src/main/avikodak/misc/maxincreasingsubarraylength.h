/****************************************************************************************************************************************************
 *  File Name                   : maxincreasingsubarraylength.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\maxincreasingsubarraylength.h
 *  Created on                  : Nov 28, 2014 :: 12:35:58 PM
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

#ifndef MAXINCREASINGSUBARRAYLENGTH_H_
#define MAXINCREASINGSUBARRAYLENGTH_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int maxIncreasingSubarrayLength(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> increasingSubarrayLength;
    increasingSubarrayLength.push_back(1);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] > userInput[counter-1]) {
            increasingSubarrayLength.push_back(increasingSubarrayLength[counter-1]+1);
        } else {
            increasingSubarrayLength.push_back(1);
        }
    }
    return max_element(increasingSubarrayLength.begin(),increasingSubarrayLength.end());
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool isVectorSortedAscending(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] < userInput[counter-1]) {
            return false;
        }
    }
    return true;
}


#endif /* MAXINCREASINGSUBARRAYLENGTH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
