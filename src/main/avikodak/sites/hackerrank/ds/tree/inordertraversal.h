/****************************************************************************************************************************************************
 *  File Name                   : inordertraversal.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\inordertraversal.h
 *  Created on                  : May 24, 2015 :: 8:00:00 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/tree-inorder-traversal
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

#ifndef INORDERTRAVERSAL_H_
#define INORDERTRAVERSAL_H_

//Tested
void Inorder(node *root) {
    if(root == NULL) {
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

#endif /* INORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
