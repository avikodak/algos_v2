/****************************************************************************************************************************************************
 *  File Name                   : span.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\span.h
 *  Created on                  : Oct 18, 2014 :: 1:16:32 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SPAN_H_
#define SPAN_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
vector<int> getSpansOfStockON(vector<int> userInput) {
    vector<int> stockSpans;
    if(userInput.size() == 0) {
        return stockSpans;
    }
    stockSpans.push_back(INT_MIN);
    stack<int> auxSpace;
    auxSpace.push(userInput[0]);
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        while(!auxSpace.empty() && userInput[auxSpace.top()] < userInput[counter]) {
            auxSpace.pop();
        }
        stockSpans.push_back(auxSpace.empty()?INT_MIN:counter - auxSpace.top());
        auxSpace.push(counter);
    }
    return stockSpans;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
vector<int> getSpansOfStockON2(vector<int> userInput) {
    vector<int> stockSpans;
    if(userInput.size() == 0) {
        return stockSpans;
    }
    stockSpans.push_back(INT_MIN);
    int innerCrawler;
    for(unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        for(innerCrawler = outerCrawler; innerCrawler >= 0; innerCrawler--) {
            if(userInput[innerCrawler] > userInput[outerCrawler]) {
                stockSpans.push_back(outerCrawler - innerCrawler);
                break;
            }
        }
        if(innerCrawler < 0) {
            stockSpans.push_back(INT_MIN);
        }
    }
    return stockSpans;
}

#endif /* SPAN_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
