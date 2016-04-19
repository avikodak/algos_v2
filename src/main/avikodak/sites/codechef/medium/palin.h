/****************************************************************************************************************************************************
 *  File Name                   : palin.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\medium\palin.h
 *  Created on                  : Aug 29, 2015 :: 8:47:56 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/PALIN
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

#ifndef PALIN_H_
#define PALIN_H_

bool reverseUInt(unsigned long long int userInput) {
    unsigned int reverse = 0;
    while(userInput) {
        reverse *= 10;
        reverse += userInput%10;
        userInput /= 10;
    }
    return reverse;
}

bool isPalindrome(unsigned long long int userInput) {
    return reverseUInt(userInput) == userInput;
}

vector<unsigned long long int> getPalindromes(unsigned long long int limit = 1000000) {
    vector<unsigned long long int> palindromes;
    for(unsigned int counter = 1; counter <= limit; counter++) {
        if(isPalindrome(counter)) {
            palindromes.push_back(counter);
        }
    }
    return palindromes;
}

void printResults() {
    vector<unsigned long long int> palindromes = getPalindromes(1111111);
    unsigned int testCases;
    scanf("%u",&testCases);
    unsigned long long int userInput;
    while(testCases--) {
        cin >> userInput;
        cout << palindromes[upper_bound(palindromes.begin(),palindromes.end(),userInput) - palindromes.begin()] << endl;
    }
}

#endif /* PALIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
