/****************************************************************************************************************************************************
 *  File Name   		: converttreetodllON2.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\converttreetodllON2.h
 *  Created on			: Nov 13, 2014 :: 9:05:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CONVERTTREETODLLON2_H_
#define CONVERTTREETODLLON2_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *oConvertTreeToDllON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp = null;
    if(ptr->left != null) {
        temp = oConvertTreeToDllON2Main(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = oConvertTreeToDllON2Main(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
void oConvertTreeToDllON2(itNode **ptr) {
    if(*ptr == null) {
        return;
    }
    oConvertTreeToDllON2Main(*ptr);
    itNode *currentNode = *ptr;
    while(currentNode->left != null) {
        currentNode = currentNode->left;
    }
    (*ptr) = currentNode;
    while(currentNode != null) {
        printf("%d\t",currentNode->value);
        currentNode = currentNode->right;
    }
}

#endif /* CONVERTTREETODLLON2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
