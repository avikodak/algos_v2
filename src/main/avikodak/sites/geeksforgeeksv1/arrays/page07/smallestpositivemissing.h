/****************************************************************************************************************************************************
 *  File Name                   : smallestpositivemissing.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\smallestpositivemissing.h
 *  Created on                  : Jan 2, 2015 :: 12:33:01 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SMALLESTPOSITIVEMISSING_H_
#define SMALLESTPOSITIVEMISSING_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int segregatePositiveNegativeNumbers(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return INT_MIN;
    }
    int firstCrawler = 0,secondCrawler = userInput.size()-1;
    while(firstCrawler < secondCrawler) {
        while(firstCrawler < secondCrawler && userInput[firstCrawler] < 0) {
            firstCrawler++;
        }
        while(firstCrawler < secondCrawler && userInput[secondCrawler] >= 0) {
            secondCrawler--;
        }
        if(firstCrawler < secondCrawler) {
            swap(userInput[firstCrawler],userInput[secondCrawler]);
        }
    }
    return secondCrawler;
}

//Tested
int smallestPositiveNumberMissingON(vector<int> userInput) {
    if(userInput.size() < 2) {
        return INT_MIN;
    }
    unsigned int positiveNumberIndex = segregatePositiveNegativeNumbers(userInput);
    for(unsigned int counter = positiveNumberIndex; counter < userInput.size(); counter++) {
        if(abs(userInput[counter])+positiveNumberIndex-1 < userInput.size()) {
            userInput[abs(userInput[counter])+positiveNumberIndex-1] *= -1;
        }
    }
    for(unsigned int counter = positiveNumberIndex; counter < userInput.size(); counter++) {
        if(userInput[counter] > 0) {
            return counter - positiveNumberIndex + 1;
        }
    }
    return userInput.size() - positiveNumberIndex + 1;
}

//Tested
int smallestPositiveNumbersHashmap(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    hash_map<int,bool> frequencyMap;
    hash_map<int,bool>::iterator itToFrequencyMap;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] > 0) {
            frequencyMap.insert(pair<int,unsigned int>(userInput[counter],true));
        }
    }
    for(unsigned int counter = 1; counter < userInput.size()+1; counter++) {
        if(frequencyMap.find(counter) == frequencyMap.end()) {
            return counter;
        }
    }
    return userInput.size()+1;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int smallestPositiveNumberMissingONLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    sort(userInput.begin(),userInput.end());
    unsigned int counter = 0;
    while(counter < userInput.size() && userInput[counter] <= 0) {
        counter++;
    }
    if(counter >= userInput.size()) {
        return 1;
    }
    int numbCounter = 1;
    while(counter < userInput.size() && userInput[counter] == numbCounter) {
        counter++;
        numbCounter++;
    }
    return numbCounter;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int smallestPositiveNumberMissingON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 1;
    }
    unsigned int innerCounter = 0;
    for(unsigned int outerCounter = 1; outerCounter <= userInput.size()+1; outerCounter++) {
        for(innerCounter = 0; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[innerCounter] == (int)outerCounter) {
                break;
            }
        }
        if(innerCounter >=  userInput.size()) {
            return outerCounter;
        }
    }
    return INT_MAX;
}

#endif /* SMALLESTPOSITIVEMISSING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
