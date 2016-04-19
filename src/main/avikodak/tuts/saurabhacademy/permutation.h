
/****************************************************************************************************************************************************
 *  File Name                   : permutation.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\permutation.h
 *  Created on                  : Oct 29, 2014 :: 10:22:41 AM
 *  Author                      : AVINASH
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

#ifndef PERMUTATION_H_
#define PERMUTATION_H_

//Tested
void printPermutation(char *userInput,unsigned int startIndex,unsigned int endIndex) {
    if(startIndex == endIndex) {
        printf("%s",userInput);
        PRINT_NEW_LINE;
        return;
    }
    for(unsigned int counter = startIndex; counter <= endIndex; counter++) {
        swap(userInput[startIndex],userInput[counter]);
        printPermutation(userInput,startIndex+1,endIndex);
        swap(userInput[startIndex],userInput[counter]);
    }
}

//Tested
void permutationOfVector(vector<int> userInput,unsigned int startIndex) {
    if(startIndex == userInput.size()) {
        printIVector(userInput,false);
        PRINT_NEW_LINE;
        return;
    }
    for(unsigned int counter = startIndex; counter < userInput.size(); counter++) {
        swap(userInput[startIndex],userInput[counter]);
        permutationOfVector(userInput,startIndex+1);
        swap(userInput[startIndex],userInput[counter]);
    }
}

#endif /* PERMUTATION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
