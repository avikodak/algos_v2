/****************************************************************************************************************************************************
 *  File Name                   : sortingelementsbyfreq.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/hard/sortingelementsbyfreq.h
 *  Created on                  : Jul 3, 2016 :: 5:38:50 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=493
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_SORTINGELEMENTSBYFREQ_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_SORTINGELEMENTSBYFREQ_H_

//Tested
struct valFrequency {
    int value;
    unsigned int frequency;

    valFrequency() {
        value = 0;
        frequency = 0;
    }

    valFrequency(int value) {
        this->value = value;
        this->frequency = 0;
    }
};

//Tested
bool sortFunc(valFrequency *first, valFrequency *second) {
    if (first->frequency == second->frequency) {
        return first->value < second->value;
    } else {
        return first->frequency > second->frequency;
    }
}

//Tested
void solveProblem() {
    unsigned int testCases, size;
    int input;
    vector<valFrequency *> frequencyMap;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        frequencyMap.clear();
        for (unsigned int counter = 1; counter <= 60; counter++) {
            frequencyMap.push_back(new valFrequency(counter));
        }
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%d", &input);
            frequencyMap[input - 1]->frequency++;
        }
        sort(frequencyMap.begin(), frequencyMap.end(), sortFunc);
        for (unsigned int counter = 0; counter < 60; counter++) {
            if (frequencyMap[counter]->frequency > 0) {
                while (frequencyMap[counter]->frequency--) {
                    printf("%d ", frequencyMap[counter]->value);
                }
            }
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_SORTINGELEMENTSBYFREQ_H_ */
