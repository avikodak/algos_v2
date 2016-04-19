/****************************************************************************************************************************************************
 *  File Name                   : combinatoricselections.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\combinatoricselections.h
 *  Created on                  : Aug 17, 2015 :: 9:38:18 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=53
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/
#define MILLION_MARKER 1000000

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef COMBINATORICSELECTIONS_H_
#define COMBINATORICSELECTIONS_H_

//Tested
//Ans : 4075
void getCombinationsUnderMillion() {
    unsigned int total = 0,currentSum;
    unsigned int innerCounter;
    vector<unsigned int> prevValues;
    vector<unsigned int> currentValues;
    prevValues.push_back(1);
    prevValues.push_back(2);
    prevValues.push_back(1);
    for(unsigned int outerCounter = 3; outerCounter <= 100; outerCounter++) {
        currentValues.clear();
        currentValues.push_back(1);
        for(innerCounter = 0; innerCounter < prevValues.size()-1; innerCounter++) {
            if(prevValues[innerCounter] == MILLION_MARKER || prevValues[innerCounter+1] == MILLION_MARKER) {
                total++;
                currentValues.push_back(MILLION_MARKER);
            } else {
                currentSum = prevValues[innerCounter] + prevValues[innerCounter+1];
                if(currentSum < MILLION_MARKER) {
                    currentValues.push_back(currentSum);
                } else {
                    total++;
                    currentValues.push_back(MILLION_MARKER);
                }
            }
        }
        currentValues.push_back(1);
        prevValues = currentValues;
    }
    cout << total << endl;
}

#endif /* COMBINATORICSELECTIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
