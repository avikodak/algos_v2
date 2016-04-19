/****************************************************************************************************************************************************
 *  File Name                   : heightoftree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\heightoftree.h
 *  Created on                  : Oct 12, 2014 :: 12:50:23 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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

#ifndef HEIGHTOFTREE_H_
#define HEIGHTOFTREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int getHeightOfTree(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
}

//Tested
unsigned int getHeightOfTreePreorderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    auxSpace.push(ptr);
    itNode *currentNode;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    unsigned int maxIndex = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        maxIndex = max(maxIndex,itToNodeIndexMap->second);
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
        }
    }
    return log2(maxIndex)+1;
}

//Tested
unsigned int getHeightOfTreeInorderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    unsigned int maxIndex = 0;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            if(currentNode->left != null) {
                itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
            }
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
            maxIndex = max(maxIndex,itToNodeIndexMap->second);
            if(currentNode->right != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
            }
            currentNode = currentNode->right;
        }
    }
    return log2(maxIndex)+1;
}

//Tested
unsigned int getHeightOfTreePostorderTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    primaryAuxspace.push(ptr);
    itNode *currentNode;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    while(!primaryAuxspace.empty()) {
        currentNode = primaryAuxspace.top();
        primaryAuxspace.pop();
        secondaryAuxspace.push(currentNode);
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        if(currentNode->left != null) {
            primaryAuxspace.push(currentNode->left);
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
        }
        if(currentNode->right != null) {
            primaryAuxspace.push(currentNode->right);
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
        }
    }
    unsigned int maxIndex = 0;
    while(!secondaryAuxspace.empty()) {
        currentNode = secondaryAuxspace.top();
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        maxIndex = max(maxIndex,itToNodeIndexMap->second);
        secondaryAuxspace.pop();
    }
    return log2(maxIndex)+1;
}

//Tested
unsigned int getHeightOfTreePostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,0));
    unsigned int maxIndex = 0;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
            if(currentNode->right != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+2));
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second+1));
            }
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(!auxSpace.empty() && currentNode->right == auxSpace.top()) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
                maxIndex = max(maxIndex,itToNodeIndexMap->second);
                currentNode = null;
            }
        }
    }
    return log2(maxIndex) + 1;
}

//Tested
unsigned int getHeightOfTreePostOrderIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    unsigned int maxIndex = 0;
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,0));
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            if(currentNode->left != null) {
                itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second+1));
            }
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
            maxIndex = max(maxIndex,itToNodeIndexMap->second);
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
                maxIndex = max(maxIndex,itToNodeIndexMap->second);
                auxSpace.pop();
            }
        }
        if(!auxSpace.empty() && auxSpace.top()->right != null) {
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)auxSpace.top());
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)auxSpace.top()->right,2*itToNodeIndexMap->second+2));
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return log2(maxIndex)+1;
}

//Tested
unsigned int getHeightOfTreeLevelOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    queue<itNode *> auxSpace;
    auxSpace.push(ptr);
    itNode *currentNode;
    unsigned int levelCounter = 0,noOfNodesCounter;
    while(!auxSpace.empty()) {
        noOfNodesCounter = auxSpace.size();
        levelCounter+=1;
        while(noOfNodesCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
    }
    return levelCounter;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool areAnyNodesPresentInLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return false;
    }
    if(level == 0) {
        return true;
    }
    return areAnyNodesPresentInLevel(ptr->left,level-1) || areAnyNodesPresentInLevel(ptr->right,level-1);
}

//Tested
unsigned int getHeightOfTreeLevelOrderON2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int heightCounter = 0;
    while(areAnyNodesPresentInLevel(ptr,heightCounter)) {
        heightCounter++;
    }
    return heightCounter;
}

#endif /* HEIGHTOFTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
