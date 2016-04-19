/****************************************************************************************************************************************************
 *  File Name                   : nextrightnode.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page03\nextrightnode.h
 *  Created on                  : Nov 15, 2014 :: 4:09:50 PM
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

#ifndef NEXTRIGHTNODE_H_
#define NEXTRIGHTNODE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
inrNode *nrGetNextRight(inrNode *ptr) {
    if(ptr ==null) {
        return null;
    }
    while(ptr != null) {
        if(ptr->left != null) {
            return ptr->left;
        } else if(ptr->right != null) {
            return ptr->right;
        }
        ptr = ptr->nextRight;
    }
    return null;
}

//Tested
void nrConnectNodesInSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    nrConnectNodesInSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = nrGetNextRight(ptr->nextRight);
        } else {
            ptr->left->nextRight = nrGetNextRight(ptr->nextRight);
        }
        nrConnectNodesInSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = nrGetNextRight(ptr->nextRight);
        nrConnectNodesInSameLevel(ptr->right);
    } else {
        nrConnectNodesInSameLevel(ptr->nextRight);
    }
}

//Tested
int getNextRightValueIfPresent(inrNode *ptr,int value) {
    while(ptr != null) {
        if(ptr->value == value) {
            return ptr->nextRight == null?0:ptr->nextRight->value;
        }
        ptr = ptr->nextRight;
    }
    return INT_MIN;
}

//Tested
int getNextRightNode(inrNode *ptr,int value) {
    if(ptr == null) {
        return 0;
    }
    nrConnectNodesInSameLevel(ptr);
    int temp;
    while(ptr != null) {
        temp = getNextRightValueIfPresent(ptr,value);
        if(temp != INT_MIN) {
            return temp;
        }
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = ptr->nextRight;
        }
    }
    return 0;
}

itNode *getNextRightLevelOrder(itNode *ptr,int level) {
    if(ptr == null) {
        return  null;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode = null;
    auxSpace.push(ptr);
    unsigned int nodeCounter = 0;
    while(!auxSpace.empty()) {
        nodeCounter = auxSpace.size();
        currentNode = auxSpace.front();
        while(nodeCounter--) {

        }
    }
    return currentNode;
}


/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* NEXTRIGHTNODE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
