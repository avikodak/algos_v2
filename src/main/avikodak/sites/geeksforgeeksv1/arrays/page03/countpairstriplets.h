/****************************************************************************************************************************************************
 *  File Name                   : countpairstriplets.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\countpairstriplets.h
 *  Created on                  : Jan 18, 2015 :: 9:23:47 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
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

#ifndef COUNTPAIRSTRIPLETS_H_
#define COUNTPAIRSTRIPLETS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int countPairsTripletsMultiplesThree(vector<int> userInput) {
    if(userInput.size() < 2) {
        return 0;
    }
    vector<unsigned int> remainderFrequency(3,0);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        remainderFrequency[userInput[counter]%3] += 1;
    }
    int counter = 0;
    counter += (remainderFrequency[0] * (remainderFrequency[0]-1))/2;
    counter += (remainderFrequency[1] * remainderFrequency[2]);
    counter += (remainderFrequency[0] * remainderFrequency[1] * remainderFrequency[2]);
    counter += (remainderFrequency[0] * (remainderFrequency[0]-1) * (remainderFrequency[0]-2))/6;
    counter += (remainderFrequency[1] * (remainderFrequency[1]-1) * (remainderFrequency[1]-2))/6;
    counter += (remainderFrequency[2] * (remainderFrequency[2]-1) * (remainderFrequency[2]-2))/6;
    return counter;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int countPairsTripletsMultiplesThreeON3(vector<int> userInput) {
    if(userInput.size() < 2) {
        return 0;
    }
    unsigned int counter = 0;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-1; outerCrawler++) {
        for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
            if((userInput[outerCrawler] + userInput[innerCrawler])%3 == 0) {
                counter += 1;
            }
        }
    }
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-2; outerCrawler++) {
        for(unsigned int middleCrawler = outerCrawler+1; middleCrawler < userInput.size()-1; middleCrawler++) {
            for(unsigned int innerCrawler = middleCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
                if((userInput[outerCrawler] + userInput[middleCrawler] + userInput[innerCrawler])%3 == 0) {
                    counter += 1;
                }
            }
        }
    }
    return counter;
}

#endif /* COUNTPAIRSTRIPLETS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
