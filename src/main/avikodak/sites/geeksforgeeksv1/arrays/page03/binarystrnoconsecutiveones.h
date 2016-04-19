/****************************************************************************************************************************************************
 *  File Name                   : binarystrnoconsecutiveones.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\binarystrnoconsecutiveones.h
 *  Created on                  : Jan 19, 2015 :: 8:47:30 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
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

#ifndef BINARYSTRNOCONSECUTIVEONES_H_
#define BINARYSTRNOCONSECUTIVEONES_H_

int countBinaryStringsByGeneratingSets(vector<bool> userInput,unsigned int nValue) {
    if(nValue == 0) {
        for(unsigned int counter = 0; counter < userInput.size()-1; counter++) {
            if(userInput[counter] && userInput[counter+1]) {
                return 0;
            }
        }
        return userInput.size() == 0?0:1;
    }
    int counter = 0;
    userInput[nValue-1] = false;
    counter += countBinaryStringsByGeneratingSets(userInput,nValue-1);
    userInput[nValue-1] = true;
    return counter + countBinaryStringsByGeneratingSets(userInput,nValue-1);
}

//Tested
int countBinaryStringsNoConsecutiveOnes(unsigned int nValue) {
    if(nValue == 0) {
        return 1;
    }
    vector<int> endingWithZero,endingWithOne;
    endingWithOne.push_back(1);
    endingWithZero.push_back(1);
    for(unsigned int counter = 1; counter < nValue; counter++) {
        endingWithZero.push_back(endingWithZero[counter-1] + endingWithOne[counter-1]);
        endingWithOne.push_back(endingWithZero[counter-1]);
    }
    return endingWithZero[endingWithZero.size()-1] + endingWithOne[endingWithOne.size()-1];
}

#endif /* BINARYSTRNOCONSECUTIVEONES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
