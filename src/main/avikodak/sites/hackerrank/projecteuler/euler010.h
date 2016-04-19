/****************************************************************************************************************************************************
 *  File Name                   : euler010.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\projecteuler\euler010.h
 *  Created on                  : Jul 28, 2015 :: 10:29:51 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/contests/projecteuler/challenges/euler010
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

#ifndef EULER010_H_
#define EULER010_H_

//Tested
bool isNumberPrime(long long int userInput) {
    long long int squareRoot = sqrtl(userInput);
    if(!(userInput&1)) {
        return false;
    }
    for(long long int counter = 3; counter <= squareRoot; counter+=2) {
        if(userInput%counter == 0) {
            return false;
        }
    }
    return true;
}

//Tested
void printSum(long long int limit) {
    if(limit < 2) {
        printf("0\n");
        return;
    }
    long long int sum = 2;
    for(long long int counter = 3; counter <= limit; counter++) {
        if(isNumberPrime(counter)) {
            sum += counter;
        }
    }
    cout << sum << endl;
}

//Tested
void getSummationOfPrimes() {
    unsigned int testCases;
    scanf("%u",&testCases);
    long long int input;
    while(testCases--) {
        cin >> input;
        printSum(input);
    }
}

#endif /* EULER010_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
