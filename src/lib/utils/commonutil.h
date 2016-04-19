/****************************************************************************************************************************************************
 *  File Name                   : commonutil.h
 *  File Location               : \algos_v2\src\lib\utils\commonutil.h
 *  Created on                  : Oct 9, 2014 :: 12:38:51 PM
 *  Author                      : AVINASH
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
#include <stdint.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef COMMONUTIL_H_
#define COMMONUTIL_H_

//Tested
void printIVector(vector<int> userInput,bool withHeadersAndFooters = false) {
    if(withHeadersAndFooters) {
        printf("\n====================================================================================================================================\n");
        printf("PRINTING VECTOR START\n");
        printf("====================================================================================================================================\n");
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d\t",userInput[counter]);
    }
    if(withHeadersAndFooters) {
        printf("\n====================================================================================================================================\n");
        printf("PRINTING VECTOR END\n");
        printf("====================================================================================================================================\n");
    }
}

void printIVector(vector<bool> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d\t",userInput[counter]==true?1:0);
    }
}

void printSVector(vector<string> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        cout << userInput[counter];
    }
}

void printCVector(vector<char> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%c",userInput[counter]);
    }
}

//Tested
void printGVector(vector<dfsTimes *> times) {
    for(unsigned int counter = 0; counter < times.size(); counter++) {
        printf("%d->%d %d\n",counter,times[counter]->arrivalTimes,times[counter]->departureTimes);
    }
}

void printIVector(vector<char> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%c\t",userInput[counter]);
    }
}

//Tested
void printIVector(vector<vector<int> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return;
    }
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < userInput[rowCounter].size(); columnCounter++) {
            printf("%d\t",userInput[rowCounter][columnCounter]);
        }
        PRINT_NEW_LINE;
    }
}

//Tested
void printIVector(vector<iInterval *> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d-%d\t",userInput[counter]->start,userInput[counter]->end);
    }
}

//Tested
void printIVector(vector<iPair *> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("(%d,%d)\t",userInput[counter]->firstValue,userInput[counter]->secondValue);
    }
}

/*void printDimensionVector(vector<dimensions *> userInput){
    if(userInput.size() == 0){
        return;
    }
    for(unsigned int counter = 0;counter < userInput.size();counter++){
        printf("%d %d %d\n",userInput[counter]->length,userInput[counter]->width,userInput[counter]->height);
    }
}*/

//Tested
void printIVector(vector<iValueIndex *> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("(%d,%d,%d)\t",userInput[counter]->value,userInput[counter]->firstValueIndex,userInput[counter]->secondvalueIndex);
    }
}

//Tested
void printIVector(vector<vector<bool> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return;
    }
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
            printf("%d\t",userInput[rowCounter][columnCounter]==true?1:0);
        }
        PRINT_NEW_LINE;
    }
}

//Tested
void printTIndexNodeMap(hash_map<unsigned int,itNode *> nodeIndexMap) {
    hash_map<unsigned int,itNode *>::iterator itToNodeIndexMap;
    for(itToNodeIndexMap = nodeIndexMap.begin(); itToNodeIndexMap != nodeIndexMap.end(); itToNodeIndexMap++) {
        printf("%d %d\n",itToNodeIndexMap->first,itToNodeIndexMap->second->value);
    }
}

//Tested
void printTNodeIndexMap(hash_map<intptr_t,unsigned int> indexNodeMap) {
    hash_map<intptr_t,unsigned int>::iterator itToIndexNodeMap;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        printf("%d %d\n",((itNode *)itToIndexNodeMap->first)->value,itToIndexNodeMap->second);
    }
}

vector<int> generatePrimeNumbers(unsigned int number) {
    vector<int> primeNumbers;
    if(number < 2) {
        return primeNumbers;
    }
    vector<bool> auxSpace(number+1,true);
    auxSpace[1] = auxSpace[0] = false;
    int multiplier;
    for(unsigned int counter = 2; counter <= number/2; counter++) {
        if(auxSpace[counter]) {
            multiplier = 2;
            while(counter * multiplier <= number) {
                auxSpace[counter * multiplier] = false;
                multiplier++;
            }
        }
    }
    for(unsigned int counter = 1; counter < number; counter++) {
        if(auxSpace[counter]) {
            primeNumbers.push_back(counter);
        }
    }
    return primeNumbers;
}

bool isNumberPrime(unsigned int number) {
    if(number < 2) {
        return true;
    }
    int sqrtOfInput = sqrt(number);
    for(unsigned int counter = 1; counter <= sqrtOfInput; counter++) {
        if(number%counter == 0) {
            return false;
        }
    }
    return true;
}

#endif /* COMMONUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
