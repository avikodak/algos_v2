/****************************************************************************************************************************************************
 *  File Name                   : findifarrayissubset.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\findifarrayissubset.h
 *  Created on                  : Nov 26, 2014 :: 8:48:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
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

#ifndef FINDIFARRAYISSUBSET_H_
#define FINDIFARRAYISSUBSET_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isArraySubsetOfAnother(vector<int> largeArray,vector<int> smallArray) {
    if(smallArray.size() == 0) {
        return true;
    }
    if(largeArray.size() == 0) {
        return false;
    }
    hash_map<int,unsigned int> valueFrequencyMap;
    hash_map<int,unsigned int>::iterator itToValueFrequencyMap;
    for(unsigned int counter = 0; counter < largeArray.size(); counter++) {
        if((itToValueFrequencyMap = valueFrequencyMap.find(largeArray[counter])) == valueFrequencyMap.end()) {
            valueFrequencyMap[largeArray[counter]] = 1;
        } else {
            valueFrequencyMap[largeArray[counter]] += 1;
        }
    }
    for(unsigned int counter = 0; counter < smallArray.size(); counter++) {
        itToValueFrequencyMap = valueFrequencyMap.find(smallArray[counter]);
        if(itToValueFrequencyMap == valueFrequencyMap.end()) {
            return false;
        }
        if(itToValueFrequencyMap->second == 1) {
            valueFrequencyMap.erase(smallArray[counter]);
        } else {
            valueFrequencyMap[smallArray[counter]]--;
        }
    }
    return true;
}


/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isArraySubsetOfAnotherONLOGN(vector<int> largeArray,vector<int> smallArray) {
    if(smallArray.size() == 0) {
        return true;
    }
    if(largeArray.size() == 0) {
        return false;
    }
    sort(largeArray.begin(),largeArray.end());
    sort(smallArray.begin(),smallArray.end());
    unsigned int firstCrawler = 0,secondCrawler = 0;
    while(firstCrawler < largeArray.size() && secondCrawler < smallArray.size()) {
        if(largeArray[firstCrawler] == smallArray[secondCrawler]) {
            firstCrawler++;
            secondCrawler++;
        } else if(largeArray[firstCrawler] < smallArray[secondCrawler]) {
            firstCrawler++;
        } else {
            return false;
        }
    }
    return true;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
//works if unique
bool isArraySubsetOfAnotherON2(vector<int> largeArray,vector<int> smallArray) {
    if(smallArray.size() == 0) {
        return true;
    }
    if(largeArray.size() == 0) {
        return false;
    }
    bool valueFound;
    for(unsigned int outerCounter = 0; outerCounter < smallArray.size(); outerCounter++) {
        valueFound = false;
        for(unsigned int innerCounter = 0; innerCounter < largeArray.size(); innerCounter++) {
            if(smallArray[outerCounter] == largeArray[innerCounter]) {
                valueFound = true;
            }
        }
        if(!valueFound) {
            return false;
        }
    }
    return true;
}

#endif /* FINDIFARRAYISSUBSET_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
