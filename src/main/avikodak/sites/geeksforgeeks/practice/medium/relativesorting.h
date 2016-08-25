/****************************************************************************************************************************************************
 *  File Name                   : relativesorting.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/relativesorting.h
 *  Created on                  : Aug 14, 2016 :: 6:17:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=434
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_RELATIVESORTING_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_RELATIVESORTING_H_

//Tested
void solveProblem() {
    unsigned int testCases, fSize, sSize;
    long long int input, frequency;
    vector<long long int> fUserInput, sUserInput, toBeSorted;
    map<long long int, long long int> fFrequency, sFrequency;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &fSize, &sSize);
        fUserInput.clear();
        sUserInput.clear();
        fFrequency.clear();
        sFrequency.clear();
        toBeSorted.clear();
        for (unsigned int counter = 0; counter < fSize; counter++) {
            scanf("%lld", &input);
            fUserInput.push_back(input);
            if (fFrequency.find(input) == fFrequency.end()) {
                fFrequency.insert(pair<long long int, long long int>(input, 1));
            } else {
                fFrequency[input]++;
            }
        }
        for (unsigned int counter = 0; counter < sSize; counter++) {
            scanf("%lld", &input);
            sUserInput.push_back(input);
            sFrequency[input] = 1;
        }
        for (unsigned int counter = 0; counter < sSize; counter++) {
            if (fFrequency.find(sUserInput[counter]) != fFrequency.end()) {
                frequency = fFrequency[sUserInput[counter]];
                while (frequency--) {
                    printf("%lld ", sUserInput[counter]);
                }
            }
        }
        for (unsigned int counter = 0; counter < fSize; counter++) {
            if (sFrequency.find(fUserInput[counter]) == sFrequency.end()) {
                toBeSorted.push_back(fUserInput[counter]);
            }
        }
        sort(toBeSorted.begin(), toBeSorted.end());
        for (unsigned int counter = 0; counter < toBeSorted.size(); counter++) {
            printf("%lld ", toBeSorted[counter]);
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_RELATIVESORTING_H_ */
