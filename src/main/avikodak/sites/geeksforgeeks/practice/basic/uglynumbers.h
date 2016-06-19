/****************************************************************************************************************************************************
 *  File Name                   : uglynumbers.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/uglynumbers.h
 *  Created on                  : Jun 19, 2016 :: 12:59:02 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=553
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    unsigned int input, minValue;
    unsigned int twoIndex = 0, threeIndex = 0, fiveIndex = 0;
    vector<unsigned int> auxSpace;
    auxSpace.push_back(1);
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &input);
        if (input >= auxSpace.size()) {
            while (input >= auxSpace.size()) {
                minValue = min(min(auxSpace[twoIndex] * 2, auxSpace[threeIndex] * 3), auxSpace[fiveIndex] * 5);
                if (auxSpace[auxSpace.size() - 1] != minValue) {
                    auxSpace.push_back(minValue);
                }
                if (minValue == auxSpace[twoIndex] * 2) {
                    twoIndex++;
                } else if (minValue == auxSpace[threeIndex] * 3) {
                    threeIndex++;
                } else {
                    fiveIndex++;
                }
            }
        }
        printf("%u\n", auxSpace[input - 1]);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_ */
