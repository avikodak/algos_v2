/****************************************************************************************************************************************************
 *  File Name                   : treetraversals.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page10\treetraversals.h
 *  Created on                  : Oct 9, 2014 :: 1:49:46 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/618/
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

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_

/****************************************************************************************************************************************************/
/*                                                             PRE ORDER TRAVERSALS                                                                    */
/****************************************************************************************************************************************************/
//Tested
void preOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    printf("%d\t",ptr->value);
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

//Tested
void preOrderTraversalIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while(currentNode != null && !auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        printf("%d\t",currentNode->value);
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

//Tested
void morrisPreOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                temp->right = currentNode;
                printf("%d\t",currentNode->value);
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                             POST ORDER TRAVERSAL                                                                     */
/****************************************************************************************************************************************************/
//Tested
void postOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    printf("%d\t",ptr->value);
}

//Tested
void postOrderIterativeTwoStacks(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> primaryAuxspace,secondaryAuxspace;
    itNode *currentNode;
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
        printf("%d\t",currentNode->value);
    }
}

//Tested
void postOrderIterative(itNode *ptr) {
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
                printf("%d\t",currentNode->value);
                currentNode = null;
            }
        }
    }
}

//Tested
void postOrderIterativeV2(itNode *ptr) {
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
            printf("%d\t",currentNode->value);
            while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                printf("%d\t",currentNode->value);
                auxSpace.pop();
            }
        }
        currentNode = auxSpace.empty()?NULL:auxSpace.top()->right;
    }
}

/****************************************************************************************************************************************************/
/*                                                             IN ORDER TRAVERSAL                                                                        */
/****************************************************************************************************************************************************/
//Tested
void inOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inOrderTraversal(ptr->left);
    printf("%d\t",ptr->value);
    inOrderTraversal(ptr->right);
}

//Tested
void inOrderTraversalIterative(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while(currentNode != null || !auxSpace.empty()) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

//Tested
void morrisInOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
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
                printf("%d\t",currentNode->value);
                currentNode = currentNode->right;
            }
        } else {
            printf("%d\t",currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

//Tested
void inOrderTraversalDllConversionMain(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevPtr = null;
    inOrderTraversalDllConversionMain(ptr->left);
    ptr->left = prevPtr;
    if(prevPtr != null) {
        prevPtr->right = ptr;
    }
    prevPtr = ptr;
    inOrderTraversalDllConversionMain(ptr->right);
}

//Tested
void inOrderTraversalDllConversion(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inOrderTraversalDllConversionMain(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}


//Tested
void fixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevPtr = null;
    fixLeftPtr(ptr->left);
    ptr->left = prevPtr;
    prevPtr = ptr;
    fixLeftPtr(ptr->right);
}

//Tested
void fixRightPtr(itNode **ptr) {
    if((*ptr) == null) {
        return;
    }
    itNode *currentNode = *ptr;
    itNode *prevPtr = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    while(currentNode != null) {
        currentNode->right = prevPtr;
        prevPtr = currentNode;
        currentNode = currentNode->left;
    }
    (*ptr) = prevPtr;
}

//Tested
void inOrderTraversalON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    fixLeftPtr(ptr);
    fixRightPtr(&ptr);
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

//Tested
itNode *inOrderTraversalON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = inOrderTraversalON2Main(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = inOrderTraversalON2Main(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
void inOrderTraversalON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inOrderTraversalON2Main(ptr);
    while(ptr->left != null) {
        ptr = ptr->left;
    }
    while(ptr != null) {
        printf("%d\t",ptr->value);
        ptr = ptr->right;
    }
}

/****************************************************************************************************************************************************/
/*                                                             LEVEL ORDER TRAVERSAL                                                                    */
/****************************************************************************************************************************************************/
//Tested
void levelOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int levelCounter = 1;
    while(!auxSpace.empty()) {
        levelCounter = auxSpace.size();
        while(levelCounter--) {
            currentNode = auxSpace.front();
            printf("%d\t",currentNode->value);
            auxSpace.pop();
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
        PRINT_NEW_LINE;
    }
}

//Tested
void printLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    printLevel(ptr->left,level-1);
    printLevel(ptr->right,level-1);
}

//Tested
void levelOrderTraversalON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    for(unsigned int levelCounter = 0; levelCounter < height; levelCounter++) {
        printLevel(ptr,levelCounter);
        PRINT_NEW_LINE;
    }
}

//Tested
inrNode *getNextRight(inrNode *ptr) {
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
void connectNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    connectNodesAtSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = getNextRight(ptr->nextRight);
        } else {
            ptr->left->nextRight = getNextRight(ptr->nextRight);
        }
        connectNodesAtSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = getNextRight(ptr->nextRight);
        connectNodesAtSameLevel(ptr->right);
    } else {
        connectNodesAtSameLevel(ptr->nextRight);
    }
}

//Tested
void printNodesAfterConnectingNodes(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    printf("%d\t",ptr->value);
    printNodesAfterConnectingNodes(ptr->nextRight);
}

//Tested
void levelOrderTraversal(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    ptr->nextRight = null;
    connectNodesAtSameLevel(ptr);
    inrNode *crawler = ptr;
    while(crawler != null) {
        printNodesAfterConnectingNodes(crawler);
        if(crawler->left != null) {
            crawler = crawler->left;
        } else if(crawler->right != null) {
            crawler = crawler->right;
        } else {
            crawler = getNextRight(crawler->nextRight);
        }
        PRINT_NEW_LINE;
    }
}

//Tested
void connectNodesAtSameLevelIterative(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    inrNode *currentNode = ptr,*crawler;
    while(currentNode != null) {
        crawler = currentNode;
        while(crawler != null) {
            if(crawler->left != null) {
                if(crawler->right != null) {
                    crawler->left->nextRight = crawler->right;
                    crawler->right->nextRight = getNextRight(crawler->nextRight);
                } else {
                    crawler->left->nextRight = getNextRight(crawler->nextRight);
                }
            }
            if(crawler->right != null) {
                crawler->right->nextRight = getNextRight(crawler->nextRight);
            }
            crawler = crawler->nextRight;
        }
        if(currentNode->left != null) {
            currentNode = currentNode->left;
        } else if(currentNode->right != null) {
            currentNode = currentNode->right;
        } else {
            currentNode = getNextRight(currentNode);
        }
    }
}

#endif /* TREETRAVERSALS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
