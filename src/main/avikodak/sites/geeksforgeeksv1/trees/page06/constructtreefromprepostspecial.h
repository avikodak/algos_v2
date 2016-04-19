/****************************************************************************************************************************************************
 *  File Name   		: constructtreefromprepostspecial.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\constructtreefromprepostspecial.h
 *  Created on			: Nov 1, 2014 :: 6:37:18 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
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

#ifndef CONSTRUCTTREEFROMPREPOSTSPECIAL_H_
#define CONSTRUCTTREEFROMPREPOSTSPECIAL_H_

//Tested
int getIndexOfNodeInPostOrder(vector<int> postOrder,int startIndex,int endIndex,int value) {
    for(int counter = startIndex; counter <= endIndex; counter++) {
        if(postOrder[counter] == value) {
            return counter;
        }
    }
    return INT_MAX;
}

//Tested
itNode *getTreeFromPrePostOrder(vector<int> preOrder,vector<int> postOrder,int startIndex,int endIndex) {
    static int preOrderIndex = 0;
    if(preOrderIndex >= (int)preOrder.size() || startIndex > endIndex) {
        return null;
    }
    itNode *root = new itNode(preOrder[preOrderIndex]);
    preOrderIndex++;
    if(startIndex == endIndex || preOrderIndex >= (int)preOrder.size()) {
        return root;
    }
    int indexOfValueInPostOrder = getIndexOfNodeInPostOrder(postOrder,startIndex,endIndex,preOrder[preOrderIndex]);
    root->left = getTreeFromPrePostOrder(preOrder,postOrder,startIndex,indexOfValueInPostOrder);
    root->right = getTreeFromPrePostOrder(preOrder,postOrder,indexOfValueInPostOrder+1,endIndex-1);
    return root;
}

#endif /* CONSTRUCTTREEFROMPREPOSTSPECIAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

