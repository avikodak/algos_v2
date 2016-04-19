/****************************************************************************************************************************************************
 *  File Name   		: bst.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\bst.h
 *  Created on			: Nov 18, 2014 :: 11:14:07 AM
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

#ifndef BST_H_
#define BST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void insertIntoBst(itNode **root,itNode *currentNode,int userInput) {
    if(*root == null) {
        (*root) = new itNode(userInput);
        return;
    } else {
        if(currentNode->value == userInput) {
            return;
        } else  if(currentNode->value > userInput) {
            if(currentNode->left == null) {
                currentNode->left = new itNode(userInput);
                return;
            } else {
                insertIntoBst(root,currentNode->left,userInput);
            }
        } else {
            if(currentNode->right == null) {
                currentNode->right = new itNode(userInput);
                return;
            } else {
                insertIntoBst(root,currentNode->right,userInput);
            }
        }
    }
}

//Tested
void insertIntoBstIterative(itNode **root,int userInput) {
    if(*root == null) {
        (*root) = new itNode(userInput);
        return;
    }
    itNode *currentNode = *root;
    while(currentNode != null) {
        if(currentNode->value == userInput) {
            return;
        } else if(currentNode->value > userInput) {
            if(currentNode->left == null) {
                currentNode->left = new itNode(userInput);
                return;
            } else {
                currentNode = currentNode->left;
            }
        } else {
            if(currentNode->right == null) {
                currentNode->right = new itNode(userInput);
                return;
            } else {
                currentNode = currentNode->right;
            }
        }
    }
}

#endif /* BST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
