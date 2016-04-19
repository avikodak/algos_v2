/****************************************************************************************************************************************************
 *  File Name                   : treefromspecialpreorder.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\treefromspecialpreorder.h
 *  Created on                  : Oct 31, 2014 :: 6:42:41 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
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

#ifndef TREEFROMSPECIALPREORDER_H_
#define TREEFROMSPECIALPREORDER_H_
//Tested
itNode *getTreeFromSpecialPreorder(vector<int> preOrderTraversal,vector<bool> flags) {
    static unsigned int runningIndex = 0;
    if(runningIndex >= preOrderTraversal.size()) {
        return null;
    }
    unsigned int index = runningIndex;
    itNode *node = new itNode(preOrderTraversal[index]);
    runningIndex++;
    if(!flags[index]) {
        node->left = getTreeFromSpecialPreorder(preOrderTraversal,flags);
        node->right = getTreeFromSpecialPreorder(preOrderTraversal,flags);
    }
    return node;
}

#endif /* TREEFROMSPECIALPREORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
