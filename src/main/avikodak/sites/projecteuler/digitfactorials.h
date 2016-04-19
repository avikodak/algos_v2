/****************************************************************************************************************************************************
 *  File Name                   : digitfactorials.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitfactorials.h
 *  Created on                  : Aug 13, 2015 :: 4:25:51 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=34
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

#ifndef DIGITFACTORIALS_H_
#define DIGITFACTORIALS_H_

//Tested
unsigned int getDigitFactorials(unsigned int userInput,map<unsigned int,unsigned int> digitFactorialMap) {
    unsigned int sum = 0;
    while(userInput) {
        sum += digitFactorialMap.find(userInput%10)->second;
        userInput /= 10;
    }
    return sum;
}

//Tested
//Ans : 40730
unsigned int getSumOfDigitFactorials() {
    unsigned int sum = 0,product = 1;
    map<unsigned int,unsigned int> digitFactorialMap;
    digitFactorialMap.insert(pair<unsigned int,unsigned int>(0,0));
    for(unsigned int counter = 1; counter < 10; counter++) {
        product *= counter;
        digitFactorialMap.insert(pair<unsigned int,unsigned int>(counter,product));
    }
    for(unsigned int counter = 3; counter < 2540161; counter++) {
        if(counter == getDigitFactorials(counter,digitFactorialMap)) {
            sum += counter;
        }
    }
    return sum;
}

#endif /* DIGITFACTORIALS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
