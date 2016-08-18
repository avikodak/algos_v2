/****************************************************************************************************************************************************
 *  File Name                   : numberofoccurence.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/numberofoccurence.h
 *  Created on                  : Aug 9, 2016 :: 10:32:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=577
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_NUMBEROFOCCURENCE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_NUMBEROFOCCURENCE_H_

//Worked locally
int getLowerBound(vector<long long int> userInput, long long int key, int lowerIndex, int upperIndex) {
    if (lowerIndex > upperIndex) {
        return -1;
    }
    if (userInput[lowerIndex] == key) {
        return lowerIndex;
    }
    int middleIndex = (lowerIndex + upperIndex) / 2;
    if (userInput[middleIndex] == key) {
        if (userInput[middleIndex - 1] == key) {
            return getLowerBound(userInput, key, lowerIndex, middleIndex - 1);
        } else {
            return middleIndex;
        }
    } else if (userInput[middleIndex] < key) {
        return getLowerBound(userInput, key, middleIndex + 1, upperIndex);
    } else {
        return getLowerBound(userInput, key, lowerIndex, middleIndex - 1);
    }
}

//Worked locally
int getUpperBound(vector<long long int> userInput, long long int key, int lowerIndex, int upperIndex) {
    if (lowerIndex > upperIndex) {
        return -1;
    }
    if (userInput[upperIndex] == key) {
        return upperIndex;
    }
    int middleIndex = (lowerIndex + upperIndex) / 2;
    if (userInput[middleIndex] == key) {
        if (userInput[middleIndex + 1] == key) {
            return getUpperBound(userInput, key, middleIndex + 1, upperIndex);
        } else {
            return middleIndex;
        }
    } else if (userInput[middleIndex] < key) {
        return getUpperBound(userInput, key, middleIndex + 1, upperIndex);
    } else {
        return getUpperBound(userInput, key, lowerIndex, middleIndex - 1);
    }
}

//Worked locally
void solveProblemByBinarySearch() {
    unsigned int testCases, size;
    long long int input, key;
    vector<long long int> userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %lld", &size, &key);
        userInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        int lowIndex = getLowerBound(userInput, key, 0, userInput.size() - 1);
        printf("%d\n", lowIndex);
    }
}

//No Need To Store
void solveProblem() {
    unsigned int testCases, size;
    long long int input, key, count;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u %lld", &size, &key);
        count = 0;
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            if (input == key) {
                count++;
            }
        }
        printf("%lld\n", count == 0 ? -1 : count);
    }
}
#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_NUMBEROFOCCURENCE_H_ */
