/****************************************************************************************************************************************************
 *  File Name                   : levelordertraversal.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\levelordertraversal.h
 *  Created on                  : Oct 14, 2014 :: 1:25:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/level-order-tree-traversal/
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

#ifndef LEVELORDERTRAVERSAL_H_
#define LEVELORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void tLevelOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int levelCounter;
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
inrNode *tGetNextRightPtr(inrNode *ptr) {
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
void tConnectNodesAtSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    tConnectNodesAtSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = tGetNextRightPtr(ptr->nextRight);
        } else {
            ptr->left->nextRight = tGetNextRightPtr(ptr->nextRight);
        }
        tConnectNodesAtSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = tGetNextRightPtr(ptr->nextRight);
        tConnectNodesAtSameLevel(ptr->right);
    } else {
        tConnectNodesAtSameLevel(tGetNextRightPtr(ptr->nextRight));
    }
}

//Tested
void printNodesAfterConnecting(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    printf("%d\t",ptr->value);
    printNodesAfterConnecting(ptr->nextRight);
}

//Tested
void tLevelOrderNodesByConnecting(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    ptr->nextRight = null;
    tConnectNodesAtSameLevel(ptr);
    while(ptr != null) {
        printNodesAfterConnecting(ptr);
        if(ptr->left != null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = tGetNextRightPtr(ptr);
        }
    }
}

//Tested
void tConnectNodesAtSameLevelIterative(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    inrNode *outerCrawler = ptr,*innerCrawler;
    while(outerCrawler != null) {
        innerCrawler = outerCrawler;
        while(innerCrawler != null) {
            if(innerCrawler->left != null) {
                if(innerCrawler->right != null) {
                    innerCrawler->left->nextRight = innerCrawler->right;
                } else {
                    innerCrawler->left->nextRight = tGetNextRightPtr(innerCrawler->nextRight);
                }
            }
            if(innerCrawler->right != null) {
                innerCrawler->right->nextRight = tGetNextRightPtr(innerCrawler->nextRight);
            }
            innerCrawler  = innerCrawler->nextRight;
        }
        if(outerCrawler->left != null) {
            outerCrawler = outerCrawler->left;
        } else if(outerCrawler->right != null) {
            outerCrawler = outerCrawler->right;
        } else {
            outerCrawler = tGetNextRightPtr(outerCrawler->right);
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void tPrintLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    tPrintLevel(ptr->left,level-1);
    tPrintLevel(ptr->right,level-1);
}

//Tested
void printLevelOrderON2(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int heightOfTree = utils->getHeightOfTree(ptr);
    for(unsigned int counter = 0; counter < heightOfTree; counter++) {
        tPrintLevel(ptr,counter);
        PRINT_NEW_LINE;
    }
}

#endif /* LEVELORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
