/****************************************************************************************************************************************************
 *  File Name                   : checkifrotationispalindrome.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/checkifrotationispalindrome.h
 *  Created on                  : Jun 19, 2016 :: 11:58:25 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=288
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_CHECKIFROTATIONISPALINDROME_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_CHECKIFROTATIONISPALINDROME_H_

//Tested
bool isPalindromeExistsForLength(string userInput, unsigned int requiredLength) {
    if (userInput.size() == 0) {
        return 0;
    }
    bool auxSpace[userInput.size()][userInput.size()];
    memset(auxSpace, false, sizeof(auxSpace));
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter][counter] = true;
        if (counter + 1 < userInput.size()) {
            if (userInput[counter] == userInput[counter + 1]) {
                auxSpace[counter][counter + 1] = true;
                if (requiredLength == 2) {
                    return true;
                }
            }
        }
    }
    for (unsigned int length = 3; length <= userInput.size(); length++) {
        for (unsigned int frontCrawler = 0; frontCrawler < userInput.size() - length + 1; frontCrawler++) {
            unsigned int rearCrawler = frontCrawler + length - 1;
            if (auxSpace[frontCrawler + 1][rearCrawler - 1] && userInput[frontCrawler] == userInput[rearCrawler]) {
                auxSpace[frontCrawler][rearCrawler] = true;
                if (length == requiredLength) {
                    return true;
                }
            }
        }
    }
    return false;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    bool flag;
    string userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> userInput;
        userInput.append(userInput);
        flag = isPalindromeExistsForLength(userInput, userInput.size() / 2);
        printf("%d\n", flag ? 1 : 0);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_CHECKIFROTATIONISPALINDROME_H_ */
