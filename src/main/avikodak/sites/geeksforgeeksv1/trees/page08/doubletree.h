/****************************************************************************************************************************************************
 *  File Name   		: doubletree.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\doubletree.h
 *  Created on			: Oct 18, 2014 :: 2:10:38 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/double-tree/
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

#ifndef DOUBLETREE_H_
#define DOUBLETREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void doubleTreePreOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *clonedNode = new itNode(ptr->value);
    clonedNode->left = ptr->left;
    ptr->left = clonedNode;
    doubleTreePreOrder(ptr->left->left);
    doubleTreePreOrder(ptr->right);
}

//Tested
void doubleTreePreOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode,*clonedNode;
    stack<itNode *> auxSpace;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        clonedNode = new itNode(currentNode->value);
        clonedNode->left = currentNode->left;
        currentNode->left = clonedNode;
        if(currentNode->left->left != null) {
            auxSpace.push(currentNode->left->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
}

//Tested
void doubleTreeInorder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    doubleTreeInorder(ptr->left);
    itNode *clonedNode = new itNode(ptr->value);
    clonedNode->left = ptr->left;
    ptr->left = clonedNode;
    doubleTreeInorder(ptr->right);
}

//Tested
void doubleTreeInorderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            itNode *clonedNode = new itNode(currentNode->value);
            clonedNode->left = currentNode->left;
            currentNode->left = clonedNode;
            currentNode = currentNode->right;
        }
    }
}

//Tested
void doubleTreePostOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    doubleTreePostOrder(ptr->left);
    doubleTreePostOrder(ptr->right);
    itNode *clonedNode = new itNode(ptr->value);
    clonedNode->left = ptr->left;
    ptr->left = clonedNode;
}

//Tested
void doubleTreePostOrderIterativeTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    primaryAuxspace.push(ptr);
    itNode *currentNode;
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
    while(!secondaryAuxspace.empty()) {
        currentNode = secondaryAuxspace.top();
        secondaryAuxspace.pop();
        itNode *clonedNode = new itNode(currentNode->value);
        clonedNode->left = currentNode->left;
        currentNode->left = clonedNode;
    }

}

//Tested
void doubleTreePostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
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
                itNode *clonedNode = new itNode(currentNode->value);
                clonedNode->left = currentNode->left;
                currentNode->left = clonedNode;
                currentNode = null;
            }
        }
    }
}

//Tested
void doubleTreePostOrderIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            itNode *clonedNode = new itNode(currentNode->value);
            clonedNode->left = currentNode->left;
            currentNode->left = clonedNode;
            auxSpace.pop();
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                itNode *clonedNode = new itNode(currentNode->value);
                clonedNode->left = currentNode->left;
                currentNode->left = clonedNode;
                auxSpace.pop();
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
}

//Tested
void doubleTreeLevelOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        itNode *clonedNode = new itNode(currentNode->value);
        clonedNode->left = currentNode->left;
        currentNode->left = clonedNode;
        if(currentNode->left->left != null) {
            auxSpace.push(currentNode->left->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
}

//Tested
void doubleTreeHashmap(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    itNode *currentNode;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        currentNode = itToIndexNodeMap->second;
        itNode *clonedNode = new itNode(currentNode->value);
        clonedNode->left = currentNode->left;
        currentNode->left = clonedNode;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void doubleTreeLevelByLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        itNode *clonedNode = new itNode(ptr->value);
        clonedNode->left = ptr->left;
        ptr->left = clonedNode;
        return;
    }
    doubleTreeLevelByLevel(ptr->left,level-1);
    doubleTreeLevelByLevel(ptr->right,level-1);
}

//Tested
void doubleTreeLevelOrderON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(int counter = height - 1; counter >= 0; counter--) {
        doubleTreeLevelByLevel(ptr,counter);
    }
}

#endif /* DOUBLETREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
