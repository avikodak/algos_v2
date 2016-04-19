/****************************************************************************************************************************************************
 *  File Name   		: bucketsort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\bucketsort.h
 *  Created on			: Dec 2, 2014 :: 12:19:58 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void bucketSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    map<int,unsigned int> frequencyMap;
    map<int,unsigned int>::iterator itToFrequencyMap;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()) {
            itToFrequencyMap->second += 1;
        } else {
            frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
        }
    }
    unsigned int counter = 0;
    for(itToFrequencyMap = frequencyMap.begin(); itToFrequencyMap != frequencyMap.end(); itToFrequencyMap++) {
        while(itToFrequencyMap->second--) {
            userInput[counter++] = itToFrequencyMap->first;
        }
    }
}

#endif /* BUCKETSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
