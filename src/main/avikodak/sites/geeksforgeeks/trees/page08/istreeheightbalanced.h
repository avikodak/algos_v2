/****************************************************************************************************************************************************
 *  File Name   		: istreeheightbalanced.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\istreeheightbalanced.h
 *  Created on			: Oct 17, 2014 :: 10:29:44 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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

#ifndef ISTREEHEIGHTBALANCED_H_
#define ISTREEHEIGHTBALANCED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int isTreeHeightBalancedV2(itNode *ptr,bool &isHeightBalanced){
	if(ptr == null){
		return 0;
	}
	int leftSubTreeHeight = isTreeHeightBalancedV2(ptr->left,isHeightBalanced);
	if(leftSubTreeHeight == INT_MIN){
		return INT_MIN;
	}
	int rightSubTreeHeight = isTreeHeightBalancedV2(ptr->right,isHeightBalanced);
	if(rightSubTreeHeight == INT_MIN){
		return INT_MIN;
	}
	if(abs(leftSubTreeHeight - rightSubTreeHeight) > 1){
		isHeightBalanced = false;
		return INT_MIN;
	}
	isHeightBalanced = true;
	return 1+max(leftSubTreeHeight,rightSubTreeHeight);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeHeightBalanced(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	int leftSubtreeHeight = utils->getHeightOfTree(ptr->left);
	int rightSubtreeHeight = utils->getHeightOfTree(ptr->right);
	if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1){
		return false;
	}
	return isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

#endif /* ISTREEHEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
