/****************************************************************************************************************************************************
 *  File Name                   : primepairsets.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\primepairsets.h
 *  Created on                  : Aug 22, 2015 :: 5:31:43 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=60
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

#ifndef PRIMEPAIRSETS_H_
#define PRIMEPAIRSETS_H_

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

unsigned int reverse(unsigned int userInput) {
    unsigned int revNumber = 0;
    while(userInput) {
        revNumber *= 10;
        revNumber += userInput%10;
        userInput/=10;
    }
    return revNumber;
}

unsigned int concate(unsigned int first,unsigned int second) {
    unsigned int temp = first;
    second = reverse(second);
    while(second) {
        temp *=10;
        temp += (second%10);
        second /=10;
    }
    return temp;
}

map<unsigned int,map<unsigned int,bool> > auxSpace;

void insertIntoAuxspace(unsigned int firstPrime,unsigned int secondPrime,bool value) {
    map<unsigned int,bool> mapInMap;
    if(auxSpace.find(firstPrime) == auxSpace.end()) {
        mapInMap.insert(pair<unsigned int,bool>(secondPrime,value));
        auxSpace.insert(pair<unsigned int,map<unsigned int,bool> >(firstPrime,mapInMap));
    } else {
        mapInMap = auxSpace.find(firstPrime)->second;
        mapInMap.insert(pair<unsigned int,bool>(secondPrime,value));
    }

    if(auxSpace.find(secondPrime) == auxSpace.end()) {
        mapInMap.insert(pair<unsigned int,bool>(firstPrime,value));
        auxSpace.insert(pair<unsigned int,map<unsigned int,bool> >(secondPrime,mapInMap));
    } else {
        mapInMap = auxSpace.find(secondPrime)->second;
        mapInMap.insert(pair<unsigned int,bool>(firstPrime,value));
    }
}

bool arePrimeSet(unsigned int firstPrime,unsigned int secondPrime,map<unsigned int,bool> primeNumberMap) {
    if(auxSpace.find(firstPrime) != auxSpace.end()) {
        map<unsigned int,bool> mapInMap = auxSpace.find(firstPrime)->second;
        map<unsigned int,bool>::iterator itToMapInMap;
        if((itToMapInMap = mapInMap.find(secondPrime)) != mapInMap.end()) {
            return itToMapInMap->second;
        }
    }
    if(auxSpace.find(secondPrime) != auxSpace.end()) {
        map<unsigned int,bool> mapInMap = auxSpace.find(secondPrime)->second;
        map<unsigned int,bool>::iterator itToMapInMap;
        if((itToMapInMap = mapInMap.find(firstPrime)) != mapInMap.end()) {
            return itToMapInMap->second;
        }
    }
    unsigned int firstConcate = concate(firstPrime,secondPrime);
    if(primeNumberMap.find(firstConcate) == primeNumberMap.end()) {
        insertIntoAuxspace(firstPrime,secondPrime,false);
        return false;
    }
    unsigned int secondConcate = concate(secondPrime,firstPrime);
    if(primeNumberMap.find(secondConcate) == primeNumberMap.end()) {
        insertIntoAuxspace(firstPrime,secondPrime,false);
        return false;
    }
    insertIntoAuxspace(firstPrime,secondPrime,true);
    return true;
}

map<unsigned int,bool> generatePrimeNumberMap(unsigned int limit) {
    vector<bool> flags;
    flags.assign(limit+2,true);
    map<unsigned int,bool> primeNumberMap;
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
            primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
        }
    }
    return primeNumberMap;
}

void generatePrimeSet() {
    vector<unsigned int> primeNumbers = generatePrimeNumber(20000);
    map<unsigned int,bool> primeNumbersMap = generatePrimeNumberMap(10000000);
    for(unsigned int firstCounter = 0; firstCounter < primeNumbers.size(); firstCounter++) {
        if(primeNumbers[firstCounter] == 2) {
            continue;
        }
        cout << "F:" << firstCounter << endl;
        for(unsigned int secondCounter = firstCounter+1; secondCounter < primeNumbers.size(); secondCounter++) {
            cout << "S:" << secondCounter << endl;
            if(arePrimeSet(primeNumbers[firstCounter],primeNumbers[secondCounter],primeNumbersMap)) {
                for(unsigned int thirdCounter = secondCounter+1; thirdCounter < primeNumbers.size(); thirdCounter++) {
                    cout << "T:" << thirdCounter << endl;
                    if(arePrimeSet(primeNumbers[firstCounter],primeNumbers[thirdCounter],primeNumbersMap) && arePrimeSet(primeNumbers[secondCounter],primeNumbers[thirdCounter],primeNumbersMap)) {
                        for(unsigned int fourthCounter = thirdCounter+1; fourthCounter < primeNumbers.size(); fourthCounter++) {
                            cout << "F:" << fourthCounter << endl;
                            if(arePrimeSet(primeNumbers[firstCounter],primeNumbers[fourthCounter],primeNumbersMap) && arePrimeSet(primeNumbers[secondCounter],primeNumbers[fourthCounter],primeNumbersMap)&& arePrimeSet(primeNumbers[thirdCounter],primeNumbers[fourthCounter],primeNumbersMap)) {
                                for(unsigned int fifthCounter = fourthCounter+1; fifthCounter < primeNumbers.size(); fifthCounter++) {
                                    cout << "FI:" << fifthCounter << endl;
                                    if(arePrimeSet(primeNumbers[firstCounter],primeNumbers[fifthCounter],primeNumbersMap) && arePrimeSet(primeNumbers[secondCounter],primeNumbers[fifthCounter],primeNumbersMap)&& arePrimeSet(primeNumbers[thirdCounter],primeNumbers[fifthCounter],primeNumbersMap)&& arePrimeSet(primeNumbers[fourthCounter],primeNumbers[fifthCounter],primeNumbersMap)) {
                                        cout << primeNumbers[firstCounter] << " " << primeNumbers[secondCounter] << " " << primeNumbers[thirdCounter]<< " " << primeNumbers[fourthCounter]<< " " << primeNumbers[fifthCounter] << endl;
                                        cout << primeNumbers[firstCounter] +primeNumbers[secondCounter] +primeNumbers[thirdCounter]+primeNumbers[fourthCounter]+primeNumbers[fifthCounter] << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

#endif /* PRIMEPAIRSETS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
