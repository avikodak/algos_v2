/****************************************************************************************************************************************************
 *  File Name   		: pairsfordifference.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\pairsfordifference.h
 *  Created on			: Dec 22, 2014 :: 8:16:10 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-pairs-difference-equal-k/
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

#ifndef PAIRSFORDIFFERENCE_H_
#define PAIRSFORDIFFERENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKON(vector<int> userInput,int difference){
	if(userInput.size() == 0){
		return 0;
	}
	hash_map<int,bool> visitedFlags;
	hash_map<int,bool>::iterator itToVisitedFlags;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		visitedFlags.insert(pair<int,bool>(userInput[counter],true));
	}
	int pairCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		itToVisitedFlags = visitedFlags.find(difference - userInput[counter]);
		if(itToVisitedFlags != visitedFlags.end()){
			pairCounter++;
			visitedFlags.erase(difference - userInput[counter]);
			visitedFlags.erase(itToVisitedFlags->first);
		}else{
			itToVisitedFlags = visitedFlags.find(userInput[counter] - difference);
			if(itToVisitedFlags != visitedFlags.end()){
				pairCounter++;
				visitedFlags.erase(userInput[counter] - difference);
				visitedFlags.erase(itToVisitedFlags->first);
			}
		}
	}
	return pairCounter;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKONLOGN(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return 0;
	}
	sort(userInput.begin(),userInput.end());
	int currentDifference,pairCounter = 0;
	unsigned int frontCrawler = 0,rearCrawler = 0;
	while(frontCrawler < userInput.size() && rearCrawler < userInput.size()){
		currentDifference = userInput[rearCrawler] - userInput[frontCrawler];
		if(currentDifference == difference){
			pairCounter += 1;
			frontCrawler++;
			rearCrawler++;
		}else if(currentDifference > difference){
			frontCrawler++;
		}else{
			rearCrawler++;
		}
	}
	return pairCounter;
}

void pfdRotateNodes(ipAvlNode *parent,ipAvlNode *child){
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

ipAvlNode *pfdInsertAtRightPlace(ipAvlNode **root,ipAvlNode *currentNode,int value){
	if(*root == null){
		(*root) = new ipAvlNode(value);
		return null;
	}
	if(currentNode->value == value){
		return null;
	}
	if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ipAvlNode(value);
			currentNode->left->parent = currentNode;
			return currentNode;
		}else{
			return pfdInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ipAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return pfdInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void pfdInsertIntoAvlTree(ipAvlNode **root,int value){
	ipAvlNode *z = pfdInsertAtRightPlace(root,*root,value);
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
				pfdRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				pfdRotateNodes(y,x);
				pfdRotateNodes(z,x);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
			}
			return;
		}
		z->height = 1 + max(leftHeight,rightHeight);
		z = z->left;
	}
}

bool pfdSearchInAvlTree(ipAvlNode *ptr,int value){
	if(ptr == null){
		return;
	}
	if(ptr->value == value){
		return true;
	}
	return pfdSearchInAvlTree(ptr->left,value) || pfdSearchInAvlTree(ptr->right,value);
}

int getCountPairsForDifference(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return 0;
	}
	ipAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		pfdInsertIntoAvlTree(&root,userInput[counter]);
	}
	hash_map<int,bool> visitedFlags;
	hash_map<int,bool>::iterator itToVisitedFlags;
	int counter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToVisitedFlags = visitedFlags.find(userInput[counter])) == visitedFlags.end()){
			if(visitedFlags.find(userInput[counter] - difference) == visitedFlags.end()){
				if(pfdSearchInAvlTree(root,userInput[counter] - difference)){
					visitedFlags.insert(pair<int,bool>(userInput[counter] - difference,true));
				}
				counter += 1;
			}
			if(visitedFlags.find(userInput[counter] + difference) == visitedFlags.end()){
				if(pfdSearchInAvlTree(root,userInput[counter] + difference)){
					visitedFlags.insert(pair<int,bool>(userInput[counter] + difference,true));
				}
				counter += 1;
			}
		}
	}
	return counter;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKON2(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return 0;
	}
	int pairCounter = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(abs(userInput[outerCrawler] - userInput[innerCrawler]) == abs(difference)){
				pairCounter++;
			}
		}
	}
	return pairCounter;
}

#endif /* PAIRSFORDIFFERENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
