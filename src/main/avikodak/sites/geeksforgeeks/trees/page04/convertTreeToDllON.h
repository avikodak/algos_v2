/****************************************************************************************************************************************************
 *  File Name   		: convertTreeToDllON.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\convertTreeToDllON.h
 *  Created on			: Nov 13, 2014 :: 9:19:24 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
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

#ifndef CONVERTTREETODLLON_H_
#define CONVERTTREETODLLON_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void oFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	oFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	oFixLeftPtr(ptr->right);
}

//Tested
void oFixRightPtr(itNode **ptr){
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
void oConvertTreeToDLLONFixing(itNode *ptr){
	if(ptr == null){
		return;
	}
	oFixLeftPtr(ptr);
	oFixRightPtr(&ptr);
	while(ptr !=null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

//Tested
void oConvertTreeToDLLONMain(itNode *ptr,itNode **head){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	oConvertTreeToDLLONMain(ptr->left,head);
	ptr->left = prevNode;
	if(prevNode == null){
		(*head) = ptr;
	}else{
		prevNode->right = ptr;
	}
	prevNode = ptr;
	oConvertTreeToDLLONMain(ptr->right,head);
}

//Tested
void oConvertTreeToDll(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *head =  null;
	oConvertTreeToDLLONMain(ptr,&head);
	while(head != null){
		printf("%d\t",head->value);
		head = head->right;
	}
}

#endif /* CONVERTTREETODLLON_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
