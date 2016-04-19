/****************************************************************************************************************************************************
 *  File Name                   : iqtest.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iqtest.h
 *  Created on                  : Apr 11, 2015 :: 5:20:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/25/A
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

#ifndef IQTEST_H_
#define IQTEST_H_

//Tested
void getNumberEvenness() {
    unsigned int testCases,firstInput,secondInput,thirdInput,input;
    scanf("%u",&testCases);
    cin >> firstInput >> secondInput >> thirdInput;
    bool printOddNumber = false;
    if(firstInput%2 == 0 && secondInput%2 == 0) {
        if(thirdInput%2 == 1) {
            printf("%u",thirdInput);
            return;
        }
        printOddNumber = true;
    } else if(firstInput%2 == 0 && thirdInput%2 == 0) {
        printf("%u",secondInput);
        return;
    } else if(secondInput%2 == 0 && thirdInput%2 == 0) {
        printf("%u",firstInput);
        return;
    }
    testCases -= 3;
    while(testCases--) {
        scanf("%u",&input);
        if(printOddNumber) {
            if(input%2 == 1) {
                printf("%u",input);
                return;
            }
        } else {
            if(input%2 == 0) {
                printf("%u",input);
                return;
            }
        }
    }
}

#endif /* IQTEST_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
