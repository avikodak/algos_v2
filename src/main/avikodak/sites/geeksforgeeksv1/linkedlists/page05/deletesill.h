/****************************************************************************************************************************************************
 *  File Name   		: deletesill.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\deletesill.h
 *  Created on			: Oct 12, 2014 :: 5:58:52 PM
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

#ifndef DELETESILL_H_
#define DELETESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void deleteSillMainTailRecursion(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    deleteSillMainTailRecursion(ptr->next);
    free(ptr);
}

//Tested
void deleteSillTailRecusion(sillNode **ptr) {
    if(*ptr == null) {
        return;
    }
    deleteSillMainTailRecursion(*ptr);
    (*ptr) = null;
}

//Tested
void deleteSillMain(sillNode *ptr) {
    if(ptr == null) {
        return;
    }
    sillNode *temp = ptr->next;
    free(ptr);
    deleteSillMain(temp);
}

//Tested
void deleteSill(sillNode **ptr) {
    if(*ptr == null) {
        return;
    }
    deleteSillMain(*ptr);
    (*ptr) = null;
}

//Tested
void deleteSillIterative(sillNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<sillNode *> auxSpace;
    sillNode *crawler = *ptr;
    while(crawler != null) {
        auxSpace.push(crawler);
        crawler = crawler->next;
    }
    while(!auxSpace.empty()) {
        crawler = auxSpace.top();
        auxSpace.pop();
        free(crawler);
    }
    (*ptr) = null;
}

//Tested
void deleteSillIterativeV2(sillNode **ptr) {
    if(*ptr == null) {
        return;
    }
    sillNode *temp,*nodeToBeDeleted = *ptr;
    do {
        temp = nodeToBeDeleted->next;
        free(nodeToBeDeleted);
        nodeToBeDeleted = temp;
    } while(temp != null);
    (*ptr) = null;
}

//Tested
void deleteSillHashmap(sillNode **ptr) {
    if(*ptr == null) {
        return;
    }
    sillutils *utils = new sillutils();
    hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(*ptr)->indexNodeMap;
    hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        free(itToIndexNodeMap->second);
    }
    (*ptr) = null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* DELETESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
