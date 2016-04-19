/****************************************************************************************************************************************************
 *  File Name                   : converttospecialbst.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\converttospecialbst.h
 *  Created on                  : Nov 13, 2014 :: 1:43:11 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/convert-bst-to-a-binary-tree/
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

#ifndef CONVERTTOSPECIALBST_H_
#define CONVERTTOSPECIALBST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void addGreaterValuesToEachNode(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static int prevValue = 0;
    addGreaterValuesToEachNode(ptr->right);
    ptr->value += prevValue;
    prevValue = ptr->value;
    addGreaterValuesToEachNode(ptr->left);
}

//Tested
void reverseInorderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    int prevValue = 0;
    while(!auxSpace.empty() || currentNode != null) {
        if(currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->right;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            currentNode->value += prevValue;
            prevValue = currentNode->value;
            currentNode = currentNode->left;
        }
    }
}

//Tested
void morrisReverseOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    int prevValue = 0;
    while(currentNode != null) {
        if(currentNode->right != null) {
            temp = currentNode->right;
            while(temp->left != null && temp->left != currentNode) {
                temp = temp->left;
            }
            if(temp->left == null) {
                temp->left = currentNode;
                currentNode = currentNode->right;
            } else {
                currentNode->value += prevValue;
                prevValue = currentNode->value;
                temp->left = null;
                currentNode = currentNode->left;
            }
        } else {
            currentNode->value += prevValue;
            prevValue = currentNode->value;
            currentNode = currentNode->left;
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* CONVERTTOSPECIALBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
