/****************************************************************************************************************************************************
 *  File Name   		: findrepeatingelements.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\findrepeatingelements.h
 *  Created on			: Nov 26, 2014 :: 2:27:12 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
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

#ifndef FINDREPEATINGELEMENTS_H_
#define FINDREPEATINGELEMENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoRepeatingElements(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[abs(userInput[counter])-1] *= -1;
	}
	iPair *result = new iPair(0,0);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			if(result->firstValue == 0){
				result->firstValue = counter+1;
			}else{
				result->secondValue = counter+1;
				return result;
			}
		}
	}
	return null;
}

//Tested
iPair *getTwoRepeatingElementsHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
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
	iPair *result = new iPair(0,0);
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second == 2){
			if(result->firstValue == 0){
				result->firstValue = itToFrequencyMap->first;
			}else{
				result->secondValue = itToFrequencyMap->first;
				return result;
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getTwoRepeatingElementsSorting(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	iPair *result = new iPair(0,0);
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter] == userInput[counter+1]){
			if(result->firstValue == 0){
				result->firstValue = userInput[counter];
			}else{
				result->secondValue = userInput[counter];
				return result;
			}
		}
	}
	return null;
}

//Tested
void gtrRotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
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
ifpAvlNode *gtrInsertAtRightPlace(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
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
			return gtrInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifpAvlNode(value);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return gtrInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void gtrInsertIntoAvlTree(ifpAvlNode **root,int value){
	ifpAvlNode *z = gtrInsertAtRightPlace(root,*root,value);
	if(z == null){
		return;
	}
	int leftHeight,rightHeight;
	ifpAvlNode *y,*x;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > value?z->left:z->right;
			x = y->value > value?y->left:y->right;
			if((z->left == y && y->left == x) && (z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				gtrRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				gtrRotateNodes(y,x);
				gtrRotateNodes(z,x);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
			}
		}
		z->height = 1 + max(leftHeight,rightHeight);
		z = z->parent;
	}
}

//Tested
void findTwoRepeatingNumbersInorder(ifpAvlNode *ptr,iPair *result){
	if(ptr == null){
		return;
	}
	if(ptr->frequency > 1){
		if(result->firstValue == 0){
			result->firstValue = ptr->value;
		}else{
			result->secondValue = ptr->value;
			return;
		}
	}
	findTwoRepeatingNumbersInorder(ptr->left,result);
	findTwoRepeatingNumbersInorder(ptr->right,result);
}

//Tested
iPair *findRepeatingNumbersAvlTree(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	ifpAvlNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		gtrInsertIntoAvlTree(&root,userInput[counter]);
	}
	iPair *result = new iPair(0,0);
	findTwoRepeatingNumbersInorder(root,result);
	return result;
}

//Tested
void gtrRotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child){
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
ifRbTreeNode *gtrInsertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value){
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
			return gtrInsertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifRbTreeNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return gtrInsertAtRightPlace(root,currentNode->right,value);
		}
	}
}

//Tested
void gtrReorganizeTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode){
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
			gtrRotateNodes(grandParent,parent);
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
			gtrReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			gtrRotateNodes(grandParent,parent);
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
			gtrReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

//Tested
void gtrInsertIntoRbTree(ifRbTreeNode **root,int value){
	ifRbTreeNode *ptrToKey = gtrInsertAtRightPlace(root,*root,value);
	if(ptrToKey == null){
		return;
	}
	if(!ptrToKey->parent->isRedNode){
		return;
	}
	gtrReorganizeTreePostInsertion(root,ptrToKey);
}

//Tested
void findTwoRepeatingNumbersInorder(ifRbTreeNode *ptr,iPair *result){
	if(ptr == null){
		return;
	}
	if(ptr->frequency > 1){
		if(result->firstValue == 0){
			result->firstValue = ptr->value;
		}else{
			result->secondValue = ptr->value;
			return;
		}
	}
	findTwoRepeatingNumbersInorder(ptr->left,result);
	findTwoRepeatingNumbersInorder(ptr->right,result);
}

//Tested
iPair *findTwoRepeatingNumbersRedBlackTrees(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	ifRbTreeNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		gtrInsertIntoRbTree(&root,userInput[counter]);
	}
	iPair *result = new iPair(0,0);
	findTwoRepeatingNumbersInorder(root,result);
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *findTwoRepeatingNumbersON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(0,0);
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				if(result->firstValue == 0){
					result->firstValue = userInput[outerCounter];
				}else{
					result->secondValue = userInput[outerCounter];
					return result;
				}
			}
		}
	}
	return result;
}

#endif /* FINDREPEATINGELEMENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
