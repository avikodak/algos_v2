/****************************************************************************************************************************************************
 *  File Name                   : longestincreasingsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\longestincreasingsubsequence.h
 *  Created on                  : Dec 25, 2014 :: 6:22:15 PM
 *  Author                      : AVINASH
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

#ifndef LONGESTINCREASINGSUBSEQUENCE_H_
#define LONGESTINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int lisLongestIncreasingSubsequenceyONLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    if(userInput.size() == 1) {
        return 1;
    }
    vector<int> activeLists;
    activeLists.push_back(userInput[0]);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(activeLists[0] > userInput[counter]) {
            activeLists[0] = userInput[counter];
        } else if(activeLists[activeLists.size()-1] < userInput[counter]) {
            activeLists.push_back(userInput[counter]);
        } else {
            unsigned int listCounter = 1;
            while(listCounter < userInput.size() && userInput[counter] > activeLists[listCounter]) {
                listCounter++;
            }
            activeLists[listCounter] = userInput[counter];
        }
    }
    return activeLists.size();
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int lisLongestIncreasingSubsequenceON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    if(userInput.size() == 1) {
        return 1;
    }
    vector<int> lengths(userInput.size());
    lengths[0] = 1;
    int maxLength;
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        maxLength = 1;
        for(unsigned int innerCrawler = 0; innerCrawler < outerCrawler; innerCrawler++) {
            if(userInput[outerCrawler] > userInput[innerCrawler]) {
                maxLength = max(maxLength,1 + lengths[innerCrawler]);
            }
        }
        lengths.push_back(maxLength);
    }
    return lengths[lengths.size()-1];
}

/****************************************************************************************************************************************************/
/*                                                                 O(2^N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int lisLongestIncreasingSubsequenceO2N(vector<int> userInput,unsigned int currentIndex) {
    if(currentIndex == 0) {
        return 1;
    }
    int maxLength = INT_MIN;
    for(int counter = currentIndex - 1; counter >= 0; counter++) {
        if(userInput[currentIndex] > userInput[counter]) {
            maxLength = max(maxLength,1 + lisLongestIncreasingSubsequenceO2N(userInput,counter));
        } else {
            maxLength = max(maxLength,lisLongestIncreasingSubsequenceO2N(userInput,counter));
        }
    }
    return maxLength;
}

int listLongestIncreasingSubsequenceO2NIterative(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    if(userInput.size() == 1) {
        return 1;
    }
    int limit = pow(2,userInput.size());
    vector<int> currentSet;
    int longestLength = INT_MIN;
    for(int setCounter = 0; setCounter < limit; setCounter++) {
        currentSet.clear();
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[setCounter] & 1 << counter) {
                currentSet.push_back(userInput[counter]);
            }
        }
        if(isVectorSorted(currentSet)) {
            longestLength = max(longestLength,1 + (int)currentSet.size());
        }
    }
    return longestLength;
}

#endif /* LONGESTINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
