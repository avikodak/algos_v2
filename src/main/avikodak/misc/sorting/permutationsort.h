/****************************************************************************************************************************************************
 *  File Name                   : permutationsort.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\sorting\permutationsort.h
 *  Created on                  : Dec 11, 2014 :: 12:45:14 PM
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

#ifndef PERMUTATIONSORT_H_
#define PERMUTATIONSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N!) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void  permutationSort(vector<int> userInput,unsigned int currentIndex = 0) {
    if(currentIndex == userInput.size()) {
        if(isVectorSorted(userInput)) {
            printIVector(userInput);
        }
    }
    vector<int> result;
    for(unsigned int counter = currentIndex; counter < userInput.size(); counter++) {
        swap(userInput[currentIndex],userInput[counter]);
        permutationSort(userInput,currentIndex+1);
        swap(userInput[currentIndex],userInput[counter]);
    }
    return;
}

#endif /* PERMUTATIONSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
