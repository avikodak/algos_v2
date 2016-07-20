/****************************************************************************************************************************************************
 *  File Name                   : palindromenumbers.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/palindromenumbers.h
 *  Created on                  : Jun 7, 2016 :: 11:59:16 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=151
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PALINDROMENUMBERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PALINDROMENUMBERS_H_

//Tested
string convertToBinary(long long unsigned int userInput) {
    string userInputInBinary;
    if (userInput == 0) {
        userInputInBinary.append("0");
        return userInputInBinary;
    }
    char ch;
    while (userInput) {
        ch = '0' + (userInput % 2);
        userInputInBinary.push_back(ch);
        userInput /= 2;
    }
    return userInputInBinary;
}

//Tested
void solveProblem() {
    unsigned int testCases, frontCrawler, rearCrawler;
    long long unsigned int input;
    string inputInBinary;
    bool isPalindrome;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%llu", &input);
        inputInBinary = convertToBinary(input);
        isPalindrome = true;
        frontCrawler = 0;
        rearCrawler = inputInBinary.size() - 1;
        while (frontCrawler < rearCrawler) {
            if (inputInBinary[frontCrawler] != inputInBinary[rearCrawler]) {
                isPalindrome = false;
                break;
            }
            frontCrawler++;
            rearCrawler--;
        }
        printf("%d\n", isPalindrome ? 1 : 0);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PALINDROMENUMBERS_H_ */
