/****************************************************************************************************************************************************
 *  File Name   		: lowestancestorstree.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\lowestancestorstree.h
 *  Created on			: Nov 15, 2014 :: 7:08:02 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
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

#ifndef LOWESTANCESTORSTREE_H_
#define LOWESTANCESTORSTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool lowestAncestor(itNode *ptr,itNode **lowAncestor,int firstUserinput,int secondUserinput) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == firstUserinput || ptr->value == secondUserinput) {
        return true;
    }
    bool leftTruthValue = lowestAncestor(ptr->left,lowAncestor,firstUserinput,secondUserinput);
    bool rightTruthValue = lowestAncestor(ptr->right,lowAncestor,firstUserinput,secondUserinput);
    if(leftTruthValue && rightTruthValue) {
        if(*lowAncestor == null) {
            (*lowAncestor) = ptr;
        }
        return false;
    }
    return leftTruthValue || rightTruthValue;
}

//Tested
void copyStacks(stack<itNode *> source,stack<itNode *> &destination) {
    if(source.size() == 0) {
        return;
    }
    stack<itNode *> temp;
    while(!source.empty()) {
        temp.push(source.top());
        source.pop();
    }
    while(!temp.empty()) {
        destination.push(temp.top());
        temp.pop();
    }
}

//Tested
void lowestAncestorMain(itNode *ptr,stack<itNode *> auxSpace,stack<itNode *> &firstValAncestors,stack<itNode *> &secondValAncestors,int firstVal,int secondVal) {
    if(ptr == null) {
        return;
    }
    auxSpace.push(ptr);
    if(ptr->value == firstVal || ptr->value == secondVal) {
        if(ptr->value == firstVal) {
            copyStacks(auxSpace,firstValAncestors);
        } else {
            copyStacks(auxSpace,secondValAncestors);
        }
        return;
    }
    lowestAncestorMain(ptr->left,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
    lowestAncestorMain(ptr->right,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
}

//Tested
itNode *lowestAncestorsAuxspace(itNode *ptr,int firstVal,int secondVal) {
    if(ptr == null) {
        return null;
    }
    stack<itNode *> auxSpace,firstValAncestors,secondValAncestors;
    lowestAncestorMain(ptr,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
    if(firstValAncestors.size() != secondValAncestors.size()) {
        if(firstValAncestors.size() > secondValAncestors.size()) {
            while(firstValAncestors.size() != secondValAncestors.size()) {
                firstValAncestors.pop();
            }
        } else {
            while(firstValAncestors.size() != secondValAncestors.size()) {
                secondValAncestors.pop();
            }
        }
    }
    itNode *commonAncestors = null;
    while(firstValAncestors.size() > 0) {
        if(firstValAncestors.top() == secondValAncestors.top()) {
            return firstValAncestors.top();
        }
        firstValAncestors.pop();
        secondValAncestors.pop();
    }
    return commonAncestors;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool tIsValuePresentInTree(itNode *ptr,int value) {
    if(ptr == null) {
        return false;
    }
    if(ptr->value == value) {
        return true;
    }
    return isValuePresentInTree(ptr->left,value) && isValuePresentInTree(ptr->right,value);
}

itNode *tLowestCommonAncestorsON2(itNode *ptr,int firstValue,int secondValue) {
    if(ptr == null) {
        return null;
    }
    if(tIsValuePresentInTree(ptr->left,firstValue) && tIsValuePresentInTree(ptr->right,secondValue)) {
        return ptr;
    }
    itNode *leftResult = tLowestCommonAncestorsON2(ptr->left,firstValue,secondValue);
    if(leftResult != null) {
        return leftResult;
    }
    return tLowestCommonAncestorsON2(ptr->right,firstValue,secondValue);
}

#endif /* LOWESTANCESTORSTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
