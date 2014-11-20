/****************************************************************************************************************************************************
 *  File Name   		: insertintoredblacktree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture15\insertintoredblacktree.h
 *  Created on			: Nov 20, 2014 :: 5:09:37 PM
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


#ifndef INSERTINTOREDBLACKTREE_H_
#define INSERTINTOREDBLACKTREE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iRbTreeNode *insertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value){
	if(*root == null){
		(*root) = new iRbTreeNode(value);
		(*root)->isRedNode = false;
		return null;
	}
	if(currentNode->value == value){
		return null;
	}else if(currentNode->value >value){
		if(currentNode->left == null){
			currentNode->left = new iRbTreeNode(value);
			currentNode->left->parent = currentNode;
			return currentNode->left;
		}else{
			return insertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new iRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return insertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void rotateNodes(iRbTreeNode *parent,iRbTreeNode *child){
	iRbTreeNode *grandParent = parent->parent;
	child->parent = grandParent;
	parent->parent = child;
	if(grandParent != null){
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}
	if(parent->left == child){
		parent->left = child->right;
		child->right = parent;
	}else{
		parent->right = child->left;
		child->left = parent;
	}
}

void reorganizingRbTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentnode){
	iRbTreeNode *parent = currentnode->parent;
	iRbTreeNode *grandParent = parent->parent;
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			rotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
		}else{
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			reorganizingRbTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			rotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
		}else{
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			grandParent->left->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			reorganizingRbTreePostInsertion(root,grandParent);
		}
	}
}

void insertIntoRedBlackTree(iRbTreeNode **root,int userInput){
	iRbTreeNode *ptrToInsertedNode = insertAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	if(!ptrToInsertedNode->parent->isRedNode){
		return;
	}
	reorganizingRbTreePostInsertion(root,ptrToInsertedNode);
}

#endif /* INSERTINTOREDBLACKTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
