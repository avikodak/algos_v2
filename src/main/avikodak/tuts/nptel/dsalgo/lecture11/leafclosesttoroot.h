/****************************************************************************************************************************************************
 *  File Name                   : leafclosesttoroot.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture11\leafclosesttoroot.h
 *  Created on                  : Nov 18, 2014 :: 5:28:27 PM
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

#ifndef LEAFCLOSESTTOROOT_H_
#define LEAFCLOSESTTOROOT_H_

void leafClosestToRootMain(itNode *ptr,itNode **ptrToLeaf,unsigned int currentLevel = 1) {
    static unsigned int minLevel = UINT_MAX;
    if(ptr == null) {
        return;
    }
    if(ptr->left == null && ptr->right == null) {
        if(currentLevel < minLevel) {
            minLevel = currentLevel;
            *ptrToLeaf = ptr;
        }
        return;
    }
    leafClosestToRootMain(ptr->left,ptrToLeaf,currentLevel+1);
    leafClosestToRootMain(ptr->right,ptrToLeaf,currentLevel+1);
}

itNode *getLeafClosestToRoot(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *leaf = null;
    leafClosestToRootMain(ptr,&leaf);
    return leaf;
}

#endif /* LEAFCLOSESTTOROOT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
