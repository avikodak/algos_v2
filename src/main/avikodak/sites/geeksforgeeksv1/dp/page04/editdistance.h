/****************************************************************************************************************************************************
 *  File Name                   : editdistance.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\editdistance.h
 *  Created on                  : Dec 15, 2014 :: 9:18:43 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
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

#ifndef EDITDISTANCE_H_
#define EDITDISTANCE_H_

//Tested
int minEditsMemoization(char *firstUserInput,char *secondUserInput,int firstLength,int secondLength) {
    if(firstLength == 0 && secondLength == 0) {
        return 0;
    }
    if(firstLength == 0 || secondLength == 0) {
        return firstLength == 0?secondLength:firstLength;
    }
    vector<vector<int> > auxSpace(firstLength+1);
    for(int rowCounter = 0; rowCounter <= firstLength; rowCounter++) {
        auxSpace[rowCounter].assign(secondLength+1,0);
        auxSpace[rowCounter][0] = rowCounter;
    }
    for(int columnCounter = 0; columnCounter <= secondLength; columnCounter++) {
        auxSpace[0][columnCounter] = columnCounter;
    }
    for(int rowCounter = 1; rowCounter <= firstLength; rowCounter++) {
        for(int columnCounter = 1; columnCounter <= secondLength; columnCounter++) {
            if(firstUserInput[rowCounter-1] == secondUserInput[columnCounter-1]) {
                auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter-1];
            } else {
                auxSpace[rowCounter][columnCounter] = 1 + min(auxSpace[rowCounter][columnCounter-1],auxSpace[rowCounter-1][columnCounter],auxSpace[rowCounter-1][columnCounter-1]);
            }
        }
    }
    return auxSpace[firstLength][secondLength];
}

//Tested
int minEdits(char *firstUserInput,char *secondUserInput,int firstLength,int secondLength) {
    if(firstLength == 0 && secondLength == 0) {
        return 0;
    }
    if(firstLength == 0 || secondLength == 0) {
        return firstLength == 0?secondLength:firstLength;
    }
    if(firstUserInput[firstLength-1] == secondUserInput[secondLength-1]) {
        return minEdits(firstUserInput,secondUserInput,firstLength-1,secondLength-1);
    } else {
        return 1 + min(minEdits(firstUserInput,secondUserInput,firstLength-1,secondLength),minEdits(firstUserInput,secondUserInput,firstLength,secondLength-1),minEdits(firstUserInput,secondUserInput,firstLength-1,secondLength-1));
    }
}


#endif /* EDITDISTANCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
