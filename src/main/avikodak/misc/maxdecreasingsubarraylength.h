/****************************************************************************************************************************************************
 *  File Name                   : maxdecreasingsubarraylength.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\maxdecreasingsubarraylength.h
 *  Created on                  : Nov 28, 2014 :: 12:41:52 PM
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

#ifndef MAXDECREASINGSUBARRAYLENGTH_H_
#define MAXDECREASINGSUBARRAYLENGTH_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int maxDecreasingSubArrayLength(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> lengths;
    lengths.push_back(1);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] < userInput[counter-1]) {
            lengths.push_back(lengths[counter-1] + 1);
        } else {
            lengths.push_back(1);
        }
    }
    return lengths;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool isVectorSortedDescending(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex || endIndex >= userInput.size()) {
        return false;
    }
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] > userInput[counter-1]) {
            return false;
        }
    }
    return true;
}

#endif /* MAXDECREASINGSUBARRAYLENGTH_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
