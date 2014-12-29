/****************************************************************************************************************************************************
 *  File Name   		: mergesortedarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\mergesortedarray.h
 *  Created on			: Oct 17, 2014 :: 6:47:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/
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
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MERGESORTEDARRAY_H_
#define MERGESORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> mergeSortedArray(vector<int> firstSortedArray,vector<int> secondSortedArray){
	vector<int> mergedArray;
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return mergedArray;
	}
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return firstSortedArray.size() != 0?firstSortedArray:secondSortedArray;
	}
	unsigned int firstArrayCounter = 0,secondArrayCounter = 0;
	while(firstArrayCounter < firstSortedArray.size() || secondArrayCounter < secondSortedArray.size()){
		if(firstArrayCounter >= firstSortedArray.size() || secondArrayCounter >= secondSortedArray.size()){
			if(firstArrayCounter < firstSortedArray.size()){
				mergedArray.push_back(firstSortedArray[firstArrayCounter]);
				firstArrayCounter++;
			}else{
				mergedArray.push_back(secondSortedArray[secondArrayCounter]);
				secondArrayCounter++;
			}
		}else{
			if(firstSortedArray[firstArrayCounter] == secondSortedArray[secondArrayCounter]){
				mergedArray.push_back(firstSortedArray[firstArrayCounter]);
				mergedArray.push_back(secondSortedArray[secondArrayCounter]);
				firstArrayCounter++;
				secondArrayCounter++;
			}else if(firstSortedArray[firstArrayCounter] < secondSortedArray[secondArrayCounter]){
				mergedArray.push_back(firstSortedArray[firstArrayCounter]);
				firstArrayCounter++;
			}else{
				mergedArray.push_back(secondSortedArray[secondArrayCounter]);
				secondArrayCounter++;
			}
		}
	}
	return mergedArray;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> mergeSortedArrayONLOGN(vector<int> firstSortedArray,vector<int> secondSortedArray){
	vector<int> mergedArray;
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return mergedArray;
	}
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return firstSortedArray.size() != 0?firstSortedArray:secondSortedArray;
	}
	mergedArray.reserve(firstSortedArray.size() + secondSortedArray.size());
	mergedArray.insert(mergedArray.end(),firstSortedArray.begin(),firstSortedArray.end());
	mergedArray.insert(mergedArray.end(),secondSortedArray.begin(),secondSortedArray.end());
	sort(mergedArray.begin(),mergedArray.end());
	return mergedArray;
}

//Tested
void msaRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
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
ifpAvlNode *msaInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			return msaInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right== null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return msaInsertAtRightPlace(root,currentNode->right,value);
		}
	}

}

//Tested
void msaInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = msaInsertAtRightPlace(root,*root,value);
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
			if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				msaRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				msaRotateNodes(y,x);
				msaRotateNodes(z,x);
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
void setInorderValuesInVector(ifpAvlNode *ptr,vector<int> &mergedArray){
	if(ptr == null){
		return;
	}
	setInorderValuesInVector(ptr->left,mergedArray);
	while(ptr->frequency--){
		mergedArray.push_back(ptr->value);
	}
	setInorderValuesInVector(ptr->right,mergedArray);
}

//Tested
vector<int> mergedSortedArraysAvl(vector<int> firstSortedArray,vector<int> secondSortedArray){
	vector<int> mergedArray;
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return mergedArray;
	}
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return firstSortedArray.size() != 0?firstSortedArray:secondSortedArray;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < firstSortedArray.size();counter++){
		msaInsertIntoAvlTree(&root,firstSortedArray[counter]);
	}
	for(unsigned int counter = 0;counter < secondSortedArray.size();counter++){
		msaInsertIntoAvlTree(&root,secondSortedArray[counter]);
	}
	setInorderValuesInVector(root,mergedArray);
	return mergedArray;
}

//Tested
void msaRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
	if(parent ==  null || child == null){
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
ifRbTreeNode *msaInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return msaInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return msaInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void msaReorganizeTree(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(currentNode == null){
		return;
	}
	ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right  == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			msaRotateNodes(grandParent,parent);
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
			msaReorganizeTree(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			msaRotateNodes(grandParent,parent);
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
			msaReorganizeTree(root,grandParent);
		}
	}
}

//Tested
void msaInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = msaInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	msaReorganizeTree(root,ptrToKey);
}

//Tested
void setValuesInVectorInorderRbTree(ifRbTreeNode *ptr,vector<int> &sortedValue){
	if(ptr == null){
		return;
	}
	setValuesInVectorInorderRbTree(ptr->left,sortedValue);
	while(ptr->frequency--){
		sortedValue.push_back(ptr->value);
	}
	setValuesInVectorInorderRbTree(ptr->right,sortedValue);
}

//Tested
vector<int> mergeSortedArrayRbTree(vector<int> firstSortedArray,vector<int> secondSortedArray){
	vector<int> mergedArray;
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return mergedArray;
	}
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return firstSortedArray.size() != 0?firstSortedArray:secondSortedArray;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < firstSortedArray.size();counter++){
		msaInsertIntoRbTree(&root,firstSortedArray[counter]);
	}
	for(unsigned int counter = 0;counter < secondSortedArray.size();counter++){
		msaInsertIntoRbTree(&root,secondSortedArray[counter]);
	}
	setValuesInVectorInorderRbTree(root,mergedArray);
	return mergedArray;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void msaInsertionSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int innerCounter,key;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		key = userInput[outerCounter];
		innerCounter = outerCounter-1;
		while(innerCounter >= 0 && userInput[innerCounter] > key){
			userInput[innerCounter+1] = userInput[innerCounter];
		}
		userInput[innerCounter+1] = key;
	}
}

//Tested
vector<int> mergeSortedArrayInsertionON2(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0){
		return secondSortedArray;
	}
	if(secondSortedArray.size() == 0){
		return firstSortedArray;
	}
	vector<int> mergedArray(firstSortedArray.size() + secondSortedArray.size());
	merge(firstSortedArray.begin(),firstSortedArray.end(),secondSortedArray.begin(),secondSortedArray.end(),mergedArray.begin());
	msaInsertionSort(mergedArray);
	return mergedArray;
}

#endif /* MERGESORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
