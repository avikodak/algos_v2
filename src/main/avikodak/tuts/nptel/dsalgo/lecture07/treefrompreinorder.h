/****************************************************************************************************************************************************
 *  File Name   		: treefrompreinorder.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\treefrompreinorder.h
 *  Created on			: Nov 18, 2014 :: 12:13:47 AM
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

#ifndef TREEFROMPREINORDER_H_
#define TREEFROMPREINORDER_H_

//Tested
int getInorderIndexForValue(vector<int> inOrder,int startIndex,int endIndex,int value) {
    if(inOrder.size() == 0 || startIndex > endIndex) {
        return UINT_MAX;
    }
    for(unsigned int counter = startIndex; counter <= inOrder.size(); counter++) {
        if(inOrder[counter] == value) {
            return counter;
        }
    }
    return UINT_MAX;
}

//Tested
itNode *constructTreeFromPreInorder(vector<int> preOrder,vector<int> inOrder,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return null;
    }
    static int preorderIndex = -1;
    int value = preOrder[++preorderIndex];
    itNode *node = new itNode(value);
    int index = getInorderIndexForValue(inOrder,startIndex,endIndex,value);
    node->left = constructTreeFromPreInorder(preOrder,inOrder,startIndex,index-1);
    node->right = constructTreeFromPreInorder(preOrder,inOrder,index+1,endIndex);
    return node;
}

//Tested
void setIndexForValues(vector<int> inorder,hash_map<int,unsigned int> &valueIndexMap) {
    if(inorder.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < inorder.size(); counter++) {
        valueIndexMap.insert(pair<int,unsigned int>(inorder[counter],counter));
    }
}

//Tested
itNode *constructTreeFromPreInorderV2Main(vector<int> preOrder,vector<int> inOrder,int startIndex,int endIndex,hash_map<int,unsigned int> &valueIndexMap) {
    static unsigned int preOrderIndex = 0;
    if(startIndex > endIndex || preOrderIndex >= preOrder.size()|| preOrder.size() == 0 || inOrder.size() == 0) {
        return null;
    }
    int value = preOrder[preOrderIndex++];
    itNode *node = new itNode(value);
    int index = (int)valueIndexMap.find(value)->second;
    node->left = constructTreeFromPreInorderV2Main(preOrder,inOrder,startIndex,index-1,valueIndexMap);
    node->right = constructTreeFromPreInorderV2Main(preOrder,inOrder,index+1,endIndex,valueIndexMap);
    return node;
}

//Tested
itNode *constructTreeFromPreInorderV2(vector<int> preOrder,vector<int> inOrder) {
    hash_map<int,unsigned int> valueIndexMap;
    setIndexForValues(inOrder,valueIndexMap);
    return constructTreeFromPreInorderV2Main(preOrder,inOrder,0,inOrder.size(),valueIndexMap);
}

#endif /* TREEFROMPREINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

