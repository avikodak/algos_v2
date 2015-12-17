/****************************************************************************************************************************************************
 *  File Name   		: maximumrepeatingnumber.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\maximumrepeatingnumber.h
 *  Created on			: Dec 22, 2014 :: 11:12:57 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/
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

#ifndef MAXIMUMREPEATINGNUMBER_H_
#define MAXIMUMREPEATINGNUMBER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maximumRepeatingNumber(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[userInput[counter] % userInput.size()] += userInput.size();
	}
	int maxFrequency = userInput[0]/userInput.size(),maxFrequencyVal = 0;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(maxFrequency < userInput[counter]/(int)userInput.size()){
			maxFrequency = userInput[counter]/userInput.size();
			maxFrequencyVal = counter;
		}
	}
	return maxFrequencyVal;
}

//Tested
int maximumRepeatingNumberHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap,itToMaxFrequencyVal;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			frequencyMap[userInput[counter]] = 1;
		}else{
			frequencyMap[userInput[counter]] += 1;
		}
	}
	itToMaxFrequencyVal = frequencyMap.begin();
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > itToMaxFrequencyVal->second){
			itToMaxFrequencyVal = itToFrequencyMap;
		}
	}
	return itToMaxFrequencyVal->first;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void mrnRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
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
ifpAvlNode *mrnInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			return mrnInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return mrnInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void mrnInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = mrnInsertAtRightPlace(root,*root,value);
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
				mrnRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				mrnRotateNodes(y,x);
				mrnRotateNodes(z,x);
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
void getMaxFrequencyBST(ifpAvlNode *ptr,unsigned int &maxFrequency,int &value){
	if(ptr == null){
		return;
	}
	if(maxFrequency < ptr->frequency){
		maxFrequency = ptr->frequency;
		value = ptr->value;
	}
	getMaxFrequencyBST(ptr->left,maxFrequency,value);
	getMaxFrequencyBST(ptr->right,maxFrequency,value);
}

//Tested
int maximumRepeatingNumberAvlSort(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		mrnInsertIntoAvlTree(&root,userInput[counter]);
	}
	unsigned int maxFrequency = 0;
	int value = INT_MIN;
	getMaxFrequencyBST(root,maxFrequency,value);
	return value;
}

//Tested
void mrnRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
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

//Tested
ifRbTreeNode *mrnInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
	if(*root == null){
		(*root) =  new ifRbTreeNode(value);
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
			return mrnInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return mrnInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void mrnReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(root == null || currentNode == null){
		return;
	}
	ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			mrnRotateNodes(grandParent,parent);
			grandParent->isRedNode = false;
			parent->isRedNode = true;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			mrnReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			mrnRotateNodes(grandParent,parent);
			grandParent->isRedNode = false;
			parent->isRedNode = true;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			mrnReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

//Tested
void mrnInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = mrnInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	mrnReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
void getMaxFrequencyBST(ifRbTreeNode *ptr,unsigned int &maxFrequency,int &value){
	if(ptr == null){
		return;
	}
	if(maxFrequency < ptr->frequency){
		maxFrequency = ptr->frequency;
		value = ptr->value;
	}
	getMaxFrequencyBST(ptr->left,maxFrequency,value);
	getMaxFrequencyBST(ptr->right,maxFrequency,value);
}

//Tested
int maximumRepeatingNumberRbSort(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		mrnInsertIntoRbTree(&root,userInput[counter]);
	}
	unsigned int maxFrequency = 0;
	int value = INT_MIN;
	getMaxFrequencyBST(root,maxFrequency,value);
	return value;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* MAXIMUMREPEATINGNUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
