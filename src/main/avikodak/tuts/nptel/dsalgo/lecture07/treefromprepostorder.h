/****************************************************************************************************************************************************
 *  File Name                   : treefromprepostorder.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\treefromprepostorder.h
 *  Created on                  : Nov 18, 2014 :: 12:39:25 AM
 *  Author                      : AVINASH
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

#ifndef TREEFROMPREPOSTORDER_H_
#define TREEFROMPREPOSTORDER_H_

int getIndexFromPostOrder(vector<int> postOrder,int startIndex,int endIndex,int value) {
    if(postOrder.size() == 0 || startIndex > endIndex) {
        return INT_MIN;
    }
    for(unsigned int counter = 0; counter < postOrder.size(); counter++) {
        if(postOrder[counter] == value) {
            return (int)counter;
        }
    }
    return INT_MIN;
}

itNode *constructTreeFromPrePostOrder(vector<int> preOrder,vector<int> postOrder,int startIndex,int endIndex) {
    static int preOrderIndex = 0;
    if(preOrderIndex >= (int)preOrder.size() || startIndex > endIndex) {
        return null;
    }
    int value = preOrder[preOrderIndex++];
    itNode *node = new itNode(value);
    if(abs(startIndex - endIndex) < 1 || preOrderIndex >= (int)preOrder.size()) {
        return node;
    }
    int index = getIndexFromPostOrder(postOrder,startIndex,endIndex,preOrder[preOrderIndex]);
    node->left = constructTreeFromPrePostOrder(preOrder,postOrder,startIndex,index);
    node->right = constructTreeFromPrePostOrder(preOrder,postOrder,index+1,endIndex-1);
    return node;
}

#endif /* TREEFROMPREPOSTORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
