/****************************************************************************************************************************************************
 *  File Name                   : brackets.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\brackets.h
 *  Created on                  : Aug 30, 2015 :: 1:47:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/BRACKETS
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef BRACKETS_H_
#define BRACKETS_H_

//Tested
unsigned int getMaxLength(string userInput) {
    unsigned int maxLength = 0,balance =0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == '(') {
            balance++;
        } else {
            balance--;
        }
        maxLength = max(maxLength,balance);
    }
    return maxLength;
}

//Tested
void printSequence(string userInput) {
    unsigned int maxLen = getMaxLength(userInput);
    string newSeq;
    for(unsigned int counter = 0; counter < maxLen; counter++) {
        newSeq.append("(");
    }
    for(unsigned int counter = 0; counter < maxLen; counter++) {
        newSeq.append(")");
    }
    cout << newSeq << endl;
}

//Tested
void printResults() {
    unsigned int testCases;
    scanf("%u",&testCases);
    string userInput;
    while(testCases--) {
        cin >> userInput;
        printSequence(userInput);
    }
}

#endif /* BRACKETS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
