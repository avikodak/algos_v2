/****************************************************************************************************************************************************
 *  File Name                   : beautifulyear.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\beautifulyear.h
 *  Created on                  : Mar 1, 2015 :: 6:28:54 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/271/A
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

#ifndef BEAUTIFULYEAR_H_
#define BEAUTIFULYEAR_H_

//Tested
bool doesNumberHasUniqueDigits(int userInput) {
    bool flags[10] = {false};
    int lastDigit;
    while(userInput > 0) {
        lastDigit = userInput%10;
        if(flags[lastDigit]) {
            return false;
        }
        flags[lastDigit] = true;
        userInput /= 10;
    }
    return true;
}

//Tested
void getMinUniqueDigitNumber() {
    int userInput;
    scanf("%d",&userInput);
    for(int counter = userInput+1; counter < 9500; counter++) {
        if(doesNumberHasUniqueDigits(counter)) {
            printf("%d",counter);
            break;
        }
    }
}

#endif /* BEAUTIFULYEAR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
