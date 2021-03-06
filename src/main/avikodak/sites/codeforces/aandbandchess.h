/****************************************************************************************************************************************************
 *  File Name                   : aandbandchess.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\aandbandchess.h
 *  Created on                  : Apr 11, 2015 :: 12:20:14 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/519/A
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

#ifndef AANDBANDCHESS_H_
#define AANDBANDCHESS_H_

//Tested
void printMaxScore() {
    unsigned int whiteScore = 0,blackScore = 0;
    string userInput;
    char currentChar;
    for(unsigned int rowCounter = 0; rowCounter < 8; rowCounter++) {
        cin >> userInput;
        for(unsigned int columnCounter = 0; columnCounter < userInput.size(); columnCounter++) {
            currentChar = userInput[columnCounter];
            if(currentChar != '.') {
                if(currentChar == 'Q' || currentChar == 'q') {
                    if(currentChar == 'Q') {
                        whiteScore += 9;
                    } else {
                        blackScore += 9;
                    }
                } else if(currentChar == 'R' || currentChar == 'r') {
                    if(currentChar == 'R') {
                        whiteScore += 5;
                    } else {
                        blackScore += 5;
                    }
                } else if(currentChar == 'B' || currentChar == 'b') {
                    if(currentChar == 'B') {
                        whiteScore += 3;
                    } else {
                        blackScore += 3;
                    }
                } else if(currentChar == 'N' || currentChar == 'n') {
                    if(currentChar == 'N') {
                        whiteScore += 3;
                    } else {
                        blackScore += 3;
                    }
                } else if(currentChar == 'P' || currentChar == 'p') {
                    if(currentChar == 'P') {
                        whiteScore += 1;
                    } else {
                        blackScore += 1;
                    }
                }
            }
        }
    }
    if(whiteScore == blackScore) {
        printf("Draw");
    } else if(whiteScore > blackScore) {
        printf("White");
    } else {
        printf("Black");
    }
}


#endif /* AANDBANDCHESS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
