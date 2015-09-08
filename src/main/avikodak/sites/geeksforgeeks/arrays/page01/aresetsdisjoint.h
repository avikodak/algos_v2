/****************************************************************************************************************************************************
 *  File Name   		: aresetsdisjoint.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\aresetsdisjoint.h
 *  Created on			: Jan 5, 2015 :: 10:42:04 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-two-given-sets-disjoint/
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

#ifndef ARESETSDISJOINT_H_
#define ARESETSDISJOINT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areSetsDisjointHashmap(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 || secondSet.size() == 0){
		return true;
	}
	hash_map<int,bool> visitedValueMap;
	for(unsigned int counter = 0;counter < firstSet.size();counter++){
		visitedValueMap[firstSet[counter]] = true;
	}
	for(unsigned int counter = 0;counter < secondSet.size();counter++){
		if(visitedValueMap.find(secondSet[counter]) != visitedValueMap.end()){
			return false;
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areSetsDisjointMerging(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 || secondSet.size() == 0){
		return true;
	}
	sort(firstSet.begin(),firstSet.end());
	sort(secondSet.begin(),secondSet.end());
	unsigned int firstCrawler = 0,secondCrawler = 0;
	while(firstCrawler < firstSet.size() && secondCrawler < secondSet.size()){
		if(firstSet[firstCrawler] == secondSet[secondCrawler]){
			return false;
		}else if(firstSet[firstCrawler] < secondSet[secondCrawler]){
			firstCrawler++;
		}else{
			secondCrawler++;
		}
	}
	return true;
}

//Tested
void sdjRotateNodes(ipAvlNode *parent,ipAvlNode *child){
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

//Tested
ipAvlNode *sdjInsertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value){
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
			return sdjInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ipAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return sdjInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void sdjInsertIntoAvlTree(ipAvlNode **root,int value){
	ipAvlNode *z = sdjInsertAtRightPlace(root,*root,value);
	if(z == null){
		return;
	}
	ipAvlNode *y,*x;
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
				sdjRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				sdjRotateNodes(y,x);
				sdjRotateNodes(z,x);
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
bool sdjSearchInAvlTree(ipAvlNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	return ptr->value == value || sdjSearchInAvlTree(ptr->left,value) || sdjSearchInAvlTree(ptr->right,value);
}

//Tested
bool areSetsDisjointAvlTree(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 ||secondSet.size() == 0){
		return true;
	}
	ipAvlNode *root = null;
	for(unsigned int counter = 0;counter < firstSet.size();counter++){
		sdjInsertIntoAvlTree(&root,firstSet[counter]);
	}
	for(unsigned int counter = 0;counter < secondSet.size();counter++){
		if(sdjSearchInAvlTree(root,secondSet[counter])){
			return false;
		}
	}
	return true;
}

//Tested
void sdjRotateNodes(iRbTreeNode *parent,iRbTreeNode *child){
	if(parent == null || child == null){
		return;
	}
	iRbTreeNode *grandParent = parent->parent;
	parent->parent = child;
	child->parent = grandParent;
	if(grandParent->left == parent){
		grandParent->left = child;
	}else{
		grandParent->right = child;
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
iRbTreeNode *sdjInsertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value){
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
			return sdjInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new iRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return sdjInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void sdjReorganizeTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode){
	if(root == null || currentNode == null){
		return;
	}
	if(!currentNode->parent->isRedNode){
		return;
	}
	iRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			sdjRotateNodes(grandParent,parent);
			grandParent->isRedNode = false;
			parent->isRedNode = true;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->right = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			sdjReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			sdjRotateNodes(grandParent,parent);
			grandParent->isRedNode = false;
			parent->isRedNode = true;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->right = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
				return;
			}
			sdjReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

//Tested
void sdjInsertIntoRbTree(iRbTreeNode **root,int value){
	iRbTreeNode *ptrToKey = sdjInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	sdjReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
bool sdjSearchRbTree(iRbTreeNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	return ptr->value == value || sdjSearchRbTree(ptr->left,value) || sdjSearchRbTree(ptr->right,value);
}

//Tested
bool areSetsDisjointRbTree(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 ||secondSet.size() == 0){
		return true;
	}
	iRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < firstSet.size();counter++){
		sdjInsertIntoRbTree(&root,firstSet[counter]);
	}
	for(unsigned int counter = 0;counter < secondSet.size();counter++){
		if(sdjSearchRbTree(root,secondSet[counter])){
			return false;
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void sdjInsertIntoBSTMain(itNode **root,itNode *currentNode,vector<int> userInput,unsigned int currentIndex){
	if(currentIndex >= userInput.size()){
		return;
	}
	if(*root == null){
		(*root) = new itNode(userInput[currentIndex]);
		sdjInsertIntoBSTMain(root,*root,userInput,currentIndex+1);
	}else if(currentNode->value == userInput[currentIndex]){
		sdjInsertIntoBSTMain(root,*root,userInput,currentIndex+1);
	}else if(currentNode->value > userInput[currentIndex]){
		if(currentNode->left == null){
			currentNode->left = new itNode(userInput[currentIndex]);
			sdjInsertIntoBSTMain(root,*root,userInput,currentIndex+1);
		}else{
			sdjInsertIntoBSTMain(root,currentNode->left,userInput,currentIndex);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new itNode(userInput[currentIndex]);
			sdjInsertIntoBSTMain(root,*root,userInput,currentIndex+1);
		}else{
			sdjInsertIntoBSTMain(root,currentNode->right,userInput,currentIndex);
		}
	}
}

//Tested
bool sdjSearchInBST(itNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	return ptr->value == value || sdjSearchInBST(ptr->left,value) || sdjSearchInBST(ptr->right,value);
}

//Tested
bool areSetsDisjointBSTON2(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 ||secondSet.size() == 0){
		return true;
	}
	itNode *root = null;
	sdjInsertIntoBSTMain(&root,root,firstSet,0);
	for(unsigned int counter = 0;counter < secondSet.size();counter++){
		if(sdjSearchInBST(root,secondSet[counter])){
			return false;
		}
	}
	return true;
}

//Tested
bool areSetsDisjointON2(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 ||secondSet.size() == 0){
		return true;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < secondSet.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler < firstSet.size();innerCrawler++){
			if(firstSet[innerCrawler] == secondSet[outerCrawler]){
				return false;
			}
		}
	}
	return true;
}
#endif /* ARESETSDISJOINT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
