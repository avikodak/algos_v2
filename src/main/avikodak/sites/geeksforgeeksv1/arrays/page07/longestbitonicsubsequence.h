/****************************************************************************************************************************************************
 *  File Name                   : longestbitonicsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\longestbitonicsubsequence.h
 *  Created on                  : Nov 28, 2014 :: 12:00:50 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
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

#ifndef LONGESTBITONICSUBSEQUENCE_H_
#define LONGESTBITONICSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
vector<int> getIncreasingLengthsubsequence(vector<int> userInput) {
    vector<int> incSubsequenceLen;
    incSubsequenceLen.push_back(1);
    int maxCurrentLength;
    for(unsigned int outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        maxCurrentLength = 1;
        for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            if(userInput[outerCounter] > userInput[innerCounter]) {
                maxCurrentLength = max(maxCurrentLength,1+incSubsequenceLen[innerCounter]);
            }
        }
        incSubsequenceLen.push_back(maxCurrentLength);
    }
    return incSubsequenceLen;
}

//Tested
vector<int> getDecreasignLengthSubsequence(vector<int> userInput) {
    vector<int> decSubsequenceLen;
    decSubsequenceLen.assign(userInput.size(),0);
    decSubsequenceLen[decSubsequenceLen.size()-1] = 1;
    int maxCurrentLength;
    for(int outerCounter = userInput.size()-2; outerCounter >=0; outerCounter--) {
        maxCurrentLength = 1;
        for(int innerCounter = outerCounter+1; innerCounter < (int)userInput.size(); innerCounter++) {
            if(userInput[outerCounter] > userInput[innerCounter]) {
                maxCurrentLength = max(maxCurrentLength,1+decSubsequenceLen[innerCounter]);
            }
        }
        decSubsequenceLen[outerCounter] = maxCurrentLength;
    }
    return decSubsequenceLen;
}

//Tested
int longestBitonicSubsequence(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int maxLength = 0;
    vector<int> incSubSequenceLen = getIncreasingLengthsubsequence(userInput);
    vector<int> decSubSequenceLen = getDecreasignLengthSubsequence(userInput);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        maxLength = max(maxLength,incSubSequenceLen[counter]+decSubSequenceLen[counter]-1);
    }
    return maxLength;
}

#endif /* LONGESTBITONICSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
