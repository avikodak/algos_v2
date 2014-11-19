/****************************************************************************************************************************************************
 *  File Name   		: mergetwobsts.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\mergetwobsts.h
 *  Created on			: Nov 1, 2014 :: 9:19:05 AM
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

#ifndef MERGETWOBSTS_H_
#define MERGETWOBSTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertIntoSecondTree(itNode *firstTree,itNode *secondTree,treeutils *utils){
	if(firstTree == null){
		return;
	}
	utils->insertIntoBST(&secondTree,firstTree->value);
	insertIntoSecondTree(firstTree->left,secondTree,utils);
	insertIntoSecondTree(firstTree->right,secondTree,utils);
}

itNode *mergeTwoBSTS(itNode *firstTree,itNode *secondTree){
	if(firstTree == null || secondTree == null){
		return firstTree == null?secondTree:firstTree;
	}
	treeutils *utils = new treeutils();
	insertIntoSecondTree(firstTree,secondTree,utils);
	return secondTree;
}

itNode *mergeTwoBSTSInorderTraversal(itNode *firstTree,itNode *secondTree){
	if(firstTree == null || secondTree == null){
		return firstTree == null?secondTree:firstTree;
	}
	treeutils *utils = new treeutils();
	vector<int> inorderValuesFirstTree = utils->getValuesInInorder(firstTree);
	vector<int> inorderValuesSecondTree = utils->getValuesInInorder(secondTree);
	vector<int> mergedValues;
	unsigned int firstVectorCounter = 0,secondVectorCounter = 0;
	while(firstVectorCounter < inorderValuesFirstTree.size() && secondVectorCounter < inorderValuesSecondTree.size()){
		if(inorderValuesFirstTree[firstVectorCounter] < inorderValuesSecondTree[secondVectorCounter]){
			mergedValues.push_back(inorderValuesFirstTree[firstVectorCounter]);
			firstVectorCounter++;
		}else{
			mergedValues.push_back(inorderValuesSecondTree[secondVectorCounter]);
			secondVectorCounter++;
		}
	}
	return utils->getBSTSortedVector(mergedValues);
}

void convertBSTToDllON(itNode *ptr,itNode **root){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	convertBSTToDllON(ptr->left,root);
	ptr->left = prevNode;
	if(prevNode != null){
		prevNode->right = ptr;
	}else{
		*root = ptr;
	}
	prevNode = ptr;
	convertBSTToDllON(ptr->right,root);
}

itNode *convertDillToBalancedBST(itNode **ptr,int nValue){
	if(*ptr == null){
		return null;
	}
	itNode *root = new itNode();
	root->left = convertDillToBalancedBST(ptr,nValue/2);
	root->value = (*ptr)->value;
	(*ptr) = (*ptr)->right;
	root->right = convertDillToBalancedBST(ptr,nValue - (nValue/2) -1);
	return root;
}

int lengthOfDill(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + lengthOfDill(ptr->right);
}

itNode *merge(itNode *firstDill,itNode *secondDill){
	if(firstDill == null || secondDill == null){
		return firstDill == null?secondDill:firstDill;
	}
	itNode *root;
	if(firstDill->value < secondDill->value){
		root = firstDill;
		root->right = merge(firstDill->right,secondDill);
	}else{
		root = secondDill;
		root->right = merge(firstDill,secondDill->right);
	}
	return root;
}

itNode  *mergeTwoBSTSByDLLConversion(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	convertBSTToDllON(firstPtr,&firstPtr);
	convertBSTToDllON(secondPtr,&secondPtr);
	itNode *mergedDillHead;
	int length = lengthOfDill(mergedDillHead);
	return convertDillToBalancedBST(&mergedDillHead,length);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *mergeTwoBSTSSorting(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	treeutils *utils = new treeutils();
	vector<int> firstTreeInorderValues = utils->getValuesInInorder(firstPtr);
	vector<int> secondTreeInorderValues = utils->getValuesInInorder(secondPtr);
	vector<int> mergedVector;
	std::merge(firstTreeInorderValues.begin(),firstTreeInorderValues.end(),secondTreeInorderValues.begin(),secondTreeInorderValues.end(),mergedVector.begin());
	sort(mergedVector.begin(),mergedVector.end());
	return utils->getBSTSortedVector(mergedVector);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* MERGETWOBSTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
