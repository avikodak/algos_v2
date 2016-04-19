/****************************************************************************************************************************************************
 *  File Name   		: mergesort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\mergesort.h
 *  Created on			: Oct 31, 2014 :: 2:09:06 PM
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

#ifndef MERGESORT_H_
#define MERGESORT_H_

//Tested
sillNode *merge(sillNode *firstSill,sillNode *secondSill) {
    if(firstSill == null || secondSill == null) {
        return firstSill == null?secondSill:firstSill;
    }
    sillNode *result;
    if(firstSill->value < secondSill->value) {
        result = firstSill;
        result->next = merge(firstSill->next,secondSill);
    } else {
        result = secondSill;
        result->next = merge(firstSill,secondSill->next);
    }
    return result;
}

//Tested
void frontBackSplit(sillNode *ptr,sillNode **firstPtr,sillNode **secondPtr) {
    if(ptr == null || ptr->next == null) {
        (*firstPtr) = ptr;
        (*secondPtr) = null;
        return;
    }
    sillNode *fast = ptr->next,*slow = ptr;
    while(fast != null) {
        fast = fast->next;
        if(fast != null) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    (*secondPtr) = slow->next;
    (*firstPtr) = ptr;
    slow->next = null;
}

//Tested
void mergeSort(sillNode **ptr) {
    if((*ptr) == null || (*ptr)->next == null) {
        return;
    }
    sillNode *firstPtr = null,*secondPtr = null;
    frontBackSplit(*ptr,&firstPtr,&secondPtr);
    mergeSort(&firstPtr);
    mergeSort(&secondPtr);
    (*ptr) = merge(firstPtr,secondPtr);
}


#endif /* MERGESORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
