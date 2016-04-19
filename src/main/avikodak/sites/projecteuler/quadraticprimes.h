/****************************************************************************************************************************************************
 *  File Name                   : quadraticprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\quadraticprimes.h
 *  Created on                  : Aug 16, 2015 :: 8:41:22 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=27
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

#ifndef QUADRATICPRIMES_H_
#define QUADRATICPRIMES_H_

//Tested
vector<unsigned int> generatePrimeNumber(unsigned int limit) {
    vector<bool> flags;
    vector<unsigned int> primes;
    flags.assign(limit+2,true);
    for(unsigned int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            unsigned int innerCounter = 2;
            while(counter*innerCounter <= limit) {
                flags[counter*innerCounter] = false;
                innerCounter+=1;
            }
        }
    }
    for(unsigned int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            primes.push_back(counter);
        }
    }
    return primes;
}

//Tested
map<long long int,bool> generatePrimeNumberMap(long long int limit) {
    vector<bool> flags;
    flags.assign(limit+2,true);
    map<long long int,bool> primeNumberMap;
    for(long long int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            long long int innerCounter = 2;
            while(counter*innerCounter <= limit) {
                flags[counter*innerCounter] = false;
                innerCounter+=1;
            }
        }
    }
    for(long long int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            primeNumberMap.insert(pair<long long int,bool>(counter,true));
        }
    }
    return primeNumberMap;
}

//Tested
long long int getConsecutiveLength(long long int a,long long int b,map<long long int,bool> primeNumberMap) {
    long long int counter = 0;
    long long int value;
    while(true) {
        value = (counter*counter) + (a*counter) + b;
        if(primeNumberMap.find(value) == primeNumberMap.end()) {
            break;
        }
        counter++;
    }
    return counter;
}

//Tested
//Ans : -59231
void printProductForMaxConsecutiveLength() {
    long long int maxLength = 0,length,maxProduct;
    map<long long int,bool> primeNumberMap = generatePrimeNumberMap(10000);
    vector<unsigned int> primeNumbers =generatePrimeNumber(1000);
    for(long long int outerCounter = -1000; outerCounter <= 1000; outerCounter++) {
        for(unsigned innerCounter = 0; innerCounter < primeNumbers.size(); innerCounter++) {
            if(outerCounter + primeNumbers[innerCounter] > 1) {
                length = getConsecutiveLength(outerCounter,primeNumbers[innerCounter],primeNumberMap);
                if(maxLength < length) {
                    maxProduct = outerCounter * primeNumbers[innerCounter];
                    maxLength = length;
                }
            }
        }
    }
    cout << maxProduct << endl;
}

#endif /* QUADRATICPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
