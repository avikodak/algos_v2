/****************************************************************************************************************************************************
 *  File Name                   : printpermutations.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\backtracking\printpermutations.h
 *  Created on                  : Dec 5, 2014 :: 12:34:57 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
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

#ifndef PRINTPERMUTATIONS_H_
#define PRINTPERMUTATIONS_H_

//Tested
void printPermutations(vector<int> userInput,unsigned int currentIndex) {
    if(currentIndex > userInput.size()) {
        return;
    }
    if(currentIndex == userInput.size()) {
        printIVector(userInput);
        PRINT_NEW_LINE;
        return;
    }
    for(unsigned int counter = currentIndex; counter < userInput.size(); counter++) {
        swap(userInput[currentIndex],userInput[counter]);
        printPermutations(userInput,currentIndex+1);
        swap(userInput[currentIndex],userInput[counter]);
    }
}

#endif /* PRINTPERMUTATIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
