/****************************************************************************************************************************************************
 *  File Name   		: istreeheightbalanced.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture11\istreeheightbalanced.h
 *  Created on			: Nov 18, 2014 :: 7:10:43 PM
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
int isTreeHeightBalancedON(itNode *ptr,bool &flag){
	if(ptr == null){
		return 0;
	}
	int leftHeight = isTreeHeightBalancedON(ptr->left,flag);
	int rightHeight = isTreeHeightBalancedON(ptr->right,flag);
	if(abs(leftHeight - rightHeight) > 1){
		flag = false;
	}
	return 1 + max(leftHeight,rightHeight);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isTreeHeightBalanced(itNode *ptr){
	if(ptr == null || (ptr->left == null && ptr->right == null)){
		return true;
	}
	treeutils *utils = new treeutils();
	unsigned int leftHeight = utils->getHeightOfTree(ptr->left);
	unsigned int rightHeight = utils->getHeightOfTree(ptr->right);
	return	leftHeight - rightHeight <= 1 && isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

#endif /* ISTREEHEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
