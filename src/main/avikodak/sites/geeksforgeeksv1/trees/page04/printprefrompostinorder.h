/****************************************************************************************************************************************************
 *  File Name   		: printprefrompostinorder.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\printprefrompostinorder.h
 *  Created on			: Nov 13, 2014 :: 11:55:39 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
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

#ifndef PRINTPREFROMPOSTINORDER_H_
#define PRINTPREFROMPOSTINORDER_H_

int findIndexInInorder(vector<int> inOrder,int startIndex,int endIndex,int key) {
    for(int counter = startIndex; counter <= endIndex; counter++) {
        if(inOrder[counter] == key) {
            return counter;
        }
    }
    return INT_MIN;
}

itNode *constructFromPostInorder(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex) {
    static int currentPostOrderIndex = postOrder.size()-1;
    if(currentPostOrderIndex < 0 || startIndex > endIndex) {
        return null;
    }
    itNode *node = new itNode(postOrder[currentPostOrderIndex]);
    int index = findIndexInInorder(inOrder,startIndex,endIndex,postOrder[currentPostOrderIndex]);
    currentPostOrderIndex--;
    node->right = constructFromPostInorder(postOrder,inOrder,startIndex,index-1);
    node->left = constructFromPostInorder(postOrder,inOrder,index+1,endIndex);
    return node;
}

void printPreOrderFromPostAndInorder(vector<int> postOrder,vector<int> inOrder) {
    if(postOrder.size() == 0) {
        return;
    }
    itNode *root = constructFromPostInorder(postOrder,inOrder,0,inOrder.size()-1);
    treeutils *utils = new treeutils();
    utils->preOrderTraversal(root);
}

#endif /* PRINTPREFROMPOSTINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
