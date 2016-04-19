/****************************************************************************************************************************************************
 *  File Name                   : longestpalindromesequence.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\longestpalindromesequence.h
 *  Created on                  : Dec 11, 2014 :: 12:29:24 PM
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

#ifndef LONGESTPALINDROMESEQUENCE_H_
#define LONGESTPALINDROMESEQUENCE_H_

int longestPalindromicSequenceMemoization(char *userInput) {
    if(userInput == null) {
        return 0;
    }
    int length = strlen(userInput);
    vector<vector<int> > auxSpace(length);
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        auxSpace[counter].resize(auxSpace.size());
        auxSpace[counter][counter] = 1;
    }
    for(int rowCounter = length-1; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = length-1; columnCounter > rowCounter; columnCounter--) {
            if(userInput[rowCounter] == userInput[columnCounter]) {
                auxSpace[rowCounter][columnCounter] = 2 + auxSpace[rowCounter+1][columnCounter-1];
            } else {
                auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter+1][columnCounter],auxSpace[rowCounter][columnCounter-1]);
            }
        }
    }
    return auxSpace[0][auxSpace.size()-1];
}

int longestPalindromicSequence(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return 1;
    }
    if(abs(startIndex - endIndex) == 1) {
        return userInput[startIndex] == userInput[endIndex]?2:1;
    }
    if(userInput[startIndex] == userInput[endIndex]) {
        return 2 + longestPalindromicSequence(userInput,startIndex+1,endIndex-1);
    } else {
        return max(longestPalindromicSequence(userInput,startIndex+1,endIndex),longestPalindromicSequence(userInput,startIndex,endIndex-1));
    }
}


#endif /* LONGESTPALINDROMESEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
