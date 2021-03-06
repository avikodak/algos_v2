/****************************************************************************************************************************************************
 *  File Name                   : parenthesischecker.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/parenthesischecker.h
 *  Created on                  : Jun 25, 2016 :: 9:51:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=147
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PARENTHESISCHECKER_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PARENTHESISCHECKER_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    string userInput;
    scanf("%u", &testCases);
    stack<char> auxSpace;
    while (testCases--) {
        cin >> userInput;
        bool isBalanced = true;
        for (unsigned int counter = 0; counter < userInput.size(); counter++) {
            if (userInput[counter] == '{' || userInput[counter] == '[' || userInput[counter] == '(') {
                auxSpace.push(userInput[counter]);
            } else {
                if(auxSpace.empty()) {
                    isBalanced = false;
                    break;
                }
                if (userInput[counter] == '}') {
                    if (auxSpace.top() != '{') {
                        isBalanced = false;
                        break;
                    }
                } else if (userInput[counter] == ']') {
                    if (auxSpace.top() != '[') {
                        isBalanced = false;
                        break;
                    }
                } else {
                    if (auxSpace.top() != '(') {
                        isBalanced = false;
                        break;
                    }
                }
                auxSpace.pop();
            }
        }
        while (!auxSpace.empty()) {
            auxSpace.pop();
        }
        printf("%s\n", isBalanced ? "balanced" : "not balanced");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PARENTHESISCHECKER_H_ */
