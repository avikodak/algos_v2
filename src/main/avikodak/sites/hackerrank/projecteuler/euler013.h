/****************************************************************************************************************************************************
 *  File Name                   : euler013.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\projecteuler\euler013.h
 *  Created on                  : Jul 26, 2015 :: 1:18:18 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/contests/projecteuler/challenges/euler013
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

#ifndef EULER013_H_
#define EULER013_H_

//Tested
vector<unsigned int> convertToDigits(string userInput) {
    vector<unsigned int> number;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        number.push_back(userInput[counter]-'0');
    }
    return number;
}

//Tested
void getSumOfNumbers(vector<vector<unsigned int> > userInputs) {
    vector<unsigned int> result;
    if(userInputs.size() == 0) {
        return;
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
    for(unsigned int counter = 0; counter < 10; counter++) {
        cout << result[counter];
    }
    cout << endl;
}

#endif /* EULER013_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
