/****************************************************************************************************************************************************
 *  File Name                   : largestpalindromicproduct.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\largestpalindromicproduct.h
 *  Created on                  : Jul 25, 2015 :: 7:17:21 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=4
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

#ifndef LARGESTPALINDROMICPRODUCT_H_
#define LARGESTPALINDROMICPRODUCT_H_

//Tested
bool isPalindrome(unsigned int number) {
    unsigned int originalNumber = number,revNumber = 0;
    while(number) {
        revNumber *= 10;
        revNumber += (number%10);
        number /= 10;
    }
    return originalNumber == revNumber;
}

//Tested
//906609
void getLargestPalindromicProduct() {
    unsigned int maxProduct = 1,result;
    for(unsigned int outerCounter = 100; outerCounter < 1000; outerCounter++) {
        for(unsigned int innerCounter = 100; innerCounter < 1000; innerCounter++) {
            result = outerCounter * innerCounter;
            if(isPalindrome(result)) {
                maxProduct = max(maxProduct,outerCounter*innerCounter);
            }
        }
    }
    cout << maxProduct;
}

#endif /* LARGESTPALINDROMICPRODUCT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
