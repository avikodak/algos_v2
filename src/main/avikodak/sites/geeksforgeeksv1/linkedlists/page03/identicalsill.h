/****************************************************************************************************************************************************
 *  File Name   		: identicalsill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\identicalsill.h
 *  Created on			: Oct 23, 2014 :: 9:27:38 AM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef IDENTICALSILL_H_
#define IDENTICALSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool areSillsIdentical(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return true;
    }
    if(firstPtr == null || secondPtr == null) {
        return false;
    }
    return firstPtr->value == secondPtr->value && areSillsIdentical(firstPtr->next,secondPtr->next);
}

bool areSillsIdentical(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return true;
    }
    if(firstPtr == null || secondPtr == null) {
        return false;
    }
    while(firstPtr != null && secondPtr != null) {
        if(firstPtr->value != secondPtr->value) {
            return false;
        }
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }
    return firstPtr == null && secondPtr == null;
}

bool areSillsIdenticalHashmap(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return true;
    }
    if(firstPtr == null || secondPtr == null) {
        return false;
    }
    sillutils *utils = new sillutils();
    hash_map<unsigned int,sillNode *> indexNodeMapFirstSill = utils->getSillAsHashmap(firstPtr,1);
    hash_map<unsigned int,sillNode *> indexNodeMapSecondSill = utils->getSillAsHashmap(secondPtr,1);
    if(indexNodeMapFirstSill.size() != indexNodeMapSecondSill.size()) {
        return false;
    }
    hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMapFirstSill,itToIndexNodeMapSecondSill;
    for(itToIndexNodeMapFirstSill = indexNodeMapFirstSill.begin(); itToIndexNodeMapFirstSill != indexNodeMapFirstSill.end(); itToIndexNodeMapFirstSill++) {
        itToIndexNodeMapSecondSill = indexNodeMapSecondSill.find(itToIndexNodeMapFirstSill->first);
        if(itToIndexNodeMapFirstSill == indexNodeMapSecondSill.end() || itToIndexNodeMapSecondSill->second->value != itToIndexNodeMapFirstSill->second->value) {
            return false;
        }
    }
    return true;
}

#endif /* IDENTICALSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
