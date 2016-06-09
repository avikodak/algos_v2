/****************************************************************************************************************************************************
 *  File Name                   : pascaltriangle.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/pascaltriangle.h
 *  Created on                  : Jun 10, 2016 :: 12:01:31 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=123
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PASCALTRIANGLE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PASCALTRIANGLE_H_

//Tested
void solveProblem() {
    unsigned int testCases, rowRequired;
    vector<long long int> currentPascalRow, nextPascalRow;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &rowRequired);
        if (rowRequired == 1) {
            printf("1\n");
        } else {
            rowRequired--;
            currentPascalRow.clear();
            for (unsigned int outerCounter = 0; outerCounter < rowRequired; outerCounter++) {
                nextPascalRow.clear();
                nextPascalRow.push_back(1);
                for (unsigned int innerCounter = 1; innerCounter < currentPascalRow.size(); innerCounter++) {
                    nextPascalRow.push_back(currentPascalRow[innerCounter] + currentPascalRow[innerCounter - 1]);
                }
                nextPascalRow.push_back(1);
                currentPascalRow = nextPascalRow;
            }
            for (unsigned int counter = 0; counter < currentPascalRow.size(); counter++) {
                printf("%lld ", currentPascalRow[counter]);
            }
            printf("\n");
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_PASCALTRIANGLE_H_ */
