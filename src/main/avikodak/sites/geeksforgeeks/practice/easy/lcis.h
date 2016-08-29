/****************************************************************************************************************************************************
 *  File Name                   : lcis.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/lcis.h
 *  Created on                  : Aug 27, 2016 :: 7:11:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=913
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LCIS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LCIS_H_

//Tested
long long int longestCommonIncreasingSequence(vector<long long int> firstUserInput, unsigned int fSize, vector<long long int> secondUserInput, unsigned int sSize) {
    long long int auxSpace[sSize], maxCommonIncSize = 0, currentMaxSize;
    memset(auxSpace, 0, sSize * sizeof(long long int));
    for (unsigned int outerCounter = 0; outerCounter < fSize; outerCounter++) {
        currentMaxSize = 0;
        for (unsigned int innerCounter = 0; innerCounter < sSize; innerCounter++) {
            if (firstUserInput[outerCounter] == secondUserInput[innerCounter]) {
                auxSpace[innerCounter] = max(auxSpace[innerCounter], currentMaxSize + 1);
            }
            if (firstUserInput[outerCounter] > secondUserInput[innerCounter]) {
                currentMaxSize = max(currentMaxSize, auxSpace[innerCounter]);
            }
        }
    }
    for (unsigned int crawler = 0; crawler < sSize; crawler++) {
        maxCommonIncSize = max(maxCommonIncSize, auxSpace[crawler]);
    }
    return maxCommonIncSize;
}

//Tested
void solveProblem() {
    unsigned int testCases, fSize, sSize;
    long long int input;
    vector<long long int> firstUserInput, secondUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &fSize);
        firstUserInput.clear();
        for (unsigned int counter = 0; counter < fSize; counter++) {
            scanf("%lld", &input);
            firstUserInput.push_back(input);
        }
        scanf("%u", &sSize);
        secondUserInput.clear();
        for (unsigned int counter = 0; counter < sSize; counter++) {
            scanf("%lld", &input);
            secondUserInput.push_back(input);
        }
        printf("%lld\n", longestCommonIncreasingSequence(firstUserInput, fSize, secondUserInput, sSize));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_LCIS_H_ */
