/****************************************************************************************************************************************************
 *  File Name   		: maxleaftorootsum.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\maxleaftorootsum.h
 *  Created on			: Oct 31, 2014 :: 6:52:05 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/
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

#ifndef MAXLEAFTOROOTSUM_H_
#define MAXLEAFTOROOTSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxLeafToRoot(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->left == null || ptr->right == null) {
        return ptr->value;
    }
    return ptr->value + max(getMaxLeafToRoot(ptr->left),getMaxLeafToRoot(ptr->right));
}

//Tested
int getLeafToRootSum(hash_map<unsigned int,itNode *> indexNodeMap,unsigned int index) {
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    int sum = 0;
    while(index > 0) {
        itToIndexNodeMap = indexNodeMap.find(index);
        sum += itToIndexNodeMap->second->value;
        index /= 2;
    }
    return sum;
}

//Tested
int getMaxLeafToRootPreOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<unsigned int,itNode *> indexNodeMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
    int maxLeafToRoot = INT_MIN;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        if(currentNode->left == null && currentNode->right == null) {
            maxLeafToRoot = max(maxLeafToRoot,getLeafToRootSum(indexNodeMap,itToNodeIndexMap->second));
        } else {
            if(currentNode->left != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
                auxSpace.push(currentNode->right);
            }
        }
    }
    return maxLeafToRoot;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getRootToLeafSumLevelByLevel(itNode *ptr,unsigned int level,int runningSum) {
    if(ptr == null) {
        return INT_MIN;
    }
    if(level == 0) {
        return ptr->left == null && ptr->right == null?ptr->value + runningSum:INT_MIN;
    }
    return max(getRootToLeafSumLevelByLevel(ptr->left,level-1,runningSum + ptr->value),getRootToLeafSumLevelByLevel(ptr->right,level-1,runningSum+ptr->value));
}

//Tested
int getRootToLeafSumON2(itNode *ptr) {
    if(ptr == null) {
        return INT_MIN;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    int maxRootToLeaf = INT_MIN;
    for(unsigned int counter = 0; counter < height; counter++) {
        maxRootToLeaf = max(maxRootToLeaf,getRootToLeafSumLevelByLevel(ptr,counter,0));
    }
    return maxRootToLeaf;
}

#endif /* MAXLEAFTOROOTSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
