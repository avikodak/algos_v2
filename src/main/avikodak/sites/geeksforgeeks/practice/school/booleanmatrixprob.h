/****************************************************************************************************************************************************
 *  File Name                   : booleanmatrixprob.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/school/booleanmatrixprob.h
 *  Created on                  : Jun 5, 2016 :: 8:39:39 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=478
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_BOOLEANMATRIXPROB_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_BOOLEANMATRIXPROB_H_

//Tested
void solveProblem() {
    unsigned int testCases, rowSize, columnSize;
    int input;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %u", &rowSize, &columnSize);
        vector<vector<bool> > userInput(rowSize);
        bool rowSetFlag = false, columnSetFlag = false;
        for (unsigned int rowCounter = 0; rowCounter < rowSize; rowCounter++) {
            for (unsigned int columnCounter = 0; columnCounter < columnSize; columnCounter++) {
                scanf("%d", &input);
                userInput[rowCounter].push_back((bool) input);
            }
        }
        for (unsigned int rowCounter = 0; rowCounter < rowSize; rowCounter++) {
            if (userInput[rowCounter][0]) {
                columnSetFlag = true;
                break;
            }
        }
        for (unsigned int columnCounter = 0; columnCounter < columnSize; columnCounter++) {
            if (userInput[0][columnCounter]) {
                rowSetFlag = true;
                break;
            }
        }
        for (unsigned int rowCounter = 1; rowCounter < rowSize; rowCounter++) {
            for (unsigned int columnCounter = 1; columnCounter < columnSize; columnCounter++) {
                userInput[0][columnCounter] = userInput[0][columnCounter] || userInput[rowCounter][columnCounter];
                userInput[rowCounter][0] = userInput[rowCounter][0] || userInput[rowCounter][columnCounter];
            }
        }
        for (unsigned int rowCounter = 1; rowCounter < rowSize; rowCounter++) {
            for (unsigned int columnCounter = 1; columnCounter < columnSize; columnCounter++) {
                userInput[rowCounter][columnCounter] = userInput[0][columnCounter] || userInput[rowCounter][0];
            }
        }
        if (rowSetFlag) {
            for (unsigned int columnCounter = 0; columnCounter < columnSize; columnCounter++) {
                userInput[0][columnCounter] = true;
            }
        }
        if (columnSetFlag) {
            for (unsigned int rowCounter = 0; rowCounter < rowSize; rowCounter++) {
                userInput[rowCounter][0] = true;
            }
        }
        for (unsigned int rowCounter = 0; rowCounter < rowSize; rowCounter++) {
            for (unsigned int columnCounter = 0; columnCounter < columnSize; columnCounter++) {
                printf("%d ", userInput[rowCounter][columnCounter] ? 1 : 0);
            }
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_BOOLEANMATRIXPROB_H_ */
