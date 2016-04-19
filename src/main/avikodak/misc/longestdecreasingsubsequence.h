/****************************************************************************************************************************************************
 *  File Name                   : longestdecreasingsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\longestdecreasingsubsequence.h
 *  Created on                  : Nov 29, 2014 :: 10:16:42 AM
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

#ifndef LONGESTDECREASINGSUBSEQUENCE_H_
#define LONGESTDECREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int longestDecreasingSequence(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> lengths;
    lengths.push_back(1);
    int maxLength;
    for(unsigned int  outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        maxLength = 1;
        for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            if(userInput[innerCounter] > userInput[outerCounter]) {
                maxLength = max(maxLength,1 + lengths[innerCounter]);
            }
        }
        lengths.push_back(maxLength);
    }
    return lengths[lengths.size()-1];
}

int longestDecreasingSubSequence(vector<int> userInput,int currentIndex = 0) {
    if(currentIndex >= userInput.size()) {
        return INT_MAX;
    }
    if(userInput.size() == 0) {
        return 0;
    }
    if(currentIndex == 1) {
        return 1;
    }
    int maxLength = 1;
    for(int counter = currentIndex - 1; counter >= 0; counter--) {
        if(userInput[counter] > userInput[currentIndex]) {
            maxLength = max(maxLength,longestDecreasingSubSequence(userInput,counter));
        }
    }
    return maxLength;
}


#endif /* LONGESTDECREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
