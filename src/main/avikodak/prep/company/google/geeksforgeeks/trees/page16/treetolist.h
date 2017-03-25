/****************************************************************************************************************************************************
 *  File Name                   : treetolist.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/trees/page16/treetolist.h
 *  Created on                  : Mar 25, 2017 :: 10:08:32 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETOLIST_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETOLIST_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void treeToDll(itNode *ptr) {
    static itNode *prevNode = null;
    if (ptr == null) {
        return;
    }
    treeToDll(ptr->left);
    ptr->left = prevNode;
    if (prevNode != null) {
        prevNode->right = ptr;
    }
    prevNode = ptr;
    treeToDll(ptr->right);
}

void fixLeftPtr(itNode *ptr) {
    static itNode *prevNode = null;
    if (ptr == null) {
        return;
    }
    fixLeftPtr(ptr->left);
    prevNode->left = prevNode;
    prevNode = ptr;
    fixLeftPtr(ptr->right);
}

void fixRightPtr(itNode **root) {
    if (*root == null) {
        return;
    }
    itNode *currentNode = *root;
    while (currentNode->right != null) {
        currentNode = currentNode->right;
    }
    itNode *prevNode = null;
    while (currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
    (*root) = prevNode;
}

void convertTreeToDllByFixing(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    fixLeftPtr(ptr);
    fixRightPtr(&ptr);
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_TREES_PAGE16_TREETOLIST_H_ */
