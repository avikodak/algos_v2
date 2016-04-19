/****************************************************************************************************************************************************
 *  File Name                   : reverselevelordertraversal.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\reverselevelordertraversal.h
 *  Created on                  : Nov 21, 2014 :: 9:23:44 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef REVERSELEVELORDERTRAVERSAL_H_
#define REVERSELEVELORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void rPrintReverseLevelOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    auxSpace.push(ptr);
    itNode *currentNode;
    stack<itNode *> reverseAuxspace;
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        reverseAuxspace.push(currentNode);
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
    while(!reverseAuxspace.empty()) {
        printf("%d\t",reverseAuxspace.top()->value);
        reverseAuxspace.pop();
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printReverseLevel(itNode *ptr,unsigned int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    printReverseLevel(ptr->right,level-1);
    printReverseLevel(ptr->left,level-1);
}

//Tested
void printReverseLevelOrderTraversal(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    int height = utils->getHeightOfTree(ptr);
    for(int counter = height-1; counter >= 0; counter--) {
        printReverseLevel(ptr,counter);
    }
}

#endif /* REVERSELEVELORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
