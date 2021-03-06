/****************************************************************************************************************************************************
 *  File Name                   : sizeoftree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page10\sizeoftree.h
 *  Created on                  : Oct 10, 2014 :: 8:42:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SIZEOFTREE_H_
#define SIZEOFTREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int getSizeOfTreePreOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return 1 + getSizeOfTreePreOrder(ptr->left) + getSizeOfTreePreOrder(ptr->right);
}

//Tested
unsigned int getSizeOfTreePreOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int size = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        size += 1;
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
    return size;
}

//Tested
unsigned int getSizeOfTreeMorrisPreOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    itNode *currentNode = ptr,*temp;
    unsigned int counter = 0;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                counter += 1;
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            counter += 1;
            currentNode = currentNode->right;
        }
    }
    return counter;
}

//Tested
unsigned int getSizeOfTreeInOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return getSizeOfTreeInOrder(ptr->left) + 1 + getSizeOfTreeInOrder(ptr->right);
}

//Tested
unsigned int getSizeOfTreeInOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    unsigned int counter = 0;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            counter += 1;
            currentNode = currentNode->right;
        }
    }
    return counter;
}

//Tested
unsigned int getSizeOfTreeMorrisInOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    itNode *currentNode = ptr,*temp;
    unsigned int counter = 0;
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
                counter += 1;
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            counter += 1;
            currentNode = currentNode->right;
        }
    }
    return counter;
}

//Tested
void convertTreeToDll(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    convertTreeToDll(ptr->left);
    ptr->left = prevNode;
    if(prevNode != null) {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    convertTreeToDll(ptr->right);
}

//Tested
unsigned int getSizeOfTreeInOrderDllConversion(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int counter = 0;
    convertTreeToDll(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null) {
        ptr = ptr->right;
        counter += 1;
    }
    return counter;
}

//Tested
void sfixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    sfixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    sfixLeftPtr(ptr->right);
}

//Tested
void sfixRightPtr(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    itNode *currentNode = *ptr,*prevNode = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
    (*ptr) = prevNode;
}

//Tested
unsigned int sizeOfTreeInorderONConversion(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    sfixLeftPtr(ptr);
    sfixRightPtr(&ptr);
    unsigned int counter = 0;
    while(ptr != null) {
        counter += 1;
        ptr = ptr->right;
    }
    return counter;
}

//Tested
unsigned int getSizeOfTreePostOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return getSizeOfTreePostOrder(ptr->left) + getSizeOfTreePostOrder(ptr->right) + 1;
}

//Tested
unsigned int getSizeOfTreePostOrderTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    itNode *currentNode;
    primaryAuxspace.push(ptr);
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
    return secondaryAuxspace.size();
}

//Tested
unsigned int getSizeOfTreePostOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    unsigned int counter = 0;
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
                counter += 1;
                currentNode = null;
            }
        }
    }
    return counter;
}

//Tested
unsigned int getSizeOfTreePostOrderIterativeV2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    unsigned int counter = 0;
    while(!auxSpace.empty() || currentNode != null) {
        while(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if(!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            counter += 1;
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                counter += 1;
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
    return counter;
}

//Tested
unsigned int getSizeOfTreeLevelOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int counter = 0;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        counter += 1;
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
    return counter;
}

//Tested
inrNode *getNextRightNode(inrNode *ptr) {
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
void sConnectNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    connectNodesAtSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = getNextRightNode(ptr->nextRight);
        } else {
            ptr->left->nextRight = getNextRightNode(ptr->nextRight);
        }
        sConnectNodesAtSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = getNextRightNode(ptr->nextRight);
        sConnectNodesAtSameLevel(ptr->right);
    } else {
        sConnectNodesAtSameLevel(ptr->nextRight);
    }
}

//Tested
unsigned int getSizeOfTreeByConnectingNodesAtSameLevelMain(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return 1 + getSizeOfTreeByConnectingNodesAtSameLevelMain(ptr->nextRight);
}

//Tested
unsigned int getSizeOfTreeByConnectingNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    ptr->nextRight = null;
    sConnectNodesAtSameLevel(ptr);
    unsigned int sizeOfTree = 0;
    while(ptr != null) {
        sizeOfTree += getSizeOfTreeByConnectingNodesAtSameLevelMain(ptr);
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = getNextRightNode(ptr->nextRight);
        }
    }
    return sizeOfTree;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *convertTreeToDllON2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = convertTreeToDllON2(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = convertTreeToDllON2(ptr->right);
        while(temp->left != null) {
            temp  = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
unsigned int sizeOfTreeInOrderON2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    convertTreeToDllON2(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    unsigned int size = 0;
    while(ptr != null) {
        size += 1;
        ptr = ptr->right;
    }
    return size;
}

//Tested
unsigned int nodeLevelCounter(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return 0;
    }
    if(level == 0) {
        return 1;
    }
    return nodeLevelCounter(ptr->left,level-1) + nodeLevelCounter(ptr->right,level-1);
}

//Tested
unsigned int getSizeOfTreeLevelOrderON2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int size = 0;
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(unsigned int levelCounter = 0; levelCounter < height; levelCounter++) {
        size += nodeLevelCounter(ptr,levelCounter);
    }
    return size;
}

//Tested
inrNode *siGetNextRight(inrNode *ptr) {
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
void siConnectNodesAtSameLevelIterative(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    inrNode *outerCrawer = ptr,*innerCrawler;
    while(outerCrawer != null) {
        innerCrawler = outerCrawer;
        while(innerCrawler != null) {
            if(innerCrawler->left != null) {
                if(innerCrawler->right != null) {
                    innerCrawler->left->nextRight = innerCrawler->right;
                    innerCrawler->right->nextRight = siGetNextRight(innerCrawler->nextRight);
                } else {
                    innerCrawler->left->nextRight = siGetNextRight(innerCrawler->nextRight);
                }
            }
            if(innerCrawler->right != null) {
                innerCrawler->right->nextRight = siGetNextRight(innerCrawler->nextRight);
            }
            innerCrawler = innerCrawler->nextRight;
        }
        if(outerCrawer->left != null) {
            outerCrawer = outerCrawer->left;
        } else if(outerCrawer->right != null) {
            outerCrawer = outerCrawer->right;
        } else {
            outerCrawer = siGetNextRight(outerCrawer->nextRight);
        }
    }
}

//Tested
unsigned int sizeOfLevelAfterConnection(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int nodeCounter = 0;
    while(ptr != null) {
        nodeCounter += 1;
        ptr = ptr->nextRight;
    }
    return nodeCounter;
}

//Tested
unsigned int siSizeOfTreePostConnectingNodes(inrNode *ptr) {
    unsigned int sizeOfTree = 0;
    siConnectNodesAtSameLevelIterative(ptr);
    while(ptr != null) {
        sizeOfTree += sizeOfLevelAfterConnection(ptr);
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right  != null) {
            ptr = ptr->right;
        } else {
            ptr = siGetNextRight(ptr->nextRight);
        }
    }
    return sizeOfTree;
}

#endif /* SIZEOFTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
