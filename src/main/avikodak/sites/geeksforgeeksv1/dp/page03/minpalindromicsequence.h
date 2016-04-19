/****************************************************************************************************************************************************
 *  File Name                   : minpalindromicsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\minpalindromicsequence.h
 *  Created on                  : Jan 14, 2015 :: 1:26:42 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
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

#ifndef MINPALINDROMICSEQUENCE_H_
#define MINPALINDROMICSEQUENCE_H_

//Tested
bool isStringPalindrome(char *userInput,int startIndex,int endIndex) {
    if(startIndex == endIndex) {
        return true;
    }
    while(startIndex < endIndex) {
        if(userInput[startIndex] != userInput[endIndex]) {
            return false;
        }
        startIndex++;
        endIndex--;
    }
    return true;
}

//Tested
int minPalindromicPartition(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return 0;
    }
    if(startIndex == endIndex || isStringPalindrome(userInput,startIndex,endIndex)) {
        return 0;
    }
    int minPartitions = INT_MAX;
    for(int counter = startIndex; counter < endIndex; counter++) {
        minPartitions = min(minPartitions,1+minPalindromicPartition(userInput,startIndex,counter)+minPalindromicPartition(userInput,counter+1,endIndex));
    }
    return minPartitions;
}

//Tested
int minPalindromicPartitionsMemoization(char *userInput) {
    if(userInput == null) {
        return 0;
    }
    int length = strlen(userInput);
    vector<vector<bool> > flag(length);
    vector<vector<int> > auxSpace(length);
    for(int rowCounter = 0; rowCounter < length; rowCounter++) {
        flag[rowCounter].assign(length,false);
        flag[rowCounter][rowCounter] = true;
        auxSpace[rowCounter].assign(length,0);
    }
    int innerCrawler,minPartitions;
    for(int lengthCounter = 2; lengthCounter <= length; lengthCounter++) {
        for(int outerCrawler = 0; outerCrawler < length - lengthCounter+1; outerCrawler++) {
            innerCrawler = outerCrawler + lengthCounter - 1;
            if(lengthCounter == 2) {
                flag[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler];
            } else {
                flag[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler] && flag[outerCrawler+1][innerCrawler-1];
            }
            if(flag[outerCrawler][innerCrawler]) {
                auxSpace[outerCrawler][innerCrawler] = 0;
            } else {
                minPartitions = INT_MAX;
                for(int counter = outerCrawler; counter < innerCrawler; counter++) {
                    minPartitions = min(minPartitions,1+auxSpace[outerCrawler][counter]+auxSpace[counter+1][innerCrawler]);
                }
                auxSpace[outerCrawler][innerCrawler] = minPartitions;
            }
        }
    }
    return auxSpace[0][length-1];
}

#endif /* MINPALINDROMICSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
