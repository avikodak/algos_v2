/****************************************************************************************************************************************************
 *  File Name                   : factorialdigitsum.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\factorialdigitsum.h
 *  Created on                  : Jul 29, 2015 :: 12:57:52 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=20
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

#ifndef FACTORIALDIGITSUM_H_
#define FACTORIALDIGITSUM_H_

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
long long int getSumOfDigits(vector<unsigned int> userInput) {
    long long int sum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        sum += userInput[counter];
    }
    return sum;
}

//Tested
//Ans : 648
void getFactorialDigitSum() {
    vector<unsigned int> result;
    result.push_back(1);
    for(unsigned int counter = 2; counter <= 100; counter++) {
        result = multiply(result,counter);
    }
    cout << getSumOfDigits(result);
}

#endif /* FACTORIALDIGITSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
