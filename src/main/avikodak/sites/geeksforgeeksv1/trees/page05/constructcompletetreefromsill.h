/****************************************************************************************************************************************************
 *  File Name                   : constructcompletetreefromsill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\constructcompletetreefromsill.h
 *  Created on                  : Nov 13, 2014 :: 1:05:02 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
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

#ifndef CONSTRUCTCOMPLETETREEFROMSILL_H_
#define CONSTRUCTCOMPLETETREEFROMSILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
itNode *constructTreeFromSill(sillNode *head) {
    if(head == null) {
        return null;
    }
    itNode *root = new itNode(head->value);
    sillNode *crawler = head->next;
    queue<itNode *> auxSpace;
    auxSpace.push(root);
    itNode *currentNode;
    while(crawler != null) {
        currentNode = auxSpace.front();
        if(currentNode->left == null) {
            currentNode->left = new itNode(crawler->value);
            auxSpace.push(currentNode->left);
        } else {
            currentNode->right = new itNode(crawler->value);
            auxSpace.push(currentNode->right);
            auxSpace.pop();
        }
        crawler = crawler->next;
    }
    return root;
}

//Tested
itNode *constructTreeFromSillHashmap(sillNode *head) {
    if(head == null) {
        return null;
    }
    hash_map<unsigned int,int> indexValueMap;
    unsigned int counter = 1;
    sillNode *crawler = head;
    while(crawler != null) {
        indexValueMap.insert(pair<unsigned int,int>(counter++,crawler->value));
        crawler = crawler->next;
    }
    treeutils *utils = new treeutils();
    return utils->getITreeFromHashmap(indexValueMap);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void insertValueIntoTree(itNode **root,int value) {
    if(*root == null) {
        (*root) = new itNode(value);
        return;
    }
    queue<itNode *> auxSpace;
    auxSpace.push(*root);
    itNode *currentNode;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        } else {
            currentNode->left = new itNode(value);
            return;
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        } else {
            currentNode->right = new itNode(value);
            return;
        }
    }
}

//Tested
itNode *constructCompleteTreeON2(sillNode *head) {
    if(head == null) {
        return null;
    }
    itNode *root = null;
    sillNode *crawler = head;
    while(crawler != null) {
        insertValueIntoTree(&root,crawler->value);
        crawler = crawler->next;
    }
    return root;
}

#endif /* CONSTRUCTCOMPLETETREEFROMSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
