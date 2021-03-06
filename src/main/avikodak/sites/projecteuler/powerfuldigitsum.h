/****************************************************************************************************************************************************
 *  File Name                   : powerfuldigitsum.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\powerfuldigitsum.h
 *  Created on                  : Jul 31, 2015 :: 2:42:22 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=56
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

#ifndef POWERFULDIGITSUM_H_
#define POWERFULDIGITSUM_H_

//Tested
unsigned int getSumOfDigits(vector<unsigned int> userInput) {
    unsigned int sum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sum += userInput[counter];
    }
    return sum;
}

//Tested
vector<unsigned int> getUINTInVector(unsigned int number) {
    vector<unsigned int> userInput;
    while(number) {
        userInput.push_back(number%10);
        number /=10;
    }
    reverse(userInput.begin(),userInput.end());
    return userInput;
}

//Tested
vector<unsigned int> sum(vector<vector<unsigned int> > userInputs) {
    vector<unsigned int> result;
    if(userInputs.size() == 0) {
        return result;
    }
    reverse(userInputs[0].begin(),userInputs[0].end());
    result = userInputs[0];
    unsigned int firstCrawler,secondCrawler,sum = 0,carry =0;
    for(unsigned int counter = 1; counter < userInputs.size(); counter++) {
        reverse(userInputs[counter].begin(),userInputs[counter].end());
        firstCrawler = secondCrawler = carry = 0;
        while(firstCrawler < result.size() && secondCrawler < userInputs[counter].size()) {
            sum = result[firstCrawler] + userInputs[counter][secondCrawler] + carry;
            result[firstCrawler] = sum%10;
            firstCrawler++;
            secondCrawler++;
            carry = sum/10;
        }
        while(firstCrawler < result.size()) {
            sum = result[firstCrawler] + carry;
            result[firstCrawler] = sum%10;
            carry = sum/10;
            firstCrawler++;
        }
        while(secondCrawler < userInputs[counter].size()) {
            sum = userInputs[counter][secondCrawler] + carry;
            result.push_back(sum%10);
            carry = sum/10;
            secondCrawler++;
        }
        while(carry) {
            result.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

//Tested
vector<unsigned int> multiply(vector<unsigned int> userInput,unsigned int digit) {
    vector<unsigned int> result;
    reverse(userInput.begin(),userInput.end());
    unsigned int carry = 0,product;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        product = userInput[counter] * digit + carry;
        result.push_back(product%10);
        carry = product/10;
    }
    while(carry) {
        result.push_back(carry%10);
        carry /= 10;
    }
    reverse(result.begin(),result.end());
    return result;
}

//Tested
vector<unsigned int> multiply(vector<unsigned int> firstUserInput,vector<unsigned int> secondUserInput) {
    reverse(secondUserInput.begin(),secondUserInput.end());
    vector<unsigned int> result,temp;
    vector<vector<unsigned int> > input;
    for(unsigned int outerCounter = 0; outerCounter < secondUserInput.size(); outerCounter++) {
        temp = multiply(firstUserInput,secondUserInput[outerCounter]);
        if(result.size() == 0) {
            result = temp;
        } else {
            for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
                temp.push_back(0);
            }
            input.clear();
            input.push_back(result);
            input.push_back(temp);
            result = sum(input);
        }
    }
    return result;
}

//Tested
vector<unsigned int> largepow(unsigned int base,unsigned int power) {
    vector<unsigned int> number = getUINTInVector(base);
    vector<unsigned int> result = number;
    for(unsigned int counter = 2; counter <= power; counter++) {
        result = multiply(result,number);
    }
    return result;
}

//Tested
//Ans : 972
void maxSumDigits() {
    unsigned int maxSum = 0;
    for(unsigned int outerCounter = 2; outerCounter < 100; outerCounter++) {
        for(unsigned int innerCounter = 1; innerCounter < 100; innerCounter++) {
            maxSum = max(maxSum,getSumOfDigits(largepow(outerCounter,innerCounter)));
        }
    }
    cout << maxSum << endl;
}

#endif /* POWERFULDIGITSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
