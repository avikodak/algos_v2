/****************************************************************************************************************************************************
 *  File Name                   : countleafnodes.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\countleafnodes.h
 *  Created on                  : Oct 15, 2014 :: 12:25:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
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

#ifndef COUNTLEAFNODES_H_
#define COUNTLEAFNODES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int countLeafNodesPreOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->left == null && ptr->right == null) {
        return 1;
    }
    return countLeafNodesPreOrderTraversal(ptr->left) + countLeafNodesPreOrderTraversal(ptr->right);
}

//Tested
unsigned int countLeafNodesPreOrderIterative(itNode *ptr) {
    if(ptr == 0) {
        return 0;
    }
    stack<itNode *> auxSpace;
    auxSpace.push(ptr);
    itNode *currentNode;
    unsigned int leafCounter = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if(currentNode->left == null && currentNode->right == null) {
            leafCounter++;
        } else {
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeafNodesMorrisTraversal(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    itNode *currentNode = ptr,*temp;
    unsigned int leafCounter = 0;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                if(temp->left == null && temp->right == null) {
                    leafCounter++;
                }
                currentNode = currentNode->right;
            }
        } else {
            if(currentNode->left == null && currentNode->right == null) {
                leafCounter++;
            }
            currentNode = currentNode->right;
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeafNodesInOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int leafNodeCounter = 0;
    leafNodeCounter = countLeafNodesInOrderTraversal(ptr->left);
    if(ptr->left == null && ptr->right == null) {
        leafNodeCounter++;
    }
    return leafNodeCounter + countLeafNodesInOrderTraversal(ptr->right);
}

//Tested
unsigned int countLeafNodesInorderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    unsigned int leafCounter = 0;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if(currentNode->left == 0 && currentNode->right == 0) {
                leafCounter++;
            }
            currentNode = currentNode->right;
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeafNodesPostOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int leafNodeCounter = 0;
    leafNodeCounter = countLeafNodesPostOrderTraversal(ptr->left);
    leafNodeCounter += countLeafNodesPostOrderTraversal(ptr->right);
    return ptr->left == null && ptr->right == null?1+leafNodeCounter:leafNodeCounter;
}

//Tested
unsigned int countLeafPostOrderIterativeTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    unsigned int leafCounter = 0;
    itNode *currentNode = ptr;
    primaryAuxspace.push(ptr);
    while(!primaryAuxspace.empty()) {
        currentNode = primaryAuxspace.top();
        secondaryAuxspace.push(currentNode);
        primaryAuxspace.pop();
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
        if(currentNode->left == null && currentNode->right == null) {
            leafCounter++;
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeavesPostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    unsigned int leafCounter = 0;
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
                if(currentNode->left == null && currentNode->right == null) {
                    leafCounter++;
                }
                currentNode = null;
            }
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeavesLevelOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int leafCounter=0,levelCounter;
    while(!auxSpace.empty()) {
        levelCounter = auxSpace.size();
        while(levelCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(currentNode->left == null && currentNode->right == null) {
                leafCounter++;
            } else {
                if(currentNode->left != null) {
                    auxSpace.push(currentNode->left);
                }
                if(currentNode->right != null) {
                    auxSpace.push(currentNode->right);
                }
            }
        }
    }
    return leafCounter;
}

//Tested
unsigned int countLeavesHashMap(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr)->indexNodeMap;
    hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    unsigned int leafCounter = 0;
    for(itToIndexNodeMap = indexNodeMap.begin(); itToIndexNodeMap != indexNodeMap.end(); itToIndexNodeMap++) {
        ptr = itToIndexNodeMap->second;
        if(ptr->left == null && ptr->right == null) {
            leafCounter++;
        }
    }
    return leafCounter;
}

//Tested
inrNode *clnGetNextRight(inrNode *ptr) {
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
void clnConnectNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    clnConnectNodesAtSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = clnGetNextRight(ptr->nextRight);
        } else {
            ptr->left->nextRight = clnGetNextRight(ptr->nextRight);
        }
        clnConnectNodesAtSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = clnGetNextRight(ptr->nextRight);
        clnConnectNodesAtSameLevel(ptr->right);
    } else {
        clnConnectNodesAtSameLevel(ptr->nextRight);
    }
}

//Tested
unsigned int clnCountLeafNodesPostConnecting(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int leafCounter = 0;
    while(ptr != null) {
        if(ptr->left == null && ptr->right == null) {
            leafCounter += 1;
        }
        ptr = ptr->nextRight;
    }
    return leafCounter;
}

//Tested
unsigned int countLeafNodes(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    clnConnectNodesAtSameLevel(ptr);
    unsigned int leafCounter = 0;
    while(ptr != null) {
        leafCounter += clnCountLeafNodesPostConnecting(ptr);
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = clnGetNextRight(ptr);
        }
    }
    return leafCounter;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int countLeavesLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return 0;
    }
    if(level == 0) {
        return ptr->left == null && ptr->right == null?1:0;
    }
    return countLeavesLevel(ptr->left,level-1) + countLeavesLevel(ptr->right,level-1);
}

//Tested
unsigned int countLeavesLevelOrderTraversalON2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int leafCounter = 0;
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(unsigned int levelCounter = 0; levelCounter < height; levelCounter++) {
        leafCounter += countLeavesLevel(ptr,levelCounter);
    }
    return leafCounter;
}

#endif /* COUNTLEAFNODES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
