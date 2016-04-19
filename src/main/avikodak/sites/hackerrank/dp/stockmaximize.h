/****************************************************************************************************************************************************
 *  File Name                   : stockmaximize.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\dp\stockmaximize.h
 *  Created on                  : Aug 2, 2015 :: 11:48:42 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/stockmax
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

#ifndef STOCKMAXIMIZE_H_
#define STOCKMAXIMIZE_H_

//Tested
unsigned int getMaxStock(vector<unsigned int> userInput) {
    unsigned int maxIndex = userInput.size()-1;
    unsigned int totalProfit = 0,cummulativeProfit = 0,shareCount = 0;
    for(int counter = userInput.size()-2; counter >= 0; counter--) {
        if(userInput[counter] > userInput[maxIndex]) {
            if(cummulativeProfit != 0) {
                totalProfit += (shareCount*userInput[maxIndex]) - cummulativeProfit;
            }
            maxIndex = counter;
            cummulativeProfit = 0;
            shareCount = 0;
        } else {
            cummulativeProfit += userInput[counter];
            shareCount++;
        }
    }
    if(maxIndex != 0 && cummulativeProfit != 0) {
        totalProfit += (shareCount*userInput[maxIndex]) - cummulativeProfit;
    }
    return totalProfit;
}

//Tested
void printMaximizeStocks() {
    unsigned int testCases,inputSize,input;
    scanf("%u",&testCases);
    vector<unsigned int> userInput;
    while(testCases--) {
        scanf("%u",&inputSize);
        userInput.clear();
        while(inputSize--) {
            scanf("%u",&input);
            userInput.push_back(input);
        }
        cout << getMaxStock(userInput) << endl;
    }
}

#endif /* STOCKMAXIMIZE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
