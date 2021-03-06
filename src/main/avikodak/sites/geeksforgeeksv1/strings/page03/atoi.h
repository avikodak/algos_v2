/****************************************************************************************************************************************************
 *  File Name                   : atoi.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page03\atoi.h
 *  Created on                  : Jan 16, 2015 :: 11:47:34 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-your-own-atoi/
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

#ifndef ATOI_H_
#define ATOI_H_

//Tested
int atoicustom(char *userInput) {
    if(userInput == null || userInput[0] == '\0') {
        return 0;
    }
    int number = 0;
    while(userInput[0] != '\0') {
        if(userInput[0] >= '0' && userInput[0] <= '9') {
            number = (number << 3) + (number << 1) + (userInput[0] - '0');
        } else {
            throw "Invalid character";
        }
        userInput++;
    }
    return number;
}

#endif /* ATOI_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
