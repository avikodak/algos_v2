/****************************************************************************************************************************************************
 *  File Name                   : goldbachsotherconjecture.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\goldbachsotherconjecture.h
 *  Created on                  : Aug 22, 2015 :: 4:24:40 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=46
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

#ifndef GOLDBACHSOTHERCONJECTURE_H_
#define GOLDBACHSOTHERCONJECTURE_H_

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
map<unsigned int,bool> getMapOfPrimeNumber(vector<unsigned int> userInput) {
    map<unsigned int,bool> mapOfPrimeNumber;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        mapOfPrimeNumber.insert(pair<unsigned int,bool>(userInput[counter],true));
    }
    return mapOfPrimeNumber;
}

//Tested
bool isPerfectSquare(unsigned long long int value) {
    unsigned long long int squareRoot = sqrtl(value);
    return squareRoot*squareRoot == value;
}

//Tested
bool checkGoldbachConjectur(vector<unsigned int> primeNumber,unsigned int userInput) {
    unsigned int difference;
    for(unsigned int counter = 0; counter < primeNumber.size() && primeNumber[counter] < userInput; counter++) {
        difference = userInput - primeNumber[counter];
        if(difference%2 == 0) {
            difference /= 2;
            if(isPerfectSquare(difference)) {
                return true;
            }
        }
    }
    return false;
}

//Tested
//Ans : 5777
void getCompositeNumber() {
    vector<unsigned int> primeNumbers = generatePrimeNumber(1000000);
    map<unsigned int,bool> mapOfPrimeNumbers = getMapOfPrimeNumber(primeNumbers);
    unsigned int counter = 3;
    while(true) {
        if(mapOfPrimeNumbers.find(counter) == mapOfPrimeNumbers.end()) {
            if(!checkGoldbachConjectur(primeNumbers,counter)) {
                cout << counter << endl;
                return;
            }
        }
        counter += 2;
    }
}

#endif /* GOLDBACHSOTHERCONJECTURE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
