/****************************************************************************************************************************************************
 *  File Name   		: getpairforgivensum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page11\getpairforgivensum.h
 *  Created on			: Oct 10, 2014 :: 4:13:13 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
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

#ifndef GETPAIRFORGIVENSUM_H_
#define GETPAIRFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenSumON(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap = getFrequencyMapFromVector(userInput);
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(sum - userInput[counter])) != frequencyMap.end()){
			iPair *result = new iPair();
			result->firstValue = userInput[counter];
			result->secondValue = sum - userInput[counter];
			return result;
		}
	}
	return null;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenSum(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int currentSum;
	while(frontCrawler < rearCrawler){
		currentSum = userInput[frontCrawler] + userInput[rearCrawler];
		if(currentSum == sum){
			iPair *result = new iPair();
			result->firstValue = userInput[frontCrawler];
			result->secondValue = userInput[rearCrawler];
			return result;
		}
		if(currentSum > sum){
			rearCrawler--;
		}else{
			frontCrawler++;
		}
	}
	return null;
}

//Tested
void gpsRotateNodes(ipAvlNode *parent,ipAvlNode *child){
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
ipAvlNode *insertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value){
	if((*root) == null){
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
			return insertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ipAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return insertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void gpsInsertIntoAvlTree(ipAvlNode **root,int value){
	ipAvlNode *ptrToKey = insertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	ipAvlNode *z = ptrToKey,*y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(rightHeight - leftHeight) > 1){
			y = z->value > value?z->left:z->right;
			x = y->value > value?y->left:y->right;
			if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				rotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				rotateNodes(y,x);
				rotateNodes(z,x);
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
ipAvlNode *gpsSearchForNode(ipAvlNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}else if(ptr->value > value){
		return gpsSearchForNode(ptr->left,value);
	}else{
		return gpsSearchForNode(ptr->right,value);
	}
}

//Tested
iPair *getPairForGivenSumAvlTree(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	ipAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		gpsInsertIntoAvlTree(&root,userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(gpsSearchForNode(root,sum-userInput[counter])){
			return new iPair(userInput[counter],sum - userInput[counter]);
		}
	}
	return null;
}

//Tested
void gpsRotateNodes(iRbTreeNode *parent,iRbTreeNode *child){
	iRbTreeNode *grandParent = parent->parent;
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
iRbTreeNode *gpsInsertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value){
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
			return gpsInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new iRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return gpsInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void gpsReorganizeTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode){
	if(currentNode == null){
		return;
	}
	iRbTreeNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == parent){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			gpsRotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				(*root) = grandParent;
				grandParent->isRedNode = false;
				return;
			}
			gpsReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			gpsRotateNodes(grandParent,parent);
			grandParent->isRedNode = true;
			parent->isRedNode = false;
			return;
		}else{
			grandParent->isRedNode = true;
			grandParent->left->isRedNode = false;
			grandParent->right->isRedNode = false;
			if(grandParent->parent == null){
				(*root) = grandParent;
				grandParent->isRedNode = false;
				return;
			}
			gpsReorganizeTreePostInsertion(root,currentNode->parent);
		}
	}
}

//Tested
void gpsInsertIntoRedBlackTree(iRbTreeNode **root,int value){
	iRbTreeNode *ptrToKey = gpsInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	gpsReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
iRbTreeNode *gpsSearchForValue(iRbTreeNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}else if(ptr->value > value){
		return gpsSearchForValue(ptr->left,value);
	}else{
		return gpsSearchForValue(ptr->right,value);
	}
}

//Tested
iPair *getPairForSumRebBlackTree(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	iRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		gpsInsertIntoRedBlackTree(&root,userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(gpsSearchForValue(root,sum-userInput[counter])){
			return new iPair(userInput[counter],sum-userInput[counter]);
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenSumON2(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] + userInput[innerCrawler] == sum){
				iPair *result = new iPair();
				result->firstValue = userInput[outerCrawler];
				result->secondValue = userInput[innerCrawler];
				return result;
			}
		}
	}
	return null;
}

//Tested
iPair *getPairForGivenSumBST(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	treeutils *utils = new treeutils();
	itNode *rootBST = utils->getBSTFromVector(userInput);
	itNode *temp;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		temp = utils->searchForValueBST(rootBST,sum-userInput[counter]);
		if(temp != null){
			iPair *result = new iPair();
			result->firstValue = userInput[counter];
			result->secondValue = sum - userInput[counter];
			return result;
		}
	}
	return null;
}

#endif /* GETPAIRFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
