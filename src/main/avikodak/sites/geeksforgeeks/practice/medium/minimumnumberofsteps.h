/****************************************************************************************************************************************************
 *  File Name                   : minimumnumberofsteps.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/minimumnumberofsteps.h
 *  Created on                  : Aug 14, 2016 :: 1:44:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=153
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_MINIMUMNUMBEROFSTEPS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_MINIMUMNUMBEROFSTEPS_H_

//Tested
void solveProblem() {
    unsigned int testCases, size;
    int input, minSteps;
    vector<int> userInput, auxSpace;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        userInput.clear();
        auxSpace.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%d", &input);
            userInput.push_back(input);
            if (counter == 0) {
                auxSpace.push_back(0);
            } else {
                auxSpace.push_back(INT_MAX);
            }
        }
        for (unsigned int outerCounter = 1; outerCounter < size; outerCounter++) {
            minSteps = INT_MAX;
            for (unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
                if (auxSpace[innerCounter] != INT_MAX && innerCounter + userInput[innerCounter] >= outerCounter) {
                    minSteps = min(minSteps, auxSpace[innerCounter] + 1);
                }
            }
            auxSpace[outerCounter] = minSteps;
        }
        printf("%d\n", auxSpace[size - 1] == INT_MAX ? -1 : auxSpace[size - 1]);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_MINIMUMNUMBEROFSTEPS_H_ */
