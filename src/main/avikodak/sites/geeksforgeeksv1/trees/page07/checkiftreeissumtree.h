/****************************************************************************************************************************************************
 *  File Name   		: checkiftreeissumtree.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\checkiftreeissumtree.h
 *  Created on			: Oct 21, 2014 :: 10:33:41 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
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

#ifndef CHECKIFTREEISSUMTREE_H_
#define CHECKIFTREEISSUMTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeSumTreePreOrder(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right == null)) {
        return true;
    }
    int sum = ptr->left == null?0:ptr->left->left == null && ptr->left->right == null?ptr->left->value:2*ptr->left->value;
    sum += ptr->right == null?0:ptr->right->left == null && ptr->right->right == null?ptr->right->value:2*ptr->right->value;
    if(ptr->value != sum) {
        return false;
    }
    return isTreeSumTreePreOrder(ptr->left) && isTreeSumTreePreOrder(ptr->right);
}

//Tested
int isTreeSumTreePostOrderMain(itNode *ptr,bool &isSumTree) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->left == null && ptr->right == null) {
        return ptr->value;
    }
    int leftSum = isTreeSumTreePostOrderMain(ptr->left,isSumTree);
    int rightSum = isTreeSumTreePostOrderMain(ptr->right,isSumTree);
    isSumTree = isSumTree && ptr->value == leftSum + rightSum;
    return ptr->value + leftSum + rightSum;
}

//Tested
bool isTreeSumTreePostOrder(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    bool flag = true;
    isTreeSumTreePostOrderMain(ptr,flag);
    return flag;
}

//Tested
bool isTreeSumTreePostOrderV2(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right == null)) {
        return true;
    }
    if(!isTreeSumTreePostOrderV2(ptr->left) || !isTreeSumTreePostOrderV2(ptr->right)) {
        return false;
    }
    int leftSum = ptr->left == null?0:ptr->left->left == null && ptr->left->right == null?ptr->left->value:2*ptr->left->value;
    int rightSum = ptr->right  == null?0:ptr->right->left == null && ptr->right->right == null?ptr->right->value:2*ptr->right->value;
    return ptr->value == leftSum + rightSum;
}

//Tested
bool isTreeSumTreePostOrderIterativeTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    primaryAuxspace.push(ptr);
    itNode *currentNode = ptr;
    while(!primaryAuxspace.empty()) {
        currentNode = primaryAuxspace.top();
        primaryAuxspace.pop();
        secondaryAuxspace.push(currentNode);
        if(currentNode->left != null) {
            primaryAuxspace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            primaryAuxspace.push(currentNode->right);
        }
    }
    int leftSum = 0,rightSum = 0;
    while(!secondaryAuxspace.empty()) {
        currentNode = secondaryAuxspace.top();
        secondaryAuxspace.pop();
        if(currentNode->left != null || currentNode->right != null) {
            leftSum = currentNode->left == null ?0:currentNode->left->left == null && currentNode->left->right == null?currentNode->left->value:2*currentNode->left->value;
            rightSum = currentNode->right == null?0:currentNode->right->left == null && currentNode->right->right == null?currentNode->right->value:2*currentNode->right->value;
            if(currentNode->value != leftSum + rightSum) {
                return false;
            }
        }
    }
    return true;
}

//Tested
bool isTreeSumTreePostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    int leftSum,rightSum;
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
                if(currentNode->left != null || currentNode->right != null) {
                    leftSum = currentNode->left == null ? 0:currentNode->left->left == null && currentNode->left->right == null?currentNode->left->value:2*currentNode->left->value;
                    rightSum = currentNode->right == null?0:currentNode->right->left == null && currentNode->right->right == null?currentNode->right->value:2*currentNode->right->value;
                    if(currentNode->value != leftSum + rightSum) {
                        return false;
                    }
                }
                currentNode = null;
            }
        }
    }
    return true;
}

//Tested
bool isTreeSumTreePostOrderIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    int leftSum,rightSum;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(currentNode->left != null || currentNode->right != null) {
                leftSum = currentNode->left == null ? 0:currentNode->left->left == null && currentNode->left->right == null?currentNode->left->value:2*currentNode->left->value;
                rightSum = currentNode->right == null?0:currentNode->right->left == null && currentNode->right->right == null?currentNode->right->value:2*currentNode->right->value;
                if(currentNode->value != leftSum + rightSum) {
                    return false;
                }
            }
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                if(currentNode->left != null || currentNode->right != null) {
                    leftSum = currentNode->left == null ? 0:currentNode->left->left == null && currentNode->left->right == null?currentNode->left->value:2*currentNode->left->value;
                    rightSum = currentNode->right == null?0:currentNode->right->left == null && currentNode->right->right == null?currentNode->right->value:2*currentNode->right->value;
                    if(currentNode->value != leftSum + rightSum) {
                        return false;
                    }
                }
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int sumOfNodesTree(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return ptr->value + sumOfNodesTree(ptr->left) + sumOfNodesTree(ptr->right);
}

//Tested
bool isTreeSumTreeON2(itNode *ptr) {
    if(ptr == null) {
        return true;
    }
    if(ptr->left == null && ptr->right == null) {
        return true;
    }
    return ptr->value == sumOfNodesTree(ptr->left) + sumOfNodesTree(ptr->right) && isTreeSumTreeON2(ptr->left) && isTreeSumTreeON2(ptr->right);
}

#endif /* CHECKIFTREEISSUMTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
