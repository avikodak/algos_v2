/****************************************************************************************************************************************************
 *  File Name   		: kthSmallestBST.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\kthSmallestBST.h
 *  Created on			: Oct 20, 2014 :: 7:17:27 PM
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

#ifndef KTHSMALLESTBST_H_
#define KTHSMALLESTBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getKthSmallestBST(itNode *ptr,unsigned int &kValue){
	if(ptr == null){
		return null;
	}
	itNode *leftResult = getKthSmallestBST(ptr->left,kValue);
	if(leftResult != null){
		return leftResult;
	}
	kValue--;
	if(kValue == 0){
		return ptr;
	}
	return getKthSmallestBST(ptr->right,kValue);
}

void kFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	kFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	kFixLeftPtr(ptr->right);
}

void kFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr;
	itNode *prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	*ptr = prevNode;
}

itNode *getKthSmallestBSTDllConversion(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return null;
	}
	kFixLeftPtr(ptr);
	kFixRightPtr(&ptr);
	itNode *currentNode = ptr;
	while(ptr != null && --kValue){
		ptr = ptr->right;
	}
	return ptr;
}

void convertTreeToDLLON(itNode *ptr,itNode **head){
	if(ptr == null){
		(*head) = null;
		return;
	}
	static itNode *prevNode = null;
	convertTreeToDLLON(ptr->left,head);
	ptr->left = prevNode;
	if(prevNode == null){
		(*head) = prevNode;
	}else{
		prevNode->right = ptr;
	}
	prevNode = ptr;
	convertTreeToDLLON(ptr->right,head);
}

itNode *getKthSmallestBSTDllConversionON(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return null;
	}
	convertTreeToDLLON(ptr,&ptr);
	while(ptr != null && --kValue){
		ptr = ptr->right;
	}
	return ptr;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int getKthSmallestBST(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	vector<int> values = utils->getValuesInPreorder(ptr);
	sort(values.begin(),values.end());
	if(kValue > values.size()){
		return INT_MIN;
	}
	return values[kValue-1];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *convertTreeToDLLON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = convertTreeToDLLON2(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		temp = convertTreeToDLLON2(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

itNode *getKthSmallestBSTDllConversionON2(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return null;
	}
	convertTreeToDLLON2(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null && --kValue){
		ptr = ptr->right;
	}
	return ptr;
}

#endif /* KTHSMALLESTBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
