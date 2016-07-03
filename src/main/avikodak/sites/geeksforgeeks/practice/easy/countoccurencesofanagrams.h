/****************************************************************************************************************************************************
 *  File Name                   : countoccurencesofanagrams.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/countoccurencesofanagrams.h
 *  Created on                  : Jul 3, 2016 :: 9:45:45 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=259
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_COUNTOCCURENCESOFANAGRAMS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_COUNTOCCURENCESOFANAGRAMS_H_

//Tested
bool areFrequenciesEqual(unsigned int *patternFrequency, unsigned int *currentTextFrequency) {
    for (unsigned int counter = 0; counter < 26; counter++) {
        if (patternFrequency[counter] != currentTextFrequency[counter]) {
            return false;
        }
    }
    return true;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    string userInput, pattern;
    unsigned int totalCount;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> userInput >> pattern;
        if (userInput.size() < pattern.size()) {
            printf("0\n");
        } else {
            totalCount = 0;
            unsigned int patternFrequency[26] = { 0 }, currentTextFrequency[26] = { 0 };
            for (unsigned int counter = 0; counter < pattern.size(); counter++) {
                patternFrequency[pattern[counter] - 'a']++;
            }
            for (unsigned int counter = 0; counter < pattern.size(); counter++) {
                currentTextFrequency[userInput[counter] - 'a']++;
            }
            if (areFrequenciesEqual(patternFrequency, currentTextFrequency)) {
                totalCount++;
            }
            for (unsigned int counter = pattern.size(); counter < userInput.size(); counter++) {
                currentTextFrequency[userInput[counter] - 'a']++;
                currentTextFrequency[userInput[counter - pattern.size()] - 'a']--;
                if (areFrequenciesEqual(patternFrequency, currentTextFrequency)) {
                    totalCount++;
                }
            }
            printf("%u\n", totalCount);
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_COUNTOCCURENCESOFANAGRAMS_H_ */
