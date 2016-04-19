/****************************************************************************************************************************************************
 *  File Name                   : istreeheightbalanced.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture11\istreeheightbalanced.h
 *  Created on                  : Nov 18, 2014 :: 7:10:43 PM
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

#ifndef ISTREEHEIGHTBALANCED_H_
#define ISTREEHEIGHTBALANCED_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int isTreeHeightBalancedON(itNode *ptr,bool &flag) {
    if(ptr == null) {
        return 0;
    }
    int leftHeight = isTreeHeightBalancedON(ptr->left,flag);
    int rightHeight = isTreeHeightBalancedON(ptr->right,flag);
    if(abs(leftHeight - rightHeight) > 1) {
        flag = false;
    }
    return 1 + max(leftHeight,rightHeight);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool isTreeHeightBalanced(itNode *ptr) {
    if(ptr == null || (ptr->left == null && ptr->right == null)) {
        return true;
    }
    treeutils *utils = new treeutils();
    unsigned int leftHeight = utils->getHeightOfTree(ptr->left);
    unsigned int rightHeight = utils->getHeightOfTree(ptr->right);
    return    leftHeight - rightHeight <= 1 && isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

#endif /* ISTREEHEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
