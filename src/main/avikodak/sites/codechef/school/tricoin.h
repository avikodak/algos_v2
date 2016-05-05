/****************************************************************************************************************************************************
 *  File Name                   : tricoin.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/school/tricoin.h
 *  Created on                  : May 5, 2016 :: 8:02:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/TRICOIN
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_SCHOOL_TRICOIN_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_SCHOOL_TRICOIN_H_

//Tested
int getLowerIndex(vector<long long int> userInput, int key, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return -1;
    }
    if (userInput[startIndex] >= key) {
        return startIndex;
    }
    int middleIndex = (startIndex + endIndex) / 2;
    if (userInput[middleIndex] == key) {
        return middleIndex;
    } else if (userInput[middleIndex] > key) {
        if (middleIndex - 1 >= startIndex && userInput[middleIndex - 1] < key) {
            return middleIndex - 1;
        } else {
            return getLowerIndex(userInput, key, startIndex, middleIndex - 1);
        }
    } else {
        if (middleIndex + 1 <= endIndex && userInput[middleIndex + 1] > key) {
            return middleIndex;
        } else {
            return getLowerIndex(userInput, key, middleIndex + 1, endIndex);
        }
    }
}

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int input, currentValue = 1, currentIndex = 1;
    vector<long long int> auxSpace;
    auxSpace.push_back(1);
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &input);
        if (input == auxSpace[auxSpace.size() - 1]) {
            cout << auxSpace.size() << endl;
        } else if (input < auxSpace[auxSpace.size() - 1]) {
            cout << getLowerIndex(auxSpace, input, 0, auxSpace.size() - 1) + 1 << endl;
        } else {
            currentIndex = auxSpace.size();
            currentValue = auxSpace[currentIndex - 1];
            while (currentValue <= input) {
                currentIndex++;
                currentValue += currentIndex;
                auxSpace.push_back(currentValue);
            }
            if (auxSpace[auxSpace.size() - 1] == input) {
                cout << auxSpace.size() << endl;
            } else {
                cout << auxSpace.size() - 1 << endl;
            }
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_SCHOOL_TRICOIN_H_ */
