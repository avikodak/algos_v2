/****************************************************************************************************************************************************
 *  File Name                   : treefromlevelinorder.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\treefromlevelinorder.h
 *  Created on                  : Nov 16, 2014 :: 10:37:08 AM
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

#ifndef TREEFROMLEVELINORDER_H_
#define TREEFROMLEVELINORDER_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int getIndexFromInorder(vector<int> inorder,int value,int startIndex,int endIndex) {
    for(int counter = startIndex; counter <= endIndex; counter++) {
        if(inorder[counter] == value) {
            return counter;
        }
    }
    return -1;
}

//Tested
void setLevelOrderNodes(vector<int> inorder,vector<int> levelOrder,int leftStartIndex,int leftEndIndex,vector<int> &leftLevelOrder,vector<int> &rightLevelOrder) {
    if(inorder.size() == 0 || levelOrder.size() == 0) {
        return;
    }
    bool flag;
    for(unsigned int outerCounter = 1; outerCounter < levelOrder.size(); outerCounter++) {
        flag = false;
        for(int index = leftStartIndex; index <= leftEndIndex; index++) {
            if(levelOrder[outerCounter] == inorder[index]) {
                leftLevelOrder.push_back(levelOrder[outerCounter]);
                flag = true;
                break;
            }
        }
        if(!flag) {
            rightLevelOrder.push_back(levelOrder[outerCounter]);
        }
    }
}

//Tested
itNode *treeFromLevelInOrder(vector<int> inorder,vector<int> levelOrder,int startInorderIndex,int endInorderIndex) {
    if(levelOrder.size() == 0 || inorder.size() == 0 || startInorderIndex > endInorderIndex) {
        return null;
    }
    itNode *root = new itNode(levelOrder[0]);
    if(levelOrder.size() == 1) {
        return root;
    }
    int index = getIndexFromInorder(inorder,levelOrder[0],startInorderIndex,endInorderIndex);
    vector<int> leftLevelOrder,rightLevelOrder;
    setLevelOrderNodes(inorder,levelOrder,startInorderIndex,index,leftLevelOrder,rightLevelOrder);
    root->left = treeFromLevelInOrder(inorder,leftLevelOrder,startInorderIndex,index-1);
    root->right = treeFromLevelInOrder(inorder,rightLevelOrder,index+1,endInorderIndex);
    return root;
}

#endif /* TREEFROMLEVELINORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
