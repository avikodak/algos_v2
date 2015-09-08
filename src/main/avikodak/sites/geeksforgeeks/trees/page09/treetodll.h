/****************************************************************************************************************************************************
 *  File Name   		: treetodll.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\treetodll.h
 *  Created on			: Oct 14, 2014 :: 12:45:34 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem/
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

#ifndef TREETODLL_H_
#define TREETODLL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void treeToDllFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	treeToDllFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	treeToDllFixLeftPtr(ptr->right);
}

//Tested
void treeToDllFixRightPtr(itNode **ptr){
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
void treeToDll(itNode **ptr){
	if(*ptr == null){
		return;
	}
	treeToDllFixLeftPtr(*ptr);
	treeToDllFixRightPtr(ptr);
}

//Tested
void treeToDllInorderONMain(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	treeToDllInorderONMain(ptr->left);
	ptr->left = prevNode;
	if(prevNode != null){
		prevNode->right = ptr;
	}
	prevNode = ptr;
	treeToDllInorderONMain(ptr->right);
}

//Tested
void treeToDllInOrderON(itNode **ptr){
	if(*ptr == null){
		return;
	}
	treeToDllInorderONMain(*ptr);
	itNode *crawler = *ptr;
	while(crawler->left != null){
		crawler = crawler->left;
	}
	(*ptr) = crawler;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *treeToDllON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = treeToDllON2Main(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		ptr->left = temp;
		temp->right = ptr;
	}
	if(ptr->right != null){
		temp = treeToDllON2Main(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		ptr->right = temp;
		temp->left = ptr;
	}
	return ptr;
}

//Tested
void treeToDllON2(itNode **ptr){
	if(ptr == null){
		return;
	}
	treeToDllON2Main(*ptr);
	itNode *crawler = *ptr;
	while(crawler->left != null){
		crawler = crawler->left;
	}
	(*ptr) = crawler;
}

#endif /* TREETODLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
