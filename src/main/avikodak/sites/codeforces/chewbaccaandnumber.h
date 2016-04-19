/****************************************************************************************************************************************************
 *  File Name                   : chewbaccaandnumber.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\chewbaccaandnumber.h
 *  Created on                  : Apr 12, 2015 :: 10:09:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/514/A
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

#ifndef CHEWBACCAANDNUMBER_H_
#define CHEWBACCAANDNUMBER_H_

//Tested
void getMinimumNumberInvertDigits() {
    long long unsigned int userInput;
    cin >> userInput;
    stack<unsigned int> digits;
    long long unsigned int result = 0;
    unsigned int lastDigit;
    while(userInput > 0) {
        lastDigit = userInput % 10;
        if(lastDigit > (9 - lastDigit) && userInput != 9) {
            digits.push(9-lastDigit);
        } else {
            digits.push(lastDigit);
        }
        userInput /= 10;
    }
    while(!digits.empty()) {
        result = (result << 3) + (result << 1) + digits.top();
        digits.pop();
    }
    cout << result;
}

#endif /* CHEWBACCAANDNUMBER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
