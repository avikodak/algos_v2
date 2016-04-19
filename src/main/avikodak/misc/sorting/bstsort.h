/****************************************************************************************************************************************************
 *  File Name   		: bstsort.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\bstsort.h
 *  Created on			: Dec 11, 2014 :: 1:01:27 PM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BSTSORTV2_H_
#define BSTSORTV2_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void bsInsertIntoBST(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int currentIndex) {
    if(currentIndex >= userInput.size()) {
        return;
    }
    if(*root == null) {
        (*root) = new iftNode(userInput[currentIndex]);
        bsInsertIntoBST(root,*root,userInput,currentIndex+1);
    } else if(currentNode->value == userInput[currentIndex]) {
        currentNode->frequency += 1;
        bsInsertIntoBST(root,*root,userInput,currentIndex+1);
    } else if(currentNode->value > userInput[currentIndex]) {
        if(currentNode->left == null) {
            currentNode->left = new iftNode(userInput[currentIndex]);
            bsInsertIntoBST(root,*root,userInput,currentIndex+1);
        } else {
            bsInsertIntoBST(root,currentNode->left,userInput,currentIndex);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new iftNode(userInput[currentIndex]);
            bsInsertIntoBST(root,*root,userInput,currentIndex+1);
        } else {
            bsInsertIntoBST(root,currentNode->right,userInput,currentIndex);
        }
    }
}

//Tested
void bsSetVectorWithInorderValues(iftNode *ptr,vector<int> &userInput) {
    if(ptr == null) {
        return;
    }
    static int fillCounter = -1;
    bsSetVectorWithInorderValues(ptr->left,userInput);
    while(ptr->frequency--) {
        userInput[++fillCounter] = ptr->value;
    }
    bsSetVectorWithInorderValues(ptr->right,userInput);
}

//Tested
void sBstSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    iftNode *root = null;
    bsInsertIntoBST(&root,root,userInput,0);
    bsSetVectorWithInorderValues(root,userInput);
}

#endif /* BSTSORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
