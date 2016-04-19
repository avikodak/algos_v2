/****************************************************************************************************************************************************
 *  File Name                   : longestincreasingsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\longestincreasingsubsequence.h
 *  Created on                  : Oct 29, 2014 :: 4:11:37 PM
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

#ifndef LONGESTINCREASINGSUBSEQUENCE_H_
#define LONGESTINCREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int longestIncreasingSubsequenceIterative(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<int> increasingLength;
    increasingLength.push_back(1);
    int key;
    int maxLength;
    for(unsigned int outerCounter = 1; outerCounter < userInput.size(); outerCounter++) {
        maxLength = 0;
        key = userInput[outerCounter];
        for(int innerCounter = outerCounter-1; innerCounter >= 0; innerCounter--) {
            if(userInput[innerCounter] <= key) {
                maxLength = max(maxLength,increasingLength[innerCounter]);
            }
        }
        increasingLength.push_back(1+maxLength);
    }
    return increasingLength[increasingLength.size()-1];
}

//Tested
unsigned int longestIncreasingSubSequence(vector<int> userInput,unsigned int currentIndex) {
    if(currentIndex == 0) {
        return 1;
    }
    unsigned int maxLength = 0;
    for(int counter = currentIndex - 1; counter >= 0; counter--) {
        if(userInput[counter] <= userInput[currentIndex]) {
            maxLength = max(maxLength,longestIncreasingSubSequence(userInput,counter));
        }
    }
    return 1 + maxLength;
}

//Tested
unsigned int longestIncreasingSubSequenceMemoization(vector<int> userInput,unsigned int currentIndex) {
    static map<unsigned int,unsigned int> indexMaxLengthMap;
    if(currentIndex == 0) {
        indexMaxLengthMap.insert(pair<unsigned int,unsigned int>(currentIndex,1));
        return 1;
    }
    unsigned int maxLength = 0;
    map<unsigned int,unsigned int>::iterator itToIndexMaxLengthMap;
    for(int counter = currentIndex - 1; counter >= 0; counter--) {
        if(userInput[currentIndex] >= userInput[counter]) {
            if((itToIndexMaxLengthMap = indexMaxLengthMap.find(counter)) == indexMaxLengthMap.end()) {
                maxLength = max(maxLength,longestIncreasingSubSequenceMemoization(userInput,counter));
            } else {
                maxLength = max(maxLength,itToIndexMaxLengthMap->second);
            }
        }
    }
    indexMaxLengthMap.insert(pair<unsigned int,unsigned int>(currentIndex,1+maxLength));
    return 1+maxLength;
}


/****************************************************************************************************************************************************/
/*                                                                 O(2^N) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* LONGESTINCREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
