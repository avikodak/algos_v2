/****************************************************************************************************************************************************
 *  File Name   		: printuniquerows.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\printuniquerows.h
 *  Created on			: Dec 1, 2014 :: 4:08:29 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTUNIQUEROWS_H_
#define PRINTUNIQUEROWS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printUniqueRowsON(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() ==  0) {
        return;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    int	sum;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        sum = 0;
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter]) {
                sum += pow(2,columnCounter);
            }
        }
        if(frequencyMap.find(sum) == frequencyMap.end()) {
            frequencyMap[sum] = 1;
        } else {
            frequencyMap[sum] += 1;
        }
    }
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        sum = 0;
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter]) {
                sum += pow(2,columnCounter);
            }
        }
        if(frequencyMap.find(sum)->second == 1) {
            for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
                printf("%d\t",userInput[rowCounter][columnCounter] == true?1:0);
            }
            PRINT_NEW_LINE;
        }
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printUniqueRowsON2(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() ==  0) {
        return;
    }
    bool isRowUnique;
    for(unsigned int outerRowCounter = 0; outerRowCounter < userInput.size(); outerRowCounter++) {
        isRowUnique = true;
        for(unsigned int innerRowCounter = 0; innerRowCounter < userInput.size(); innerRowCounter++) {
            for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
                if(userInput[outerRowCounter][columnCounter] != userInput[innerRowCounter][columnCounter]) {
                    isRowUnique = false;
                    break;
                }
            }
        }
        if(isRowUnique) {
            for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
                printf("%d\t",userInput[outerRowCounter][columnCounter]?1:0);
            }
            PRINT_NEW_LINE;
        }
    }
}

#endif /* PRINTUNIQUEROWS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
