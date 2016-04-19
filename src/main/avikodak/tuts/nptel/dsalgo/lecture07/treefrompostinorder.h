/****************************************************************************************************************************************************
 *  File Name                   : treefrompostinorder.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\treefrompostinorder.h
 *  Created on                  : Nov 18, 2014 :: 12:26:56 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef TREEFROMPOSTINORDER_H_
#define TREEFROMPOSTINORDER_H_

int getIndexOfValueFromInorder(vector<int> inOrder,int value,int startIndex,int endIndex) {
    if(inOrder.size() == 0 || startIndex > endIndex) {
        return INT_MAX;
    }
    for(int counter = startIndex; counter <= endIndex; counter++) {
        if(inOrder[counter] == value) {
            return counter;
        }
    }
    return INT_MAX;
}

itNode *constructTreeFromPostInorderMain(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex,int postOrderStartIndex,int postOrderEndIndex) {
    if(startIndex > endIndex || postOrder.size() == 0 || inOrder.size() == 0 || postOrderIndex < 0) {
        return null;
    }
    int value = postOrder[postOrderEndIndex];
    itNode *node = new itNode(value);
    int index = getIndexOfValueFromInorder(inOrder,value,startIndex,endIndex);
    /*node->right = constructTreeFromPostInorderMain(postOrder,inOrder,startIndex,index-1,postOrderStartIndex,postOrderStartIndex);
    node->left = constructTreeFromPostInorderMain(postOrder,inOrder,index+1,endIndex,postOrderIndex);*/
    return node;
}

itNode *constructTreeFromPostInorder(vector<int> postOrder,vector<int> inOrder) {
    return constructTreeFromPostInorderMain(postOrder,inOrder,0,inOrder.size()-1,0,postOrder.size()-1);
}

void setValueIndexMap(vector<int> inOrder,hash_map<int,unsigned int> &valueIndexMap) {
    if(inOrder.size() == 0) {
        return;
    }
    for(unsigned int counter = 0; counter < inOrder.size(); counter++) {
        valueIndexMap.insert(pair<int,unsigned int>(inOrder[counter],counter));
    }
}

itNode *constructTreeFromPostInOrderV2(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex,int &postOrderIndex) {
    if(startIndex > endIndex || postOrder.size() == 0 || inOrder.size() == 0 || postOrderIndex < 0) {
        return null;
    }
    static hash_map<int,unsigned int> valueIndexMap;
    if(valueIndexMap.size() == 0) {
        setValueIndexMap(inOrder,valueIndexMap);
    }
    int value = postOrder[postOrderIndex--];
    itNode *node = new itNode(value);
    int index = valueIndexMap.find(value)->second;
    node->left = constructTreeFromPostInOrderV2(postOrder,inOrder,startIndex,index-1,postOrderIndex);
    node->right = constructTreeFromPostInOrderV2(postOrder,inOrder,index+1,endIndex,postOrderIndex);
    return node;
}

#endif /* TREEFROMPOSTINORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
