/****************************************************************************************************************************************************
 *  File Name   		: successor.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\successor.h
 *  Created on			: Nov 18, 2014 :: 8:40:26 PM
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

#ifndef SUCCESSOR_H_
#define SUCCESSOR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *getSuccessor(itNode *ptr,int value) {
    static bool keyFound = false;
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        if(ptr->right != null) {
            ptr = ptr->right;
            while(ptr->left != null) {
                ptr = ptr->left;
            }
            return ptr;
        }
        keyFound = true;
        return null;
    } else if(ptr->value > value) {
        itNode *result = getSuccessor(ptr->left,value);
        if(result == null) {
            return keyFound?ptr:null;
        }
        return result;
    } else {
        return getSuccessor(ptr->right,value);
    }
}

//Tested
itNode *getSuccessorIterative(itNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    itNode *probableSuccessor = null,*currentNode = ptr;
    while(currentNode != null) {
        if(currentNode->value == value) {
            if(currentNode->right == null) {
                return probableSuccessor;
            } else {
                currentNode = currentNode->right;
                while(currentNode->left != null) {
                    currentNode = currentNode->left;
                }
                return currentNode;
            }
        } else if(currentNode->value > value) {
            probableSuccessor = currentNode;
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return currentNode;
}

#endif /* SUCCESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
