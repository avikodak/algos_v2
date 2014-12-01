/****************************************************************************************************************************************************
 *  File Name   		: kthsmallest.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\kthsmallest.h
 *  Created on			: Nov 26, 2014 :: 1:06:44 PM
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

#ifndef KTHSMALLEST_H_
#define KTHSMALLEST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int kthSmallestSortingONLOGN(vector<int> userInput,int kValue){
	sort(userInput.begin(),userInput.end());
	if(kValue > userInput.size()){
		return INT_MIN;
	}
	return userInput[kValue-1];
}

void kmvRotateNodes(ipAvlNode *parent,ipAvlNode *child){
	if(parent == null || child == null){
		return;
	}
	ipAvlNode *grandParent = parent->parent;
	parent->parent = child;
	child->parent = grandParent;
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

ipAvlNode *kmvInsertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value){
	if(*root == null){
		(*root) = new ipAvlNode(value);
		return null;
	}
	if(currentNode->value == value){
		return null;
	}else if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ipAvlNode(value);
			currentNode->left->parent = currentNode;
			return currentNode;
		}else{
			return kmvInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ipAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return kmvInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

ipAvlNode *kmvInsertIntoAvlTree(ipAvlNode **root,int value){
	ipAvlNode *z = kmvInsertAtRightPlace(root,*root,value);
	if(z == null){
		return;
	}
	ipAvlNode *y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right = null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > value?z->left:z->right;
			x = y->value > value?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				kmvRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				kmvRotateNodes(y,x);
				kmvRotateNodes(z,x);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
			}
			return;
		}
		z->height = 1 + max(leftHeight,rightHeight);
		z = z->parent;
	}
}

void setKthSmallestRbTree(ipAvlNode *ptr,ipAvlNode **kPtr,int &kValue){
	if(ptr == null){
		return;
	}
	setKthSmallestRbTree(ptr->left,kPtr,kValue);
	kValue--;
	if(kValue == 0){
		(*kPtr) = ptr;
	}
	setKthSmallestRbTree(ptr,kPtr,kValue);
}

int getKthSmallestRbTree(vector<int> userInput){
	if(userInput.size() == null){
		return null;
	}
}

void kmvRotateNodes(iRbTreeNode *parent,iRbTreeNode *child){
	if(parent == null || child == null){
		return;
	}
	iRbTreeNode *grandParent = parent->parent;
	parent->parent = child;
	child->parent = grandParent;
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

iRbTreeNode *kmvInsertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value){
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
			return kmvInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new iRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return kmvInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void kmvReorganizeTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode){
	if(*root == null || currentNode == null){
		return;
	}
	iRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			kmvRotateNodes(grandParent,parent);
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
			kmvReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			kmvRotateNodes(grandParent,parent);
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
			kmvReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

void kmvInsertIntoRbTree(iRbTreeNode **root,int value){
	iRbTreeNode *ptrToKey = kmvInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	kmvReorganizeTreePostInsertion(root,ptrToKey);
}

void setKthSmallestRbTree(iRbTreeNode *ptr,iRbTreeNode **kPtr,int &kValue){
	if(ptr == null){
		return;
	}
	setKthSmallestRbTree(ptr->left,kPtr,kValue);
	kValue--;
	if(kValue == 0){
		(*kPtr) = ptr;
	}
	setKthSmallestRbTree(ptr,kPtr,kValue);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Distinct elements;
void kmvInsertIntoBst(itAuxNode **root,itAuxNode *currentNode,vector<int> userInput,int counter){
	if(*root == null){
		(*root) = userInput[counter];
		kmvInsertIntoBst(root,*root,userInput,counter+1);
	}else{
		if(currentNode->value == userInput[counter]){
			kmvInsertIntoBst(root,*root,userInput,counter+1);
		}else if(currentNode->value > userInput[counter]){
			if(currentNode->left == null){
				currentNode->left = new itAuxNode(userInput[counter]);
				currentNode->left->auxValue += 1;
				kmvInsertIntoBst(root,*root,userInput,counter+1);
			}else{
				currentNode->auxValue += 1;
				kmvInsertIntoBst(root,currentNode->left,userInput,counter);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new itAuxNode(userInput[counter]);
				currentNode->right->auxValue += 1;
				kmvInsertIntoBst(root,*root,userInput,counter+1);
			}else{
				kmvInsertIntoBst(root,currentNode->right,userInput,counter);
			}
		}
	}
}

int getKthSmallestAuxBst(itAuxNode *ptr,int kValue){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->auxValue+1== kValue){
		return ptr->value;
	}
	if(ptr->auxValue+1 > kValue){
		return getKthSmallestAuxBst(ptr->left,kValue);
	}else{
		return getKthSmallestAuxBst(ptr->right,kValue - ptr->auxValue -1);
	}
}

#endif /* KTHSMALLEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
