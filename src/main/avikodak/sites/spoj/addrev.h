/****************************************************************************************************************************************************
 *  File Name                   : addrev.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\spoj\addrev.h
 *  Created on                  : Feb 3, 2015 :: 11:01:42 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.spoj.com/problems/ADDREV/
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

#ifndef ADDREV_H_
#define ADDREV_H_

//Tested
int reverseNumber(int userInput) {
    int reversedNumber = 0;
    while(userInput > 0 && userInput%10 == 0) {
        userInput /= 10;
    }
    while(userInput > 0) {
        reversedNumber = (((reversedNumber << 3) + (reversedNumber << 1)) + userInput%10);
        userInput /= 10;
    }
    return reversedNumber;
}

//Tested
void printAddRev(int firstUserInput,int secondUserInput) {
    firstUserInput = reverseNumber(firstUserInput);
    secondUserInput = reverseNumber(secondUserInput);
    printf("%d\n",reverseNumber(firstUserInput+secondUserInput));
}


#endif /* ADDREV_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
