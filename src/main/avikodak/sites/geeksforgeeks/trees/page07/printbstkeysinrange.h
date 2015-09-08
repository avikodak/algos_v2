/****************************************************************************************************************************************************
 *  File Name   		: printbstkeysinrange.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\printbstkeysinrange.h
 *  Created on			: Oct 20, 2014 :: 8:38:37 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef PRINTBSTKEYSINRANGE_H_
#define PRINTBSTKEYSINRANGE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printBSTKeysInRange(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	if(ptr->value >= minValue){
		printBSTKeysInRange(ptr->left,minValue,maxValue);
	}
	if(ptr->value >= minValue && ptr->value <= maxValue){
		printf("%d\t",ptr->value);
	}
	if(ptr->value <= maxValue){
		printBSTKeysInRange(ptr->right,minValue,maxValue);
	}
}

//Tested
void pFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	pFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	pFixLeftPtr(ptr->right);
}

//Tested
void pFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr,*prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	(*ptr) = prevNode;
}

//Tested
void printBSTKeysInRangeDllConversionON(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	pFixLeftPtr(ptr);
	pFixRightPtr(&ptr);
	while(ptr != null){
		if(ptr->value >= minValue && ptr->value <= maxValue){
			printf("%d\t",ptr->value);
		}
		ptr = ptr->right;
	}
}

//Tested
void pConvertTreeToDLLON(itNode *ptr,itNode **root){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	pConvertTreeToDLLON(ptr->left,root);
	ptr->left = prevNode;
	if(prevNode == null){
		(*root) = ptr;
	}else{
		prevNode->right = ptr;
	}
	prevNode = ptr;
	pConvertTreeToDLLON(ptr->right,root);
}

//Tested
void printKeysBSTInOrderDLLConversion(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	pConvertTreeToDLLON(ptr,&ptr);
	while(ptr != null){
		if(ptr->value >= minValue && ptr->value <= maxValue){
			printf("%d\t",ptr->value);
		}
		ptr = ptr->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printKeysBSTBySorting(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	vector<int> userInput = utils->getValuesInPreorder(ptr);
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= minValue && userInput[counter] <= maxValue){
			printf("%d\t",userInput[counter]);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *pConvertTreeToDllON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = pConvertTreeToDllON2(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		temp = pConvertTreeToDllON2(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

//Tested
void printKeysBSTDllConversionON2(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	pConvertTreeToDllON2(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null){
		if(ptr->value >= minValue && ptr->value <= maxValue){
			printf("%d\t",ptr->value);
		}
		ptr = ptr->right;
	}
}

#endif /* PRINTBSTKEYSINRANGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
