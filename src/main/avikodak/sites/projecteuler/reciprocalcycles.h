/****************************************************************************************************************************************************
 *  File Name                   : reciprocalcycles.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\reciprocalcycles.h
 *  Created on                  : Aug 27, 2015 :: 12:07:10 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=26
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

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef RECIPROCALCYCLES_H_
#define RECIPROCALCYCLES_H_

//Tested
unsigned int getReciprocalLength(unsigned int userInput) {
    map<unsigned int,bool> visitedRemainders;
    vector<unsigned int> visitedRemaindersList;
    unsigned int numerator = 1,remainder;
    while((remainder = numerator%userInput) != 0) {
        if(visitedRemainders.find(remainder) != visitedRemainders.end()) {
            unsigned int counter;
            for(counter = 0; counter < visitedRemaindersList.size(); counter++) {
                if(visitedRemaindersList[counter] == remainder) {
                    break;
                }
            }
            return visitedRemainders.size() - counter;
        }
        visitedRemainders.insert(pair<unsigned int,bool>(remainder,true));
        visitedRemaindersList.push_back(remainder);
        numerator = remainder*10;
    }
    return 0;
}

//Tested
void getLongestReciprocalCycle() {
    unsigned int maxLength = 0,cycleLength,maxLengthValue;
    for(unsigned int counter = 2; counter < 1000; counter++) {
        cycleLength = getReciprocalLength(counter);
        if( maxLength < cycleLength) {
            maxLength =cycleLength;
            maxLengthValue = counter;
        }
    }
    cout << maxLengthValue << endl;
}

#endif /* RECIPROCALCYCLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
