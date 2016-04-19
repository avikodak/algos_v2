/****************************************************************************************************************************************************
 *  File Name                   : constructionlongestincreasingsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\constructionlongestincreasingsubsequence.h
 *  Created on                  : Jan 3, 2015 :: 11:55:12 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
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

#ifndef CONSTRUCTIONLONGESTINCREASINGSUBSEQUENCE_H_
#define CONSTRUCTIONLONGESTINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
vector<int> constructionOfLongestIncreasingSubsequence(vector<int> userInput) {
    vector<int> incSubSequence;
    if(userInput.size() == 0) {
        return incSubSequence;
    }
    vector<int> activeLists;
    activeLists.push_back(userInput[0]);
    incSubSequence.push_back(userInput[0]);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(activeLists[0] > userInput[counter]) {
            activeLists[0] = userInput[counter];
        } else if(activeLists[activeLists.size()-1] < userInput[counter]) {
            incSubSequence.push_back(userInput[counter]);
            activeLists.push_back(userInput[counter]);
        } else {

        }
    }

}

#endif /* CONSTRUCTIONLONGESTINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
