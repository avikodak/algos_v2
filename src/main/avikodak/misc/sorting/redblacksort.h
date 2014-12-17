/****************************************************************************************************************************************************
 *  File Name   		: redblacksort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\redblacksort.h
 *  Created on			: Dec 11, 2014 :: 1:01:43 PM
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef REDBLACKSORT_H_
#define REDBLACKSORT_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void srbRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
	if(parent == null || child == null){
		return;
	}
	ifRbTreeNode *grandParent = parent->parent;
	parent->parent = child;
	child->parent = grandParent;
	if(grandParent != null){
		if(grandParent->left == parent){
			grandParent->left =  child;
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

//Tested
ifRbTreeNode *srbInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
	if(*root == null){
		(*root) = new ifRbTreeNode(value);
		(*root)->isRedNode = false;
		return null;
	}
	if(currentNode->value == value){
		currentNode->frequency += 1;
		return null;
	}else if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ifRbTreeNode(value);
			currentNode->left->parent = currentNode;
			return currentNode->left;
		}else{
			return srbInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return srbInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void srbReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(*root == null || currentNode == null){
		return;
	}
	ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent ==  null){
				(*root) = parent;
			}
			srbRotateNodes(grandParent,parent);
			parent->isRedNode = false;
			grandParent->isRedNode = true;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			srbReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent ==  null){
				(*root) = parent;
			}
			srbRotateNodes(grandParent,parent);
			parent->isRedNode = false;
			grandParent->isRedNode = true;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			srbReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

//Tested
void srbInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = srbInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	srbReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
void srbSetVectorWithInorderValues(ifRbTreeNode *ptr,vector<int> &userInput){
	if(ptr == null){
		return;
	}
	static int fillCounter = -1;
	srbSetVectorWithInorderValues(ptr->left,userInput);
	while(ptr->frequency--){
		userInput[++fillCounter] = ptr->value;
	}
	srbSetVectorWithInorderValues(ptr->right,userInput);
}

//Tested
void srbRbTreeSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		srbInsertIntoRbTree(&root,userInput[counter]);
	}
	srbSetVectorWithInorderValues(root,userInput);
}

#endif /* REDBLACKSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
