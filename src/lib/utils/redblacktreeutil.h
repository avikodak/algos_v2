/****************************************************************************************************************************************************
 *  File Name   		: redblacktreeutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\redblacktreeutil.h
 *  Created on			: Oct 9, 2014 :: 12:38:08 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef REDBLACKTREEUTIL_H_
#define REDBLACKTREEUTIL_H_

class rbutils {
private:
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

	iRbTreeNode *insertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value){
		if(*root == null){
			(*root) = new iRbTreeNode(value);
			(*root)->isRedNode = false;
			return null;
		}
		if(currentNode->value == value){
			return null;
		}else if(currentNode->value > value){
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

	void reorganiseRbTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode){
		if(currentNode->parent == null){
			if(currentNode->isRedNode){
				currentNode->isRedNode = false;
			}
			return;
		}
		iRbTreeNode *parent = currentNode->parent;
		iRbTreeNode *grandParent = parent->parent;
		if(grandParent->left == parent){
			if(grandParent->right == null || !grandParent->right->isRedNode){
				if(grandParent->parent == null){
					(*root) = parent;
				}
				rotateNodes(grandParent,parent);
				grandParent->isRedNode = true;
				parent->isRedNode = false;
				return;
			}else{
				grandParent->isRedNode = true;
				grandParent->left->isRedNode = false;
				grandParent->right->isRedNode = false;
				if(grandParent->parent == null){
					grandParent->isRedNode = false;
					return;
				}
				reorganiseRbTreePostInsertion(root,grandParent);
			}
		}else{
			if(grandParent->left == null || !grandParent->left->isRedNode){
				if(grandParent->parent == null){
					(*root) = parent;
				}
				rotateNodes(grandParent,parent);
				grandParent->isRedNode = true;
				parent->isRedNode = false;
				return;
			}else{
				grandParent->isRedNode = true;
				grandParent->left->isRedNode = false;
				grandParent->right->isRedNode = false;
				if(grandParent->parent == null){
					grandParent->isRedNode = false;
					return;
				}
				reorganiseRbTreePostInsertion(root,grandParent);
			}
		}
	}
public:
	void insert(iRbTreeNode **root,int value){
		iRbTreeNode *ptrToInsertedNode = insertAtRightPlace(root,*root,value);
		if(ptrToInsertedNode == null){
			return;
		}
		if(!ptrToInsertedNode->parent->isRedNode){
			return;
		}
		reorganiseRbTreePostInsertion(root,ptrToInsertedNode);
	}
};

#endif /* REDBLACKTREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
