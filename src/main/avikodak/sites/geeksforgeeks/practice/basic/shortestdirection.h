/****************************************************************************************************************************************************
 *  File Name                   : shortestdirection.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/shortestdirection.h
 *  Created on                  : Aug 2, 2016 :: 7:26:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=821
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SHORTESTDIRECTION_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SHORTESTDIRECTION_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int temp;
    string userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        long long int frequencyCount[4] = { 0 };
        cin >> userInput;
        for (unsigned int counter = 0; counter < userInput.size(); counter++) {
            switch (userInput[counter]) {
                case 'N':
                    frequencyCount[0]++;
                    break;
                case 'S':
                    frequencyCount[1]++;
                    break;
                case 'E':
                    frequencyCount[2]++;
                    break;
                case 'W':
                    frequencyCount[3]++;
                    break;
            }
        }
        temp = frequencyCount[0];
        frequencyCount[0] = frequencyCount[0] - frequencyCount[1];
        frequencyCount[1] = frequencyCount[1] - temp;
        temp = frequencyCount[2];
        frequencyCount[2] = frequencyCount[2] - frequencyCount[3];
        frequencyCount[3] = frequencyCount[3] - temp;
        while (frequencyCount[2] > 0) {
            printf("E");
            frequencyCount[2]--;
        }
        while (frequencyCount[0] > 0) {
            printf("N");
            frequencyCount[0]--;
        }
        while (frequencyCount[1] > 0) {
            printf("S");
            frequencyCount[1]--;
        }
        while (frequencyCount[3] > 0) {
            printf("W");
            frequencyCount[3]--;
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_SHORTESTDIRECTION_H_ */
