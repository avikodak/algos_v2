/****************************************************************************************************************************************************
 *  File Name   		: numberoddtimes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\numberoddtimes.h
 *  Created on			: Oct 17, 2014 :: 4:29:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
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

#ifndef NUMBERODDTIMES_H_
#define NUMBERODDTIMES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int xorValue = 0;
	for(unsigned int counter =0;counter < userInput.size();counter++){
		xorValue ^= userInput[counter];
	}
	return xorValue;
}

int numberOccuringOddTimesON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequencyMap.find(userInput[counter]) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second%2 == 1){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int outerCrawler = 0,innerCrawler,frequency;
	while(outerCrawler < userInput.size()){
		innerCrawler = outerCrawler;
		frequency = 0;
		while(innerCrawler < userInput.size() && userInput[innerCrawler] == userInput[outerCrawler]){
			frequency += 1;
			innerCrawler++;
		}
		if(frequency%2 == 1){
			return userInput[outerCrawler];
		}
		outerCrawler += innerCrawler;
	}
}

void notRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
	if(parent == null || child == null){
		return;
	}
	ifpAvlNode *grandParent = parent;
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

ifAvlNode *notInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
	if(*root == null){
		(*root) = new ifpAvlNode(value);
		return null;
	}
	if(currentNode->value == value){
		currentNode->frequency += 1;
		return null;
	}else if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ifAvlNode(value);
			currentNode->left->parent = currentNode;
			return currentNode;
		}else{
			return notInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return notInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void notInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *ptrToInsertedNode = notInsertAtRightPlace(root,*root,value);
	if(ptrToInsertedNode == null){
		return;
	}
	ifpAvlNode *z = ptrToInsertedNode,*y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > value?z->left:z->right;
			x = x->value > value?x->left:x->right;
			if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
				notRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				notRotateNodes(y,x);
				notRotateNodes(z,x);
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

int checkForOddFrequencyNode(ifpAvlNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency % 2 == 1){
		return ptr->value;
	}
	int leftResult = checkForOddFrequencyNode(ptr->left);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return checkForOddFrequencyNode(ptr->right);
}

int numberOccuringOddTimes(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		notInsertIntoAvlTree(&root,userInput[counter]);
	}
	return checkForOddFrequencyNode(root);
}

void ntRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
	if(parent == null || child == null){
		return;
	}
	ifRbTreeNode *grandParent = parent->parent;
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

ifRbTreeNode *ntInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return ntInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return ntInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void ntReorganizeRbTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
	if(currentNode == null){
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
			ntReorganizeRbTreePostInsertion(root,parent);
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
			ntReorganizeRbTreePostInsertion(root,parent);
		}
	}
}

void ntInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = ntInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	ntReorganizeRbTreePostInsertion(root,ptrToKey);
}

int getNodeWithOddFrequency(ifRbTreeNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency%2 == 1){
		return ptr;
	}
	int leftResult = getNodeWithOddFrequency(ptr->left);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return getNodeWithOddFrequency(ptr->right);
}

int numberOccuringOddTimesRbTree(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		ntInsertIntoRbTree(&root,userInput[counter]);
	}
	return getNodeWithOddFrequency(root);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequency;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] == userInput[outerCrawler]){
				frequency++;
			}
		}
		if(frequency%2 == 1){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

int getNumberOccuringOddNumber(iftNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency % 2 == 1){
		return ptr;
	}
	int leftValue = getNumberOccuringOddNumber(ptr->left);
	if(leftValue != INT_MIN){
		return leftValue;
	}
	return getNumberOccuringOddNumber(ptr->right);
}

int numberOccuringOddTimesBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getBSTFromVector(userInput);
	return getNumberOccuringOddNumber(rootBST);
}

#endif /* NUMBERODDTIMES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
