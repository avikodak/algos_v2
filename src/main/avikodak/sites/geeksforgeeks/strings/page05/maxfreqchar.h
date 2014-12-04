/****************************************************************************************************************************************************
 *  File Name   		: maxfreqchar.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\maxfreqchar.h
 *  Created on			: Dec 3, 2014 :: 11:24:44 AM
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

#ifndef MAXFREQCHAR_H_
#define MAXFREQCHAR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
char maxOccuringCharHashmap(char *userInput){
	if(userInput == null){
		return '\0';
	}
	hash_map<char,unsigned int> charFrequency;
	hash_map<char,unsigned int>::iterator itToCharFrequency;
	while(*userInput != '\0'){
		if(charFrequency.find(userInput[0]) == charFrequency.end()){
			charFrequency.insert(pair<char,unsigned int>(userInput[0],1));
		}else{
			charFrequency[userInput[0]]++;
		}
		userInput++;
	}
	unsigned int maxFrequency = 0;
	char maxOccuringChar;
	for(itToCharFrequency = charFrequency.begin();itToCharFrequency != charFrequency.end();itToCharFrequency++){
		if(itToCharFrequency->second > maxFrequency){
			maxFrequency = itToCharFrequency->second;
			maxOccuringChar = itToCharFrequency->first;
		}
	}
	return maxOccuringChar;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void mfcMerge(char *userInput,int startIndex,int middleIndex,int endIndex){
	if(userInput == null){
		return;
	}
	char *auxSpace = (char *)malloc(sizeof(char) * (endIndex - startIndex + 2));
	int firstCrawler = startIndex;
	int secondCrawler = middleIndex+1;
	int counter = -1;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace[++counter] = userInput[firstCrawler++];
			}else{
				auxSpace[++counter] = userInput[secondCrawler++];
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
				auxSpace[++counter] = userInput[firstCrawler++];
			}else{
				auxSpace[++counter] = userInput[secondCrawler++];
			}
		}
	}
	auxSpace[++counter] = '\0';
	for(int counter = 0;counter <= endIndex - startIndex;counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

//Tested
void mfcMergeSort(char *userInput,int startIndex,int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mfcMergeSort(userInput,startIndex,middleIndex);
	mfcMergeSort(userInput,middleIndex+1,endIndex);
	mfcMerge(userInput,startIndex,middleIndex,endIndex);
}

//Tested
int mfcDivideStepQuickSort(char *userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	char key  = userInput[endIndex],temp;
	int pivotIndex = endIndex;
	while(startIndex  < endIndex){
		while(userInput[startIndex] < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			temp = userInput[startIndex];
			userInput[startIndex] = userInput[endIndex];
			userInput[endIndex] = temp;
		}
	}
	temp = userInput[pivotIndex];
	userInput[pivotIndex] = userInput[endIndex];
	userInput[endIndex] = temp;
	return endIndex;
}

//Tested
void mfcQuickSort(char *userInput,int startIndex,int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int dividingIndex = mfcDivideStepQuickSort(userInput,startIndex,endIndex);
	mfcQuickSort(userInput,startIndex,dividingIndex-1);
	mfcQuickSort(userInput,dividingIndex+1,endIndex);
}

void mfcRotateNodes(cfpAvlNode *parent,cfpAvlNode *child){
	if(parent == null || child == null){
		return;
	}
	cfpAvlNode *grandParent = parent->parent;
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

cfpAvlNode *mfcInsertAtRightPlace(cfpAvlNode **root,cfpAvlNode *currentNode,char ch){
	if(ch == '\0'){
		return null;
	}
	if(*root == null){
		(*root) = new cfpAvlNode(ch);
		return null;
	}
	if(currentNode->ch == ch){
		currentNode->frequency += 1;
		return null;
	}else if(currentNode->ch > ch){
		if(currentNode->left == null){
			currentNode->left = new cfpAvlNode(ch);
			currentNode->left->parent = currentNode;
			return currentNode;
		}else{
			return mfcInsertAtRightPlace(root,currentNode->left,ch);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new cfpAvlNode(ch);
			currentNode->right->parent = currentNode;
			return currentNode;
		}else{
			return mfcInsertAtRightPlace(root,currentNode->right,ch);
		}
	}
}

void mfcInsertIntoAvlTree(cfpAvlNode **root,char ch){
	cfpAvlNode *z = mfcInsertAtRightPlace(root,*root,ch);
	if(z == null){
		return;
	}
	cfpAvlNode *y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->ch > ch?z->left:z->right;
			x = y->ch > ch?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				mfcRotateNodes(z,y);
				z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
				y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				mfcRotateNodes(y,x);
				mfcRotateNodes(z,x);
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

void setMaxOccuringCharInorderAvl(cfpAvlNode *ptr,char &ch,unsigned int &frequency){
	if(ptr == null){
		return;
	}
	setMaxOccuringCharInorderAvl(ptr->left,ch,frequency);
	if(frequency < ptr->frequency){
		frequency = ptr->frequency;
		ch = ptr->ch;
	}
	setMaxOccuringCharInorderAvl(ptr->right,ch,frequency);
}

char maxFrequencyAvlTree(char *userInput,int size){
	if(userInput == null){
		return '\0';
	}
	cfpAvlNode *root = null;
	while(userInput != null){
		mfcInsertIntoAvlTree(&root,userInput[0]);
		userInput++;
	}
	unsigned int maxFrequency = 0;
	char maxOccuringChar;
	setMaxOccuringCharInorderAvl(root,maxOccuringChar,maxFrequency);
	return maxOccuringChar;
}

void mfcRotateNodes(cfpRbTNode *parent,cfpRbTNode *child){
	if(parent == null || child  == null){
		return;
	}
	cfpRbTNode *grandParent = parent->parent;
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

cfpRbTNode *mfcInsertAtRightPlace(cfpRbTNode **root,cfpRbTNode *currentNode,char ch){
	if(*root == null){
		(*root) = new cfpRbTNode(ch);
		(*root)->isRedNode = false;
		return null;
	}
	if(currentNode->ch == ch){
		currentNode->frequency += 1;
		return null;
	}else if(currentNode->ch > ch){
		if(currentNode->left == null){
			currentNode->left = new cfpRbTNode(ch);
			currentNode->left->parent = currentNode;
			return currentNode->left;
		}else{
			return mfcInsertAtRightPlace(root,currentNode->left,ch);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new cfpRbTNode(ch);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return mfcInsertAtRightPlace(root,currentNode->right,ch);
		}
	}
}

void mfcReorganizeTreePostInsertion(cfpRbTNode **root,cfpRbTNode *currentNode){
	if(*root == null || currentNode == null){
		return;
	}
	cfpRbTNode *parent = currentNode->parent,*grandParent = parent->parent;
	if(!parent->isRedNode){
		return;
	}
	if(grandParent->left == null){
		if(grandParent->right == null || !grandParent->right->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			mfcRotateNodes(grandParent,parent);
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
			mfcReorganizeTreePostInsertion(root,grandParent);
		}
	}else{
		if(grandParent->left == null || !grandParent->left->isRedNode){
			if(grandParent->parent == null){
				(*root) = parent;
			}
			mfcRotateNodes(grandParent,parent);
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
			mfcReorganizeTreePostInsertion(root,grandParent);
		}
	}
}

void mfcInsertIntoRbTree(cfpRbTNode **root,char ch){
	cfpRbTNode *ptrToKey = mfcInsertAtRightPlace(root,*root,ch);
	if(ptrToKey == null || !ptrToKey->parent->isRedNode){
		return;
	}
	mfcReorganizeTreePostInsertion(root,ptrToKey);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
char maxOccuringCharON2(char *userInput){
	if(userInput == null){
		return '\0';
	}
	char *outerCrawler = userInput,*innerCrawler;
	unsigned int frequency,maxFrequency;
	char maxOccuringChar;
	while(outerCrawler != null){
		innerCrawler = outerCrawler+1;
		frequency = 0;
		while(innerCrawler != null){
			if(outerCrawler[0] == innerCrawler[0]){
				frequency++;
			}
		}
		if(maxFrequency > frequency){
			maxFrequency = frequency;
			maxOccuringChar = outerCrawler[0];
		}
	}
	return maxOccuringChar;
}

void mfcGetBstForString(cftNode **root,cftNode *currentNode,char *userInput){
	if(userInput == null){
		return;
	}
	if(*root == null){
		(*root) = new cftNode(userInput[0]);
		mfcGetBstForString(root,*root,userInput++);
	}else if(currentNode->ch == userInput[0]){
		currentNode->frequency += 1;
		mfcGetBstForString(root,*root,userInput++);
	}else if(currentNode->ch > userInput[0]){
		if(currentNode->left == null){
			currentNode->left = new cftNode(userInput[0]);
			mfcGetBstForString(root,*root,userInput++);
		}else{
			mfcGetBstForString(root,currentNode->left,userInput);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new cftNode(userInput[0]);
			mfcGetBstForString(root,*root,userInput++);
		}else{
			mfcGetBstForString(root,currentNode->right,userInput);
		}
	}
}

void setMaxOccuringCharBSTInorder(cftNode *ptr,unsigned int &maxFrequency,char &ch){
	if(ptr == null){
		return;
	}
	setMaxOccuringCharBSTInorder(ptr->left,maxFrequency,ch);
	if(maxFrequency < ptr->frequency){
		maxFrequency = ptr->frequency;
		ch = ptr->ch;
	}
	setMaxOccuringCharBSTInorder(ptr->right,maxFrequency,ch);
}

char maxOccuringCharBST(char *userInput){
	if(userInput == null){
		return '\0';
	}
	cftNode *root = null;
	mfcGetBstForString(&root,root,userInput);
	unsigned int maxFrequency = 0;
	char maxOccuringChar = '\0';
	setMaxOccuringCharBSTInorder(root,maxFrequency,maxOccuringChar);
	return maxOccuringChar;
}

#endif /* MAXFREQCHAR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
