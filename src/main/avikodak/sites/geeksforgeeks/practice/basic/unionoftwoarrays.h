/****************************************************************************************************************************************************
 *  File Name                   : unionoftwoarrays.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/unionoftwoarrays.h
 *  Created on                  : May 22, 2016 :: 7:09:27 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=537
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UNIONOFTWOARRAYS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UNIONOFTWOARRAYS_H_

//Tested
void solveProblem() {
    unsigned int testCases, fInputSize, sInputSize, fCounter, sCounter;
    long long int input, key;
    vector<long long int> fUserInput, sUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &fInputSize, &sInputSize);
        fUserInput.clear();
        sUserInput.clear();
        for (unsigned int counter = 0; counter < fInputSize; counter++) {
            scanf("%lld", &input);
            fUserInput.push_back(input);
        }
        sort(fUserInput.begin(), fUserInput.end());
        for (unsigned int counter = 0; counter < sInputSize; counter++) {
            scanf("%lld", &input);
            sUserInput.push_back(input);
        }
        sort(sUserInput.begin(), sUserInput.end());
        fCounter = 0;
        sCounter = 0;
        while (fCounter < fUserInput.size() || sCounter < sUserInput.size()) {
            if (fCounter >= fUserInput.size() || sCounter >= sUserInput.size()) {
                if (fCounter < fUserInput.size()) {
                    printf("%lld ", fUserInput[fCounter++]);
                } else {
                    printf("%lld ", sUserInput[sCounter++]);
                }
            } else {
                if (fUserInput[fCounter] == sUserInput[sCounter]) {
                    key = fUserInput[fCounter];
                    printf("%lld ", fUserInput[fCounter]);
                    while (fCounter < fUserInput.size() && fUserInput[fCounter] == key) {
                        fCounter++;
                    }
                    while (sCounter < sUserInput.size() && sUserInput[sCounter] == key) {
                        sCounter++;
                    }
                } else if (fUserInput[fCounter] < sUserInput[sCounter]) {
                    printf("%lld ", fUserInput[fCounter]);
                    fCounter++;
                } else {
                    printf("%lld ", sUserInput[sCounter]);
                    sCounter++;
                }
            }
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UNIONOFTWOARRAYS_H_ */
