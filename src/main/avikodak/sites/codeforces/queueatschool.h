/****************************************************************************************************************************************************
 *  File Name                   : queueatschool.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\queueatschool.h
 *  Created on                  : Apr 28, 2015 :: 12:25:07 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/266/B
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

#ifndef QUEUEATSCHOOL_H_
#define QUEUEATSCHOOL_H_

//Tested
void getArrangement() {
    unsigned int people,noOfRounds;
    scanf("%u %u",&people,&noOfRounds);
    string userInput;
    cin >> userInput;
    for(unsigned int outerCounter = 0; outerCounter < noOfRounds; outerCounter++) {
        for(unsigned int innerCounter = 0; innerCounter < userInput.size();) {
            if(userInput[innerCounter] == 'B') {
                if(innerCounter+1 < userInput.size() && userInput[innerCounter+1] =='G') {
                    swap(userInput[innerCounter],userInput[innerCounter+1]);
                    innerCounter+= 2;
                } else {
                    innerCounter++;
                }
            } else {
                innerCounter++;
            }
        }
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%c",userInput[counter]);
    }
}
#endif /* QUEUEATSCHOOL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
