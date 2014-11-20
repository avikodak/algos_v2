/****************************************************************************************************************************************************
 *  File Name   		: deletefromredblacktree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture14\deletefromredblacktree.h
 *  Created on			: Nov 20, 2014 :: 1:18:34 PM
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

#ifndef DELETEFROMREDBLACKTREE_H_
#define DELETEFROMREDBLACKTREE_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

iRbTreeNode *search(iRbTreeNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	if(ptr->value > value){
		return search(ptr->left,value);
	}else{
		return search(ptr->right,value);
	}
}

iRbTreeNode *successorIfTwoNodesPresent(iRbTreeNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->right == null){
		throw "Invalid node";
	}
	ptr = ptr->right;
	while(ptr->left != null){
		ptr = ptr->left;
	}
	return ptr;
}

void reorganiseTree(iRbTreeNode *nodeToBeDeleted){
	if(nodeToBeDeleted == null){
		return;
	}
	if(nodeToBeDeleted->isRedNode){
		return;
	}
	iRbTreeNode *parentToKeyNode = nodeToBeDeleted->parent;
	if(parentToKeyNode->left != null || parentToKeyNode->right != null){
		return;
	}

}

void deleteFromRedBlackTree(iRbTreeNode **root,int value){
	if(*root == null){
		return;
	}
	if((*root)->value == value){
		return;
	}
	iRbTreeNode *ptrToKey = search(*root,value);
	if(ptrToKey == null){
		return;
	}
	if(ptrToKey->left != null && ptrToKey->right != null){
		iRbTreeNode *successor = successorIfTwoNodesPresent(ptr);
		ptrToKey->value = successor->value;
		successor->value = value;
		ptrToKey = successor;
	}
}

#endif /* DELETEFROMREDBLACKTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
