/****************************************************************************************************************************************************
 *  File Name                   : longestpalindromicsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\longestpalindromicsequence.h
 *  Created on                  : Dec 15, 2014 :: 9:20:31 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
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

#ifndef LONGESTPALINDROMICSEQUENCE_H_
#define LONGESTPALINDROMICSEQUENCE_H_

//Tested
int longestPalindromicSubSequenceMemoization(char *userInput) {
    if(userInput == null) {
        return 0;
    }
    int length = strlen(userInput);
    vector<vector<int> > auxSpace(length);
    for(unsigned int diagonalCounter = 0; diagonalCounter < auxSpace.size(); diagonalCounter++) {
        auxSpace[diagonalCounter].assign(length,0);
        auxSpace[diagonalCounter][diagonalCounter] = 1;
    }
    for(int counter = 0; counter < length-1; counter++) {
        if(userInput[counter] == userInput[counter+1]) {
            auxSpace[counter][counter+1] = 2;
        } else {
            auxSpace[counter][counter+1] = 1;
        }
    }
    for(int rowCounter = length-2; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = rowCounter+2; columnCounter < length; columnCounter++) {
            if(userInput[rowCounter] == userInput[columnCounter]) {
                auxSpace[rowCounter][columnCounter] = 2 + auxSpace[rowCounter+1][columnCounter-1];
            } else {
                auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter+1][columnCounter],auxSpace[rowCounter][columnCounter-1]);
            }
        }
    }
    return auxSpace[0][auxSpace[0].size()-1];
}

//Tested
int longestPalindromicSubsequenceV2(char *userInput) {
    if(userInput == null) {
        return 0;
    }
    int length = strlen(userInput);
    vector<vector<int> > auxSpace(length);
    for(unsigned int diagonalCounter = 0; diagonalCounter < auxSpace.size(); diagonalCounter++) {
        auxSpace[diagonalCounter].assign(length,0);
        auxSpace[diagonalCounter][diagonalCounter] = 1;
    }
    for(int counter = 0; counter < length-1; counter++) {
        if(userInput[counter] == userInput[counter+1]) {
            auxSpace[counter][counter+1] = 2;
        } else {
            auxSpace[counter][counter+1] = 1;
        }
    }
    int innerCounter;
    for(int lengthCounter = 2; lengthCounter <= length; lengthCounter++) {
        for(int outerCounter = 0; outerCounter < length - lengthCounter+1; outerCounter++) {
            innerCounter = outerCounter + lengthCounter - 1;
            if(userInput[outerCounter] == userInput[innerCounter] && abs(innerCounter - outerCounter) == 1) {
                auxSpace[outerCounter][innerCounter] = 2;
            } else if(userInput[outerCounter] == userInput[innerCounter]) {
                auxSpace[outerCounter][innerCounter] = 2 + auxSpace[outerCounter+1][innerCounter-1];
            } else {
                auxSpace[outerCounter][innerCounter] = max(auxSpace[outerCounter+1][innerCounter],auxSpace[outerCounter][innerCounter-1]);
            }
        }
    }
    return auxSpace[0][length-1];
}

//Tested
int longestPalindromicSubSequence(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    if(startIndex == endIndex) {
        return 1;
    }
    if(endIndex - startIndex == 1) {
        return userInput[startIndex] == userInput[endIndex]?2:1;
    }
    if(userInput[startIndex] == userInput[endIndex]) {
        return 2 + longestPalindromicSubSequence(userInput,startIndex+1,endIndex-1);
    } else {
        return max(longestPalindromicSubSequence(userInput,startIndex+1,endIndex),longestPalindromicSubSequence(userInput,startIndex,endIndex-1));
    }
}

#endif /* LONGESTPALINDROMICSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
