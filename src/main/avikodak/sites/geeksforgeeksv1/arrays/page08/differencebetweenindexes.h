/****************************************************************************************************************************************************
 *  File Name                   : differencebetweenindexes.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\differencebetweenindexes.h
 *  Created on                  : Dec 1, 2014 :: 11:14:19 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
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

#ifndef DIFFERENCEBETWEENINDEXES_H_
#define DIFFERENCEBETWEENINDEXES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maxIJIndexAuxspace(vector<int> userInput) {
    if(userInput.size() < 1) {
        return 0;
    }
    vector<int> lMin,rMax;
    lMin.push_back(0);
    rMax.assign(userInput.size(),INT_MIN);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        lMin.push_back(userInput[counter] > userInput[lMin[counter-1]]?lMin[counter-1]:counter);
    }
    rMax[userInput.size()-1] = userInput.size()-1;
    for(int counter = userInput.size()-2; counter >= 0; counter--) {
        rMax[counter] = userInput[counter] > userInput[rMax[counter+1]]?counter:rMax[counter+1];
    }
    int maxDistance = 0;
    int firstCrawler = 0,secondCrawler = 0;
    while(firstCrawler < (int)userInput.size() && secondCrawler < (int)userInput.size()) {
        if(userInput[lMin[firstCrawler]] < userInput[rMax[secondCrawler]]) {
            maxDistance = max(maxDistance,secondCrawler-firstCrawler);
            secondCrawler++;
        } else {
            firstCrawler++;
        }
    }
    return maxDistance;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maxIJIndexesON2(vector<int> userInput) {
    if(userInput.size() < 1) {
        return 0;
    }
    unsigned int maxDiffIndex = 0;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-1; outerCrawler++) {
        for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
            if(userInput[innerCrawler] > userInput[outerCrawler]) {
                maxDiffIndex = max(maxDiffIndex,innerCrawler - outerCrawler);
            }
        }
    }
    return maxDiffIndex;
}

#endif /* DIFFERENCEBETWEENINDEXES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
