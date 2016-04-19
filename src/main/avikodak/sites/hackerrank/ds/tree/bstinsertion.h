/****************************************************************************************************************************************************
 *  File Name                   : bstinsertion.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\bstinsertion.h
 *  Created on                  : Jul 6, 2015 :: 9:07:05 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/challenges/binary-search-tree-insertion
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

#ifndef BSTINSERTION_H_
#define BSTINSERTION_H_

/*struct node{
   int data;
   node * left;
   node * right;
};*/

//Tested
node * insert(node *root, int value) {
    node *crawler = root;
    if(root == null) {
        root = new node();
        root->data = value;
        root->left = null;
        root->right = null;
        return root;
    }
    while(crawler != null) {
        if(crawler->data >= value) {
            if(crawler->left == null) {
                crawler->left = new node();
                crawler->left->data = value;
                crawler->left->left = null;
                crawler->left->right = null;
                break;
            } else {
                crawler = crawler->left;
            }
        } else {
            if(crawler->right == null) {
                crawler->right = new node();
                crawler->right->data = value;
                crawler->right->left = null;
                crawler->right->right = null;
                break;
            } else {
                crawler = crawler->right;
            }
        }
    }
    return root;
}

#endif /* BSTINSERTION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
