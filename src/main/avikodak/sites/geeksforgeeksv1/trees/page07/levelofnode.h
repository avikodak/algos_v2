/****************************************************************************************************************************************************
 *  File Name                   : levelofnode.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\levelofnode.h
 *  Created on                  : Oct 20, 2014 :: 7:07:21 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
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

#ifndef LEVELOFNODE_H_
#define LEVELOFNODE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int lGetLevelOfNode(itNode *ptr,int value) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->value == value) {
        return 1;
    }
    int temp = lGetLevelOfNode(ptr->left,value);
    if(temp != 0) {
        return 1 + temp;
    }
    temp = lGetLevelOfNode(ptr->right,value);
    if(temp != 0) {
        return 1 + temp;
    }
    return 0;
}

//Tested
unsigned int getLevelOfNodeHashmap(itNode *ptr,int value) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        if(itToIndexNodeMap->second->value == value) {
            return log2(itToIndexNodeMap->first)+1;
        }
    }
    return 0;
}

//Tested
unsigned int getLevelOfNodePostOrderIterative(itNode *ptr,int value) {
    if(ptr == null) {
        return 0;
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
            if(currentNode->value == value) {
                return auxSpace.size();
            }
            auxSpace.pop();
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                if(currentNode->value == value) {
                    return auxSpace.size();
                }
                auxSpace.pop();
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return 0;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool presentInLevel(itNode *ptr,int value,int level) {
    if(ptr == null) {
        return false;
    }
    if(level == 0) {
        return ptr->value == value;
    }
    return presentInLevel(ptr->left,value,level-1) || presentInLevel(ptr->right,value,level-1);
}

//Tested
unsigned int getLevelOfNodeON2(itNode *ptr,int value) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(unsigned int counter = 0; counter < height; counter++) {
        if(presentInLevel(ptr,value,counter)) {
            return counter+1;
        }
    }
    return 0;
}

#endif /* LEVELOFNODE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
