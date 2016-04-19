/****************************************************************************************************************************************************
 *  File Name                   : factorial.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\factorial.h
 *  Created on                  : Jan 20, 2015 :: 10:42:42 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/factorial-large-number/
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

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

//Tested
void factorialLargeNumber(vector<int> &userInput,int number) {
    if(number == 1) {
        return;
    }
    int carry = 0,result;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        result = userInput[counter] * number + carry;
        userInput[counter] = result % 10;
        carry = result/10;
    }
    while(carry > 0) {
        userInput.push_back(carry%10);
        carry /= 10;
    }
    factorialLargeNumber(userInput,number-1);
}

#endif /* FACTORIAL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
