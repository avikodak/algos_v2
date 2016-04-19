/****************************************************************************************************************************************************
 *  File Name                   : longestcommonsubsequence.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\longestcommonsubsequence.h
 *  Created on                  : Oct 29, 2014 :: 6:16:39 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

int longestCommonSubsequenceMemoization(char *firstUserInput,char *secondUserInput) {
    if(firstUserInput == null || secondUserInput == null) {
        return 0;
    }
    int firstStringLength = strlen(firstUserInput);
    int secondStringLength = strlen(secondUserInput);
    vector<vector<int> > auxSpace(firstStringLength);
    for(int counter = 0; counter < firstStringLength; counter++) {
        auxSpace[counter].resize(secondStringLength);
    }
    for(unsigned int rowCounter = 0; rowCounter < auxSpace.size(); rowCounter++) {
        auxSpace[rowCounter][0] = 0;
    }
    for(unsigned int columnCounter = 0; columnCounter < auxSpace[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = 0;
    }
    for(unsigned int rowCounter = 1; rowCounter < auxSpace.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < auxSpace[0].size(); columnCounter++) {
            if(firstUserInput[rowCounter] == secondUserInput[columnCounter]) {
                auxSpace[rowCounter][columnCounter] = 1 + auxSpace[rowCounter-1][columnCounter-1];
            } else {
                auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter-1][columnCounter],auxSpace[rowCounter][columnCounter-1]);
            }
        }
    }
    return auxSpace[firstStringLength-1][secondStringLength-1];
}

int longestCommonSubsequence(char *firstUserInput,char *secondUserInput) {
    if(*firstUserInput == '\0' || *secondUserInput == '\0') {
        return 0;
    }
    if(firstUserInput[0] == secondUserInput[0]) {
        return 1 + longestCommonSubsequence(firstUserInput+1,secondUserInput+1);
    } else {
        return max(longestCommonSubsequence(firstUserInput+1,secondUserInput),longestCommonSubsequence(firstUserInput,secondUserInput+1));
    }
}


#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
