/****************************************************************************************************************************************************
 *  File Name                   : digitcancellingfractions.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitcancellingfractions.h
 *  Created on                  : Aug 16, 2015 :: 10:42:28 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=33
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

#ifndef DIGITCANCELLINGFRACTIONS_H_
#define DIGITCANCELLINGFRACTIONS_H_

//Tested
struct fraction {
    unsigned int numerator;
    unsigned int denominator;

    fraction() {};
    fraction(unsigned int numerator,unsigned int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
};

//Tested
unsigned int reverseNumber(unsigned int userInput) {
    unsigned int reverse = 0;
    while(userInput) {
        reverse = (reverse << 1)+(reverse << 3)+userInput%10;
        userInput /= 10;
    }
    return reverse;
}

//Tested
fraction * reduceFraction(unsigned int numerator,unsigned int denominator) {
    unsigned flags[10] = {0};
    unsigned int temp = numerator;
    while(temp) {
        flags[temp%10]++;
        temp /= 10;
    }
    unsigned int reducedDenominator = 0;
    denominator = reverseNumber(denominator);
    while(denominator) {
        if(flags[denominator%10] > 0) {
            flags[denominator%10]--;
        } else {
            reducedDenominator *= 10;
            reducedDenominator += denominator%10;
        }
        denominator /= 10;
    }
    unsigned int reducedNumerator = 0;
    temp = reverseNumber(numerator);
    while(temp) {
        if(flags[temp%10] > 0) {
            reducedNumerator *= 10;
            reducedNumerator += temp%10;
            flags[temp%10]--;
        }
        temp /= 10;
    }
    return new fraction(reducedNumerator,reducedDenominator);
}

//Tested
unsigned int gcd(unsigned int a,unsigned int b) {
    if(a == 1 || b == 1) {
        return 1;
    }
    if(b%a == 0) {
        return a;
    }
    return gcd(a%b,a);
}

//Tested
//Ans : 100
void getProductDenominator() {
    fraction *reducedResult;
    unsigned int productOfDenominator = 1,productNumerator = 1;
    for(unsigned int numerator = 11; numerator < 100; numerator++) {
        for(unsigned int denominator = numerator+1; denominator < 100; denominator++) {
            if(denominator %10 ==0 || (numerator%10 == numerator/10)) {
                continue;
            }
            reducedResult = reduceFraction(numerator,denominator);
            if(reducedResult->numerator  != numerator && (double)reducedResult->numerator/(double)reducedResult->denominator == ((double)(numerator)/(double)(denominator))) {
                productNumerator *= reducedResult->numerator;
                productOfDenominator *= reducedResult->denominator;
            }
        }
    }
    cout << productOfDenominator/(gcd(productNumerator,productOfDenominator)) << endl;
}

#endif /* DIGITCANCELLINGFRACTIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
