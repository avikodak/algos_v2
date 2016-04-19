/****************************************************************************************************************************************************
 *  File Name   		: reversealternatelevels.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\reversealternatelevels.h
 *  Created on			: Nov 16, 2014 :: 11:27:58 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef REVERSEALTERNATELEVELS_H_
#define REVERSEALTERNATELEVELS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
//Works only for full tree
void setVectorWithInorderNodesInAlternateLevels(itNode *ptr,vector<int> &alternateInorderNodes) {
    if(ptr == null) {
        return;
    }
    setVectorWithInorderNodesInAlternateLevels(ptr->left,alternateInorderNodes);
    alternateInorderNodes.push_back(ptr->value);
    setVectorWithInorderNodesInAlternateLevels(ptr->right,alternateInorderNodes);
}

//Tested
void setTreeWithVectorInAlternateLevels(itNode *ptr,vector<int> inorderNodes) {
    static unsigned int indexCounter = 0;
    if(ptr == null || indexCounter >= inorderNodes.size()) {
        return;
    }
    setTreeWithVectorInAlternateLevels(ptr->left,inorderNodes);
    ptr->value = inorderNodes[indexCounter++];
    setTreeWithVectorInAlternateLevels(ptr->right,inorderNodes);
}

//Tested
void reverseNodesInAlternateLevel(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    vector<int> inorderNodesOfAlternateLevels;
    setVectorWithInorderNodesInAlternateLevels(ptr,inorderNodesOfAlternateLevels);
    reverse(inorderNodesOfAlternateLevels.begin(),inorderNodesOfAlternateLevels.end());
    setTreeWithVectorInAlternateLevels(ptr,inorderNodesOfAlternateLevels);
}

//Tested
void reverseAlternateLevels(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<int> reversedLevel;
    queue<itNode *> auxSpace;
    queue<int> reversedAlternateValues;
    unsigned int nodeCounter = 0;
    auxSpace.push(ptr);
    itNode *currentNode;
    bool flag = false;
    while(!auxSpace.empty()) {
        nodeCounter = auxSpace.size();
        while(nodeCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(flag) {
                reversedLevel.push(currentNode->value);
            }
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
        if(flag) {
            while(!reversedLevel.empty()) {
                reversedAlternateValues.push(reversedLevel.top());
                reversedLevel.pop();
            }
        }
        flag = !flag;
    }
    flag = false;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        nodeCounter = auxSpace.size();
        while(nodeCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(flag) {
                currentNode->value = reversedAlternateValues.front();
                reversedAlternateValues.pop();
            }
            if(currentNode->left  != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
        flag = !flag;
    }
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setValuesInVectorFromLevel(itNode *ptr,unsigned int level,vector<int> &valuesInLevel) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        valuesInLevel.push_back(ptr->value);
        return;
    }
    setValuesInVectorFromLevel(ptr->left,level-1,valuesInLevel);
    setValuesInVectorFromLevel(ptr->right,level-1,valuesInLevel);
}

//Tested
void setValuesInTreeIntoLevel(itNode *ptr,unsigned int level,vector<int> &valuesInLevel,unsigned int &index) {
    if(index >= valuesInLevel.size() || ptr == null) {
        return;
    }
    if(level == 0) {
        ptr->value = valuesInLevel[index++];
        return;
    }
    setValuesInTreeIntoLevel(ptr->left,level-1,valuesInLevel,index);
    setValuesInTreeIntoLevel(ptr->right,level-1,valuesInLevel,index);
}

//Tested
void reverseAlternateLevel(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    unsigned int height = utils->getHeightOfTree(ptr);
    vector<int> levelNodeValues;
    unsigned int index;
    for(unsigned int counter = 1; counter < height; counter += 2) {
        levelNodeValues.clear();
        setValuesInVectorFromLevel(ptr,counter,levelNodeValues);
        reverse(levelNodeValues.begin(),levelNodeValues.end());
        index = 0;
        setValuesInTreeIntoLevel(ptr,counter,levelNodeValues,index);
    }
}

#endif /* REVERSEALTERNATELEVELS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
