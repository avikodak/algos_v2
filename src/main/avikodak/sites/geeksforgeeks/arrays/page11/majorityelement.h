/****************************************************************************************************************************************************
 *  File Name   		: majorityelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\majorityelement.h
 *  Created on			: Oct 11, 2014 :: 11:20:57 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/majority-element/
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

#ifndef MAJORITYELEMENT_H_
#define MAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementMooreVotingAlgo(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int frequency = 0,index = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == userInput[index]){
			frequency++;
		}else{
			if(frequency == 1){
				index = counter;
				frequency = 1;
			}else{
				frequency--;
			}
		}
	}
	frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == userInput[index]){
			frequency++;
		}
	}
	return frequency > userInput.size()/2?userInput[index]:INT_MIN;
}

//Tested
int majorityElementONHashmap(vector<int> userInput){
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
		if(itToFrequencyMap->second > userInput.size()/2){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int requiredFrequency = userInput.size() / 2;
	for(unsigned int counter = 0;counter <= userInput.size()/2;counter++){
		if(userInput[counter] == userInput[counter + requiredFrequency]){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

//Tested
void meRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
	ifpAvlNode *grandParent = parent->parent;
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

//Tested
ifpAvlNode *meInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			return meInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return meInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
int majorityElememtInorder(ifpAvlNode *ptr,unsigned int size){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency > size/2){
		return ptr->value;
	}
	int leftResult = majorityElememtInorder(ptr->left,size);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return majorityElememtInorder(ptr->right,size);
}

//Tested
int majorityElementAvlTree(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		meInsertAtRightPlace(&root,root,userInput[counter]);
	}
	return majorityElememtInorder(root,userInput.size());
}

//Tested
void meRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
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
ifRbTreeNode *meInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return meInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return meInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void meReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
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
			meRotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				(*root) = parent;
				grandParent->isRedNode = false;
				return;
			}
			meReorganizeTreePostInsertion(root,parent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			meRotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				(*root) = parent;
				grandParent->isRedNode = false;
				return;
			}
			meReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

//Tested
void meInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = meInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	meReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
int getMajorityElementInorderRBTree(ifRbTreeNode *ptr,unsigned int size){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency > size/2){
		return ptr->value;
	}
	int leftResult = getMajorityElementInorderRBTree(ptr->left,size);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return getMajorityElementInorderRBTree(ptr->right,size);
}

//Tested
int getMajorityElementRbTree(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		meInsertIntoRbTree(&root,userInput[counter]);
	}
	return getMajorityElementInorderRBTree(root,userInput.size());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequency = 0;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(innerCrawler = outerCrawler;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency++;
			}
		}
		if(frequency > userInput.size()/2){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

//Tested
int getMajorityElementPreOrderBST(iftNode *ptr,unsigned int vectorSize){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency > vectorSize/2){
		return ptr->value;
	}
	int leftResult = getMajorityElementPreOrderBST(ptr->left,vectorSize);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return getMajorityElementPreOrderBST(ptr->right,vectorSize);
}

//Tested
int getMajorityElementON2BST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getFBSTFromVector(userInput);
	return getMajorityElementPreOrderBST(rootBST,userInput.size());
}

#endif /* MAJORITYELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
