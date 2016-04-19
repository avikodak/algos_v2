/****************************************************************************************************************************************************
 *  File Name   		: heightparentarray.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\heightparentarray.h
 *  Created on			: Jan 24, 2015 :: 9:40:18 AM
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

#ifndef HEIGHTPARENTARRAY_H_
#define HEIGHTPARENTARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void fillDepthHeightParent(vector<int> parent,vector<int> depth,int currentNodeIndex) {
    if(depth[currentNodeIndex] == INT_MIN) {
        return;
    }
    if(parent[currentNodeIndex] == -1) {
        depth[currentNodeIndex] = 1;
        return;
    }
    if(depth[parent[currentNodeIndex]] == INT_MIN) {
        fillDepthHeightParent(parent,depth,parent[currentNodeIndex]);
    }
    depth[currentNodeIndex] = 1 + depth[parent[currentNodeIndex]];
}

int getHeightParentArray(vector<int> parent) {
    if(parent.size() == 0) {
        return 0;
    }
    vector<int> depth(parent.size(),INT_MIN);
    fillDepthHeightParent(parent,depth,0);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *constructTreeParentArray(vector<int> parentArray,int currentIndex) {
    if(currentIndex >= parentArray.size()) {
        return null;
    }
    itNode *root = new itNode(currentIndex);
    int leftChildIndex = INT_MIN,rightChildIndex = INT_MIN;
    for(unsigned int counter = 0; counter < parentArray.size(); counter++) {
        if(parentArray[counter] == currentIndex) {
            leftChildIndex = counter;
            break;
        }
    }
    if(leftChildIndex != INT_MIN) {
        root->left = constructTreeParentArray(parentArray,leftChildIndex);
    }
    for(unsigned int counter = 0; counter < parentArray.size() && counter != leftChildIndex; counter++) {
        if(parentArray[counter] == currentIndex) {
            rightChildIndex = counter;
            break;
        }
    }
    if(rightChildIndex != INT_MIN) {
        root->right = constructTreeParentArray(parentArray,rightChildIndex);
    }
    return root;
}

int getHeightOfTreeByConstruction(vector<int> parentArray) {
    if(parentArray.size() == 0) {
        return 0;
    }
    unsigned int rootIndex;
    for(rootIndex = 0; rootIndex < parentArray.size(); rootIndex++) {
        if(parentArray[rootIndex] == -1) {
            break;
        }
    }
    if(rootIndex >= parentArray.size()) {
        throw "Invalid user input";
    }
    itNode *root = constructTreeParentArray(parentArray,rootIndex);
    treeutils *utils = new treeutils();
    return utils->getHeightOfTree(root);
}

#endif /* HEIGHTPARENTARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
