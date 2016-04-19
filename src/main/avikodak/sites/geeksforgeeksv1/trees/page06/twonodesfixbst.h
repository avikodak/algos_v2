/****************************************************************************************************************************************************
 *  File Name                   : twonodesfixbst.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\twonodesfixbst.h
 *  Created on                  : Nov 13, 2014 :: 10:24:20 AM
 *  Author                      : avikodak
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

#ifndef TWONODESFIXBST_H_
#define TWONODESFIXBST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void fixNodesInInorderMain(itNode *ptr,itNode **firstPtr,itNode **midPtr,itNode **lastPtr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    fixNodesInInorderMain(ptr->left,firstPtr,midPtr,lastPtr);
    if(prevNode != null) {
        if(ptr->value < prevNode->value) {
            if(*firstPtr == null) {
                (*firstPtr) = prevNode;
                (*midPtr) = ptr;
            } else {
                (*lastPtr) = ptr;
            }
        }
    }
    prevNode = ptr;
    fixNodesInInorderMain(ptr->right,firstPtr,midPtr,lastPtr);
}

//Tested
void fixNodesInInOrderON(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *firstPtr = null,*midPtr = null,*lastPtr = null;
    fixNodesInInorderMain(ptr,&firstPtr,&midPtr,&lastPtr);
    int temp;
    if(lastPtr != null) {
        temp = lastPtr->value;
        lastPtr->value = firstPtr->value;
        firstPtr->value = temp;
    } else {
        temp = midPtr->value;
        midPtr->value = firstPtr->value;
        firstPtr->value = temp;
    }
}


/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void insertNodesInInorder(itNode *ptr,vector<int> inorderValues) {
    if(ptr == null) {
        return;
    }
    static unsigned int counter = 0;
    insertNodesInInorder(ptr->left,inorderValues);
    ptr->value = inorderValues[counter++];
    insertNodesInInorder(ptr->right,inorderValues);
}

//Tested
void fixBST(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    treeutils *utils = new treeutils();
    vector<int> inorderValues = utils->getValuesInInorder(ptr);
    sort(inorderValues.begin(),inorderValues.end());
    insertNodesInInorder(ptr,inorderValues);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* TWONODESFIXBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
