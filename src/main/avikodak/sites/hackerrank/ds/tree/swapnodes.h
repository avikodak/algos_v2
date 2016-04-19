/****************************************************************************************************************************************************
 *  File Name                   : swapnodes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\swapnodes.h
 *  Created on                  : Jul 14, 2015 :: 9:13:58 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/swap-nodes-algo
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef SWAPNODES_H_
#define SWAPNODES_H_

//Tested
void inorderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    inorderTraversal(ptr->left);
    printf("%d ",ptr->value);
    inorderTraversal(ptr->right);
}

//Tested
void swapAtMultipleLevels(itNode *ptr,int currentLevel,int target) {
    if(ptr == null) {
        return;
    }
    if(currentLevel%target == 0) {
        itNode *temp = ptr->right;
        ptr->right = ptr->left;
        ptr->left = temp;
    }
    swapAtMultipleLevels(ptr->left,currentLevel+1,target);
    swapAtMultipleLevels(ptr->right,currentLevel+1,target);
}

//Tested
void swapNodes() {
    unsigned int noOfNodes;
    scanf("%u",&noOfNodes);
    itNode *root = new itNode(1);
    itNode *node;
    int leftChild,rightChild;
    map<unsigned int,itNode *> indexNodeMap;
    indexNodeMap.insert(pair<unsigned int,itNode *>(1,root));
    map<unsigned int,itNode *>::iterator itToIndexNodeMap;
    for(unsigned int counter = 1; counter <= noOfNodes; counter++) {
        scanf("%d %d",&leftChild,&rightChild);
        itToIndexNodeMap = indexNodeMap.find(counter);
        node  = itToIndexNodeMap->second;
        if(leftChild != -1) {
            node->left = new itNode(leftChild);
            indexNodeMap.insert(pair<unsigned int,itNode *>(leftChild,node->left));
        }
        if(rightChild != -1) {
            node->right = new itNode(rightChild);
            indexNodeMap.insert(pair<unsigned int,itNode *>(rightChild,node->right));
        }
    }
    unsigned int testCases;
    scanf("%u",&testCases);
    int userInput;
    while(testCases--) {
        scanf("%d",&userInput);
        swapAtMultipleLevels(root,1,userInput);
        inorderTraversal(root);
        printf("\n");
    }
}

#endif /* SWAPNODES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
