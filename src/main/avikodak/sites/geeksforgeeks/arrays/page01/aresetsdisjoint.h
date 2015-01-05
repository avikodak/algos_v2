/****************************************************************************************************************************************************
 *  File Name   		: aresetsdisjoint.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\aresetsdisjoint.h
 *  Created on			: Jan 5, 2015 :: 10:42:04 AM
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef ARESETSDISJOINT_H_
#define ARESETSDISJOINT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
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
bool areSetsDisjointMerging(vector<int> firstSet,vector<int> secondSet){
	if(firstSet.size() == 0 || secondSet.size() == 0){
		return true;
	}
	sort(firstSet.begin(),firstSet.end());
	sort(secondSet.begin(),secondSet.end());
	int firstCrawler = 0,secondCrawler = 0;
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

bool sdjSearchInAvlTree(ipAvlNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	return ptr->value == value || sdjSearchInAvlTree(ptr->left,value) || sdjSearchInAvlTree(ptr->right.value);
}



/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ARESETSDISJOINT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
