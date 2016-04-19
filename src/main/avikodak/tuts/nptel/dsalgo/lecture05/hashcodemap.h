/****************************************************************************************************************************************************
 *  File Name                   : hashcodemap.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture05\hashcodemap.h
 *  Created on                  : Nov 17, 2014 :: 7:34:44 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/
#define POLYNOMIAL_ACCUMULATION_CONSTANT 31

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef HASHCODEMAP_H_
#define HASHCODEMAP_H_

unsigned int getHashCodeValue(char *userInput) {
    unsigned int hashValue = 0;
    while(userInput != null) {
        hashValue += (char)*userInput;
        userInput++;
    }
    return hashValue;
}

unsigned int getHashCodeValuePolynomialAccumulation(char *userInput) {
    unsigned int hashValue;
    unsigned int xValue = 1;
    char ch;
    while(*userInput != '\0') {
        ch = *userInput;
        hashValue += xValue*ch;
        xValue *= POLYNOMIAL_ACCUMULATION_CONSTANT;

    }
    return hashValue;
}

#endif /* HASHCODEMAP_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
