/****************************************************************************************************************************************************
 *  File Name                   : numberofuniquepaths.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/numberofuniquepaths.h
 *  Created on                  : Aug 3, 2016 :: 8:12:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=115
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_NUMBEROFUNIQUEPATHS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_NUMBEROFUNIQUEPATHS_H_

//Tested
void printNumberOfPaths(int rows, int columns) {
    int auxSpace[rows][columns];
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        auxSpace[rowCounter][0] = 1;
    }
    for (int columnCounter = 0; columnCounter < columns; columnCounter++) {
        auxSpace[0][columnCounter] = 1;
    }
    for (int rowCounter = 1; rowCounter < rows; rowCounter++) {
        for (int columnCounter = 1; columnCounter < columns; columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter - 1][columnCounter] + auxSpace[rowCounter][columnCounter - 1];
        }
    }
    printf("%d\n", auxSpace[rows - 1][columns - 1]);
}

//Tested
void solveProblem() {
    unsigned int testCases;
    int rows, columns;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%d %d", &rows, &columns);
        printNumberOfPaths(rows, columns);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_NUMBEROFUNIQUEPATHS_H_ */
