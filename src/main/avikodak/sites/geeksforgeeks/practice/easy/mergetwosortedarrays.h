/****************************************************************************************************************************************************
 *  File Name                   : mergetwosortedarrays.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/mergetwosortedarrays.h
 *  Created on                  : Jun 9, 2016 :: 11:37:42 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=174
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MERGETWOSORTEDARRAYS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MERGETWOSORTEDARRAYS_H_

//Tested
void solveProblem() {
    unsigned int testCases, fSize, sSize, fInputCrawler, sInputCrawler;
    long long int input;
    vector<long long int> fUserInput, sUserInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &fSize, &sSize);
        fUserInput.clear();
        sUserInput.clear();
        for (unsigned int counter = 0; counter < fSize; counter++) {
            scanf("%lld", &input);
            fUserInput.push_back(input);
        }
        for (unsigned int counter = 0; counter < sSize; counter++) {
            scanf("%lld", &input);
            sUserInput.push_back(input);
        }
        fInputCrawler = 0;
        sInputCrawler = 0;
        while (fInputCrawler < fUserInput.size() && sInputCrawler < sUserInput.size()) {
            if (fUserInput[fInputCrawler] > sUserInput[sInputCrawler]) {
                printf("%lld ", fUserInput[fInputCrawler++]);
            } else {
                printf("%lld ", sUserInput[sInputCrawler++]);
            }
        }
        while (fInputCrawler < fUserInput.size()) {
            printf("%lld ", fUserInput[fInputCrawler++]);
        }
        while (sInputCrawler < sUserInput.size()) {
            printf("%lld ", sUserInput[sInputCrawler++]);
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MERGETWOSORTEDARRAYS_H_ */
