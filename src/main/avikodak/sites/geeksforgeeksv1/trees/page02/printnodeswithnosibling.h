/****************************************************************************************************************************************************
 *  File Name                   : printnodeswithnosibling.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printnodeswithnosibling.h
 *  Created on                  : Nov 15, 2014 :: 5:45:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/
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

#ifndef PRINTNODESWITHNOSIBLING_H_
#define PRINTNODESWITHNOSIBLING_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printNodesWithNoSiblingsPreOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    if(ptr->left == null && ptr->right == null) {
        return;
    }
    if(ptr->left == null || ptr->right == null) {
        if(ptr->left == null) {
            printf("%d\t",ptr->right->value);
        } else {
            printf("%d\t",ptr->left->value);
        }
    }
    printNodesWithNoSiblingsPreOrder(ptr->left);
    printNodesWithNoSiblingsPreOrder(ptr->right);
}

//Tested
void printNodesWithNoSiblingsPreOrderIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if(currentNode->left == null && currentNode->right == null) {
            continue;
        }
        if(currentNode->left == null || currentNode->right == null) {
            if(currentNode->left == null) {
                printf("%d\t",currentNode->right->value);
            } else {
                printf("%d\t",currentNode->left->value);
            }
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

//Tested
void printNodesWithNoSiblingsPostOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    if(ptr->left == null && ptr->right == null) {
        return;
    }
    printNodesWithNoSiblingsPostOrder(ptr->left);
    printNodesWithNoSiblingsPostOrder(ptr->right);
    if(ptr->left == null || ptr->right == null) {
        if(ptr->left == null) {
            printf("%d\t",ptr->right->value);
        } else {
            printf("%d\t",ptr->left->value);
        }
    }
}

//Tested
void printSiblingNode(itNode *currentNode) {
    if(currentNode->left != null || currentNode->right != null) {
        if(currentNode->left == null || currentNode->right == null) {
            if(currentNode->left == null) {
                printf("%d\t",currentNode->right->value);
            } else {
                printf("%d\t",currentNode->left->value);
            }
        }
    }
}

//Tested
void printNodesWithNoSiblingsPostOrderTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return;
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
    while(!secondaryAuxspace.empty()) {
        currentNode = secondaryAuxspace.top();
        secondaryAuxspace.pop();
        printSiblingNode(currentNode);
    }
}

//Tested
void printNodesWithNoSiblingsPostOrderIterative(itNode *ptr) {
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
            if(!auxSpace.empty() && auxSpace.top() == currentNode->right) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                printSiblingNode(currentNode);
                currentNode = null;
            }
        }
    }
}

//Tested
void printNodesWithNoSiblingsPostOrderIterativeV2(itNode *ptr) {
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
            auxSpace.pop();
            printSiblingNode(currentNode);
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                printSiblingNode(currentNode);
            }
        }
        currentNode = auxSpace.empty()?null:auxSpace.top()->right;
    }
}

//Tested
inrNode *psGetNextRightPtr(inrNode *ptr) {
    inrNode *currentNode = ptr;
    while(currentNode != null) {
        if(currentNode->left != null) {
            return currentNode->left;
        } else if(currentNode->right != null) {
            return currentNode->right;
        }
        currentNode = currentNode->nextRight;
    }
    return null;
}

//Tested
void psConnectNodesInSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    psConnectNodesInSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = psGetNextRightPtr(ptr->nextRight);
        } else {
            ptr->left->nextRight = psGetNextRightPtr(ptr->nextRight);
        }
        psConnectNodesInSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = psGetNextRightPtr(ptr->nextRight);
        psConnectNodesInSameLevel(ptr->right);
    } else {
        psConnectNodesInSameLevel(ptr->nextRight);
    }
}

//Tested
void printSiblingsIfPresentInLevel(inrNode *ptr) {
    while(ptr != null) {
        if(ptr->left == null || ptr->right == null) {
            if(ptr->left != null) {
                printf("%d\t",ptr->left->value);
            } else if(ptr->right != null) {
                printf("%d\t",ptr->right->value);
            }
        }
        ptr = ptr->nextRight;
    }
}

//Tested
void printNodesWithoutSiblings(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    psConnectNodesInSameLevel(ptr);
    while(ptr != null) {
        printSiblingsIfPresentInLevel(ptr);
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = psGetNextRightPtr(ptr->nextRight);
        }
    }
}

#endif /* PRINTNODESWITHNOSIBLING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
