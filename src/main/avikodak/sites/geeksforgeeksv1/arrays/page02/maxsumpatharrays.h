/****************************************************************************************************************************************************
 *  File Name                   : maxsumpatharrays.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\maxsumpatharrays.h
 *  Created on                  : Jan 5, 2015 :: 11:38:44 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
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

#ifndef MAXSUMPATHARRAYS_H_
#define MAXSUMPATHARRAYS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maxSumPathArrays(vector<int> firstSortedInput,vector<int> secondSortedInput) {
    if(firstSortedInput.size() == 0 && secondSortedInput.size()) {
        return 0;
    }
    int maxSum = 0,maxFirstArraySum = 0,maxSecondArraySum = 0;
    unsigned int firstCrawler = 0,secondCrawler = 0;
    while(firstCrawler < firstSortedInput.size() && secondCrawler < secondSortedInput.size()) {
        if(firstSortedInput[firstCrawler] == secondSortedInput[secondCrawler]) {
            maxSum += max(maxFirstArraySum,maxSecondArraySum);
            maxFirstArraySum = 0;
            maxSecondArraySum = 0;
            while(firstCrawler < firstSortedInput.size() && secondCrawler < secondSortedInput.size() && firstSortedInput[firstCrawler] == secondSortedInput[secondCrawler]) {
                maxSum += firstSortedInput[firstCrawler++];
                secondCrawler++;
            }
        } else if(firstSortedInput[firstCrawler] < secondSortedInput[secondCrawler]) {
            maxFirstArraySum += firstSortedInput[firstCrawler++];
        } else {
            maxSecondArraySum += secondSortedInput[secondCrawler++];
        }
    }
    while(firstCrawler < firstSortedInput.size()) {
        maxFirstArraySum += firstSortedInput[firstCrawler++];
    }
    while(secondCrawler < secondSortedInput.size()) {
        maxSecondArraySum += secondSortedInput[secondCrawler++];
    }
    return maxSum + max(maxFirstArraySum,maxSecondArraySum);;
}

#endif /* MAXSUMPATHARRAYS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
