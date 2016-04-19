/****************************************************************************************************************************************************
 *  File Name                   : depthofoddleafnode.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\depthofoddleafnode.h
 *  Created on                  : Nov 14, 2014 :: 12:04:40 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-depth-of-the-deepest-odd-level-node/
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

#ifndef DEPTHOFODDLEAFNODE_H_
#define DEPTHOFODDLEAFNODE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
unsigned int depthOfOddLeafNode(itNode *ptr,unsigned int currentLevel = 1) {
    if(ptr == null) {
        return 0;
    }
    if(ptr->left == null && ptr->right == null) {
        return currentLevel&1?currentLevel:0;
    }
    return max(depthOfOddLeafNode(ptr->left,currentLevel+1),depthOfOddLeafNode(ptr->right,currentLevel+1));
}

//Tested
unsigned int depthOfOddLeafNodeIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    queue<itNode *> auxSpace;
    unsigned int levelCounter = 0,nodeCounter,oddLevel = 0;
    auxSpace.push(ptr);
    itNode *currentNode = ptr;
    while(!auxSpace.empty()) {
        nodeCounter = auxSpace.size();
        levelCounter++;
        while(nodeCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(currentNode->left == null && currentNode->right == null) {
                if(levelCounter%2) {
                    oddLevel = max(oddLevel,levelCounter);
                }
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
    return oddLevel;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isLeafPresentInLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return false;
    }
    if(level == 0) {
        return ptr->left == null && ptr->right == null;
    }
    return isLeafPresentInLevel(ptr->left,level-1) || isLeafPresentInLevel(ptr->right,level-1);
}

//Tested
unsigned int getDepthOfOddLeafNode(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    unsigned int oddLevel = 0;
    for(unsigned int counter = 0; counter < height; counter += 2) {
        if(isLeafPresentInLevel(ptr,counter)) {
            oddLevel = max(oddLevel,counter+1);
        }
    }
    return oddLevel;
}

#endif /* DEPTHOFODDLEAFNODE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
