/****************************************************************************************************************************************************
 *  File Name   		: printbstkeysinrange.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\printbstkeysinrange.h
 *  Created on			: Oct 20, 2014 :: 8:38:37 PM
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

#ifndef PRINTBSTKEYSINRANGE_H_
#define PRINTBSTKEYSINRANGE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
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

void pFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = ptr;
	pFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	pFixLeftPtr(ptr->right);
}

void pFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr,*prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode = currentNode->left;
		currentNode->right = prevNode;
		prevNode = currentNode;
	}
	(*ptr) = prevNode;
}

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

void convertTreeToDLLON(itNode *ptr,itNode **root){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	convertTreeToDLLON(ptr->left,root);
	ptr->left = prevNode;
	if(prevNode == null){
		(*root) = ptr;
	}else{
		prevNode->right = ptr;
	}
	prevNode = ptr;
	convertTreeToDLLON(ptr->right,root);
}

void printKeysBSTInOrderDLLConversion(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	convertTreeToDLLON(ptr,&ptr);
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
itNode *convertTreeToDllON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = convertTreeToDllON2(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		temp = convertTreeToDllON2(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

void printKeysBSTDllConversionON2(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	convertTreeToDllON2(ptr);
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
