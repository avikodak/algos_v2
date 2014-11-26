/****************************************************************************************************************************************************
 *  File Name   		: findduplicates.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\findduplicates.h
 *  Created on			: Nov 26, 2014 :: 4:50:48 PM
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

#ifndef FINDDUPLICATES_H_
#define FINDDUPLICATES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return;
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
		if(itToFrequencyMap->second > 1){
			printf("%d\t",itToFrequencyMap->first);
		}
	}
}

void printDuplicatesArrayAuxspace(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int *frequency = (int *)malloc(sizeof(int) *userInput.size());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequency[counter] = 0;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequency[userInput[counter]] += 1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequency[userInput[counter]] > 1){
			printf("%d\t",userInput[counter]);
		}
	}
}

void printDuplicates(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[userInput[counter]] > 0){
			userInput[userInput[counter]] *= -1;
		}else{
			printf("%d\t",userInput[counter]);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter] == userInput[counter+1]){
			printf("%d\t",userInput[counter]);
			while(counter < userInput.size() && userInput[counter] == userInput[counter]){
				counter++;
			}
		}
	}
}

void pdRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
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

ifpAvlNode *pdInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			return currentNode->left;
		}else{
			return pdInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return pdInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void pdInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = pdInsertAtRightPlace(root,*root,value);
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
			x = y->value > value?x->left:x->right;
			if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				rotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:y->right->height);
				y->height = 1 + max(y->left == null?0:z->left->height,y->right == null?0:z->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				rotateNodes(y,x);
				rotateNodes(z,x);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:y->right->height);
				y->height = 1 + max(y->left == null?0:z->left->height,y->right == null?0:z->right->height);
				x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
			}
			return;
		}
		z->height = 1 + max(leftHeight,rightHeight);
		z = z->parent;
	}
}

void printDuplicatesAvlTree(ifpAvlNode *ptr){
	if(ptr == null){
		return;
	}
	printDuplicatesAvlTree(ptr->left);
	if(ptr->frequency > 1){
		printf("%d\t",ptr->value);
	}
	printDuplicatesAvlTree(ptr->right);
}

void printDuplicatesAvlTree(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		pdInsertIntoAvlTree(&root,userInput[counter]);
	}
	printDuplicatesAvlTree(root);
}

void pdRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
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

ifRbTreeNode *pdInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return pdInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return pdInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void pdReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(currentNode == null){
		return;
	}
	ifRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right == null && !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
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
			pdReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null && !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
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
			pdReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

void pdInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = pdInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	pdReorganizeTreePostInsertion(root,ptrToKey);
}

void printDuplicatesRbTree(ifRbTreeNode *ptr){
	if(ptr == null){
		return;
	}
	printDuplicatesRbTree(ptr->left);
	if(ptr->frequency > 1){
		printf("%d\t",ptr->value);
	}
	printDuplicatesRbTree(ptr->right);
}

void printDuplicatesRbTree(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		pdInsertIntoRbTree(&root,userInput[counter]);
	}
	printDuplicatesRbTree(root);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	vector<bool> flags(userInput.size(),false);
	unsigned int frequency;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		frequency = 0;
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				frequency += 1;
			}
		}
		if(frequency > 1){
			if(!flags[userInput[outerCounter]]){
				printf("%d\t",userInput[outerCounter]);
				flags[userInput[outerCounter]] = true;
			}
		}
	}
}

#endif /* FINDDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
