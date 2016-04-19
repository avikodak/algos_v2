/****************************************************************************************************************************************************
 *  File Name   		: lowestcommonancestorsbst.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\lowestcommonancestorsbst.h
 *  Created on			: Oct 14, 2014 :: 11:36:49 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
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

#ifndef LOWESTCOMMONANCESTORSBST_H_
#define LOWESTCOMMONANCESTORSBST_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *lowestCommonAncestors(itNode *ptr,int low,int high) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value >= low && ptr->value <= high) {
        return ptr;
    }
    if(ptr->value > low) {
        return lowestCommonAncestors(ptr->left,low,high);
    } else {
        return lowestCommonAncestors(ptr->right,low,high);
    }
}

//Tested
itNode *lowestCommonAncestorsIterative(itNode *ptr,int low,int high) {
    if(ptr == null) {
        return false;
    }
    itNode *crawler = ptr;
    while(crawler != null) {
        if(crawler->value >= low && ptr->value <= high) {
            return crawler;
        }
        if(crawler->value > low) {
            crawler = crawler->left;
        } else {
            crawler = crawler->right;
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isNodePresentInSubTree(itNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    }
    return isNodePresentInSubTree(ptr->left,value) || isNodePresentInSubTree(ptr->right,value);
}

itNode *lowestCommonAncestorsON2(itNode *ptr,int low,int high) {
    if(ptr == null) {
        return null;
    }
    if(isNodePresentInSubTree(ptr->left,low) && isNodePresentInSubTree(ptr->right,high)) {
        return ptr;
    }
    itNode *result = lowestCommonAncestorsON2(ptr->left,low,high);
    if(result != null) {
        return result;
    }
    return lowestCommonAncestorsON2(ptr->right,low,high);
}

#endif /* LOWESTCOMMONANCESTORSBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
