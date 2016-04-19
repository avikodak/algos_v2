/****************************************************************************************************************************************************
 *  File Name                   : boundaryoftree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\boundaryoftree.h
 *  Created on                  : Oct 31, 2014 :: 8:17:41 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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

#ifndef BOUNDARYOFTREE_H_
#define BOUNDARYOFTREE_H_

//Tested
void printLeftView(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    if(ptr->left != null && ptr->right != null) {
        printf("%d\t",ptr->value);
    }
    if(ptr->left != null) {
        printLeftView(ptr->left);
    } else if(ptr->right != null) {
        printLeftView(ptr->right);
    }
}

//Tested
void printRightView(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    if(ptr->right != null) {
        printRightView(ptr->right);
    } else if(ptr->left != null) {
        printRightView(ptr->left);
    }
    if(ptr->left != null && ptr->right != null) {
        printf("%d\t",ptr->value);
    }
}

//Tested
void printLeaves(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    if(ptr->left == null && ptr->right == null) {
        printf("%d\t",ptr->value);
        return;
    }
    printLeaves(ptr->left);
    printLeaves(ptr->right);
}

//Tested
void printBoundary(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    printLeftView(ptr);
    printLeaves(ptr);
    printRightView(ptr);
}

#endif /* BOUNDARYOFTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
