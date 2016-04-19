/****************************************************************************************************************************************************
 *  File Name                   : funnystrings.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\funnystrings.h
 *  Created on                  : May 24, 2015 :: 7:37:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/funny-string
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

#ifndef FUNNYSTRINGS_H_
#define FUNNYSTRINGS_H_

//Tested
void areStringsFunny() {
    unsigned int testCases;
    int diffFirst,diffSecond;
    scanf("%u",&testCases);
    string userInput,revUserInput;
    while(testCases--) {
        cin >> userInput;
        revUserInput.clear();
        revUserInput.resize(userInput.size());
        reverse_copy(userInput.begin(),userInput.end(),revUserInput.begin());
        bool flag = true;
        for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
            diffFirst = abs(userInput[outerCrawler] - userInput[outerCrawler-1]);
            diffSecond = abs(revUserInput[outerCrawler] - revUserInput[outerCrawler-1]);
            if(diffFirst != diffSecond) {
                printf("Not Funny\n");
                flag = false;
                break;
            }
        }
        if(flag) {
            printf("Funny\n");
        }

    }
}

#endif /* FUNNYSTRINGS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
