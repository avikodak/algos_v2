/****************************************************************************************************************************************************
 *  File Name   		: spirallevelordertraversal.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\spirallevelordertraversal.h
 *  Created on			: Oct 16, 2014 :: 11:05:54 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
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

#ifndef SPIRALLEVELORDERTRAVERSAL_H_
#define SPIRALLEVELORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void spiralLevelOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> levelAuxspace;
    stack<itNode *> reversedLevelAuxspace;
    levelAuxspace.push(ptr);
    itNode *currentNode;
    while(!levelAuxspace.empty() || !reversedLevelAuxspace.empty()) {
        while(!levelAuxspace.empty()) {
            currentNode = levelAuxspace.top();
            levelAuxspace.pop();
            printf("%d\t",currentNode->value);
            if(currentNode->left != null) {
                reversedLevelAuxspace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                reversedLevelAuxspace.push(currentNode->right);
            }
        }
        PRINT_NEW_LINE;
        while(!reversedLevelAuxspace.empty()) {
            currentNode = reversedLevelAuxspace.top();
            reversedLevelAuxspace.pop();
            printf("%d\t",currentNode->value);
            if(currentNode->right != null) {
                levelAuxspace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                levelAuxspace.push(currentNode->left);
            }
        }
        PRINT_NEW_LINE;
    }
}

//Tested
void spiralLevelOrderTraversalHashmap(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *>	indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    unsigned int heightOfTree = utils->getHeightOfTree(ptr);
    for(unsigned int counter = 0; counter < heightOfTree; counter++) {
        if(counter&1) {
            for(unsigned int nodeIndexCounter = pow(2,counter+1)-1; nodeIndexCounter >= pow(2,counter); nodeIndexCounter--) {
                itToIndexNodeMap = indexNodeMap.find(nodeIndexCounter);
                if(itToIndexNodeMap != indexNodeMap.end()) {
                    printf("%d\t",itToIndexNodeMap->second->value);
                }
            }
        } else {
            for(unsigned int nodeIndexCounter = pow(2,counter); nodeIndexCounter < pow(2,counter+1); nodeIndexCounter++) {
                itToIndexNodeMap = indexNodeMap.find(nodeIndexCounter);
                if(itToIndexNodeMap != indexNodeMap.end()) {
                    printf("%d\t",itToIndexNodeMap->second->value);
                }
            }
        }
        PRINT_NEW_LINE;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevel(itNode *ptr,unsigned int level,bool inReverse = false) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    if(inReverse) {
        printLevel(ptr->right,level-1,inReverse);
        printLevel(ptr->left,level-1,inReverse);
    } else {
        printLevel(ptr->left,level-1,inReverse);
        printLevel(ptr->right,level-1,inReverse);
    }
}

//Tested
void spiralOrderTraversalON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    bool printReverse = false;
    for(unsigned int counter = 0; counter < height; counter++) {
        printLevel(ptr,counter,printReverse);
        printReverse = !printReverse;
        PRINT_NEW_LINE;
    }
}

#endif /* SPIRALLEVELORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
