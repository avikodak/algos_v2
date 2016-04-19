/****************************************************************************************************************************************************
 *  File Name                   : euler003.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\projecteuler\euler003.h
 *  Created on                  : Jul 28, 2015 :: 8:41:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/contests/projecteuler/challenges/euler003
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

#ifndef EULER003_H_
#define EULER003_H_

//Tested
long long int max(long int firstInput,long long  int secondInput) {
    return firstInput > secondInput?firstInput:secondInput;
}

//Tested
void printLargestPrimeFactor() {
    unsigned int testCases;
    scanf("%u",&testCases);
    long long int userInput;
    long long int squareRoot,largestDivisor;
    bool flag;
    while(testCases--) {
        cin  >> userInput;
        squareRoot = sqrtl(userInput);
        largestDivisor = 0;
        flag = true;
        while(flag) {
            flag = false;
            while(!(userInput&1)) {
                largestDivisor = max(largestDivisor,2);
                flag = true;
                userInput /= 2;
            }
            for(long long int counter = 3; counter <= squareRoot; counter+=2) {
                if(userInput%counter == 0) {
                    largestDivisor = max(counter,largestDivisor);
                    flag = true;
                    userInput /= counter;
                    break;
                }
            }
            if(!flag) {
                largestDivisor = max(largestDivisor,userInput);
            }
        }
        cout << largestDivisor << endl;
    }
}

#endif /* EULER003_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
