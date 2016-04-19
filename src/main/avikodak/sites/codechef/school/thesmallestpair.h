/****************************************************************************************************************************************************
 *  File Name                   : thesmallestpair.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\thesmallestpair.h
 *  Created on                  : Aug 24, 2015 :: 8:28:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SMPAIR
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

#ifndef THESMALLESTPAIR_H_
#define THESMALLESTPAIR_H_

//Tested
void printTheSmallestPairSum(vector<unsigned int> userInput) {
    unsigned int smallestSum = UINT_MAX,runningMin = userInput[userInput.size()-1];
    for(int counter = userInput.size()-2; counter >= 0; counter--) {
        smallestSum = min(smallestSum,userInput[counter]+runningMin);
        if(runningMin > userInput[counter]) {
            runningMin = userInput[counter];
        }
    }
    cout << smallestSum << endl;
}

//Tested
void getSmallestPairs() {
    unsigned int testCases,input,inputSize;
    scanf("%u",&testCases);
    vector<unsigned int> userInput;
    while(testCases--) {
        userInput.clear();
        scanf("%u",&inputSize);
        while(inputSize--) {
            scanf("%u",&input);
            userInput.push_back(input);
        }
        printTheSmallestPairSum(userInput);
    }
}

#endif /* THESMALLESTPAIR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
