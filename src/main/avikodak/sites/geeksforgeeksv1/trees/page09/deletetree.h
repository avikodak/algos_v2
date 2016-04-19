/****************************************************************************************************************************************************
 *  File Name                   : deletetree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\deletetree.h
 *  Created on                  : Oct 12, 2014 :: 7:06:22 PM
 *  Author                      : AVINASH
 *  Testing Status              : PARTIALLY TESTED // SHOULD CHECK VIA PTRS
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
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

#ifndef DELETETREE_H_
#define DELETETREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void deleteTreePreOrderMain(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *left = ptr->left,*right = ptr->right;
    free(ptr);
    deleteTreePreOrderMain(left);
    deleteTreePreOrderMain(right);
}

//Tested
void deletePreOrder(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    deleteTreePreOrderMain(*ptr);
    (*ptr) = null;
}

//Tested
void deletePreOrderIterative(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode,*left,*right;
    auxSpace.push(*ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        left = currentNode->left;
        right = currentNode->right;
        free(currentNode);
        if(left != null) {
            auxSpace.push(left);
        }
        if(right != null) {
            auxSpace.push(right);
        }
    }
    (*ptr) = null;
}

//Tested
void deleteTreeInOrderMain(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    deleteTreeInOrderMain(ptr->left);
    itNode *right = ptr->right;
    free(ptr);
    deleteTreeInOrderMain(right);
}

//Tested
void deleteInOrder(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    deleteTreeInOrderMain(*ptr);
    (*ptr) = null;
}

//Tested
void deleteInorderIterative(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = *ptr,*temp;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            temp = currentNode->right;
            free(currentNode);
            currentNode = temp;
        }
    }
    (*ptr) = null;
}

//Tested
void deleteTreePostOrderMain(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    deleteTreePostOrderMain(ptr->left);
    deleteTreePostOrderMain(ptr->right);
    free(ptr);
}

//Tested
void deleteTreePostOrder(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    deleteTreePostOrderMain(*ptr);
    (*ptr) = null;
}

//Tested
void deleteTreePostOrderIterativeTwoStacks(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    itNode *currentNode;
    primaryAuxspace.push(*ptr);
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
        free(currentNode);
    }
    (*ptr) = null;
}

//Tested
void deleteTreePostOrderIterative(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = *ptr;
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
            if(!auxSpace.empty() && auxSpace.top() == currentNode->right) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                free(currentNode);
                currentNode = null;
            }
        }
    }
    (*ptr) = null;
}

//Tested
void deleteTreePostOrderIterativeV2(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = *ptr;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    (*ptr) = null;
}

//Tested
void deleteTreeHashmap(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(*ptr)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        free(itToIndexNodeMap->second);
    }
    (*ptr) = null;
}

//Tested
void deleteTreeLevelOrderIterative(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(*ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        free(currentNode);
    }
    (*ptr) = null;
}

//Tested
inrNode *dGetNextRightNode(inrNode *ptr) {
    if(ptr == null) {
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
void dConnectNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    dConnectNodesAtSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = dGetNextRightNode(ptr->nextRight);
        } else {
            ptr->left->nextRight = dGetNextRightNode(ptr->nextRight);
        }
        dConnectNodesAtSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = dGetNextRightNode(ptr->nextRight);
        dConnectNodesAtSameLevel(ptr->right);
    } else {
        dConnectNodesAtSameLevel(ptr->nextRight);
    }
}

//Tested
void deleteLevelAfterConnecting(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    deleteLevelAfterConnecting(ptr->nextRight);
    free(ptr);
}

//Tested
void deleteTreeLevelOrder(inrNode **ptr) {
    if(*ptr == null) {
        return;
    }
    dConnectNodesAtSameLevel(*ptr);
    inrNode *crawler = *ptr;
    inrNode *temp;
    while(crawler != null) {
        temp = crawler;
        if(crawler->left != null) {
            crawler = crawler->left;
        } else if(crawler->right != null) {
            crawler = crawler->right;
        } else {
            crawler = dGetNextRightNode(crawler->nextRight);
        }
        deleteLevelAfterConnecting(temp);
    }
    (*ptr) = null;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void deleteLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        free(ptr);
        return;
    }
    deleteLevel(ptr->left,level-1);
    deleteLevel(ptr->right,level-1);
}

//Tested
void deleteLevelON2(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(*ptr);
    for(int level = height-1; level >= 0; level--) {
        deleteLevel(*ptr,level);
    }
    (*ptr) = null;
}

#endif /* DELETETREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
