/****************************************************************************************************************************************************
 *  File Name   		: productthreesequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\productthreesequence.h
 *  Created on			: Dec 22, 2014 :: 2:47:07 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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

#ifndef PRODUCTTHREESEQUENCE_H_
#define PRODUCTTHREESEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
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

//Tested
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

//Tested
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

//Tested
int getFloorAvlTree(ifpAvlNode *ptr,int value){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->value == value){
		return INT_MIN;
	}
	if(ptr->value > value){
		return getFloorAvlTree(ptr->left,value);
	}else{
		int result = getFloorAvlTree(ptr->right,value);
		return result == INT_MIN?ptr->value:result;
	}
}

//Tested
int productThreeSequenceON(vector<int> userInput){
	if(userInput.size() < 3){
		return INT_MIN;
	}
	vector<int> lsl,rsl(userInput.size());
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		ptsInsertIntoAvlTree(&root,userInput[counter]);
	}
	lsl.push_back(INT_MIN);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		lsl.push_back(getFloorAvlTree(root,userInput[counter]));
	}
	int maxVal = userInput[userInput.size()-1];
	rsl[userInput.size()-1] = INT_MIN;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rsl[counter] = max(maxVal,userInput[counter+1]);
	}
	int maxProduct = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxProduct = max(maxProduct,lsl[counter] * userInput[counter] * rsl[counter]);
	}
	return maxProduct;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int productThreeSequenceON2(vector<int> userInput){
	if(userInput.size() < 3){
		return INT_MIN;
	}
	vector<int> lsl,rsl(userInput.size(),INT_MIN);
	int maxElement;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		maxElement = INT_MIN;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			maxElement = max(maxElement,userInput[innerCounter]);
		}
		lsl.push_back(maxElement);
		maxElement = INT_MIN;
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			maxElement = max(maxElement,userInput[innerCounter]);
		}
		rsl[outerCounter] = maxElement;
	}
	int maxProduct = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxProduct = max(maxProduct,lsl[counter] * userInput[counter] * rsl[counter]);
	}
	return maxProduct;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
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
