/****************************************************************************************************************************************************
 *  File Name   		: frequencysill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\frequencysill.h
 *  Created on			: Oct 12, 2014 :: 6:36:50 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FREQUENCYSILL_H_
#define FREQUENCYSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int frequencyOfInt(sillNode *ptr,int userInput) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->value == userInput) {
        return 1+frequencyOfInt(ptr->next,userInput);
    } else {
        return frequencyOfInt(ptr->next,userInput);
    }
}

//Tested
unsigned int frequencyOfIntHashmap(sillNode *ptr,int userInput) {
    if(ptr == null) {
        return 0;
    }
    hash_map<int,unsigned int> frequencyMap;
    hash_map<int,unsigned int>::iterator itToFrequencyMap;
    sillNode *crawler = ptr;
    while(crawler != null) {
        if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()) {
            frequencyMap[itToFrequencyMap->first]++;
        } else {
            frequencyMap[crawler->value] = 1;
        }
        crawler = crawler->next;
    }
    return (itToFrequencyMap = frequencyMap.find(userInput)) == frequencyMap.end()?0:itToFrequencyMap->second;
}

//Tested
unsigned int frequencyOfIntBST(sillNode *ptr,int userInput) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    iftNode *rootBST = utils->getFBSTFromSill(ptr);
    iftNode *keyNode = utils->searchForValueBST(rootBST,userInput);
    return keyNode == null?0:keyNode->frequency;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Merge sort
#endif /* FREQUENCYSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
