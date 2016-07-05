/****************************************************************************************************************************************************
 *  File Name                   : binarytreetodll.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/hard/binarytreetodll.h
 *  Created on                  : Jul 2, 2016 :: 11:24:30 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=700144
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_BINARYTREETODLL_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_BINARYTREETODLL_H_

struct Node {
    int data;
    Node *left, *right;
};

//Tested
void convertByInorderTraversal(Node *root, Node **prev) {
    if (root == null) {
        return;
    }
    convertByInorderTraversal(root->left, prev);
    root->left = prev;
    if (*prev != null) {
        (*prev)->right = root;
    }
    *prev = root;
    convertByInorderTraversal(root->right, prev);
}

//Tested
void BToDLL(Node *root, Node **head_ref) {
    if (root == null) {
        (*head_ref) = null;
        return;
    }
    Node *prev = null;
    convertByInorderTraversal(root, &prev);
    while (root->left != null) {
        root = root->left;
    }
    (*head_ref) = root;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_HARD_BINARYTREETODLL_H_ */
