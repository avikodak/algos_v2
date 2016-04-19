/****************************************************************************************************************************************************
 *  File Name                   : printallnodesatkdistance.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printallnodesatkdistance.h
 *  Created on                  : Nov 16, 2014 :: 9:10:07 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
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

#ifndef PRINTALLNODESATKDISTANCE_H_
#define PRINTALLNODESATKDISTANCE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void setNodesForLevelInHashmap(itNode *ptr,int currentLevel,hash_map<unsigned int,vector<itNode *> > &levelNodeMap,int key,int &keyLevel,int &height) {
    if(ptr == null) {
        return;
    }
    height = max(height,currentLevel);
    hash_map<unsigned int,vector<itNode *> >::iterator itToLevelNodeMap = levelNodeMap.find(currentLevel);
    if(itToLevelNodeMap == levelNodeMap.end()) {
        vector<itNode *> levelList;
        levelList.push_back(ptr);
        levelNodeMap[currentLevel] = levelList;
    } else {
        itToLevelNodeMap->second.push_back(ptr);
    }
    if(key == ptr->value) {
        keyLevel = currentLevel;
    }
    setNodesForLevelInHashmap(ptr->left,currentLevel+1,levelNodeMap,key,keyLevel,height);
    setNodesForLevelInHashmap(ptr->right,currentLevel+1,levelNodeMap,key,keyLevel,height);
}

//Tested
void printNodesAtDistanceK(itNode *ptr,int value,int kValue) {
    if(ptr == null) {
        return;
    }
    int keyLevel = 0,height = 0;
    hash_map<unsigned int,vector<itNode *> > levelNodeMap;
    hash_map<unsigned int,vector<itNode *> >::iterator itToLevelNodeMap;
    setNodesForLevelInHashmap(ptr,1,levelNodeMap,value,keyLevel,height);
    while(height >= 0) {
        itToLevelNodeMap = levelNodeMap.find(height);
        if(itToLevelNodeMap == levelNodeMap.end()) {
            break;
        }
        height -= 2;
        for(unsigned int counter = 0; counter < itToLevelNodeMap->second.size(); counter++) {
            if(itToLevelNodeMap->second[counter]->value != value)
                printf("%d\t",itToLevelNodeMap->second[counter]->value);
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool pSetAncestorsForNode(itNode *ptr,int value,queue<itNode *> &ancestors) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        ancestors.push(ptr);
        return true;
    }
    bool truthValue = pSetAncestorsForNode(ptr->left,value,ancestors) || pSetAncestorsForNode(ptr->right,value,ancestors);
    if(truthValue) {
        ancestors.push(ptr);
    }
    return truthValue;
}

//Tested
void pPrintAllNodesAtLevel(itNode *ptr,unsigned int kLevel,int value) {
    if(ptr == null) {
        return;
    }
    if(kLevel == 0) {
        if(ptr->value != value)
            printf("%d\t",ptr->value);
        return;
    }
    pPrintAllNodesAtLevel(ptr->left,kLevel-1,value);
    pPrintAllNodesAtLevel(ptr->right,kLevel-1,value);
}

//Tested
void printAllNodesAtKDistance(itNode *ptr,int value,unsigned int kDistance) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> ancestors;
    pSetAncestorsForNode(ptr,value,ancestors);
    itNode *currentNode;
    while(kDistance > 0 && !ancestors.empty()) {
        currentNode = ancestors.front();
        ancestors.pop();
        pPrintAllNodesAtLevel(currentNode,kDistance,value);
        kDistance -= 1;
    }
}

iptNode *searchForNodes(iptNode *ptr,int value) {
    if(ptr == null) {
        return null;
    }
    if(ptr->value == value) {
        return ptr;
    }
    iptNode *leftResult = searchForNodes(ptr->left,value);
    if(leftResult != null) {
        return leftResult;
    }
    return searchForNodes(ptr->right,value);
}

void printAllNodesAtLevel(iptNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    printAllNodesAtLevel(ptr->left,level-1);
    printAllNodesAtLevel(ptr->right,level-1);
}

void printAllNodesAtKDistance(iptNode *ptr,unsigned int kDistance,int value) {
    if(ptr == null) {
        return;
    }
    iptNode *currentNode = searchForNodes(ptr,value);
    while(currentNode != null && kDistance > 0) {
        printf("asd");
        printAllNodesAtLevel(currentNode,kDistance);
        kDistance -= 1;
        currentNode = currentNode->parent;
    }
}

#endif /* PRINTALLNODESATKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
