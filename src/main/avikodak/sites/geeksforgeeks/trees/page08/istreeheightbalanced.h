/****************************************************************************************************************************************************
 *  File Name   		: istreeheightbalanced.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\istreeheightbalanced.h
 *  Created on			: Oct 17, 2014 :: 10:29:44 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
int isTreeHeighBalanced(itNode *ptr,bool &isHeightBalanced){
	if(ptr == null){
		return 0;
	}
	int leftSubTreeHeight = isTreeHeighBalanced(ptr->left,isHeightBalanced);
	if(leftSubTreeHeight == INT_MIN){
		return INT_MIN;
	}
	int rightSubTreeHeight = isTreeHeighBalanced(ptr->right,isHeightBalanced);
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
bool isTreeHeightBalanced(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	int leftSubtreeHeight = utils->getHeightOfTree(ptr->left);
	int rightSubtreeHeight = utils->getHeightOfTree(ptr->right);
	if(abs(leftSubtreeHeight - rightSubtreeHeight) <= 1){
		return false;
	}
	return isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

#endif /* ISTREEHEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
