/****************************************************************************************************************************************************
 *  File Name                   : triangularnumber.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/triangularnumber.h
 *  Created on                  : Jul 16, 2016 :: 10:04:00 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=517
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRIANGULARNUMBER_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRIANGULARNUMBER_H_

//Tested
bool isTriangularNumber(long long int userInput) {
    if (userInput < 0) {
        return false;
    }
    long long int c = (-2 * userInput), b = 1, a = 1;
    long long int discriminate = (b * b) - (4 * a * c);
    if (discriminate < 0) {
        return false;
    }
    float firstRoot = (-b + sqrt(discriminate)) / (2 * a);
    float secondRoot = (-b - sqrt(discriminate)) / (2 * a);
    if (firstRoot > 0 && floor(firstRoot) == firstRoot) {
        return true;
    }
    if (secondRoot > 0 && floor(secondRoot) == secondRoot) {
        return true;
    }
    return false;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int input;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &input);
        printf("%d\n", isTriangularNumber(input) ? 1 : 0);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRIANGULARNUMBER_H_ */
