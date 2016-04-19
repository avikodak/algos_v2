/****************************************************************************************************************************************************
 *  File Name                   : specificlevelorder.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\specificlevelorder.h
 *  Created on                  : Jan 22, 2015 :: 7:44:11 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SPECIFICLEVELORDER_H_
#define SPECIFICLEVELORDER_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void perfectTreeSpecificLevelOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *firstNode,*secondNode;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        firstNode = auxSpace.front();
        auxSpace.pop();
        printf("%d\t",firstNode->value);
        if(!auxSpace.empty()) {
            secondNode = auxSpace.front();
            auxSpace.pop();
            printf("%d\t",secondNode->value);
        } else {
            secondNode = null;
        }
        if(firstNode->left != null) {
            auxSpace.push(firstNode->left);
        }
        if(secondNode != null && secondNode->right != null) {
            auxSpace.push(secondNode->right);
        }
        if(firstNode->right != null) {
            auxSpace.push(firstNode->right);
        }
        if(secondNode != null && secondNode->left != null) {
            auxSpace.push(secondNode->left);
        }
    }
}

#endif /* SPECIFICLEVELORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
