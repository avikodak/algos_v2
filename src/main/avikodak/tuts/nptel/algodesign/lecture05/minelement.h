/****************************************************************************************************************************************************
 *  File Name                   : minelement.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture05\minelement.h
 *  Created on                  : Dec 12, 2014 :: 11:51:54 AM
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

#ifndef MINELEMENT_H_
#define MINELEMENT_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int minElementON(vector<int> userInput,unsigned int currentIndex = 0) {
    if(currentIndex >= userInput.size()) {
        return INT_MAX;
    }
    return min(userInput[currentIndex],minElementON(userInput,currentIndex+1));
}

//Tested
int minElementIterative(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MAX;
    }
    int minElement = INT_MAX;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        minElement = min(minElement,userInput[counter]);
    }
    return minElement;
}

//Tested
int minElementDAD(vector<int> userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MAX;
    }
    if(startIndex  == endIndex) {
        return userInput[startIndex];
    }
    int middleIndex = (startIndex + endIndex)/2;
    return min(minElementDAD(userInput,startIndex,middleIndex),minElementDAD(userInput,middleIndex+1,endIndex));
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int minElementONLOGN(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    sort(userInput.begin(),userInput.end());
    return userInput[0];
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int minElementON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return INT_MIN;
    }
    int minElement;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        minElement = userInput[outerCrawler];
        for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
            minElement = min(minElement,userInput[innerCrawler]);
        }
        if(minElement == userInput[outerCrawler]) {
            return minElement;
        }
    }
    return INT_MIN;
}

#endif /* MINELEMENT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
