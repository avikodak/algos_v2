/****************************************************************************************************************************************************
 *  File Name                   : totientmaximum.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\totientmaximum.h
 *  Created on                  : Aug 20, 2015 :: 12:20:55 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=69
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

#ifndef TOTIENTMAXIMUM_H_
#define TOTIENTMAXIMUM_H_

//Tested
map<unsigned long long int,unsigned long long int> getPrimeFactorization(unsigned long long int userInput) {
    unsigned long long int squareRoot = sqrtl(userInput);
    map<unsigned long long int,unsigned long long int> factorsCounter;
    map<unsigned long long int,unsigned long long int>::iterator itToFactorsCount;
    bool flag = true;
    while(flag && userInput > 1) {
        flag = false;
        while(!(userInput&1)) {
            if((itToFactorsCount = factorsCounter.find(2)) == factorsCounter.end()) {
                factorsCounter[2] = 1;
            } else {
                factorsCounter[2]++;
            }
            flag = true;
            userInput /= 2;
        }
        for(unsigned long long int counter = 3; counter <= squareRoot; counter+=2) {
            if(userInput%counter == 0) {
                if(factorsCounter.find(counter) == factorsCounter.end()) {
                    factorsCounter[counter] = 1;
                } else {
                    factorsCounter[counter]++;
                }
                flag = true;
                userInput /= counter;
                break;
            }
        }
        if(!flag && userInput != 1) {
            if(factorsCounter.find(userInput) == factorsCounter.end()) {
                factorsCounter[userInput] = 1;
            } else {
                factorsCounter[userInput]++;
            }
        }
    }
    return factorsCounter;
}

//Tested
double getTotientFuncValue(unsigned long long int userInput) {
    map<unsigned long long int,unsigned long long int> primeFactorization = getPrimeFactorization(userInput);
    map<unsigned long long int,unsigned long long int>::iterator itToPrimeFactorization;
    double result = userInput;
    for(itToPrimeFactorization = primeFactorization.begin(); itToPrimeFactorization != primeFactorization.end(); itToPrimeFactorization++) {
        result *= (double)(itToPrimeFactorization->first-1);
        result /= (double)itToPrimeFactorization->first;
    }
    return result;
}

//Tested
//Ans : 510510
void getMaximumTotientFunction() {
    double maxValue = 0;
    double totientValue;
    unsigned int maxN;
    for(unsigned int counter = 2; counter <= 1000000; counter++) {
        totientValue = getTotientFuncValue(counter);
        if(maxValue < ((double)(counter)/(double)(totientValue))) {
            maxValue = ((double)(counter)/(double)(totientValue));
            maxN = counter;
        }
    }
    cout << maxN << endl;
}

#endif /* TOTIENTMAXIMUM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
