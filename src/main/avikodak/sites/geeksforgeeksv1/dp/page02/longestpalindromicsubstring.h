/****************************************************************************************************************************************************
 *  File Name   		: longestpalindromicsubstring.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\longestpalindromicsubstring.h
 *  Created on			: Dec 15, 2014 :: 3:23:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LONGESTPALINDROMICSUBSTRING_H_
#define LONGESTPALINDROMICSUBSTRING_H_


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int longestPalindromicSubSequenceON2(char *userInput,int length) {
    if(userInput == null || length == 0) {
        return 0;
    }
    vector<vector<bool> > auxSpace(length);
    int maxLength = 1;
    for(int counter = 0; counter < length; counter++) {
        auxSpace[counter].assign(length,false);
        auxSpace[counter][counter] = true;
    }
    for(int counter = 0; counter < length - 1; counter++) {
        if(userInput[counter] == userInput[counter+1]) {
            auxSpace[counter][counter+1] = true;
            maxLength = 2;
        }
    }
    for(int rowCounter = auxSpace.size()-2; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = rowCounter+2; columnCounter < (int)auxSpace[0].size(); columnCounter++) {
            if(userInput[rowCounter] == userInput[columnCounter] && auxSpace[rowCounter+1][columnCounter-1]) {
                maxLength = max(maxLength,columnCounter - rowCounter + 1);
                auxSpace[rowCounter][columnCounter] = true;
            }
        }
    }
    return maxLength;
}

//Tested
int longestPalindromicSubSequenceON2V2(char *userInput,int length) {
    if(userInput == null || length == 0) {
        return 0;
    }
    vector<vector<bool> > auxSpace(length);
    int innerCounter;
    for(int counter = 0; counter < length; counter++) {
        auxSpace[counter].assign(length,false);
        auxSpace[counter][counter] = true;
    }
    int maxLength = INT_MIN;
    for(int lengthCounter = 2; lengthCounter <= length; lengthCounter++) {
        for(int outerCounter = 0; outerCounter < length - lengthCounter + 1; outerCounter++) {
            innerCounter = outerCounter + lengthCounter - 1;
            if(lengthCounter == 2) {
                auxSpace[outerCounter][innerCounter] = userInput[outerCounter] == userInput[innerCounter];
            } else {
                auxSpace[outerCounter][innerCounter] = (userInput[outerCounter] == userInput[innerCounter] && auxSpace[outerCounter+1][innerCounter-1]);
            }
            if(auxSpace[outerCounter][innerCounter]) {
                maxLength = max(maxLength,innerCounter - outerCounter + 1);
            }
        }
    }
    return maxLength;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int isSubStringPalindrome(char *userInput,int start,int end) {
    int startCrawler = start,endCrawler = end;
    while(startCrawler < endCrawler) {
        if(userInput[startCrawler] != userInput[endCrawler]) {
            return false;
        }
        startCrawler++;
        endCrawler--;
    }
    return true;
}

//Tested
int longestPalindromicSubstring(char *userInput,unsigned int size) {
    if(userInput == null) {
        return 0;
    }
    int maxLength = INT_MIN;
    for(unsigned int outerCrawler = 0; outerCrawler < size; outerCrawler++) {
        for(unsigned int innerCrawler = outerCrawler; innerCrawler < size; innerCrawler++) {
            if(isSubStringPalindrome(userInput,outerCrawler,innerCrawler)) {
                maxLength = max(maxLength,(int)(innerCrawler - outerCrawler + 1));
            }
        }
    }
    return maxLength;
}

#endif /* LONGESTPALINDROMICSUBSTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
