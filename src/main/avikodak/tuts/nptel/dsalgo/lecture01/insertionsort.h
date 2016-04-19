/****************************************************************************************************************************************************
 *  File Name                   : insertionsort.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture01\insertionsort.h
 *  Created on                  : Oct 18, 2014 :: 11:52:39 AM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/
#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void insertionSort(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    int key,innerCrawler;
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        key = userInput[outerCrawler];
        innerCrawler = outerCrawler-1;
        while(innerCrawler >= 0 && userInput[innerCrawler] > key) {
            userInput[innerCrawler+1] = userInput[innerCrawler];
            innerCrawler--;
        }
        userInput[innerCrawler+1] = key;
    }
}

#endif /* INSERTIONSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
