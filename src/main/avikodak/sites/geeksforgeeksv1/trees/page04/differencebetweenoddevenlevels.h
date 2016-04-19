/****************************************************************************************************************************************************
 *  File Name                   : differencebetweenoddevenlevels.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\differencebetweenoddevenlevels.h
 *  Created on                  : Nov 14, 2014 :: 5:26:34 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/
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

#ifndef DIFFERENCEBETWEENODDEVENLEVELS_H_
#define DIFFERENCEBETWEENODDEVENLEVELS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int differenceBetweenEvenOddLevels(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return ptr->value - differenceBetweenEvenOddLevels(ptr->left) - differenceBetweenEvenOddLevels(ptr->right);
}

//Tested
int differenceBetweenEvenOddLevelsIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    int difference = 0;
    queue<itNode *> auxSpace;
    itNode *currentNode = ptr;
    auxSpace.push(currentNode);
    unsigned int nodeCounter = 0;
    bool isOddLevel = true;
    while(!auxSpace.empty()) {
        nodeCounter = auxSpace.size();
        while(nodeCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            difference += isOddLevel?currentNode->value:-currentNode->value;
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
        isOddLevel = !isOddLevel;
    }
    return difference;
}

//Tested
inrNode *dGetNextRightPtr(inrNode *ptr) {
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
void connectNodesInSameLevel(inrNode *ptr) {
    if(ptr == null) {
        return;
    }
    connectNodesInSameLevel(ptr->nextRight);
    if(ptr->left != null) {
        if(ptr->right != null) {
            ptr->left->nextRight = ptr->right;
            ptr->right->nextRight = dGetNextRightPtr(ptr->nextRight);
        } else {
            ptr->left->nextRight = dGetNextRightPtr(ptr->nextRight);
        }
        connectNodesInSameLevel(ptr->left);
    } else if(ptr->right != null) {
        ptr->right->nextRight = dGetNextRightPtr(ptr->nextRight);
        connectNodesInSameLevel(ptr->right);
    } else {
        connectNodesInSameLevel(ptr->nextRight);
    }
}

//Tested
int sumOfNodesInLevel(inrNode *ptr) {
    int sum = 0;
    while(ptr != null) {
        sum += ptr->value;
        ptr = ptr->nextRight;
    }
    return sum;
}

//Tested
int differenceOfNodes(inrNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    connectNodesInSameLevel(ptr);
    //inrNode *currentNode = ptr;
    int difference  = 0;
    bool isOddLevel = true;
    while(ptr != null) {
        if(isOddLevel) {
            difference += sumOfNodesInLevel(ptr);
        } else {
            difference -= sumOfNodesInLevel(ptr);
        }
        if(ptr->left !=  null) {
            ptr = ptr->left;
        } else if(ptr->right != null) {
            ptr = ptr->right;
        } else {
            ptr = getNextRight(ptr->nextRight);
        }
        isOddLevel = !isOddLevel;
    }
    return difference;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int sumOfNodesInLevel(itNode *ptr,int level) {
    if(ptr == null) {
        return 0;
    }
    if(level == 0) {
        return ptr->value;
    }
    return sumOfNodesInLevel(ptr->left,level-1) + sumOfNodesInLevel(ptr->right,level-1);
}

//Tested
int differenceValueBetweenLevels(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    bool isOddLevel = true;
    int difference = 0;
    for(unsigned int counter = 0; counter < height; counter++) {
        if(isOddLevel) {
            difference += sumOfNodesInLevel(ptr,counter);
        } else {
            difference -= sumOfNodesInLevel(ptr,counter);
        }
        isOddLevel = !isOddLevel;
    }
    return difference;
}

#endif /* DIFFERENCEBETWEENODDEVENLEVELS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/

