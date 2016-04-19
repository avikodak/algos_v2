/****************************************************************************************************************************************************
 *  File Name                   : roottoleafsum.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\roottoleafsum.h
 *  Created on                  : Oct 17, 2014 :: 1:45:45 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
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

#ifndef ROOTTOLEAFSUM_H_
#define ROOTTOLEAFSUM_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool rootToLeafSumPreOrder(itNode *ptr,int sum) {
    if(ptr == null) {
        return false;
    }
    if(ptr->left == null && ptr->right == null) {
        return sum == ptr->value;
    }
    return rootToLeafSumPreOrder(ptr->left,sum - ptr->value) || rootToLeafSumPreOrder(ptr->right,sum - ptr->value);
}

//Tested
bool checkForSumStack(stack<int> userInput,int sum) {
    int currentSum = 0;
    while(!userInput.empty()) {
        currentSum += userInput.top();
        userInput.pop();
    }
    return currentSum == sum;
}

//Tested
bool rootToLeafSumAncestorsAuxspace(itNode *ptr,int sum,stack<int> ancestors) {
    if(ptr == null) {
        return sum == 0;
    }
    ancestors.push(ptr->value);
    if(ptr->left == null && ptr->right == null) {
        return checkForSumStack(ancestors,sum);
    }
    return rootToLeafSumAncestorsAuxspace(ptr->left,sum,ancestors) || rootToLeafSumAncestorsAuxspace(ptr->right,sum,ancestors);
}

//Tested
bool checkForSumRootToLeaf(hash_map<unsigned int,itNode *> indexNodeMap,unsigned int leafIndex,int sum) {
    if(leafIndex == 0) {
        return sum == 0;
    }
    int currentSum = 0;
    while(leafIndex > 0) {
        currentSum += indexNodeMap.find(leafIndex)->second->value;
        leafIndex /= 2;
    }
    return currentSum == sum;
}

//Tested
bool eRootToLeafSumPreOrderIterative(itNode *ptr,int sum) {
    if(ptr == null) {
        return sum == 0;
    }
    stack<itNode *> auxSpace;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<unsigned int,itNode *> indexNodeMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    itNode *currentNode;
    auxSpace.push(ptr);
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        if(currentNode->left == null && currentNode->right == null) {
            if(checkForSumRootToLeaf(indexNodeMap,itToNodeIndexMap->second,sum)) {
                return true;
            }
        } else {
            if(currentNode->right != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
                auxSpace.push(currentNode->left);
            }
        }
    }
    return false;
}

//Tested
bool rootToLeafSumInOrder(itNode *ptr,int sum,int runningSum = 0) {
    if(ptr == null) {
        return false;
    }
    bool leftTruthValue = rootToLeafSumInOrder(ptr->left,sum,runningSum + ptr->value);
    if(leftTruthValue) {
        return true;
    }
    if(ptr->left == null && ptr->right == null) {
        return runningSum + ptr->value == sum;
    } else {
        return rootToLeafSumInOrder(ptr->right,sum,runningSum + ptr->value);
    }
}

//Tested
bool checkForSumHashmap(hash_map<unsigned int,itNode *> indexNodeMap,int sum,unsigned int index) {
    int currentSum = 0;
    while(index > 0) {
        currentSum += indexNodeMap.find(index)->second->value;
        index /= 2;
    }
    return currentSum == sum;
}

//Tested
bool rootToLeafSumPreOrderIterative(itNode *ptr,int sum) {
    if(ptr == null) {
        return sum != 0;
    }
    stack<itNode *> auxSpace;
    auxSpace.push(ptr);
    itNode *currentNode;
    hash_map<unsigned int,itNode *> indexNodeMap;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
        if(currentNode->left == null && currentNode->right == null) {
            if(checkForSumHashmap(indexNodeMap,sum,itToNodeIndexMap->second)) {
                return true;
            }
        } else {
            if(currentNode->right != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,2*itToNodeIndexMap->second+1));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
                auxSpace.push(currentNode->left);
            }
        }
    }
    return false;
}

//Tested
bool rootToLeafSumPostOrderIterativeV2(itNode *ptr,int sum) {
    if(ptr == null) {
        return sum == 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    hash_map<unsigned int,itNode *> indexNodeMap;
    hash_map<intptr_t,unsigned int> nodeIndexMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
    indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
    nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
            if(currentNode->left != null) {
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,2*itToNodeIndexMap->second));
                indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
            }
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)currentNode);
            if(checkForSumHashmap(indexNodeMap,sum,itToNodeIndexMap->second)) {
                return true;
            }
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                if(checkForSumHashmap(indexNodeMap,sum,itToNodeIndexMap->second)) {
                    return true;
                }
            }
        }
        if(!auxSpace.empty() && auxSpace.top()->right != null) {
            itToNodeIndexMap = nodeIndexMap.find((intptr_t)auxSpace.top());
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)auxSpace.top()->right,2*itToNodeIndexMap->second+1));
            indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,auxSpace.top()->right));
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return false;
}

//Tested
bool rootToLeafSumHashmap(itNode *ptr,int sum) {
    if(ptr == null) {
        return sum == 0;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        if(indexNodeMap.find(2*itToIndexNodeMap->first) == indexNodeMap.end() && indexNodeMap.find(2*itToIndexNodeMap->first+1) == indexNodeMap.end()) {
            if(checkForSumRootToLeaf(indexNodeMap,itToIndexNodeMap->first,sum)) {
                return true;
            }
        }
    }
    return false;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* ROOTTOLEAFSUM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
