/****************************************************************************************************************************************************
 *  File Name                   : maxcollatzsequencelength.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/maxcollatzsequencelength.h
 *  Created on                  : Aug 30, 2016 :: 12:07:22 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=837
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXCOLLATZSEQUENCELENGTH_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXCOLLATZSEQUENCELENGTH_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int input, length, maxLength = 0, crawler;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &input);
        maxLength = 0;
        long long int auxSpace[input + 1];
        for (long long int counter = 1; counter <= input; counter++) {
            length = 1;
            crawler = counter;
            while (crawler != 1) {
                if (crawler < counter) {
                    length += (auxSpace[crawler] - 1);
                    break;
                }
                if (crawler & 1) {
                    crawler = 3 * crawler + 1;
                } else {
                    crawler /= 2;
                }
                length++;
            }
            auxSpace[counter] = length;
            maxLength = max(maxLength, auxSpace[counter]);
        }
        printf("%lld\n", maxLength);
    }
}

//Tested Locally
void solveProblemV2() {
    unsigned int testCases;
    long long int input, length, maxLength = 0, crawler;
    map<long long int, long long int> auxSpace;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &input);
        maxLength = 0;
        for (long long int counter = 1; counter <= input; counter++) {
            if (auxSpace.find(counter) != auxSpace.end()) {
                length = auxSpace[counter];
            } else {
                length = 1;
                crawler = counter;
                while (crawler != 1) {
                    if (auxSpace.find(counter) != auxSpace.end()) {
                        length += auxSpace[counter];
                        break;
                    }
                    if (crawler & 1) {
                        crawler = 3 * crawler + 1;
                    } else {
                        crawler /= 2;
                    }
                    length++;
                }
                auxSpace[crawler] = length;
            }
            maxLength = max(maxLength, length);
        }
        printf("%lld\n", maxLength);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MAXCOLLATZSEQUENCELENGTH_H_ */
