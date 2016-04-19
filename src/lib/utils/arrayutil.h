/****************************************************************************************************************************************************
 *  File Name                   : arrayutil.h
 *  File Location               : \algos_v2\src\lib\utils\arrayutil.h
 *  Created on                  : Oct 9, 2014 :: 12:38:45 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#define null NULL

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ARRAYUTIL_H_
#define ARRAYUTIL_H_

//Tested
vector<int> generateIRandomVector(unsigned int size,int lowerLimit = INT_MIN,int upperLimit = INT_MAX) {
    vector<int> randomnumbers;
    srand(time(NULL));
    for(unsigned int counter = 0; counter < size; counter++) {
        randomnumbers.push_back(rand() % upperLimit + lowerLimit);
    }
    return randomnumbers;
}

//Tested
vector<int> generateISequenceVector(unsigned int size) {
    vector<int> sequence;
    for(unsigned int counter = 1; counter <= size; counter++) {
        sequence.push_back(counter);
    }
    return sequence;
}

//Tested
vector<int> getVectorForUserInput() {
    vector<int> userInput;
    unsigned int sizeOfInput;
    int temp;
    scanf("%d",&sizeOfInput);
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%d",&temp);
        userInput.push_back(temp);
    }
    return userInput;
}

//Tested
vector<iPair *> getPairVectorForUserInput() {
    vector<iPair *> userInput;
    unsigned int sizeOfInput;
    int firstInput,secondInput;
    scanf("%d",&sizeOfInput);
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%d %d",&firstInput,&secondInput);
        userInput.push_back(new iPair(firstInput,secondInput));
    }
    return userInput;
}

//Tested
vector<bool> getBVectorForUserInput() {
    vector<bool> userInput;
    unsigned int sizeOfInput;
    int temp;
    scanf("%d",&sizeOfInput);
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%d",&temp);
        userInput.push_back(temp);
    }
    return userInput;
}

vector<char> getCVectorForUserInput() {
    vector<char> userInput;
    unsigned int sizeOfInput;
    char temp;
    scanf("%d",&sizeOfInput);
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%c",&temp);
        userInput.push_back(temp);
    }
    return userInput;
}

//Tested
vector<iInterval *> getVectorForIntervalsUserInput() {
    vector<iInterval *> userInput;
    userInput.clear();
    unsigned int sizeOfInput;
    scanf("%d",&sizeOfInput);
    int start,end;
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%d %d",&start,&end);
        userInput.push_back(new iInterval(start,end));
    }
    return userInput;
}

//Tested
vector<vector<int> > getVectorForMatrixUserInput() {
    vector<vector<int> > userInput;
    int rows,columns;
    scanf("%d %d",&rows,&columns);
    userInput.resize(rows);
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        userInput[rowCounter].resize(columns);
    }
    for(unsigned int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < columns; columnCounter++) {
            scanf("%d",&userInput[rowCounter][columnCounter]);
        }
    }
    return userInput;
}

//Tested
vector<vector<bool> > getBVectorForMatrixUserInput() {
    vector<vector<bool> > userInput;
    int rows,columns,temp;
    scanf("%d %d",&rows,&columns);
    userInput.resize(rows);
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        userInput[rowCounter].resize(columns);
    }
    for(unsigned int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < columns; columnCounter++) {
            scanf("%d",&temp);
            userInput[rowCounter][columnCounter] = temp;
        }
    }
    return userInput;
}

//Tested
vector<unsigned int> getUVectorForUserInput() {
    vector<unsigned int> userInput;
    unsigned int sizeOfInput;
    unsigned int temp;
    scanf("%d",&sizeOfInput);
    for(unsigned int counter = 0; counter < sizeOfInput; counter++) {
        scanf("%u",&temp);
        userInput.push_back(temp);
    }
    return userInput;
}

hash_map<unsigned int,int> getUserInputForIndexValueMap() {
    hash_map<unsigned int,int> userInput;
    unsigned int sizeOfInput;
    unsigned int index;
    int value;
    scanf("%d",&sizeOfInput);
    while(sizeOfInput--) {
        scanf("%d %d",&index,&value);
        userInput.insert(pair<unsigned int,int>(index,value));
    }
    return userInput;
}

hash_map<int,unsigned int> getFrequencyMapFromVector(vector<int> userInput) {
    hash_map<int,unsigned int> frequencyMap;
    if(userInput.size() == 0) {
        return frequencyMap;
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(frequencyMap.find(userInput[counter]) != frequencyMap.end()) {
            frequencyMap[userInput[counter]] += 1;
        } else {
            frequencyMap[userInput[counter]] = 1;
        }
    }
    return frequencyMap;
}

//Tested
bool isVectorSorted(vector<int> userInput) {
    if(userInput.size() == 0 || userInput.size() == 1) {
        return true;
    }
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] < userInput[counter-1]) {
            return false;
        }
    }
    return true;
}

//Tested
bool areIVectorsEquivalent(vector<int> firstVector,vector<int> secondVector) {
    if(firstVector.size() != secondVector.size()) {
        return false;
    }
    for(unsigned int counter = 0; counter < firstVector.size(); counter++) {
        if(firstVector[counter] != secondVector[counter]) {
            return false;
        }
    }
    return true;
}

//Tested
void reverseArray(vector<int> &userInput,unsigned int startIndex = 0,unsigned int endIndex = 0) {
    if(endIndex == 0) {
        endIndex = userInput.size()-1;
    }
    while(startIndex < endIndex) {
        swap(userInput[startIndex],userInput[endIndex]);
        startIndex++;
        endIndex--;
    }
}

unsigned int uMinValueVector(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    unsigned int minValue = UINT_MAX;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] < minValue) {
            minValue = userInput[counter];
        }
    }
    return minValue;
}

int sumVector(vector<int> userInput,int currentIndex = 0) {
    if(currentIndex >= userInput.size()) {
        return 0;
    }
    return userInput[currentIndex] + sumVector(userInput,currentIndex+1);
}

#endif /* ARRAYUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
