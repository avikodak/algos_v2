/****************************************************************************************************************************************************
 *  File Name                   : stringsstartendone.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\stringsstartendone.h
 *  Created on                  : Jan 5, 2015 :: 1:55:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/given-binary-string-count-number-substrings-start-end-1/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef STRINGSSTARTENDONE_H_
#define STRINGSSTARTENDONE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int countStringsStartEndOnesON(vector<bool> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    int setBitCounter = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter]) {
            setBitCounter++;
        }
    }
    return ((setBitCounter) * (setBitCounter-1))/2;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int stringStartEndOnesON2(vector<bool> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    int totalStrings = 0;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        if(userInput[outerCounter]) {
            for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
                if(userInput[innerCounter]) {
                    totalStrings++;
                }
            }
        }
    }
    return totalStrings;
}

#endif /* STRINGSSTARTENDONE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
