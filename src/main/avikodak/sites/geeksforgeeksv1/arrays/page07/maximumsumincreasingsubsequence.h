/****************************************************************************************************************************************************
 *  File Name                   : maximumsumincreasingsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maximumsumincreasingsubsequence.h
 *  Created on                  : Nov 27, 2014 :: 7:56:46 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
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

#ifndef MAXIMUMSUMINCREASINGSUBSEQUENCE_H_
#define MAXIMUMSUMINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maximumSumIncreasingSubsequence(vector<int> userInput) {
    vector<int> maxSumSubsequence;
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    maxSumSubsequence.push_back(userInput[0]);
    int maxSum;
    for(unsigned int outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        maxSum = INT_MIN;
        for(unsigned int innercounter = 0; innercounter < outerCounter; innercounter++) {
            if(userInput[outerCounter] > userInput[innercounter]) {
                maxSum = max(maxSum,maxSumSubsequence[innercounter] + userInput[outerCounter]);
            }
        }
        maxSumSubsequence.push_back(maxSum);
    }
    return *max_element(maxSumSubsequence.begin(),maxSumSubsequence.end());
}

#endif /* MAXIMUMSUMINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
