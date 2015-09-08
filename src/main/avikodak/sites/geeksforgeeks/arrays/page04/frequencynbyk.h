/****************************************************************************************************************************************************
 *  File Name   		: frequencynbyk.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\frequencynbyk.h
 *  Created on			: Dec 24, 2014 :: 5:02:26 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
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

#ifndef FREQUENCYNBYK_H_
#define FREQUENCYNBYK_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> getValuesFrequencyNByK(vector<int> userInput,int k){
	vector<int> values;
	if(userInput.size() < 1 || k >= userInput.size()){
		return values;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			frequencyMap[userInput[counter]] = 1;
		}else{
			frequencyMap[userInput[counter]] += 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > userInput.size()/k){
			values.push_back(itToFrequencyMap->first);
		}
	}
	return values;
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void fnkRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
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
}

ifpAvlNode *fnkInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			currentNode->left->parent = currentNode;
			return currentNode;
		}else{
			return fnkInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return fnkInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void fnkInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = fnkInsertAtRightPlace(root,*root,value);
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
					*root = y;
				}
				fnkRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:z->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					*root = x;
				}
				fnkRotateNodes(y,x);
				fnkRotateNodes(z,x);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:z->left->height,y->right == null?0:y->right->height);
				x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
			}
			return;
		}
		z->height = 1 + max(leftHeight,rightHeight);
		z = z->parent;
	}
}

void setVectorWithFrequencyNBYK(ifpAvlNode *ptr,vector<int> &values,int reqFrequency){
	if(ptr == null){
		return;
	}
	if(ptr->frequency >= reqFrequency){
		values.push_back(ptr->value);
	}
	setVectorWithFrequencyNBYK(ptr->left,values,reqFrequency);
	setVectorWithFrequencyNBYK(ptr->right,values,reqFrequency);
}

vector<int> getValuesFrequencyNByKAvlTree(vector<int> userInput,int k){
	vector<int> values;
	if(userInput.size() < 1){
		return values;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		fnkInsertIntoAvlTree(&root,userInput[counter]);
	}
	setVectorWithFrequencyNBYK(root,values,userInput.size()/k);
	return values;
}

void fnkRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
	if(parent == null || child == null){
		return;
	}
	ifRbTreeNode *grandParent = parent->parent;
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

ifRbTreeNode *fnkInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return fnkInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return fnkInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void fnkReorganiseTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(*root == null || currentNode == null){
		return;
	}
	if(!currentNode->parent->isRedNode){
		return;
	}
	ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			fnkRotateNodes(grandParent,parent);
			parent->isRedNode = true;
			grandParent->isRedNode = false;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			fnkReorganiseTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			fnkRotateNodes(grandParent,parent);
			parent->isRedNode = true;
			grandParent->isRedNode = false;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			fnkReorganiseTreePostInsertion(root,grandParent);
		}
	}
}

void fnkInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = fnkInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	fnkReorganiseTreePostInsertion(root,ptrToKey);
}

void setVectorWithFrequencyNBYK(ifRbTreeNode *ptr,vector<int> &values,int reqFrequency){
	if(ptr == null){
		return;
	}
	if(ptr->frequency >= reqFrequency){
		values.push_back(ptr->value);
	}
	setVectorWithFrequencyNBYK(ptr->left,values,reqFrequency);
	setVectorWithFrequencyNBYK(ptr->right,values,reqFrequency);
}

vector<int> getValuesFrequencyNByKRbTree(vector<int> userInput,int k){
	vector<int> values;
	if(userInput.size() == 0){
		return values;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		fnkInsertIntoRbTree(&root,userInput[counter]);
	}
	setVectorWithFrequencyNBYK(root,values,userInput.size()/k);
	return values;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> getValuesFreqencyNByKON2(vector<int> userInput,int k){
	vector<int> values;
	if(userInput.size() < 1 || k >= userInput.size()){
		return values;
	}
	int frequency;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter] != INT_MAX){
			frequency = 1;
			for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
				if(userInput[outerCounter] == userInput[innerCounter]){
					frequency = 0;
					userInput[innerCounter] = INT_MAX;
				}
			}
			if(frequency > userInput.size()/k){
				values.push_back(userInput[outerCounter]);
			}
		}
	}
	return values;
}

#endif /* FREQUENCYNBYK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
