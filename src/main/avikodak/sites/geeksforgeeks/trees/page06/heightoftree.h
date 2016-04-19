/****************************************************************************************************************************************************
 *  File Name                   : heightoftree.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/trees/page06/heightoftree.h
 *  Created on                  : Feb 21, 2016 :: 5:18:46 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_HEIGHTOFTREE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_HEIGHTOFTREE_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
unsigned int getHeightOfTree(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
}

unsigned int getHeightOfTreeInOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    unsigned int subTreeHeight = 0;
    unsigned int leftHeight = getHeightOfTreeInOrder(ptr->left);
    subTreeHeight = 1+leftHeight;
    return max(subTreeHeight,1+getHeightOfTreeInOrder(ptr->right));
}

unsigned int getHeightOfTreePostOrder(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    return max(getHeightOfTreePostOrder(ptr->left),getHeightOfTreePostOrder(ptr->right))+1;
}

unsigned int getHeightOfTreeIterative(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    unsigned int heightOfTree = 0,levelSize;
    while(!auxSpace.empty()) {
        levelSize = auxSpace.size();
        while(levelSize--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            heightOfTree++;
        }
    }
    return heightOfTree;
}


/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
bool isNodePresentInLevel(itNode *ptr,unsigned int currentLevel) {
    if(ptr == null) {
        return false;
    }
    if(currentLevel == 0) {
        return true;
    }
    return isNodePresentInLevel(ptr->left,currentLevel-1) || isNodePresentInLevel(ptr->right,currentLevel-1);
}
unsigned int heightOfTreeON2(itNode *ptr) {
    if(ptr == null) {
        return 0;
    }
    for(unsigned int counter = 0;; counter++) {
        if(!isNodePresentInLevel(ptr,counter)) {
            return counter-1;
        }
    }
    return 0;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_HEIGHTOFTREE_H_ */
