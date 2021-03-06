/****************************************************************************************************************************************************
 *  File Name                   : longestincsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\longestincsubsequence.h
 *  Created on                  : Nov 28, 2014 :: 1:58:53 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
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

#ifndef LONGESTINCSUBSEQUENCE_H_
#define LONGESTINCSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int longestIncreasingSubSequenceONLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> activeLists;
    activeLists.push_back(userInput[0]);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(activeLists[0] > userInput[counter]) {
            activeLists[0] = userInput[counter];
        } else if(activeLists[activeLists.size()-1] < userInput[counter]) {
            activeLists.push_back(userInput[counter]);
        } else {
            unsigned int innerCounter = 1;
            while(innerCounter < activeLists.size()-1 && userInput[counter] > activeLists[innerCounter]) {
                innerCounter++;
            }
            activeLists[innerCounter] = userInput[counter];
        }
        printIVector(activeLists);
        PRINT_NEW_LINE;
    }
    return activeLists.size();
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int longestIncreasingSubSequenceDP(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> maxLengths;
    int finalMaxVal = 1,currentMax;
    maxLengths.push_back(1);
    for(unsigned int outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        currentMax = 1;
        for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            if(userInput[outerCounter] > userInput[innerCounter]) {
                currentMax = max(currentMax,1 + maxLengths[innerCounter]);
            }
        }
        maxLengths.push_back(currentMax);
        finalMaxVal = max(finalMaxVal,currentMax);
    }
    return finalMaxVal;
}

//Tested
int longestIncreasingSubSequence(vector<int> userInput,int currentIndex) {
    if(userInput.size() == 0) {
        return 0;
    }
    if(currentIndex == 0) {
        return 1;
    }
    int maxLength = 1,result;
    for(int counter = currentIndex-1; counter >= 0; counter--) {
        result = longestIncreasingSubSequence(userInput,counter);
        if(userInput[counter] < userInput[currentIndex]) {
            maxLength = max(maxLength,1+result);
        } else {
            maxLength = max(maxLength,result);
        }
    }
    return maxLength;
}

#endif /* LONGESTINCSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
