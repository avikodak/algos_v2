/****************************************************************************************************************************************************
 *  File Name   		: bst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\bst.h
 *  Created on			: Nov 18, 2014 :: 11:14:07 AM
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

#ifndef BST_H_
#define BST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertIntoBst(itNode **root,itNode *currentNode,int userInput){
	if(*root == null){
		(*root) = new itNode(userInput);
		return;
	}else{
		if(currentNode->value == userInput){
			return;
		}else  if(currentNode->value > userInput){
			if(currentNode->left == null){
				currentNode->left = new itNode(userInput);
				return;
			}else{
				insertIntoBst(root,currentNode->left,userInput);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new itNode(userInput);
				return;
			}else{
				insertIntoBst(root,currentNode->right,userInput);
			}
		}
	}
}

void insertIntoBstIterative(itNode **root,int userInput){
	if(*root == null){
		(*root) = new itNode(userInput);
		return;
	}
	itNode *currentNode = *root;
	while(currentNode != null){
		if(currentNode->value == userInput){
			return;
		}else if(currentNode->value > userInput){
			if(currentNode->left == null){
				currentNode->left = new itNode(userInput);
				return;
			}else{
				currentNode = currentNode->left;
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new itNode(userInput);
				return;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
}

#endif /* BST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
