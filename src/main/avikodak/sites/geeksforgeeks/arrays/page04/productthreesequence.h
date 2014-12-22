/****************************************************************************************************************************************************
 *  File Name   		: productthreesequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\productthreesequence.h
 *  Created on			: Dec 22, 2014 :: 2:47:07 PM
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

#ifndef PRODUCTTHREESEQUENCE_H_
#define PRODUCTTHREESEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void ptsRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
	if(parent == null || child == null){
		return;
	}
	ifpAvlNode *grandParent = parent->parent;
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

ifpAvlNode *ptsInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
	if(*root == null){
		(*root) = new ifpAvlNode(value);
		return null;
	}
	if(currentNode->value == value){
		currentNode->frequency += 1;
		return null;
	}else if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ifpAvlNode(value);
			currentNode->left->parent  = currentNode;
			return currentNode;
		}else{
			return ptsInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return ptsInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void ptsInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = ptsInsertAtRightPlace(root,*root,value);
	if(z == null){
		return;
	}
	ifpAvlNode *y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > value?z->left:z->right;
			x = y->value > value?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				ptsRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				ptsRotateNodes(y,x);
				ptsRotateNodes(z,x);
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

int getFloorAvlTree(ifpAvlNode *ptr,int value){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->value == value){
		return ptr->value;
	}
	if(ptr->value > value){
		return getFloorAvlTree(ptr->left,value);
	}else{
		int result = getFloorAvlTree(ptr->right,value);
		return result == INT_MIN?ptr->value:result;
	}
}

int productThreeSequenceON(vector<int> userInput){
	if(userInput.size() < 3){
		return INT_MIN;
	}

}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int productThreeSequenceON3(vector<int> userInput){
	if(userInput.size() < 3){
		return INT_MIN;
	}
	int maxProduct = INT_MIN;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-2;outerCrawler++){
		for(unsigned int middleCrawler = outerCrawler+1;middleCrawler < userInput.size()-1;middleCrawler++){
			for(unsigned int innerCrawler = middleCrawler+1;innerCrawler < userInput.size();innerCrawler++){
				maxProduct = max(maxProduct,userInput[outerCrawler] * userInput[middleCrawler] * userInput[innerCrawler]);
			}
		}
	}
	return maxProduct;
}
#endif /* PRODUCTTHREESEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
