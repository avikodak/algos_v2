/****************************************************************************************************************************************************
 *  File Name                   : treetraversals.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/trees/page16/treetraversals.h
 *  Created on                  : Mar 2, 2017 :: 8:33:32 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETRAVERSALS_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETRAVERSALS_H_

void preOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    printf("%d\t", ptr->value);
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

void preOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while (!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

void morrisPreOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    itNode *currentNode = ptr;
    itNode *temp;
    while (currentNode != null) {
        if (currentNode->left != null) {
            temp = currentNode->left;
            while (temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if (temp->right == null) {
                printf("%d\t", currentNode->value);
                temp->right = currentNode;
            } else {
                temp->right = null;
            }
        } else {
            printf("%d\t", currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

void inOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    inOrderTraversal(ptr->left);
    printf("%d\t", ptr->value);
    inOrderTraversal(ptr->right);
}

void inOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while (!auxSpace.empty() || currentNode != null) {
        if (currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            printf("%d\t", currentNode->value);
            auxSpace.pop();
            currentNode = currentNode->right;
        }
    }
}

void morrisInOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    itNode *currentNode = ptr;
    itNode *temp;
    while (currentNode != null) {
        if (currentNode->left != null) {
            temp = currentNode->left;
            while (temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if (temp->right == null) {
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                printf("%d\t", currentNode->value);
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            printf("%d\t", currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

void inOrderTraversalConversionToDllON(itNode *ptr) {
    static itNode *prevPtr = null;
    if (ptr == null) {
        return;
    }
    inOrderTraversalConversionToDllON(ptr->left);
    if (prevPtr != null) {
        prevPtr->right = ptr;
    }
    ptr->left = prevPtr;
    prevPtr = ptr;
    inOrderTraversalConversionToDllON(ptr->left);
}

void fixLeftPtr(itNode *ptr) {
    if (ptr == null) {
        return;
    }
}

void inOrderTraversalConversionToDllONFixingPtr(itNode *ptr) {
    if (ptr == null) {
        return;
    }
}

void postOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    printf("%d\t", ptr->value);
}

void postOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> primaryAuxSpace, secondaryAuxSpace;
    itNode *currentNode;
    primaryAuxSpace.push(ptr);
    while (!primaryAuxSpace.empty()) {
        currentNode = primaryAuxSpace.top();
        primaryAuxSpace.pop();
        secondaryAuxSpace.push(currentNode);
        if (currentNode->left != null) {
            primaryAuxSpace.push(currentNode->left);
        }
        if (currentNode->right != null) {
            primaryAuxSpace.push(currentNode->right);
        }
    }
    while (!secondaryAuxSpace.empty()) {
        currentNode = secondaryAuxSpace.top();
        secondaryAuxSpace.pop();
        printf("%d\t", currentNode->value);
    }
}

void postOrderTraversalIterativeAuxSpace(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while (!auxSpace.empty() || currentNode != null) {
        if (currentNode != null) {
            if (currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            if (!auxSpace.empty() && auxSpace.top() == currentNode->right) {
                auxSpace.pop();
                auxSpace.push(currentNode);
                currentNode = currentNode->right;
            } else {
                printf("%d\t", currentNode->value);
                currentNode = null;
            }
        }
    }
}

void postOrderTraversalIterativeAuxSpaceV2(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    while (!auxSpace.empty() || currentNode != null) {
        while (currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        }
        if (!auxSpace.empty() && auxSpace.top()->right == null) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t", currentNode->value);
            while (!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                printf("%d\t", currentNode->value);
            }
        }
        currentNode = auxSpace.empty() ? null : auxSpace.top()->right;
    }
}

void levelOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while (!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
}

void printLevel(itNode *ptr, int level) {
    if (ptr == null) {
        return;
    }
    if (level == 0) {
        printLevel(ptr->left, level - 1);
        return;
    }
    printLevel(ptr->left, level - 1);
    printLevel(ptr->right, level - 1);
}

int heightOfTree(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    return 1 + max(heightOfTree(ptr->left), heightOfTree(ptr->right));
}

void levelOrderTraversalByPrintingLevel(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    int height = heightOfTree(ptr);
    for (int levelCounter = 0; levelCounter < height; levelCounter++) {
        printLevel(ptr, levelCounter);
    }
}

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETRAVERSALS_H_ */
