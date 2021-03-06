/****************************************************************************************************************************************************
 *  File Name                   : word.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\word.h
 *  Created on                  : Apr 11, 2015 :: 9:42:58 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/59/A
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

#ifndef WORD_H_
#define WORD_H_

//Tested
void changeCaseWord() {
    string userInput;
    cin >> userInput;
    unsigned int lowerCaseCount = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            lowerCaseCount++;
        }
    }
    if(lowerCaseCount >= userInput.size() - lowerCaseCount) {
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
                userInput[counter] = userInput[counter] - 'A' + 'a';
            }
        }
    } else {
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
                userInput[counter] = userInput[counter] - 'a' + 'A';
            }
        }
    }
    cout << userInput;
}

#endif /* WORD_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
