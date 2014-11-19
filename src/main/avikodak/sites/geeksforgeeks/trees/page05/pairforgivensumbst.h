/****************************************************************************************************************************************************
 *  File Name   		: pairforgivensumbst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\pairforgivensumbst.h
 *  Created on			: Nov 13, 2014 :: 6:57:00 PM
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

#ifndef PAIRFORGIVENSUMBST_H_
#define PAIRFORGIVENSUMBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void pFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	pFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	pFixLeftPtr(ptr->right);
}

void pFixRightPtr(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = *ptr,*prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	(*ptr) = currentNode;
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	return prevNode;
}

iPair *getPairForSumDllConversion(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	pFixLeftPtr(ptr);
	itNode *head = pFixRightPtr(&ptr);
	itNode *tail = ptr;
}

void pConvertTreeToDllONMain(itNode *ptr,itNode **head,itNode **tail){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	pConvertTreeToDllONMain(ptr->left,head,tail);
	ptr->left = prevNode;
	if(prevNode == null){
		(*head) = ptr;
	}else{
		prevNode->right = ptr;
	}
	prevNode = tail = ptr;
	pConvertTreeToDllONMain(ptr->right,head,tail);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/



/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *pConvertTreeToDllON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = pConvertTreeToDllON2Main(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		temp = pConvertTreeToDllON2Main(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

iPair *getPairForDllConversion(itNode *ptr){
	if(ptr == null){
		return null;
	}
	pConvertTreeToDllON2Main(ptr);
	itNode *head = ptr,*tail = ptr;
	while(tail->right != null){
		tail = tail->right;
	}
	while(head->left != null){
		head = head->left;
	}
}

itNode *searchForNode(itNode *ptr,itNode *key,int reqiredSum){
	if(ptr == null){
		return null;
	}
	if(ptr != key){
		if(ptr->value == reqiredSum){
			return ptr;
		}
	}
	itNode *result = searchForNode(ptr->left,key,reqiredSum);
	if(result != null){
		return result;
	}
	return searchForNode(ptr->right,key,reqiredSum);
}

iPair *getPairForGivenSum(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode,*result;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if((result = searchForNode(ptr,currentNode,sum-currentNode->value)) != null){
			return new iPair(currentNode->value,result->value);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
}

#endif /* PAIRFORGIVENSUMBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
