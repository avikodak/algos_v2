/****************************************************************************************************************************************************
 *  File Name                   : findsubarraywithsum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\findsubarraywithsum.h
 *  Created on                  : Nov 27, 2014 :: 7:52:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-subarray-with-given-sum/
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

#ifndef FINDSUBARRAYWITHSUM_H_
#define FINDSUBARRAYWITHSUM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
iPair *getSubArrayForSumON(vector<int> userInput,int sum) {
    if(userInput.size() == 0) {
        return null;
    }
    int runningSum = userInput[0],startIndex = 0;
    for(int counter = 1; counter < (int)userInput.size(); counter++) {
        while(runningSum > sum && startIndex < counter-1) {
            runningSum -= userInput[startIndex++];
        }
        if(runningSum+userInput[counter] == sum) {
            return new iPair(startIndex,counter);
        } else {
            runningSum += userInput[counter];
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
iPair *getSubarrayForSumON2(vector<int> userInput,int sum) {
    if(userInput.size() == 0) {
        return null;
    }
    int runningSum;
    for(unsigned int outerCrawler = 0; outerCrawler <userInput.size(); outerCrawler++) {
        runningSum = 0;
        for(unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            runningSum += userInput[innerCrawler];
            if(runningSum == sum) {
                return new iPair(outerCrawler,innerCrawler);
            }
        }
    }
    return null;
}

#endif /* FINDSUBARRAYWITHSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
