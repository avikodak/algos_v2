/****************************************************************************************************************************************************
 *  File Name                   : insertionsort2.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\sorting\insertionsort2.h
 *  Created on                  : Feb 12, 2015 :: 1:39:25 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
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

#ifndef INSERTIONSORT2_H_
#define INSERTIONSORT2_H_

//Tested
void printVector(vector<int> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d ",userInput[counter]);
    }
    printf("\n");
}

//Tested
void insertionSort() {
    int size,input;
    scanf("%d",&size);
    vector<int> userInput;
    while(size--) {
        scanf("%d",&input);
        userInput.push_back(input);
    }
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        int key = userInput[outerCrawler],crawler = outerCrawler-1;
        while(crawler >= 0 && userInput[crawler] > key) {
            userInput[crawler+1] = userInput[crawler];
            crawler--;
        }
        userInput[crawler+1] = key;
        printVector(userInput);
    }
}

#endif /* INSERTIONSORT2_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
