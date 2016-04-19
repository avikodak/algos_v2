/****************************************************************************************************************************************************
 *  File Name   		: postordertraversal.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\postordertraversal.h
 *  Created on			: Nov 17, 2014 :: 11:30:59 PM
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

#ifndef POSTORDERTRAVERSAL_H_
#define POSTORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void postOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    printf("%d\t",ptr->value);
}

//Tested
void postOrderTraversalIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(!auxSpace.empty() && currentNode->right == auxSpace.top()) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                printf("%d\t",currentNode->value);
                currentNode = null;
            }
        }
    }
}

//Tested
void postOrderTraversalIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t",currentNode->value);
            while(!auxSpace.empty() && currentNode == auxSpace.top()->right) {
                currentNode = auxSpace.top();
                printf("%d\t",currentNode->value);
                auxSpace.pop();
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
}

#endif /* POSTORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
